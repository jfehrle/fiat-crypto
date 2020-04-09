/* Autogenerated: src/ExtractionOCaml/bedrock2_word_by_word_montgomery --lang=bedrock2 --no-wide-int --widen-carry --widen-bytes --split-multiret p384 '2^384 - 2^128 - 2^96 + 2^32 - 1' 64 nonzero to_bytes from_bytes */
/* curve description: p384 */
/* requested operations: nonzero, to_bytes, from_bytes */
/* m = 0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffeffffffff0000000000000000ffffffff (from "2^384 - 2^128 - 2^96 + 2^32 - 1") */
/* machine_wordsize = 64 (from "64") */
/*                                                                    */
/* NOTE: In addition to the bounds specified above each function, all */
/*   functions synthesized for this Montgomery arithmetic require the */
/*   input to be strictly less than the prime modulus (m), and also   */
/*   require the input to be in the unique saturated representation.  */
/*   All functions also ensure that these two properties are true of  */
/*   return values.                                                   */



/*
 * Input Bounds:
 *   in0: [[0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff]]
 * Output Bounds:
 *   out0: [0x0 ~> 0xffffffffffffffff]
 */
uintptr_t fiat_p384_nonzero(uintptr_t in0) {
  uintptr_t x0, x1, x2, x3, x4, x5, x6, out0, x7;
  x0 = *(uintptr_t*)((in0)+((uintptr_t)0ULL));
  x1 = *(uintptr_t*)((in0)+((uintptr_t)8ULL));
  x2 = *(uintptr_t*)((in0)+((uintptr_t)16ULL));
  x3 = *(uintptr_t*)((in0)+((uintptr_t)24ULL));
  x4 = *(uintptr_t*)((in0)+((uintptr_t)32ULL));
  x5 = *(uintptr_t*)((in0)+((uintptr_t)40ULL));
  /*skip*/
  /*skip*/
  x6 = (x0)|((x1)|((x2)|((x3)|((x4)|((x5)|((uintptr_t)0ULL))))));
  x7 = x6;
  out0 = x7;
  return out0;
}


/*
 * Input Bounds:
 *   in0: [[0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff]]
 * Output Bounds:
 *   out0: [[0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff]]
 */
void fiat_p384_to_bytes(uintptr_t in0, uintptr_t out0) {
  uintptr_t x5, x4, x3, x2, x1, x0, x11, x12, x14, x16, x18, x20, x22, x24, x10, x27, x29, x31, x33, x35, x37, x39, x9, x42, x44, x46, x48, x50, x52, x54, x8, x57, x59, x61, x63, x65, x67, x69, x7, x72, x74, x76, x78, x80, x82, x84, x6, x87, x89, x91, x93, x95, x97, x13, x15, x17, x19, x21, x23, x25, x26, x28, x30, x32, x34, x36, x38, x40, x41, x43, x45, x47, x49, x51, x53, x55, x56, x58, x60, x62, x64, x66, x68, x70, x71, x73, x75, x77, x79, x81, x83, x85, x86, x88, x90, x92, x94, x96, x98, x100, x99, x101, x102, x103, x104, x105, x106, x107, x108, x109, x110, x111, x112, x113, x114, x115, x116, x117, x118, x119, x120, x121, x122, x123, x124, x125, x126, x127, x128, x129, x130, x131, x132, x133, x134, x135, x136, x137, x138, x139, x140, x141, x142, x143, x144, x145, x146, x147, x148;
  x0 = *(uintptr_t*)((in0)+((uintptr_t)0ULL));
  x1 = *(uintptr_t*)((in0)+((uintptr_t)8ULL));
  x2 = *(uintptr_t*)((in0)+((uintptr_t)16ULL));
  x3 = *(uintptr_t*)((in0)+((uintptr_t)24ULL));
  x4 = *(uintptr_t*)((in0)+((uintptr_t)32ULL));
  x5 = *(uintptr_t*)((in0)+((uintptr_t)40ULL));
  /*skip*/
  /*skip*/
  x6 = x5;
  x7 = x4;
  x8 = x3;
  x9 = x2;
  x10 = x1;
  x11 = x0;
  x12 = (x11)>>((uintptr_t)8ULL);
  x13 = (x11)&((uintptr_t)255ULL);
  x14 = (x12)>>((uintptr_t)8ULL);
  x15 = (x12)&((uintptr_t)255ULL);
  x16 = (x14)>>((uintptr_t)8ULL);
  x17 = (x14)&((uintptr_t)255ULL);
  x18 = (x16)>>((uintptr_t)8ULL);
  x19 = (x16)&((uintptr_t)255ULL);
  x20 = (x18)>>((uintptr_t)8ULL);
  x21 = (x18)&((uintptr_t)255ULL);
  x22 = (x20)>>((uintptr_t)8ULL);
  x23 = (x20)&((uintptr_t)255ULL);
  x24 = (x22)>>((uintptr_t)8ULL);
  x25 = (x22)&((uintptr_t)255ULL);
  x26 = (x24)&((uintptr_t)255ULL);
  x27 = (x10)>>((uintptr_t)8ULL);
  x28 = (x10)&((uintptr_t)255ULL);
  x29 = (x27)>>((uintptr_t)8ULL);
  x30 = (x27)&((uintptr_t)255ULL);
  x31 = (x29)>>((uintptr_t)8ULL);
  x32 = (x29)&((uintptr_t)255ULL);
  x33 = (x31)>>((uintptr_t)8ULL);
  x34 = (x31)&((uintptr_t)255ULL);
  x35 = (x33)>>((uintptr_t)8ULL);
  x36 = (x33)&((uintptr_t)255ULL);
  x37 = (x35)>>((uintptr_t)8ULL);
  x38 = (x35)&((uintptr_t)255ULL);
  x39 = (x37)>>((uintptr_t)8ULL);
  x40 = (x37)&((uintptr_t)255ULL);
  x41 = (x39)&((uintptr_t)255ULL);
  x42 = (x9)>>((uintptr_t)8ULL);
  x43 = (x9)&((uintptr_t)255ULL);
  x44 = (x42)>>((uintptr_t)8ULL);
  x45 = (x42)&((uintptr_t)255ULL);
  x46 = (x44)>>((uintptr_t)8ULL);
  x47 = (x44)&((uintptr_t)255ULL);
  x48 = (x46)>>((uintptr_t)8ULL);
  x49 = (x46)&((uintptr_t)255ULL);
  x50 = (x48)>>((uintptr_t)8ULL);
  x51 = (x48)&((uintptr_t)255ULL);
  x52 = (x50)>>((uintptr_t)8ULL);
  x53 = (x50)&((uintptr_t)255ULL);
  x54 = (x52)>>((uintptr_t)8ULL);
  x55 = (x52)&((uintptr_t)255ULL);
  x56 = (x54)&((uintptr_t)255ULL);
  x57 = (x8)>>((uintptr_t)8ULL);
  x58 = (x8)&((uintptr_t)255ULL);
  x59 = (x57)>>((uintptr_t)8ULL);
  x60 = (x57)&((uintptr_t)255ULL);
  x61 = (x59)>>((uintptr_t)8ULL);
  x62 = (x59)&((uintptr_t)255ULL);
  x63 = (x61)>>((uintptr_t)8ULL);
  x64 = (x61)&((uintptr_t)255ULL);
  x65 = (x63)>>((uintptr_t)8ULL);
  x66 = (x63)&((uintptr_t)255ULL);
  x67 = (x65)>>((uintptr_t)8ULL);
  x68 = (x65)&((uintptr_t)255ULL);
  x69 = (x67)>>((uintptr_t)8ULL);
  x70 = (x67)&((uintptr_t)255ULL);
  x71 = (x69)&((uintptr_t)255ULL);
  x72 = (x7)>>((uintptr_t)8ULL);
  x73 = (x7)&((uintptr_t)255ULL);
  x74 = (x72)>>((uintptr_t)8ULL);
  x75 = (x72)&((uintptr_t)255ULL);
  x76 = (x74)>>((uintptr_t)8ULL);
  x77 = (x74)&((uintptr_t)255ULL);
  x78 = (x76)>>((uintptr_t)8ULL);
  x79 = (x76)&((uintptr_t)255ULL);
  x80 = (x78)>>((uintptr_t)8ULL);
  x81 = (x78)&((uintptr_t)255ULL);
  x82 = (x80)>>((uintptr_t)8ULL);
  x83 = (x80)&((uintptr_t)255ULL);
  x84 = (x82)>>((uintptr_t)8ULL);
  x85 = (x82)&((uintptr_t)255ULL);
  x86 = (x84)&((uintptr_t)255ULL);
  x87 = (x6)>>((uintptr_t)8ULL);
  x88 = (x6)&((uintptr_t)255ULL);
  x89 = (x87)>>((uintptr_t)8ULL);
  x90 = (x87)&((uintptr_t)255ULL);
  x91 = (x89)>>((uintptr_t)8ULL);
  x92 = (x89)&((uintptr_t)255ULL);
  x93 = (x91)>>((uintptr_t)8ULL);
  x94 = (x91)&((uintptr_t)255ULL);
  x95 = (x93)>>((uintptr_t)8ULL);
  x96 = (x93)&((uintptr_t)255ULL);
  x97 = (x95)>>((uintptr_t)8ULL);
  x98 = (x95)&((uintptr_t)255ULL);
  x99 = (x97)>>((uintptr_t)8ULL);
  x100 = (x97)&((uintptr_t)255ULL);
  x101 = x13;
  x102 = x15;
  x103 = x17;
  x104 = x19;
  x105 = x21;
  x106 = x23;
  x107 = x25;
  x108 = x26;
  x109 = x28;
  x110 = x30;
  x111 = x32;
  x112 = x34;
  x113 = x36;
  x114 = x38;
  x115 = x40;
  x116 = x41;
  x117 = x43;
  x118 = x45;
  x119 = x47;
  x120 = x49;
  x121 = x51;
  x122 = x53;
  x123 = x55;
  x124 = x56;
  x125 = x58;
  x126 = x60;
  x127 = x62;
  x128 = x64;
  x129 = x66;
  x130 = x68;
  x131 = x70;
  x132 = x71;
  x133 = x73;
  x134 = x75;
  x135 = x77;
  x136 = x79;
  x137 = x81;
  x138 = x83;
  x139 = x85;
  x140 = x86;
  x141 = x88;
  x142 = x90;
  x143 = x92;
  x144 = x94;
  x145 = x96;
  x146 = x98;
  x147 = x100;
  x148 = x99;
  /*skip*/
  *(uintptr_t*)((out0)+((uintptr_t)0ULL)) = x101;
  *(uintptr_t*)((out0)+((uintptr_t)8ULL)) = x102;
  *(uintptr_t*)((out0)+((uintptr_t)16ULL)) = x103;
  *(uintptr_t*)((out0)+((uintptr_t)24ULL)) = x104;
  *(uintptr_t*)((out0)+((uintptr_t)32ULL)) = x105;
  *(uintptr_t*)((out0)+((uintptr_t)40ULL)) = x106;
  *(uintptr_t*)((out0)+((uintptr_t)48ULL)) = x107;
  *(uintptr_t*)((out0)+((uintptr_t)56ULL)) = x108;
  *(uintptr_t*)((out0)+((uintptr_t)64ULL)) = x109;
  *(uintptr_t*)((out0)+((uintptr_t)72ULL)) = x110;
  *(uintptr_t*)((out0)+((uintptr_t)80ULL)) = x111;
  *(uintptr_t*)((out0)+((uintptr_t)88ULL)) = x112;
  *(uintptr_t*)((out0)+((uintptr_t)96ULL)) = x113;
  *(uintptr_t*)((out0)+((uintptr_t)104ULL)) = x114;
  *(uintptr_t*)((out0)+((uintptr_t)112ULL)) = x115;
  *(uintptr_t*)((out0)+((uintptr_t)120ULL)) = x116;
  *(uintptr_t*)((out0)+((uintptr_t)128ULL)) = x117;
  *(uintptr_t*)((out0)+((uintptr_t)136ULL)) = x118;
  *(uintptr_t*)((out0)+((uintptr_t)144ULL)) = x119;
  *(uintptr_t*)((out0)+((uintptr_t)152ULL)) = x120;
  *(uintptr_t*)((out0)+((uintptr_t)160ULL)) = x121;
  *(uintptr_t*)((out0)+((uintptr_t)168ULL)) = x122;
  *(uintptr_t*)((out0)+((uintptr_t)176ULL)) = x123;
  *(uintptr_t*)((out0)+((uintptr_t)184ULL)) = x124;
  *(uintptr_t*)((out0)+((uintptr_t)192ULL)) = x125;
  *(uintptr_t*)((out0)+((uintptr_t)200ULL)) = x126;
  *(uintptr_t*)((out0)+((uintptr_t)208ULL)) = x127;
  *(uintptr_t*)((out0)+((uintptr_t)216ULL)) = x128;
  *(uintptr_t*)((out0)+((uintptr_t)224ULL)) = x129;
  *(uintptr_t*)((out0)+((uintptr_t)232ULL)) = x130;
  *(uintptr_t*)((out0)+((uintptr_t)240ULL)) = x131;
  *(uintptr_t*)((out0)+((uintptr_t)248ULL)) = x132;
  *(uintptr_t*)((out0)+((uintptr_t)256ULL)) = x133;
  *(uintptr_t*)((out0)+((uintptr_t)264ULL)) = x134;
  *(uintptr_t*)((out0)+((uintptr_t)272ULL)) = x135;
  *(uintptr_t*)((out0)+((uintptr_t)280ULL)) = x136;
  *(uintptr_t*)((out0)+((uintptr_t)288ULL)) = x137;
  *(uintptr_t*)((out0)+((uintptr_t)296ULL)) = x138;
  *(uintptr_t*)((out0)+((uintptr_t)304ULL)) = x139;
  *(uintptr_t*)((out0)+((uintptr_t)312ULL)) = x140;
  *(uintptr_t*)((out0)+((uintptr_t)320ULL)) = x141;
  *(uintptr_t*)((out0)+((uintptr_t)328ULL)) = x142;
  *(uintptr_t*)((out0)+((uintptr_t)336ULL)) = x143;
  *(uintptr_t*)((out0)+((uintptr_t)344ULL)) = x144;
  *(uintptr_t*)((out0)+((uintptr_t)352ULL)) = x145;
  *(uintptr_t*)((out0)+((uintptr_t)360ULL)) = x146;
  *(uintptr_t*)((out0)+((uintptr_t)368ULL)) = x147;
  *(uintptr_t*)((out0)+((uintptr_t)376ULL)) = x148;
  /*skip*/
  return;
}


/*
 * Input Bounds:
 *   in0: [[0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff], [0x0 ~> 0xff]]
 * Output Bounds:
 *   out0: [[0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff]]
 */
void fiat_p384_from_bytes(uintptr_t in0, uintptr_t out0) {
  uintptr_t x47, x46, x45, x44, x43, x42, x41, x40, x39, x38, x37, x36, x35, x34, x33, x32, x31, x30, x29, x28, x27, x26, x25, x24, x23, x22, x21, x20, x19, x18, x17, x16, x15, x14, x13, x12, x11, x10, x9, x8, x7, x6, x5, x4, x3, x2, x1, x0, x95, x94, x93, x92, x91, x90, x89, x88, x96, x55, x54, x53, x52, x51, x50, x49, x48, x63, x62, x61, x60, x59, x58, x57, x56, x71, x70, x69, x68, x67, x66, x65, x64, x79, x78, x77, x76, x75, x74, x73, x72, x87, x86, x85, x84, x83, x82, x81, x80, x102, x101, x100, x99, x97, x103, x104, x105, x106, x98, x107, x108, x109, x110, x111, x112;
  x0 = *(uintptr_t*)((in0)+((uintptr_t)0ULL));
  x1 = *(uintptr_t*)((in0)+((uintptr_t)8ULL));
  x2 = *(uintptr_t*)((in0)+((uintptr_t)16ULL));
  x3 = *(uintptr_t*)((in0)+((uintptr_t)24ULL));
  x4 = *(uintptr_t*)((in0)+((uintptr_t)32ULL));
  x5 = *(uintptr_t*)((in0)+((uintptr_t)40ULL));
  x6 = *(uintptr_t*)((in0)+((uintptr_t)48ULL));
  x7 = *(uintptr_t*)((in0)+((uintptr_t)56ULL));
  x8 = *(uintptr_t*)((in0)+((uintptr_t)64ULL));
  x9 = *(uintptr_t*)((in0)+((uintptr_t)72ULL));
  x10 = *(uintptr_t*)((in0)+((uintptr_t)80ULL));
  x11 = *(uintptr_t*)((in0)+((uintptr_t)88ULL));
  x12 = *(uintptr_t*)((in0)+((uintptr_t)96ULL));
  x13 = *(uintptr_t*)((in0)+((uintptr_t)104ULL));
  x14 = *(uintptr_t*)((in0)+((uintptr_t)112ULL));
  x15 = *(uintptr_t*)((in0)+((uintptr_t)120ULL));
  x16 = *(uintptr_t*)((in0)+((uintptr_t)128ULL));
  x17 = *(uintptr_t*)((in0)+((uintptr_t)136ULL));
  x18 = *(uintptr_t*)((in0)+((uintptr_t)144ULL));
  x19 = *(uintptr_t*)((in0)+((uintptr_t)152ULL));
  x20 = *(uintptr_t*)((in0)+((uintptr_t)160ULL));
  x21 = *(uintptr_t*)((in0)+((uintptr_t)168ULL));
  x22 = *(uintptr_t*)((in0)+((uintptr_t)176ULL));
  x23 = *(uintptr_t*)((in0)+((uintptr_t)184ULL));
  x24 = *(uintptr_t*)((in0)+((uintptr_t)192ULL));
  x25 = *(uintptr_t*)((in0)+((uintptr_t)200ULL));
  x26 = *(uintptr_t*)((in0)+((uintptr_t)208ULL));
  x27 = *(uintptr_t*)((in0)+((uintptr_t)216ULL));
  x28 = *(uintptr_t*)((in0)+((uintptr_t)224ULL));
  x29 = *(uintptr_t*)((in0)+((uintptr_t)232ULL));
  x30 = *(uintptr_t*)((in0)+((uintptr_t)240ULL));
  x31 = *(uintptr_t*)((in0)+((uintptr_t)248ULL));
  x32 = *(uintptr_t*)((in0)+((uintptr_t)256ULL));
  x33 = *(uintptr_t*)((in0)+((uintptr_t)264ULL));
  x34 = *(uintptr_t*)((in0)+((uintptr_t)272ULL));
  x35 = *(uintptr_t*)((in0)+((uintptr_t)280ULL));
  x36 = *(uintptr_t*)((in0)+((uintptr_t)288ULL));
  x37 = *(uintptr_t*)((in0)+((uintptr_t)296ULL));
  x38 = *(uintptr_t*)((in0)+((uintptr_t)304ULL));
  x39 = *(uintptr_t*)((in0)+((uintptr_t)312ULL));
  x40 = *(uintptr_t*)((in0)+((uintptr_t)320ULL));
  x41 = *(uintptr_t*)((in0)+((uintptr_t)328ULL));
  x42 = *(uintptr_t*)((in0)+((uintptr_t)336ULL));
  x43 = *(uintptr_t*)((in0)+((uintptr_t)344ULL));
  x44 = *(uintptr_t*)((in0)+((uintptr_t)352ULL));
  x45 = *(uintptr_t*)((in0)+((uintptr_t)360ULL));
  x46 = *(uintptr_t*)((in0)+((uintptr_t)368ULL));
  x47 = *(uintptr_t*)((in0)+((uintptr_t)376ULL));
  /*skip*/
  /*skip*/
  x48 = (x47)<<((uintptr_t)56ULL);
  x49 = (x46)<<((uintptr_t)48ULL);
  x50 = (x45)<<((uintptr_t)40ULL);
  x51 = (x44)<<((uintptr_t)32ULL);
  x52 = (x43)<<((uintptr_t)24ULL);
  x53 = (x42)<<((uintptr_t)16ULL);
  x54 = (x41)<<((uintptr_t)8ULL);
  x55 = x40;
  x56 = (x39)<<((uintptr_t)56ULL);
  x57 = (x38)<<((uintptr_t)48ULL);
  x58 = (x37)<<((uintptr_t)40ULL);
  x59 = (x36)<<((uintptr_t)32ULL);
  x60 = (x35)<<((uintptr_t)24ULL);
  x61 = (x34)<<((uintptr_t)16ULL);
  x62 = (x33)<<((uintptr_t)8ULL);
  x63 = x32;
  x64 = (x31)<<((uintptr_t)56ULL);
  x65 = (x30)<<((uintptr_t)48ULL);
  x66 = (x29)<<((uintptr_t)40ULL);
  x67 = (x28)<<((uintptr_t)32ULL);
  x68 = (x27)<<((uintptr_t)24ULL);
  x69 = (x26)<<((uintptr_t)16ULL);
  x70 = (x25)<<((uintptr_t)8ULL);
  x71 = x24;
  x72 = (x23)<<((uintptr_t)56ULL);
  x73 = (x22)<<((uintptr_t)48ULL);
  x74 = (x21)<<((uintptr_t)40ULL);
  x75 = (x20)<<((uintptr_t)32ULL);
  x76 = (x19)<<((uintptr_t)24ULL);
  x77 = (x18)<<((uintptr_t)16ULL);
  x78 = (x17)<<((uintptr_t)8ULL);
  x79 = x16;
  x80 = (x15)<<((uintptr_t)56ULL);
  x81 = (x14)<<((uintptr_t)48ULL);
  x82 = (x13)<<((uintptr_t)40ULL);
  x83 = (x12)<<((uintptr_t)32ULL);
  x84 = (x11)<<((uintptr_t)24ULL);
  x85 = (x10)<<((uintptr_t)16ULL);
  x86 = (x9)<<((uintptr_t)8ULL);
  x87 = x8;
  x88 = (x7)<<((uintptr_t)56ULL);
  x89 = (x6)<<((uintptr_t)48ULL);
  x90 = (x5)<<((uintptr_t)40ULL);
  x91 = (x4)<<((uintptr_t)32ULL);
  x92 = (x3)<<((uintptr_t)24ULL);
  x93 = (x2)<<((uintptr_t)16ULL);
  x94 = (x1)<<((uintptr_t)8ULL);
  x95 = x0;
  x96 = (x95)+((x94)+((x93)+((x92)+((x91)+((x90)+((x89)+(x88)))))));
  x97 = (x96)&((uintptr_t)18446744073709551615ULL);
  x98 = (x55)+((x54)+((x53)+((x52)+((x51)+((x50)+((x49)+(x48)))))));
  x99 = (x63)+((x62)+((x61)+((x60)+((x59)+((x58)+((x57)+(x56)))))));
  x100 = (x71)+((x70)+((x69)+((x68)+((x67)+((x66)+((x65)+(x64)))))));
  x101 = (x79)+((x78)+((x77)+((x76)+((x75)+((x74)+((x73)+(x72)))))));
  x102 = (x87)+((x86)+((x85)+((x84)+((x83)+((x82)+((x81)+(x80)))))));
  x103 = (x102)&((uintptr_t)18446744073709551615ULL);
  x104 = (x101)&((uintptr_t)18446744073709551615ULL);
  x105 = (x100)&((uintptr_t)18446744073709551615ULL);
  x106 = (x99)&((uintptr_t)18446744073709551615ULL);
  x107 = x97;
  x108 = x103;
  x109 = x104;
  x110 = x105;
  x111 = x106;
  x112 = x98;
  /*skip*/
  *(uintptr_t*)((out0)+((uintptr_t)0ULL)) = x107;
  *(uintptr_t*)((out0)+((uintptr_t)8ULL)) = x108;
  *(uintptr_t*)((out0)+((uintptr_t)16ULL)) = x109;
  *(uintptr_t*)((out0)+((uintptr_t)24ULL)) = x110;
  *(uintptr_t*)((out0)+((uintptr_t)32ULL)) = x111;
  *(uintptr_t*)((out0)+((uintptr_t)40ULL)) = x112;
  /*skip*/
  return;
}

