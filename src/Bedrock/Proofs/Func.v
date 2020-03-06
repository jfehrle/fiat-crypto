Require Import Coq.ZArith.ZArith.
Require Import Coq.Strings.String.
Require Import Coq.Lists.List.
Require Import Coq.micromega.Lia.
Require Import bedrock2.Syntax.
Require Import bedrock2.ProgramLogic.
Require Import bedrock2.Map.Separation.
Require Import bedrock2.Map.SeparationLogic.
Require Import bedrock2.WeakestPreconditionProperties.
Require Import coqutil.Word.Interface.
Require Import coqutil.Word.Properties.
Require Import coqutil.Map.Interface.
Require Import coqutil.Map.Properties.
Require Import Crypto.Bedrock.Types.
Require Import Crypto.Bedrock.Tactics.
Require Import Crypto.Bedrock.Util.
Require Import Crypto.Bedrock.Proofs.Cmd.
Require Import Crypto.Bedrock.Proofs.Flatten.
Require Import Crypto.Bedrock.Proofs.Varnames.
Require Import Crypto.Bedrock.Proofs.LoadStoreList.
Require Import Crypto.Bedrock.Translation.Func.
Require Import Crypto.Bedrock.Translation.Flatten.
Require Import Crypto.Bedrock.Translation.LoadStoreList.
Require Import Crypto.Language.API.
Require Import Crypto.Util.ListUtil.
Require Import Crypto.Util.Option.
Import ListNotations. Local Open Scope Z_scope.

Import API.Compilers.
Import Wf.Compilers.expr.
Import Types.Notations Types.Types.

Section Func.
  Context {p : parameters} {p_ok : @ok p}.
  Local Notation bedrock_func := (string * (list string * list string * cmd))%type.

  (* TODO: are these all needed? *)
  Local Existing Instance rep.Z.
  Local Instance sem_ok : Semantics.parameters_ok semantics
    := semantics_ok.
  Local Instance mem_ok : map.ok Semantics.mem
    := Semantics.mem_ok.
  Local Instance varname_eqb_spec x y : BoolSpec _ _ _
    := Decidable.String.eqb_spec x y.

  Inductive valid_func : forall {t}, @API.expr (fun _ => unit) t -> Prop :=
  | validf_Abs :
      forall {s d} f, valid_func (f tt) ->
                      valid_func (expr.Abs (s:=type.base s) (d:=d) f)
  | validf_base :
      forall {b} e, valid_cmd e -> valid_func (t:=type.base b) e
  .

  Lemma translate_func'_correct {t}
        (* three exprs, representing the same Expr with different vars *)
        (e0 : @API.expr (fun _ => unit) t)
        (e1 : @API.expr API.interp_type t)
        (e2 : @API.expr ltype t)
        (* expressions are valid input to translate_func' *)
        (e0_valid : valid_func e0)
        (* context list (consists only of arguments) *)
        (G : list _) :
    (* exprs are all related *)
    wf3 G e0 e1 e2 ->
    forall (argnames : type.for_each_lhs_of_arrow ltype t)
           (args : type.for_each_lhs_of_arrow API.interp_type t)
           (nextn : nat),
      (* ret1 := fiat-crypto interpretation of e1 applied to args1 *)
      let ret1 : base.interp (type.final_codomain t) :=
          type.app_curried (API.interp e1) args in
      (* out := translation output for e2; triple of
         (# varnames used, return values, cmd) *)
      let out := translate_func' e2 nextn argnames in
      let nvars := fst (fst out) in
      let ret2 := base_rtype_of_ltype (snd (fst out)) in
      let body := snd out in
      (* look up variables in argnames *)
      let argvalues :=
          type.map_for_each_lhs_of_arrow rtype_of_ltype argnames in
      (* argnames don't contain variables we could later overwrite *)
      (forall n,
        (nextn <= n)%nat ->
        ~ varname_set_args argnames (varname_gen n)) ->
      (* G doesn't contain variables we could later overwrite *)
      (forall n,
        (nextn <= n)%nat ->
        ~ context_varname_set G (varname_gen n)) ->
      forall (tr : Semantics.trace)
             (locals : Semantics.locals)
             (mem : Semantics.mem)
             (functions : list bedrock_func),
        (* argument values are equivalent *)
        locally_equivalent_args args argvalues locals ->
        (* contexts are equivalent; for every variable in the context list G,
           the fiat-crypto and bedrock2 results match *)
        context_equiv G locals ->
        (* executing translation output is equivalent to interpreting e *)
        WeakestPrecondition.cmd
          (WeakestPrecondition.call functions)
          body tr mem locals
          (fun tr' mem' locals' =>
             tr = tr' /\
             mem = mem' /\
             PropSet.subset (varname_set (snd (fst out)))
                            (used_varnames nextn nvars) /\
             Interface.map.only_differ
               locals (used_varnames nextn nvars) locals' /\
             locally_equivalent (listZ:=rep.listZ_local) ret1 ret2 locals').
  Proof.
    revert G. cbv zeta.
    induction e0_valid; intros *.
    { (* Abs *)
      inversion 1; cleanup_wf.
      cbn [translate_func']; intros.
      match goal with
      | H : context [varname_set_args] |- _ =>
        cbn [varname_set_args] in H;
          setoid_rewrite not_union_iff in H;
          match type of H with
            forall x y, ?P /\ ?Q =>
            assert (forall x y, P) by (apply H);
            assert (forall x y, Q) by (apply H);
            clear H
          end
      end.
      destruct argnames.
      cbv [locally_equivalent_args] in *.
      cbn [fst snd equivalent_args
               type.map_for_each_lhs_of_arrow] in *.
      match goal with H : sep _ _ map.empty |- _ =>
                      apply sep_empty_iff in H; cleanup
      end.
      eapply IHe0_valid; eauto; [ | ].
      { destruct args; cbn [fst snd].
        cbn [context_varname_set]; intros.
        apply not_union_iff; eauto with lia. }
      { eapply Forall_cons; eauto. } }
    { (* base case *)
      inversion 1; cleanup_wf;
      cbv [translate_func']; intros.
      all:eapply Proper_cmd;
        [solve [apply Proper_call]
        | repeat intro
        | eapply translate_cmd_correct;
          solve [eauto using Proper_call] ];
        cbv beta in *; cleanup; subst;
          tauto. }
  Qed.

  (* This lemma handles looking up the return values *)
  (* TODO : rename *)
  Lemma look_up_return_values {t} :
    forall (ret : base.interp t)
           (retnames : base_ltype (listZ:=rep.listZ_mem) t)
           (locals : Semantics.locals)
           (mem : Semantics.mem)
           (R : Semantics.mem -> Prop),
    sep (equivalent ret (base_rtype_of_ltype retnames) locals) R mem ->
    let retvalues := base_rtype_of_ltype retnames in
    WeakestPrecondition.list_map
      (WeakestPrecondition.get locals) (flatten_retnames retnames)
      (fun flat_rets =>
         sep (equivalent_flat_base ret flat_rets) R mem).
  Proof.
    cbv [flatten_retnames].
    induction t;
      cbn [flatten_base_ltype
             flatten_rets base_rtype_of_ltype rep.rtype_of_ltype
             flatten_base_rtype equivalent_flat_base
             rep.listZ_mem rep.Z equivalent]; break_match;
        repeat match goal with
               | _ => progress (intros; cleanup)
               | _ => progress subst
               | _ => progress cbn [rep.equiv rep.listZ_mem rep.Z] in *
               | _ => progress cbn [List.hd
                                      WeakestPrecondition.list_map
                                      WeakestPrecondition.list_map_body
                                      WeakestPrecondition.literal
                                      WeakestPrecondition.dexpr
                                      WeakestPrecondition.dexprs
                                      WeakestPrecondition.expr
                                      WeakestPrecondition.expr_body]
               | _ => rewrite word.of_Z_unsigned
               | H : sep (emp _) _ _ |- _ => apply sep_emp_l in H
               | H : sep (fun _ => emp _ _) _ _ |- _ => apply sep_emp_l in H
               | H : sep (sep (fun _ => emp _ _) _) _ _ |- _ => apply sep_assoc in H
               | H : sep (Lift1Prop.ex1 _) _ _ |- _ => apply sep_ex1_l in H; destruct H
               | H : WeakestPrecondition.dexpr _ _ _ _ |- _ => destruct H
               | |- WeakestPrecondition.get _ _ _ => eexists; split; [ eassumption | ]
               | |- WeakestPrecondition.literal _ _ =>
                 cbv [WeakestPrecondition.literal dlet.dlet]
               | |- sep (emp _) _ _ => apply sep_emp_l
               | |- sep (sep (emp _) _) _ _ => apply sep_assoc
               | |- _ /\ _ => split
               | H : False |- _ => tauto
               | _ => reflexivity
               | _ => solve [eauto]
               end.
    { apply list_map_app_iff;
        [ split; intros;
          (eapply Proper_get; [|eassumption]); repeat intro;
          match goal with H : _ |- _ => apply H; solve [eauto] end |  ].
      eapply Proper_list_map; [ solve [apply Proper_get] | repeat intro | ].
      2:{ eapply IHt1;
          (* TODO: why does ecancel_assumption not work here? *)
          use_sep_assumption; rewrite sep_assoc; reflexivity. }
      cbv beta in *.
      eapply Proper_list_map; [ solve [apply Proper_get] | repeat intro | ].
      2:{ eapply IHt2.
          (* TODO: why does ecancel_assumption not work here? *)
          use_sep_assumption; rewrite sep_comm,sep_assoc; reflexivity. }
      cbv beta in *.
      apply sep_ex1_l.
      match goal with |- context[List.firstn _ (?x ++ ?y)] =>
                      exists (length x) end.
      rewrite firstn_app_sharp, skipn_app_sharp by reflexivity.
      ecancel_assumption. }
    { apply sep_ex1_l; eexists.
      apply sep_assoc, sep_emp_l. split; eauto.
      cbv [WeakestPrecondition.literal dlet.dlet].
      rewrite word.of_Z_unsigned. reflexivity. }
  Qed.

  Lemma initial_context_correct' {t} :
    forall (names : base_ltype t)
           (values : base.interp t)
           (flat_values : list Semantics.word)
           (locals locals' : Semantics.locals),
      NoDup (flatten_base_ltype names) ->
      map.putmany_of_list_zip
        (flatten_base_ltype names) flat_values locals = Some locals' ->
      Lift1Prop.iff1
        (equivalent_flat_base values flat_values) 
        (equivalent values (base_rtype_of_ltype names) locals').
  Proof.
    induction t; 
      cbn [rep.Z rep.equiv base_rtype_of_ltype
                 equivalent equivalent_flat_base
                 flatten_base_ltype];
      break_match; cbn [fst snd]; intros; try reflexivity; [ | | ].
    all:match goal with
          H : _ |- _ =>
          pose proof H;
            eapply map.putmany_of_list_zip_sameLength in H;
            cbn [length] in H
        end.
    { repeat intro. rewrite sep_emp_l.
      destruct flat_values as [| ? [|? ?] ]; cbn [length] in *; try lia.
      cbv [emp List.hd
               WeakestPrecondition.literal dlet.dlet
               WeakestPrecondition.get WeakestPrecondition.dexpr
               WeakestPrecondition.expr WeakestPrecondition.expr_body].
      repeat match goal with
             | _ => progress cbn [map.putmany_of_list_zip] in *
             | H : Some _ = Some _ |- _ => inversion H; clear H; subst
             | _ => rewrite map.get_put_same, word.of_Z_unsigned
             | _ => split; intros; cleanup; subst
             | _ => solve [eauto]
             end. }
    { match goal with
      | H : _ |- _ =>
        rewrite putmany_of_list_zip_app_l in H;
          pose proof H;
          rewrite putmany_of_list_zip_bind_comm in H by auto
      end.
      match goal with
        H : NoDup (_ ++ _) |- _ =>
        pose proof H;
        apply NoDup_app_iff in H; cleanup
      end.
      cbv [bind] in *.
      break_match_hyps; try congruence.
      repeat intro; split; intros.
      { match goal with
        | H : Lift1Prop.ex1 _ _ |- _ => destruct H end.
        eapply Proper_sep_iff1;
          [ symmetry; eapply IHt1; eassumption
          | symmetry; eapply IHt2; eassumption | ].
        erewrite <-flatten_base_samelength by ecancel_assumption.
        rewrite firstn_length_firstn, skipn_length_firstn.
        assumption. }
      { eexists. 
        eapply Proper_sep_iff1;
          [ eapply IHt1; eassumption
          | eapply IHt2; eassumption | ].
        eapply Proper_sep_iff1; [ | reflexivity | ].
        { eapply (equivalent_only_differ_iff1
                    ltac:(eapply equiv_listZ_only_differ_mem)
                 _ locals');
            eauto using only_differ_sym, map.only_differ_putmany.
          symmetry.
          eapply disjoint_sameset; eauto using varname_set_flatten.
          apply NoDup_disjoint; eauto using string_dec. }
        { eauto. } } }
    { repeat intro. rewrite sep_emp_l.
      destruct flat_values as [| ? [|? ?] ]; cbn [length] in *; try lia.
      cbv [List.hd
             rep.equiv rep.rtype_of_ltype rep.listZ_mem rep.Z
             WeakestPrecondition.literal dlet.dlet
             WeakestPrecondition.get WeakestPrecondition.dexpr
             WeakestPrecondition.expr WeakestPrecondition.expr_body].
      match goal with
        H : map.putmany_of_list_zip _ _ _ = _ |- _ =>
        cbn [map.putmany_of_list_zip] in H; inversion H; clear H; subst
      end.
      split; intros;
        repeat match goal with
               | _ => progress sepsimpl 
               | _ => progress subst
               | H : Some _ = Some _ |- _ =>
                 inversion H; clear H; subst
               | H : _ |- _ => rewrite word.of_Z_unsigned in H
               | H : _ |- _ => rewrite map.get_put_same in H
               | _ => rewrite map.get_put_same
               | _ => rewrite word.of_Z_unsigned
               | |- Lift1Prop.ex1 _ _ => eexists
               | |- exists _, _ => eexists
               | |- _ /\ _ => split
               | _ => solve [eauto]
               | _ => congruence
               end. }
  Qed.

  (* When arguments are loaded into initial locals, the new argument names map
     to the correct values *)
  Lemma initial_context_correct {t} :
    forall (argnames : type.for_each_lhs_of_arrow ltype t)
           (args : type.for_each_lhs_of_arrow API.interp_type t)
           (flat_args : list Semantics.word)
           (locals locals' : Semantics.locals),
      NoDup (flatten_argnames argnames) ->
      map.putmany_of_list_zip
        (flatten_argnames argnames) flat_args locals = Some locals' ->
      let argvalues :=
          type.map_for_each_lhs_of_arrow rtype_of_ltype argnames in
      Lift1Prop.iff1
        (equivalent_flat_args args flat_args) 
        (equivalent_args args argvalues locals').
  Proof.
    induction t;
      cbn [equivalent_args
             equivalent_flat_args
             flatten_argnames type.map_for_each_lhs_of_arrow];
      break_match; intros; try reflexivity; [ | ].
    all:match goal with
          H : _ |- _ =>
          pose proof H;
            eapply map.putmany_of_list_zip_sameLength in H
        end.
    { 
      destruct flat_args; cbn [length] in *; try lia; [ ].
      repeat intro; cbv [emp]; tauto. }
    { destruct argnames. cbn [fst snd rtype_of_ltype] in *.
      match goal with
      | H : _ |- _ =>
        pose proof H; rewrite putmany_of_list_zip_app_l in H
      end.
      match goal with
      | H : NoDup (_ ++ _) |- _ =>
        pose proof H; apply NoDup_app_iff in H; cleanup
      end.
      cbv [bind] in *. break_match_hyps; try congruence.
      repeat intro; split; intros.
      { repeat match goal with
               | _ => progress cleanup
               | H : Lift1Prop.ex1 _ _ |- _ => destruct H
               | H: _ |- _ =>
                 erewrite <-flatten_base_samelength in H by eauto;
                   rewrite ?firstn_length_firstn, ?skipn_length_firstn in H
               end.
        eapply Proper_sep_iff1;
          [ | symmetry; eapply IHt2; eassumption | eassumption ].
        { symmetry.
          erewrite equivalent_only_differ_iff1 by
            (eauto using only_differ_sym, map.only_differ_putmany
               with equiv;
             rewrite varname_set_flatten; symmetry;
             apply NoDup_disjoint; eauto using string_dec).
          eapply initial_context_correct'; eauto. } }
      { eexists.
        eapply Proper_sep_iff1;
          [ | eapply IHt2; solve [eauto] | eassumption ].
        match goal with
          H : map.putmany_of_list_zip _ (List.skipn _ _) ?x = _ |- _ =>
          erewrite equivalent_only_differ_iff1 with (locals2:=x) by
              (eauto using only_differ_sym, map.only_differ_putmany
                 with equiv; rewrite varname_set_flatten; symmetry;
               apply NoDup_disjoint; eauto using string_dec)
        end.
        eapply initial_context_correct'; solve[eauto]. } }
  Qed.

  Lemma translate_func_correct {t}
        (e : API.Expr t)
        (* expressions are valid input to translate_func *)
        (e_valid : valid_func (e _)) :
    Wf3 e ->
    forall (fname : string)
           (locs : list_locs (type.final_codomain t))
           (retnames : base_ltype (type.final_codomain t))
           (argnames : type.for_each_lhs_of_arrow ltype t)
           (args : type.for_each_lhs_of_arrow API.interp_type t),
      (* rets := fiat-crypto interpretation of e1 applied to args *)
      let rets : base.interp (type.final_codomain t) :=
          type.app_curried (API.interp (e _)) args in
      (* extract list lengths from fiat-crypto arguments/return values *)
      let arglengths := list_lengths_from_args args in
      let retlengths := list_lengths_from_value rets in
      (* out := translation output for e2; triple of
         (function arguments, function return variable names, body) *)
      let out := translate_func e argnames arglengths retnames locs in
      let f : bedrock_func := (fname, out) in
      forall (tr : Semantics.trace)
             (mem : Semantics.mem)
             (flat_args : list Semantics.word)
             (functions : list bedrock_func)
             (P Ra Rr : Semantics.mem -> Prop),
        (* argnames don't contain variables we could later overwrite *)
        (forall n, ~ varname_set_args argnames (varname_gen n)) ->
        (* argument values are equivalent *)
        sep (equivalent_flat_args args flat_args) Ra mem ->
        (* argnames don't have duplicates *)
        NoDup (flatten_argnames argnames) ->
        (* retnames don't contain variables we could later overwrite *)
        (forall n, ~ varname_set retnames (varname_gen n)) ->
        (* retnames don't have duplicates *)
        NoDup (flatten_base_ltype retnames) ->
        (* seplogic frame for return values *)
        sep (lists_reserved retlengths locs) Rr mem ->
        (* translated function produces equivalent results *)
        WeakestPrecondition.call
          ((fname, out) :: functions) fname tr mem flat_args
          (fun tr' mem' flat_rets =>
             tr = tr' /\
             (* return values are equivalent *)
             sep (equivalent_flat_base rets flat_rets) Rr mem').
  Proof.
    cbv [translate_func Wf3]; intros.
    cbn [WeakestPrecondition.call
           WeakestPrecondition.call_body WeakestPrecondition.func].
    rewrite eqb_refl.
    match goal with H : _ |- _ =>
                    pose proof H;
                      eapply of_list_zip_flatten_argnames
                        with (argnames0:=argnames) in H;
                      cleanup
    end.
    eexists; split; [ eassumption | ].
    cbn [WeakestPrecondition.cmd WeakestPrecondition.cmd_body].
    eapply Proper_cmd; [ solve [apply Proper_call] | repeat intro | ].
    2 : { eapply load_arguments_correct; try eassumption; eauto.
          eapply Proper_sep_iff1;
            [ symmetry; eapply initial_context_correct; solve [eauto]
            | reflexivity | eassumption ]. }
    cbv beta in *. cleanup; subst.
    eapply Proper_cmd; [ solve [apply Proper_call] | repeat intro | ].
    2 : { eapply translate_func'_correct with (args0:=args);
          cbv [context_equiv]; eauto. }
    cbv beta in *. cleanup; subst.
    eapply Proper_cmd; [ solve [apply Proper_call] | repeat intro | ].
    2 : { eapply store_return_values_correct; eauto.
          eapply subset_disjoint'; try eassumption.
          symmetry.
          eauto using disjoint_used_varnames_lt. }
    
    cbv beta in *. cleanup; subst.
    eapply Proper_list_map; [ solve [apply Proper_get]
                            | | eapply look_up_return_values; eauto ].
    repeat intro; cleanup; eauto.
  Qed.

  (*
    TODO : prove assumptions shown by:
    Print Assumptions translate_func_correct.
    
    equiv_Z_only_differ_iff1 (medium)
    assign_correct (medium/hard)
    translate_expr_correct (hard)
  *)
End Func.