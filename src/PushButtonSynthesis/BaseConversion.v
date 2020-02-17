(** * Push-Button Synthesis of Unsaturated Solinas *)
Require Import Coq.Strings.String.
Require Import Coq.micromega.Lia.
Require Import Coq.ZArith.ZArith.
Require Import Coq.MSets.MSetPositive.
Require Import Coq.Lists.List.
Require Import Coq.QArith.QArith_base Coq.QArith.Qround.
Require Import Coq.derive.Derive.
Require Import Crypto.Util.ErrorT.
Require Import Crypto.Util.ListUtil.
Require Import Crypto.Util.ListUtil.FoldBool.
Require Import Crypto.Util.Strings.Decimal.
Require Import Crypto.Util.Strings.Equality.
Require Import Crypto.Util.ZRange.
Require Import Crypto.Util.Strings.Show.
Require Import Crypto.Util.ZUtil.Definitions.
Require Import Crypto.Util.ZUtil.Zselect.
Require Import Crypto.Util.ZUtil.Log2.
Require Import Crypto.Util.ZUtil.Tactics.LtbToLt.
Require Import Crypto.Util.ZUtil.Tactics.PeelLe.
Require Import Crypto.Util.ZUtil.Tactics.DivModToQuotRem.
Require Import Crypto.Util.ZUtil.Tactics.ReplaceNegWithPos.
Require Import Crypto.Util.Tactics.HasBody.
Require Import Crypto.Util.Tactics.Head.
Require Import Crypto.Util.Tactics.SpecializeBy.
Require Import Rewriter.Language.Wf.
Require Import Rewriter.Language.Language.
Require Import Crypto.Language.API.
Require Import Crypto.AbstractInterpretation.AbstractInterpretation.
Require Import Crypto.Stringification.Language.
Require Import Crypto.Arithmetic.Core.
Require Import Crypto.Arithmetic.ModOps.
Require Import Crypto.Arithmetic.BaseConversion.
Require Import Crypto.BoundsPipeline.
Require Import Crypto.COperationSpecifications.
Require Import Crypto.UnsaturatedSolinasHeuristics.
Require Import Crypto.PushButtonSynthesis.ReificationCache.
Require Import Crypto.PushButtonSynthesis.Primitives.
Require Import Crypto.PushButtonSynthesis.BaseConversionReificationCache.
Import ListNotations.
Local Open Scope Z_scope. Local Open Scope list_scope. Local Open Scope bool_scope.

Import
  Language.Wf.Compilers
  Language.Compilers
  AbstractInterpretation.Compilers
  Stringification.Language.Compilers.
Import Compilers.API.

Import COperationSpecifications.Primitives.
Import COperationSpecifications.BaseConversion.

Import Associational Positional.

Local Coercion Z.of_nat : nat >-> Z.
Local Coercion QArith_base.inject_Z : Z >-> Q.
Local Coercion Z.pos : positive >-> Z.

Local Set Keyed Unification. (* needed for making [autorewrite] fast, c.f. COQBUG(https://github.com/coq/coq/issues/9283) *)

(* needed for making [autorewrite] not take a very long time *)
Local Opaque
      reified_convert_bases_gen
      expr.Interp.

Inductive bounds := exactly (_ : list Z) | use_prime | use_bitwidth.

Global Instance show_bounds : Show bounds
  := fun with_parens v
     => match v with
        | use_prime => "use_prime"
        | use_bitwidth => "use_bitwidth"
        | exactly l => @show_list _ PowersOfTwo.show_Z with_parens l
        end%string.

Definition default_bounds : bounds := use_prime.

Section __.
  Context {output_language_api : ToString.OutputLanguageAPI}
          {static : static_opt}
          {internal_static : internal_static_opt}
          {low_level_rewriter_method : low_level_rewriter_method_opt}
          {only_signed : only_signed_opt}
          {use_mul_for_cmovznz : use_mul_for_cmovznz_opt}
          {emit_primitives : emit_primitives_opt}
          {should_split_mul : should_split_mul_opt}
          {should_split_multiret : should_split_multiret_opt}
          {widen_carry : widen_carry_opt}
          {widen_bytes : widen_bytes_opt}
          (s : Z) (c : list (Z * Z))
          (src_n : nat)
          (src_limbwidth : Q)
          (dst_limbwidth : Q)
          (machine_wordsize : Z)
          (inbounds_multiplier : option Q)
          (outbounds_multiplier : option Q)
          (inbounds : bounds)
          (outbounds : bounds).

  Local Notation src_weight := (weight (Qnum src_limbwidth) (Qden src_limbwidth)).
  Local Notation dst_weight := (weight (Qnum dst_limbwidth) (Qden dst_limbwidth)).

  Local Notation force_power_of_two v
    := (2^Z.log2_up v) (only parsing).

  Let in_upperbounds : list Z
    := List.map
         (fun v : Z => Qceiling (Option.value inbounds_multiplier 1 * v))
         (let encode := encode_no_reduce src_weight src_n in
          match inbounds with
          | exactly l => l
          | use_prime => encode (s - 1)
          | use_bitwidth => encode (src_weight src_n - 1)
          end).
  Let dst_n : nat
    := let max := match outbounds with
                  | exactly l => inl (List.length l)
                  | use_prime => inr s
                  | use_bitwidth => inr (src_weight src_n)
                  end in
       match max with
       | inl len => len
       | inr max
         => Z.to_nat (Qceiling (Z.log2_up max / dst_limbwidth))
       end.
  Let out_upperbounds : list Z
    := List.map
         (fun v : Z => Qceiling (Option.value outbounds_multiplier 1 * v))
         (let encode := encode_no_reduce dst_weight dst_n in
          match outbounds with
          | exactly l => l
          | use_prime => encode (s - 1)
          | use_bitwidth => encode (dst_weight dst_n - 1)
          end).

  (* We include [0], so that even after bounds relaxation, we can
       notice where the constant 0s are, and remove them. *)
  Definition possible_values_of_machine_wordsize_with_bytes
    := prefix_with_carry_bytes [machine_wordsize; 2 * machine_wordsize]%Z.

  Let possible_values_with_bytes := possible_values_of_machine_wordsize_with_bytes.
  Definition in_bounds : list (ZRange.type.option.interp base.type.Z)
    := List.map (fun u => Some r[0~>u]%zrange) in_upperbounds.
  Definition out_bounds : list (ZRange.type.option.interp base.type.Z)
    := List.map (fun u => Some r[0~>u]%zrange) out_upperbounds.

  Local Instance split_mul_to : split_mul_to_opt := split_mul_to_of_should_split_mul machine_wordsize possible_values_of_machine_wordsize_with_bytes.
  Local Instance split_multiret_to : split_multiret_to_opt := split_multiret_to_of_should_split_multiret machine_wordsize possible_values_of_machine_wordsize_with_bytes.

  (** Note: If you change the name or type signature of this
        function, you will need to update the code in CLI.v *)
  Definition check_args {T} (res : Pipeline.ErrorT T)
    : Pipeline.ErrorT T
    := fold_right
         (fun '(b, e) k => if b:bool then Error e else k)
         res
         [(negb (Qle_bool 1 src_limbwidth)%Q, Pipeline.Value_not_leQ "src_limbwidth < 1" 1%Q src_limbwidth);
            (negb (Qle_bool 1 dst_limbwidth)%Q, Pipeline.Value_not_leQ "dst_limbwidth < 1" 1%Q dst_limbwidth);
            ((src_n =? 0)%nat, Pipeline.Values_not_provably_distinctZ "src_n = 0" src_n 0%nat);
            ((dst_n =? 0)%nat, Pipeline.Values_not_provably_distinctZ "dst_n = 0" dst_n 0%nat);
            (negb (List.length in_bounds =? src_n)%nat, Pipeline.Values_not_provably_equalZ "length in_bounds ≠ src_n" (List.length in_bounds) src_n);
            (negb (List.length in_upperbounds =? src_n)%nat, Pipeline.Values_not_provably_equalZ "length in_upperbounds ≠ src_n" (List.length in_upperbounds) src_n);
            (negb (List.length out_bounds =? dst_n)%nat, Pipeline.Values_not_provably_equalZ "length out_bounds ≠ dst_n" (List.length out_bounds) dst_n);
            (negb (List.length out_upperbounds =? dst_n)%nat, Pipeline.Values_not_provably_equalZ "length out_upperbounds ≠ dst_n" (List.length out_upperbounds) dst_n);
            ((negb (Associational.eval c <? s))%Z, Pipeline.Value_not_ltZ "s ≤ Associational.eval c" (Associational.eval c) s);
            ((s =? 0)%Z, Pipeline.Values_not_provably_distinctZ "s = 0" s 0);
            (let eval_in_upperbounds := eval src_weight src_n in_upperbounds in
             let dst_weight_n := dst_weight dst_n in
             (negb (eval_in_upperbounds <? dst_weight_n)%Z,
              Pipeline.Value_not_ltZ "dst_weight dst_n ≤ src_eval in_upperbounds" eval_in_upperbounds dst_weight_n));
            ((negb (0 <? machine_wordsize)), Pipeline.Value_not_ltZ "machine_wordsize ≤ 0" 0 machine_wordsize);
            (let v1 := List.fold_right Z.max 0 in_upperbounds in
             let v2 := 2^machine_wordsize-1 in
             (negb (v1 <=? v2)%Z,
              Pipeline.Value_not_leZ "max(in_upperbounds) > 2^machine_wordsize-1" v1 v2));
            (let v1 := List.fold_right Z.max 0 out_upperbounds in
             let v2 := 2^machine_wordsize-1 in
             (negb (v1 <=? v2)%Z,
              Pipeline.Value_not_leZ "max(out_upperbounds) > 2^machine_wordsize-1" v1 v2))].

  Local Ltac use_curve_good_t :=
    repeat first [ assumption
                 | progress rewrite ?map_length, ?Z.mul_0_r, ?Pos.mul_1_r, ?Z.mul_1_r in *
                 | reflexivity
                 | lia
                 | rewrite expr.interp_reify_list, ?map_map
                 | rewrite map_ext with (g:=id), map_id
                 | progress distr_length
                 | progress cbv [Qceiling Qfloor Qopp Qdiv Qplus inject_Z Qmult Qinv] in *
                 | progress cbv [Qle] in *
                 | progress cbn -[reify_list] in *
                 | progress intros
                 | progress break_innermost_match
                 | progress specialize_by_assumption
                 | progress specialize_by (exact eq_refl)
                 | solve [ auto ]
                 | progress break_innermost_match_hyps ].

  Ltac prepare_use_curve_good _ :=
    let curve_good := lazymatch goal with | curve_good : check_args _ = Success _ |- _ => curve_good end in
    clear -curve_good;
    cbv [check_args fold_right] in curve_good |- *;
    repeat first [ match goal with
                   | [ H : context[match ?b with true => _ | false => _ end ] |- _ ] => destruct b eqn:?
                   end
                 | discriminate
                 | progress Reflect.reflect_hyps
                 | assumption
                 | apply conj
                 | progress destruct_head'_and ].

  Context (curve_good : check_args (Success tt) = Success tt).

  Lemma use_curve_good
    : 0 < machine_wordsize
      /\ s - Associational.eval c <> 0
      /\ s <> 0
      /\ src_n <> 0%nat
      /\ dst_n <> 0%nat
      /\ List.length in_bounds = src_n
      /\ List.length out_bounds = dst_n
      /\ List.length in_upperbounds = src_n
      /\ List.length out_upperbounds = dst_n
      /\ 0 < Qden src_limbwidth <= Qnum src_limbwidth
      /\ 0 < Qden dst_limbwidth <= Qnum dst_limbwidth
      /\ eval src_weight src_n in_upperbounds < dst_weight dst_n.
  Proof using curve_good.
    prepare_use_curve_good ().
    { use_curve_good_t. }
    { use_curve_good_t. }
    { use_curve_good_t. }
    { use_curve_good_t. }
    { use_curve_good_t. }
  Qed.

  Local Notation src_weightf := (weight (Qnum src_limbwidth) (QDen src_limbwidth)).
  Local Notation src_evalf := (eval src_weightf src_n).
  Local Notation dst_weightf := (weight (Qnum dst_limbwidth) (QDen dst_limbwidth)).
  Local Notation dst_evalf := (eval dst_weightf dst_n).
  Local Notation notations_for_docstring
    := (CorrectnessStringification.dyn_context.cons
          src_weightf "src_weight"
          (CorrectnessStringification.dyn_context.cons
             src_evalf "src_eval"
             (CorrectnessStringification.dyn_context.cons
                dst_weightf "dst_weight"
                (CorrectnessStringification.dyn_context.cons
                   dst_evalf "dst_eval"
                   (CorrectnessStringification.dyn_context.cons
                      (s - Associational.eval c) "(s - c)"
                      CorrectnessStringification.dyn_context.nil)))))%string.
  Local Notation "'docstring_with_summary_from_lemma!' summary correctness"
    := (docstring_with_summary_from_lemma_with_ctx!
          notations_for_docstring
          summary
          correctness)
         (only parsing, at level 10, summary at next level, correctness at next level).

  Definition convert_bases
    := Pipeline.BoundsPipeline
         false (* subst01 *)
         None (* fancy *)
         possible_values_with_bytes
         (reified_convert_bases_gen
            @ GallinaReify.Reify (Qnum src_limbwidth) @ GallinaReify.Reify (Z.pos (Qden src_limbwidth))
            @ GallinaReify.Reify (Qnum dst_limbwidth) @ GallinaReify.Reify (Z.pos (Qden dst_limbwidth))
            @ GallinaReify.Reify src_n
            @ GallinaReify.Reify dst_n)
         (Some in_bounds, tt)
         (Some out_bounds).

  Definition sconvert_bases (prefix : string)
    : string * (Pipeline.ErrorT (list string * ToString.ident_infos))
    := Eval cbv beta in
        FromPipelineToString
          prefix "convert_bases" convert_bases
          (docstring_with_summary_from_lemma!
             (fun fname : string => ["The function " ++ fname ++ " converts a field element from base " ++ Decimal.show_Q false src_limbwidth ++ " to base " ++ Decimal.show_Q false dst_limbwidth ++ " in little-endian order."]%string)
             (convert_bases_correct src_weight dst_weight src_n dst_n in_bounds)).

  Local Ltac solve_extra_bounds_side_conditions :=
    cbn [lower upper fst snd] in *; Bool.split_andb; Z.ltb_to_lt; lia.

  Hint Rewrite
       eval_convert_basesmod
       using solve [ auto | congruence | solve_extra_bounds_side_conditions ] : push_eval.

  Local Ltac prove_correctness _ :=
    Primitives.prove_correctness use_curve_good;
    try solve [ auto | congruence | solve_extra_bounds_side_conditions ].

  Lemma convert_bases_correct res
        (Hres : convert_bases = Success res)
    : convert_bases_correct src_weight dst_weight src_n dst_n in_bounds (Interp res).
  Proof using curve_good.
    prove_correctness (); [].
    erewrite convert_basesmod_partitions; [ reflexivity | .. ].
    all: repeat apply conj; (congruence || auto).
    all: cbv [in_bounds] in *.
    all: lazymatch goal with
         | [ H1 : list_Z_bounded_by (List.map (fun y => Some (@?f y)) ?b) ?x
             |- context[eval ?wt ?n ?x] ]
           => unshelve epose proof (eval_list_Z_bounded_by wt n (List.map (fun x => Some (f x)) b) (List.map f b) x H1 _ _ (fun A B => Z.lt_le_incl _ _ (weight_positive _ _))); clear H1
         end.
    all: congruence || auto.
    all: repeat first [ reflexivity
                      | apply wprops
                      | progress rewrite ?map_map in *
                      | progress rewrite ?map_id in *
                      | progress cbn [upper lower] in *
                      | lia
                      | match goal with
                        | [ H : context[List.map (fun _ => 0) _] |- _ ] => erewrite <- zeros_ext_map, ?eval_zeros in H by reflexivity
                        | [ H : List.length ?l = ?n, H' : context[eval ?w ?n (zeros (List.length ?l))] |- _ ]
                          => rewrite !H, eval_zeros in H'
                        end
                      | progress autorewrite with distr_length push_eval in *
                      | destruct_head'_and; eapply Z.le_lt_trans; eassumption ].
  Qed.

  Section for_stringification.
    Local Open Scope string_scope.
    Local Open Scope list_scope.

    Definition known_functions
      := [("convert_bases", sconvert_bases)].

    Definition valid_names : string
      := Eval compute in String.concat ", " (List.map (@fst _ _) known_functions).

    Definition extra_special_synthesis (function_name_prefix : string) (name : string)
      : list (option (string * Pipeline.ErrorT (list string * ToString.ident_infos)))
      := [].

    (** Note: If you change the name or type signature of this
          function, you will need to update the code in CLI.v *)
    Definition Synthesize (comment_header : list string) (function_name_prefix : string) (requests : list string)
      : list (string * Pipeline.ErrorT (list string))
      := Primitives.Synthesize
           machine_wordsize valid_names known_functions (extra_special_synthesis function_name_prefix)
           check_args
           ((ToString.comment_block comment_header)
              ++ [""]
              ++ (ToString.comment_block
                    ["Computed values:";
                       "dst_n = " ++ show false dst_n]%string)
              ++ [""])
           function_name_prefix requests.
  End for_stringification.
End __.
