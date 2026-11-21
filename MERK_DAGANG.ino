
// CODING UNTUK MENAMPILKAN NAMA TOKO ATAU BENGKEL ANDA
// CODING INI JGA UNTUK MENAMPILKAN ID CAL ECM DAN FLASH COUNT

void merk_dagang() {

  lcd.setCursor(2, 0);
  lcd.print("Andalas Lima");
  lcd.setCursor(6, 1);
  lcd.print("Tech");
  delay(2000);
  lcd.clear();

  bike.write(id_ecm, sizeof(id_ecm));
  bike.flush();
  delay(30);
  //byte fc[] = {0x7B, 0x06, 0x00, 0x01, 0x03, 0x7B};
  byte fc[] = {0x7D, 0x06, 0x01, 0x01, 0x03, 0x78};
  bike.write(fc, sizeof(fc));
  bike.flush();
  delay(30);

  int buffCount = 0;
  byte buff[PACKET_BUFFER_SIZE];
  while ( (bike.available() > 0 ) && ( buffCount < PACKET_BUFFER_SIZE)) {
    buff[buffCount++] = bike.read();
  }

  data_satu = buff[9];
  data_dua = buff[10];
  data_tiga = buff[11];
  data_empat = buff[12];
  data_lima = buff[13];

  fc1 = buff[25];
  fc2 = buff[26];
  fc3 = buff[27];
  fc4 = buff[28];
  fc5 = buff[29];
  fc6 = buff[30];
  fc7 = buff[31];
  fc8 = buff[32];


  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("ID_ECM");
  lcd.setCursor(1, 1);
  lcd.print(data_satu, HEX);
  lcd.setCursor(3, 1);
  lcd.print("_");
  lcd.setCursor(4, 1);
  lcd.print(data_dua, HEX);
  lcd.setCursor(6, 1);
  lcd.print("_");
  lcd.setCursor(7, 1);
  lcd.print(data_tiga, HEX);
  lcd.setCursor(9, 1);
  lcd.print("_");
  lcd.setCursor(10, 1);
  lcd.print(data_empat, HEX);
  lcd.setCursor(12, 1);
  lcd.print("_");
  lcd.setCursor(14, 1);
  lcd.print(data_lima, HEX);
  delay(1500);
  lcd.clear();

  fc_jumlah17 = buff[31];

  fc_jumlah17esp = buff[32];

  fc_jumlah11 = buff[34];

  fc_jumlah10 = buff[32];

  lcd.clear();
  if ((display_tampil == 1) ||  (display_tampil == 7) )  {
    fc_jumlah = fc_jumlah11;
    lcd.setCursor(3, 0);
    lcd.print("Flash Count");
    lcd.setCursor(3, 1);
    lcd.print("no detect");

  }
  if (display_tampil == 2) {
    fc_jumlah = fc_jumlah17;
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Flash Count");
    lcd.setCursor(7, 1);
    lcd.print(fc_jumlah17);

  }
  if (display_tampil == 3) {
    fc_jumlah = fc_jumlah17esp;
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Flash Count");
    lcd.setCursor(7, 1);
    lcd.print(fc_jumlah17esp);
  }

  if (display_tampil == 8) {
    fc_jumlah = fc_jumlah10;
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Flash Count");
    lcd.setCursor(7, 1);
    lcd.print(fc_jumlah10);

  }
  delay(1500);
  lcd.clear();

}
