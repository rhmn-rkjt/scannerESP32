
// CODING UNTUK MENAMPILKAN DATA ECU MOTOR ( ALL BEAT STARTER HALUS / ESP , VARIO FAMILY, DLL )







void data_17esp () {
 


  byte data17[] = {0x72, 0x05, 0x71, 0x17};
  int chk17 = calcChecksum(data17, sizeof(data17));
  byte dataWithChk17[] = {0x72, 0x05, 0x71, 0x17, chk17};
  bike.write(dataWithChk17, sizeof(dataWithChk17));
  bike.flush();
  delay(50);

  byte data[] = {0x72, 0x05, 0x71, 0x20};
  int chk = calcChecksum(data, sizeof(data));
  byte dataWithChk[] = {0x72, 0x05, 0x71, 0x20, chk};
  bike.write(dataWithChk, sizeof(dataWithChk));
  bike.flush();
  delay(50);

  byte data1[] = {0x72, 0x05, 0x71, 0xD1};
  int chk1 = calcChecksum(data1, sizeof(data1));
  byte dataWithChk1[] = {0x72, 0x05, 0x71, 0xD1, chk1};
  bike.write(dataWithChk1, sizeof(dataWithChk1));
  bike.flush();
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

  ectv = calcValueDivide256(buff[17]);

  ectc = calcValueMinus40(buff[18]);

  iatv = calcValueDivide256(buff[15]);

  iatc = calcValueMinus40(buff[16]);

  mapv = calcValueDivide256(buff[17]);

  mapk = buff[18];

  batv = calcValueDivide10(buff[19]);

  injj = (buff[20]) / (65535 * 265, 5);

  // ckpp = (buff[21] - 64) * 80 / 256;

  // spdk = buff[24];

  injj = (((buff[20] * 256) + buff[21]) / 255.0);

  ckpp = -64 + buff[22] * 0.5;

  spdk = buff[24];

  oxigenv = calcValueDivide256 (buff[38]);//37
  oxigens = kalo2 (buff[39]);//38


  d1 = buff[51];//49
  if (d1 == 2) {
    d1_1 = true;
  } else {
    d1_1 = false;
  }

  d6 = buff[55];//53
  if (d6 == 1) {
    d6_fpump = true;
    d6_iacv = false;
    d6_mrelay = false;
  }
  else

    if (d6 == 64) {
      d6_fpump = false;
      d6_iacv = true;
      d6_mrelay = false;
    }
    else

      if (d6 == 16) {
        d6_fpump = false;
        d6_iacv = false;
        d6_mrelay = true;
      }
      else

        if (d6 == 65) {
          d6_fpump = true;
          d6_iacv = true;
          d6_mrelay = false;
        }
        else

          if (d6 == 17) {
            d6_fpump = true;
            d6_iacv = false;
            d6_mrelay = true;
          }
          else

            if (d6 == 80) {
              d6_fpump = false;
              d6_iacv = true;
              d6_mrelay = true;
            }
            else

              if (d6 == 81) {
                d6_fpump = true;
                d6_iacv = true;
                d6_mrelay = true;
              }
              else

              {
                d6_fpump = false;
                d6_iacv = false;
                d6_mrelay = false;
              }



}
