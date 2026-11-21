
// CODING UNTUK MENHAPUS DTC


void clear_dtc() {

  if (menureset == 0 ) {
    lcd.clear();
    delay(30);
    menureset = 1;
  }

  if (menureset == 1 ) {

    for ( int i = 0; i <= 20; i++) {

      byte data[] = {0x72, 0x05, 0x60, 0x03};
      int chk = calcChecksum(data, sizeof(data));
      byte dataWithChk[] = {0x72, 0x05, 0x60, 0x03, chk};

      bike.write(dataWithChk, sizeof(dataWithChk));
      delay(50);
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Proses......!!!");
    lcd.setCursor(0, 1 );
    lcd.print("Hapus DTC .");
    delay(2000);
    lcd.clear();
   // bike.write(dataWithChk, sizeof(dataWithChk));
    lcd.setCursor(0, 0);
    lcd.print("Sabar Yaa...!!!");
    lcd.setCursor(0, 1 );
    lcd.print("Hapus DTC ..");
    delay(2000);
  //  bike.write(dataWithChk, sizeof(dataWithChk));
    lcd.setCursor(0, 1 );
    lcd.print("Hapus DTC ...");
    lcd.setCursor(0, 1 );
    lcd.print("Hapus DTC ....");
    delay(1000);
  //  bike.write(dataWithChk, sizeof(dataWithChk));
    lcd.setCursor(0, 1 );
    lcd.print("Hapus DTC .....");
    delay(1000);
    lcd.setCursor(0, 1 );
    lcd.print("Hapus DTC ......");
    delay(1000);
    lcd.clear();
    lcd.setCursor(1, 1 );
    lcd.print("Selesai....!!!!");
    delay(2000);
    lcd.setCursor(1, 0);
    lcd.print("off/on scaner");
    lcd.setCursor(0, 1);
    lcd.print("dan kunci kontak");
    menu_live = 26;

  }
}
