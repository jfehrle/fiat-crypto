static void fecarry(uint32_t out[18], const uint32_t in1[18]) {
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
  { uint32_t x35 = (x18 >> 0x18);
  { uint32_t x36 = (x18 & 0xffffff);
  { uint32_t x37 = (x33 >> 0x18);
  { uint32_t x38 = (x33 & 0xffffff);
  { uint32_t x39 = ((0x1000000 * x37) + x38);
  { uint32_t x40 = (x39 >> 0x18);
  { uint32_t x41 = (x39 & 0xffffff);
  { uint32_t x42 = ((x35 + x20) + x40);
  { uint32_t x43 = (x42 >> 0x19);
  { uint32_t x44 = (x42 & 0x1ffffff);
  { uint32_t x45 = (x2 + x40);
  { uint32_t x46 = (x45 >> 0x19);
  { uint32_t x47 = (x45 & 0x1ffffff);
  { uint32_t x48 = (x43 + x22);
  { uint32_t x49 = (x48 >> 0x19);
  { uint32_t x50 = (x48 & 0x1ffffff);
  { uint32_t x51 = (x46 + x4);
  { uint32_t x52 = (x51 >> 0x19);
  { uint32_t x53 = (x51 & 0x1ffffff);
  { uint32_t x54 = (x49 + x24);
  { uint32_t x55 = (x54 >> 0x19);
  { uint32_t x56 = (x54 & 0x1ffffff);
  { uint32_t x57 = (x52 + x6);
  { uint32_t x58 = (x57 >> 0x19);
  { uint32_t x59 = (x57 & 0x1ffffff);
  { uint32_t x60 = (x55 + x26);
  { uint32_t x61 = (x60 >> 0x19);
  { uint32_t x62 = (x60 & 0x1ffffff);
  { uint32_t x63 = (x58 + x8);
  { uint32_t x64 = (x63 >> 0x19);
  { uint32_t x65 = (x63 & 0x1ffffff);
  { uint32_t x66 = (x61 + x28);
  { uint32_t x67 = (x66 >> 0x19);
  { uint32_t x68 = (x66 & 0x1ffffff);
  { uint32_t x69 = (x64 + x10);
  { uint32_t x70 = (x69 >> 0x19);
  { uint32_t x71 = (x69 & 0x1ffffff);
  { uint32_t x72 = (x67 + x30);
  { uint32_t x73 = (x72 >> 0x19);
  { uint32_t x74 = (x72 & 0x1ffffff);
  { uint32_t x75 = (x70 + x12);
  { uint32_t x76 = (x75 >> 0x19);
  { uint32_t x77 = (x75 & 0x1ffffff);
  { uint32_t x78 = (x73 + x32);
  { uint32_t x79 = (x78 >> 0x19);
  { uint32_t x80 = (x78 & 0x1ffffff);
  { uint32_t x81 = (x76 + x14);
  { uint32_t x82 = (x81 >> 0x19);
  { uint32_t x83 = (x81 & 0x1ffffff);
  { uint32_t x84 = (x79 + x34);
  { uint32_t x85 = (x84 >> 0x19);
  { uint32_t x86 = (x84 & 0x1ffffff);
  { uint32_t x87 = (x82 + x16);
  { uint32_t x88 = (x87 >> 0x19);
  { uint32_t x89 = (x87 & 0x1ffffff);
  { uint32_t x90 = (x85 + x41);
  { uint32_t x91 = (x90 >> 0x18);
  { uint32_t x92 = (x90 & 0xffffff);
  { uint32_t x93 = (x88 + x36);
  { uint32_t x94 = (x93 >> 0x18);
  { uint32_t x95 = (x93 & 0xffffff);
  { uint32_t x96 = ((0x1000000 * x91) + x92);
  { uint32_t x97 = (x96 >> 0x18);
  { uint32_t x98 = (x96 & 0xffffff);
  { uint32_t x99 = ((x94 + x44) + x97);
  { uint32_t x100 = (x99 >> 0x19);
  { uint32_t x101 = (x99 & 0x1ffffff);
  { uint32_t x102 = (x47 + x97);
  { uint32_t x103 = (x102 >> 0x19);
  { uint32_t x104 = (x102 & 0x1ffffff);
  out[0] = x104;
  out[1] = (x103 + x53);
  out[2] = x59;
  out[3] = x65;
  out[4] = x71;
  out[5] = x77;
  out[6] = x83;
  out[7] = x89;
  out[8] = x95;
  out[9] = x101;
  out[10] = (x100 + x50);
  out[11] = x56;
  out[12] = x62;
  out[13] = x68;
  out[14] = x74;
  out[15] = x80;
  out[16] = x86;
  out[17] = x98;
  }}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
}