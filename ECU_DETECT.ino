
// CODING UNTUK MENENTUKAN MODEL MOTOR YANG TERHUBUNG KE SCANNER



void ecu_detect11() {

  byte data[] = {0x72, 0x05, 0x71, 0x11};
  int chk = calcChecksum(data, sizeof(data));
  byte dataWithChk[] = {0x72, 0x05, 0x71, 0x11, chk};
  bike.write(dataWithChk, sizeof(dataWithChk));
  delay(50);

  int buffCount = 0;
  byte buff[PACKET_BUFFER_SIZE];
  while ( (bike.available() > 0 ) && ( buffCount < PACKET_BUFFER_SIZE)) {
    buff[buffCount++] = bike.read();
  }
  byte sub_tampil = buffCount;
  if (sub_tampil == 30) {
    display_tampil = 1;
    dtc_sel = 1;
  } else if (sub_tampil == 29) {
    display_tampil = 7;
    dtc_tampil = 7;
    dtc_sel = 7;
  }
}

void ecu_detect17 () {

  byte data[] = {0x72, 0x05, 0x71, 0x17};
  int chk = calcChecksum(data, sizeof(data));
  byte dataWithChk[] = {0x72, 0x05, 0x71, 0x17, chk};
  bike.write(dataWithChk, sizeof(dataWithChk));
  delay(50);

  int buffCount = 0;
  byte buff[PACKET_BUFFER_SIZE];
  while ( (bike.available() > 0 ) && ( buffCount < PACKET_BUFFER_SIZE)) {
    buff[buffCount++] = bike.read();
  }

  byte sub_tampil = buffCount;
  if (sub_tampil == 28) {
    display_tampil = 2;
    dtc_sel = 2;
  } else if (sub_tampil == 29) {
    display_tampil = 3;
    dtc_sel = 3;
  }
}


void ecu_detect10() {

  byte data[] = {0x72, 0x05, 0x71, 0x10};
  int chk = calcChecksum(data, sizeof(data));
  byte dataWithChk[] = {0x72, 0x05, 0x71, 0x10, chk};
  bike.write(dataWithChk, sizeof(dataWithChk));
  delay(50);

  int buffCount = 0;
  byte buff[PACKET_BUFFER_SIZE];
  while ( (bike.available() > 0 ) && ( buffCount < PACKET_BUFFER_SIZE)) {
    buff[buffCount++] = bike.read();
  }
  byte sub_tampil = buffCount;
  if (sub_tampil == 27) {
    display_tampil = 8;
    dtc_sel = 8;
  }
}
