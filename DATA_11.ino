
// CODING UNTUK MENAMPILKAN DATA ECU  MOTOR ( ADV , PCX, CRF, CBR, CB FAMILY, DLL )


void data_11() {

  byte data11[] = {0x72, 0x05, 0x71, 0x11};
  int chk11 = calcChecksum(data11, sizeof(data11));
  byte dataWithChk11[] = {0x72, 0x05, 0x71, 0x11, chk11};
  bike.write(dataWithChk11, sizeof(dataWithChk11));
  delay(50);

  byte data[] = {0x72, 0x05, 0x71, 0x20};
  int chk = calcChecksum(data, sizeof(data));
  byte dataWithChk[] = {0x72, 0x05, 0x71, 0x20, chk};
  bike.write(dataWithChk, sizeof(dataWithChk));
  delay(50);

  byte data1[] = {0x72, 0x05, 0x71, 0xD1};
  int chk1 = calcChecksum(data1, sizeof(data1));
  byte dataWithChk1[] = {0x72, 0x05, 0x71, 0xD1, chk1};
  bike.write(dataWithChk1, sizeof(dataWithChk1));
  delay(50);

  int buffCount = 0;
  byte buff[PACKET_BUFFER_SIZE];
  while ( (bike.available() > 0 ) && ( buffCount < PACKET_BUFFER_SIZE)) {
    buff[buffCount++] = bike.read();
  }

  rpm = (uint16_t) (buff[9] << 8) + buff[10];

  tpsv = calcValueDivide256(buff[11]);

  tpsp = (calcValueDivide16(buff[12]));

  eotv = calcValueDivide256(buff[13]);

  eotc = calcValueMinus40(buff[14]);

  ectv = calcValueDivide256(buff[15]);

  ectc = calcValueMinus40(buff[16]);

  iatv = calcValueDivide256(buff[17]);

  iatc = calcValueMinus40(buff[18]);

  mapv = calcValueDivide256(buff[19]);

  mapk = buff[20];

  batv = calcValueDivide10(buff[21]);

  injj = (((buff[23] * 256) + buff[24]) / 255.0);

  ckpp = -64 + buff[25] * 0.5;

  // ckpp = ckp(buff[23]);

  // injj = inj(buff[24]);

  spdk = buff[22];

  oxigenv = calcValueDivide256 (buff[39]);
  oxigens = kalo2 (buff[40]);

  d1 = buff[52];
  if (d1 == 0) {
    d1_1 = false;
    d6_mrelay = false;
  } else if ( d1 == 2) {
    d1_1 = true;
    d6_mrelay = false;
  } else if (d1 == 32) {
    d6_mrelay = true;
    d1_1 = false;
  } else if (d1 == 34) {
    d1_1 = true;
    d6_mrelay = true;
  }

  d6 = buff[56];
  if (d6 == 0) {
    d6_fpump = false;
  } else if (d6 == 1) {
    d6_fpump = true;
  }


}
