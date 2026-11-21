


void dtcapk() {

  byte data[] = {0x72, 0x05, 0x74, 0x01};
  int chk = calcChecksum(data, sizeof(data));
  byte dataWithChk[] = {0x72, 0x05, 0x74, 0x01, chk};
  bike.write(dataWithChk, sizeof(dataWithChk));
  delay(50);

  int buffCount = 0;
  byte buff[PACKET_BUFFER_SIZE];
  while ( (bike.available() > 0 ) && ( buffCount < PACKET_BUFFER_SIZE)) {
    buff[buffCount++] = bike.read();
  }


  if (display_tampil == 8) {
    dtc1 = (buff[12]) ;
    dtc2 = (buff[14]);
    dtc3 = (buff[16]);

    dtc4 = (buff[13]) ;
    dtc5 = (buff[15]);
    dtc6 = (buff[17]);
  } else

    if (display_tampil == 2) {
      dtca = (buff[9]) ;
      dtcb = (buff[10]);
      dtcc = (buff[11]);
      
      dtcd = (buff[12]) ;
      dtce = (buff[13]);
      dtcf = (buff[14]);
    }
}
