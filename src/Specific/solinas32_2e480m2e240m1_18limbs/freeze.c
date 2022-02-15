static void freeze(uint32_t out[18], const uint32_t in1[18]) {
  { const uint32_t x33 = in1[17];
  { const uint32_t x34 = in1[16];
  { const uint32_t x32 = in1[15];
  { const uint32_t x30 = in1[14];
  { const uint32_t x28 = in1[13];
  { const uint32_t x26 = in1[12];
  { const uint32_t x24 = in1[11];
  { const uint32_t x22 = in1[10];
  { const uint32_t x20 = in1[9];
  { const uint32_t x18 = in1[8];
  { const uint32_t x16 = in1[7];
  { const uint32_t x14 = in1[6];
  { const uint32_t x12 = in1[5];
  { const uint32_t x10 = in1[4];
  { const uint32_t x8 = in1[3];
  { const uint32_t x6 = in1[2];
  { const uint32_t x4 = in1[1];
  { const uint32_t x2 = in1[0];
  { uint32_t x36, uint8_t/*bool*/ x37 = Op (Syntax.SubWithGetBorrow 27 (Syntax.TWord 0) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 0)) (0x0, Return x2, 0x7ffffff);
  { uint32_t x39, uint8_t/*bool*/ x40 = Op (Syntax.SubWithGetBorrow 27 (Syntax.TWord 0) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 0)) (Return x37, Return x4, 0x7ffffff);
  { uint32_t x42; uint8_t/*bool*/ x43 = _subborrow_u26(x40, x6, 0x3ffffff, &x42);
  { uint32_t x45, uint8_t/*bool*/ x46 = Op (Syntax.SubWithGetBorrow 27 (Syntax.TWord 0) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 0)) (Return x43, Return x8, 0x7ffffff);
  { uint32_t x48, uint8_t/*bool*/ x49 = Op (Syntax.SubWithGetBorrow 27 (Syntax.TWord 0) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 0)) (Return x46, Return x10, 0x7ffffff);
  { uint32_t x51; uint8_t/*bool*/ x52 = _subborrow_u26(x49, x12, 0x3ffffff, &x51);
  { uint32_t x54, uint8_t/*bool*/ x55 = Op (Syntax.SubWithGetBorrow 27 (Syntax.TWord 0) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 0)) (Return x52, Return x14, 0x7ffffff);
  { uint32_t x57, uint8_t/*bool*/ x58 = Op (Syntax.SubWithGetBorrow 27 (Syntax.TWord 0) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 0)) (Return x55, Return x16, 0x7ffffff);
  { uint32_t x60; uint8_t/*bool*/ x61 = _subborrow_u26(x58, x18, 0x3ffffff, &x60);
  { uint32_t x63, uint8_t/*bool*/ x64 = Op (Syntax.SubWithGetBorrow 27 (Syntax.TWord 0) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 0)) (Return x61, Return x20, 0x7fffffe);
  { uint32_t x66, uint8_t/*bool*/ x67 = Op (Syntax.SubWithGetBorrow 27 (Syntax.TWord 0) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 0)) (Return x64, Return x22, 0x7ffffff);
  { uint32_t x69; uint8_t/*bool*/ x70 = _subborrow_u26(x67, x24, 0x3ffffff, &x69);
  { uint32_t x72, uint8_t/*bool*/ x73 = Op (Syntax.SubWithGetBorrow 27 (Syntax.TWord 0) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 0)) (Return x70, Return x26, 0x7ffffff);
  { uint32_t x75, uint8_t/*bool*/ x76 = Op (Syntax.SubWithGetBorrow 27 (Syntax.TWord 0) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 0)) (Return x73, Return x28, 0x7ffffff);
  { uint32_t x78; uint8_t/*bool*/ x79 = _subborrow_u26(x76, x30, 0x3ffffff, &x78);
  { uint32_t x81, uint8_t/*bool*/ x82 = Op (Syntax.SubWithGetBorrow 27 (Syntax.TWord 0) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 0)) (Return x79, Return x32, 0x7ffffff);
  { uint32_t x84, uint8_t/*bool*/ x85 = Op (Syntax.SubWithGetBorrow 27 (Syntax.TWord 0) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 0)) (Return x82, Return x34, 0x7ffffff);
  { uint32_t x87; uint8_t/*bool*/ x88 = _subborrow_u26(x85, x33, 0x3ffffff, &x87);
  { uint32_t x89 = cmovznz32(x88, 0x0, 0xffffffff);
  { uint32_t x90 = (x89 & 0x7ffffff);
  { uint32_t x92, uint8_t/*bool*/ x93 = Op (Syntax.AddWithGetCarry 27 (Syntax.TWord 0) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 0)) (0x0, Return x36, Return x90);
  { uint32_t x94 = (x89 & 0x7ffffff);
  { uint32_t x96, uint8_t/*bool*/ x97 = Op (Syntax.AddWithGetCarry 27 (Syntax.TWord 0) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 0)) (Return x93, Return x39, Return x94);
  { uint32_t x98 = (x89 & 0x3ffffff);
  { uint32_t x100; uint8_t/*bool*/ x101 = _addcarryx_u26(x97, x42, x98, &x100);
  { uint32_t x102 = (x89 & 0x7ffffff);
  { uint32_t x104, uint8_t/*bool*/ x105 = Op (Syntax.AddWithGetCarry 27 (Syntax.TWord 0) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 0)) (Return x101, Return x45, Return x102);
  { uint32_t x106 = (x89 & 0x7ffffff);
  { uint32_t x108, uint8_t/*bool*/ x109 = Op (Syntax.AddWithGetCarry 27 (Syntax.TWord 0) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 0)) (Return x105, Return x48, Return x106);
  { uint32_t x110 = (x89 & 0x3ffffff);
  { uint32_t x112; uint8_t/*bool*/ x113 = _addcarryx_u26(x109, x51, x110, &x112);
  { uint32_t x114 = (x89 & 0x7ffffff);
  { uint32_t x116, uint8_t/*bool*/ x117 = Op (Syntax.AddWithGetCarry 27 (Syntax.TWord 0) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 0)) (Return x113, Return x54, Return x114);
  { uint32_t x118 = (x89 & 0x7ffffff);
  { uint32_t x120, uint8_t/*bool*/ x121 = Op (Syntax.AddWithGetCarry 27 (Syntax.TWord 0) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 0)) (Return x117, Return x57, Return x118);
  { uint32_t x122 = (x89 & 0x3ffffff);
  { uint32_t x124; uint8_t/*bool*/ x125 = _addcarryx_u26(x121, x60, x122, &x124);
  { uint32_t x126 = (x89 & 0x7fffffe);
  { uint32_t x128, uint8_t/*bool*/ x129 = Op (Syntax.AddWithGetCarry 27 (Syntax.TWord 0) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 0)) (Return x125, Return x63, Return x126);
  { uint32_t x130 = (x89 & 0x7ffffff);
  { uint32_t x132, uint8_t/*bool*/ x133 = Op (Syntax.AddWithGetCarry 27 (Syntax.TWord 0) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 0)) (Return x129, Return x66, Return x130);
  { uint32_t x134 = (x89 & 0x3ffffff);
  { uint32_t x136; uint8_t/*bool*/ x137 = _addcarryx_u26(x133, x69, x134, &x136);
  { uint32_t x138 = (x89 & 0x7ffffff);
  { uint32_t x140, uint8_t/*bool*/ x141 = Op (Syntax.AddWithGetCarry 27 (Syntax.TWord 0) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 0)) (Return x137, Return x72, Return x138);
  { uint32_t x142 = (x89 & 0x7ffffff);
  { uint32_t x144, uint8_t/*bool*/ x145 = Op (Syntax.AddWithGetCarry 27 (Syntax.TWord 0) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 0)) (Return x141, Return x75, Return x142);
  { uint32_t x146 = (x89 & 0x3ffffff);
  { uint32_t x148; uint8_t/*bool*/ x149 = _addcarryx_u26(x145, x78, x146, &x148);
  { uint32_t x150 = (x89 & 0x7ffffff);
  { uint32_t x152, uint8_t/*bool*/ x153 = Op (Syntax.AddWithGetCarry 27 (Syntax.TWord 0) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 0)) (Return x149, Return x81, Return x150);
  { uint32_t x154 = (x89 & 0x7ffffff);
  { uint32_t x156, uint8_t/*bool*/ x157 = Op (Syntax.AddWithGetCarry 27 (Syntax.TWord 0) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 0)) (Return x153, Return x84, Return x154);
  { uint32_t x158 = (x89 & 0x3ffffff);
  { uint32_t x160; uint8_t/*bool*/ _ = _addcarryx_u26(x157, x87, x158, &x160);
  out[0] = x92;
  out[1] = x96;
  out[2] = x100;
  out[3] = x104;
  out[4] = x108;
  out[5] = x112;
  out[6] = x116;
  out[7] = x120;
  out[8] = x124;
  out[9] = x128;
  out[10] = x132;
  out[11] = x136;
  out[12] = x140;
  out[13] = x144;
  out[14] = x148;
  out[15] = x152;
  out[16] = x156;
  out[17] = x160;
  }}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
}