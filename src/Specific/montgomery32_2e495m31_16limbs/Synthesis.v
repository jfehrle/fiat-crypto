Require Import Crypto.Specific.Framework.SynthesisFramework. Export SynthesisFramework.Exports.
Require Import Crypto.Specific.montgomery32_2e495m31_16limbs.CurveParameters.

Module P <: PrePackage.
  Definition package : Tag.Context.
  Proof. make_Synthesis_package curve extra_prove_mul_eq extra_prove_square_eq. Defined.
End P.

Module Export S := PackageSynthesis P.