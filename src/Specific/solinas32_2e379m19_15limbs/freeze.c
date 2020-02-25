static void freeze(uint32_t out[15], const uint32_t in1[15]) {
  { const uint32_t x27 = in1[14];
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
  { uint32_t x30; uint8_t/*bool*/ x31 = _subborrow_u26(0x0, x2, 0x3ffffed, &x30);
  { uint32_t x33; uint8_t/*bool*/ x34 = _subborrow_u25(x31, x4, 0x1ffffff, &x33);
  { uint32_t x36; uint8_t/*bool*/ x37 = _subborrow_u25(x34, x6, 0x1ffffff, &x36);
  { uint32_t x39; uint8_t/*bool*/ x40 = _subborrow_u26(x37, x8, 0x3ffffff, &x39);
  { uint32_t x42; uint8_t/*bool*/ x43 = _subborrow_u25(x40, x10, 0x1ffffff, &x42);
  { uint32_t x45; uint8_t/*bool*/ x46 = _subborrow_u25(x43, x12, 0x1ffffff, &x45);
  { uint32_t x48; uint8_t/*bool*/ x49 = _subborrow_u25(x46, x14, 0x1ffffff, &x48);
  { uint32_t x51; uint8_t/*bool*/ x52 = _subborrow_u26(x49, x16, 0x3ffffff, &x51);
  { uint32_t x54; uint8_t/*bool*/ x55 = _subborrow_u25(x52, x18, 0x1ffffff, &x54);
  { uint32_t x57; uint8_t/*bool*/ x58 = _subborrow_u25(x55, x20, 0x1ffffff, &x57);
  { uint32_t x60; uint8_t/*bool*/ x61 = _subborrow_u25(x58, x22, 0x1ffffff, &x60);
  { uint32_t x63; uint8_t/*bool*/ x64 = _subborrow_u26(x61, x24, 0x3ffffff, &x63);
  { uint32_t x66; uint8_t/*bool*/ x67 = _subborrow_u25(x64, x26, 0x1ffffff, &x66);
  { uint32_t x69; uint8_t/*bool*/ x70 = _subborrow_u25(x67, x28, 0x1ffffff, &x69);
  { uint32_t x72; uint8_t/*bool*/ x73 = _subborrow_u25(x70, x27, 0x1ffffff, &x72);
  { uint32_t x74 = cmovznz32(x73, 0x0, 0xffffffff);
  { uint32_t x75 = (x74 & 0x3ffffed);
  { uint32_t x77; uint8_t/*bool*/ x78 = _addcarryx_u26(0x0, x30, x75, &x77);
  { uint32_t x79 = (x74 & 0x1ffffff);
  { uint32_t x81; uint8_t/*bool*/ x82 = _addcarryx_u25(x78, x33, x79, &x81);
  { uint32_t x83 = (x74 & 0x1ffffff);
  { uint32_t x85; uint8_t/*bool*/ x86 = _addcarryx_u25(x82, x36, x83, &x85);
  { uint32_t x87 = (x74 & 0x3ffffff);
  { uint32_t x89; uint8_t/*bool*/ x90 = _addcarryx_u26(x86, x39, x87, &x89);
  { uint32_t x91 = (x74 & 0x1ffffff);
  { uint32_t x93; uint8_t/*bool*/ x94 = _addcarryx_u25(x90, x42, x91, &x93);
  { uint32_t x95 = (x74 & 0x1ffffff);
  { uint32_t x97; uint8_t/*bool*/ x98 = _addcarryx_u25(x94, x45, x95, &x97);
  { uint32_t x99 = (x74 & 0x1ffffff);
  { uint32_t x101; uint8_t/*bool*/ x102 = _addcarryx_u25(x98, x48, x99, &x101);
  { uint32_t x103 = (x74 & 0x3ffffff);
  { uint32_t x105; uint8_t/*bool*/ x106 = _addcarryx_u26(x102, x51, x103, &x105);
  { uint32_t x107 = (x74 & 0x1ffffff);
  { uint32_t x109; uint8_t/*bool*/ x110 = _addcarryx_u25(x106, x54, x107, &x109);
  { uint32_t x111 = (x74 & 0x1ffffff);
  { uint32_t x113; uint8_t/*bool*/ x114 = _addcarryx_u25(x110, x57, x111, &x113);
  { uint32_t x115 = (x74 & 0x1ffffff);
  { uint32_t x117; uint8_t/*bool*/ x118 = _addcarryx_u25(x114, x60, x115, &x117);
  { uint32_t x119 = (x74 & 0x3ffffff);
  { uint32_t x121; uint8_t/*bool*/ x122 = _addcarryx_u26(x118, x63, x119, &x121);
  { uint32_t x123 = (x74 & 0x1ffffff);
  { uint32_t x125; uint8_t/*bool*/ x126 = _addcarryx_u25(x122, x66, x123, &x125);
  { uint32_t x127 = (x74 & 0x1ffffff);
  { uint32_t x129; uint8_t/*bool*/ x130 = _addcarryx_u25(x126, x69, x127, &x129);
  { uint32_t x131 = (x74 & 0x1ffffff);
  { uint32_t x133; uint8_t/*bool*/ _ = _addcarryx_u25(x130, x72, x131, &x133);
  out[0] = x77;
  out[1] = x81;
  out[2] = x85;
  out[3] = x89;
  out[4] = x93;
  out[5] = x97;
  out[6] = x101;
  out[7] = x105;
  out[8] = x109;
  out[9] = x113;
  out[10] = x117;
  out[11] = x121;
  out[12] = x125;
  out[13] = x129;
  out[14] = x133;
  }}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
}