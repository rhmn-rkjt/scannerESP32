
// CODING UNTUK MENAMPILKAN DATA ECU MOTOR ( BEAT FI , HAMPIR SEMUA BEBEK HONDA NON RADIATOR, DLL)




void data_17 () {
 

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

  rpm = (uint16_t) (buff[8] << 8) + buff[9];

  tpsv = calcValueDivide256(buff[10]);

  tpsp = (calcValueDivide16(buff[11]));

  eotv = calcValueDivide256(buff[12]);

  eotc = calcValueMinus40(buff[13]);

  ectv = calcValueDivide256(buff[14]);

  ectc = calcValueMinus40(buff[15]);

  iatv = calcValueDivide256(buff[14]);

  iatc = calcValueMinus40(buff[15]);

  mapv = calcValueDivide256(buff[16]);

  mapk = buff[17];

  batv = calcValueDivide10(buff[18]);

  injj = (((buff[19] * 256) + buff[20]) / 255.0);

  ckpp = -64 + buff[21] * 0.5;

  // ckpp = ckp(buff[19]);

  // injj = inj(buff[20]);

  spdk = buff[24];

  oxigenv = calcValueDivide256 (buff[36]);
  oxigens = kalo2 (buff[37]);


  d1 = buff[47];
  if (d1 == 2) {
    d1_1 = true;
  } else {
    d1_1 = false;
  }

  d6 = buff[51];
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
