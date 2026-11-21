


void eeprom_mode() {

  unsigned long SEKARANG = millis();
  // debug.print(mode_eeprom);
  // debug.println(konter);

  if (!digitalRead(downButton)) {
    mode_eeprom--;
    lcd.clear();
    delay(150);
    while (!digitalRead(downButton));
  }

  if (!digitalRead(upButton)) {
    mode_eeprom++;
    lcd.clear();
    delay(150);
    while (!digitalRead(upButton));
  }

  switch (mode_eeprom) {


    case 0:
      mode_eeprom = 1;
      break;

    case 1:
      lcd.setCursor(2, 0);
      lcd.print("ADVANCE MODE");
      lcd.setCursor(2, 1);
      lcd.print("Menu > Enter");
      if (digitalRead(pb) == LOW) {
        delay(300);
        mode_eeprom = 4;
        lcd.clear();
      }
      break;

    case 2:
      mode_eeprom = 1;
      break;

    case 3:
      mode_eeprom = 4;
      break;

    case 4:
      lcd.setCursor(0, 0);
      lcd.print("1.Keihin");
      lcd.setCursor(15, 0);
      lcd.print(char(127));
      lcd.setCursor(0, 1);
      lcd.print("2.Shindengen");
      if (digitalRead(pb) == LOW) {
        delay(300);
        mode_eeprom = 8;
        lcd.clear();
      }
      break;

    case 5:
      lcd.setCursor(0, 0);
      lcd.print("1.Keihin");
      lcd.setCursor(15, 1);
      lcd.print(char(127));
      lcd.setCursor(0, 1);
      lcd.print("2.Shindengen");
      if (digitalRead(pb) == LOW) {

        lcd.clear();
      }
      break;


    case 6:
      mode_eeprom = 5;
      break;

    case 7:
      mode_eeprom = 8;
      break;

    case 8:
      lcd.setCursor(0, 0);
      lcd.print("1.Set flsh cnt");
      lcd.setCursor(15, 0);
      lcd.print(char(127));
      lcd.setCursor(0, 1);
      lcd.print("2.Format eeprom");
      if (digitalRead(pb) == LOW) {
        delay(300);
        mode_eeprom = 12;
        lcd.clear();
      }
      break;

    case 9:
      lcd.setCursor(0, 0);
      lcd.print("1.Set flsh cnt");
      lcd.setCursor(15, 1);
      lcd.print(char(127));
      lcd.setCursor(0, 1);
      lcd.print("2.Format eeprom");
      if (digitalRead(pb) == LOW) {

        lcd.clear();
      }
      break;


    case 10:
      mode_eeprom = 9;
      break;

    case 11:
      mode_eeprom = 12;
      break;

    case 12:
      lcd.setCursor(0, 0);
      lcd.print("SET >>");
      lcd.setCursor(9, 0);
      lcd.print(count_flash);
      lcd.setCursor(15, 0);
      lcd.print(char(127));
      lcd.setCursor(0, 1);
      lcd.print("Lnjt tkan down");
      if (digitalRead(pb) == LOW) {
        delay(300);
        count_flash = count_flash + 1;
        if (count_flash == 4) {
          count_flash = 0;
        }
      }
      break;

    case 13: if (mode_eeprom == 13) {


        pinMode(TX_PIN, OUTPUT);
        digitalWrite(TX_PIN, LOW);
        delay(70);
        digitalWrite(TX_PIN, HIGH);
        delay(130);
        // delay(50);
        pinMode(TX_PIN, OUTPUT);
        digitalWrite(TX_PIN, LOW);
        delay(70);
        digitalWrite(TX_PIN, HIGH);
        // delay(130);
        delay(200);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(188);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(750);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(270);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(92);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(470);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(92);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(92);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(866);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, HIGH);
        delay(23);

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(288);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(480);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(866);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(481);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(480);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delay(10);

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(385);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(480);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(864);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(672);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(576);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(384);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, HIGH);
        //delay(545);

        lcd.setCursor(0, 0);
        lcd.print("off kunci kontak");

        for (int i = 8; i > 0; i--) {

          konter = i;

          lcd.setCursor(8, 1);
          lcd.print(konter);
          delay(1000);

          if (konter == 0) {
            konter = 0;
          }

          if (konter == 1) {
            mode_eeprom = 16;
            lcd.clear();

          }
        }
      }
      break;

    case 14:
      mode_eeprom = 13;
      break;

    case 15:
      mode_eeprom = 16;
      break;

    case 16:

      digitalWrite(TX_PIN, LOW);
      delayMicroseconds(96);
      digitalWrite(TX_PIN, HIGH);
      delay(500);
      digitalWrite(TX_PIN, LOW);
      delayMicroseconds(188);
      digitalWrite(TX_PIN, HIGH);
      delayMicroseconds(750);
      digitalWrite(TX_PIN, LOW);
      delayMicroseconds(270);
      digitalWrite(TX_PIN, HIGH);
      delayMicroseconds(92);
      digitalWrite(TX_PIN, LOW);
      delayMicroseconds(470);
      digitalWrite(TX_PIN, HIGH);
      delayMicroseconds(92);
      digitalWrite(TX_PIN, LOW);
      delayMicroseconds(92);
      digitalWrite(TX_PIN, HIGH);
      delayMicroseconds(866);
      digitalWrite(TX_PIN, LOW);
      delayMicroseconds(96);
      digitalWrite(TX_PIN, HIGH);
      delay(23);

      lcd.setCursor(0, 0);
      lcd.print("on kunci kontak");

      if ((bike.available() > 0) && (mode_eeprom == 16)) {
        int buffCount = 0;
        byte buff[PACKET_BUFFER_SIZE];
        while ( (bike.available() > 0 ) && ( buffCount < PACKET_BUFFER_SIZE)) {
          buff[buffCount++] = bike.read();
        }
        int jkl = buff[1];
        int jkm = buff[2];
        int jkn = buff[3];
        int jko = buff[4];

        //  debug.print(jkl);
        //  debug.print(" ");
        //  debug.print(jkm);
        //  debug.print(" ");
        //  debug.print(jkn);
        //  debug.print(" ");
        // debug.println(jko);

        if (jkl == 254) {
          lcd.setCursor(5, 1);
          lcd.print("detect");
          mode_eeprom = 19;
          lcd.clear();
        }
      }
      break;

    case 17:
      mode_eeprom = 16;
      break;

    case 18:
      mode_eeprom = 19;
      break;

    case 19:
      lcd.setCursor(0, 0);
      lcd.print("proses..........");
      vigaro_satu();
      mode_eeprom = 22;
      break;


    case 20:
      mode_eeprom = 19;
      break;

    case 21:
      mode_eeprom = 22;
      break;

    case 22:
      vigaro_dua();
      delay(50);
      mode_eeprom = 25;
      break;

    case 23:
      mode_eeprom = 22;
      break;

    case 24:
      mode_eeprom = 25;
      break;

    case 25:
      if (count_flash == 1) {

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(481);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(192);

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(97);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(480);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(192);

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(289);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(289);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(384);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(385);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(769);

        //vigaro 00

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(673);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(673);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(576);
        digitalWrite(TX_PIN, HIGH);
        delay(23);

        /////////////////

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(481);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(210);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(481);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(210);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(481);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(288);

        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(995);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(481);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(995);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(867);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(1000);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delay(30);
      }

      if (count_flash == 0) {

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(481);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(192);

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(97);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(480);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(192);

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(289);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(289);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(384);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(385);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(769);

        //vigaro 10

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(865);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(866);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(288);
        digitalWrite(TX_PIN, HIGH);
        delay(23);

        /////////////////

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(481);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(210);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(481);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(210);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(481);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(288);

        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(995);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(481);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(995);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(867);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(1000);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delay(30);
      }

      if (count_flash == 2) {

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(481);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(192);

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(97);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(480);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(192);

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(289);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(289);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(384);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(385);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(769);

        //vigaro 20

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(97);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(576);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(193);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(577);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(384);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(97);
        digitalWrite(TX_PIN, HIGH);
        delay(23);

        /////////////////

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(481);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(210);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(481);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(210);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(481);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(288);

        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(995);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(481);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(995);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(867);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(1000);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delay(30);
      }

      if (count_flash == 3) {

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(481);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(192);

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(97);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(480);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(192);

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(289);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(289);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(384);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(385);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(769);

        //vigaro 30

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(193);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(576);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(193);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(576);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(288);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(288);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(97);
        digitalWrite(TX_PIN, HIGH);
        delay(23);

        /////////////////

        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(481);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(210);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(481);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(210);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(481);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(96);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(288);

        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(995);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(481);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(995);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(867);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(1000);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, LOW);
        delayMicroseconds(192);
        digitalWrite(TX_PIN, HIGH);
        delay(30);
      }

      lcd.setCursor(0, 1);
      lcd.print("finish..........");
      delay(2000);
      mode_eeprom = 28;
      lcd.clear();
      break;

    case 26:
      mode_eeprom = 25;
      break;

    case 27:
      mode_eeprom = 28;
      break;

    case 28:
      lcd.setCursor(0, 0);
      lcd.print("off/on knci kntk");
      lcd.setCursor(1, 1);
      lcd.print("off/on scanner");
      delay(2000);
      break;

    case 29:
      mode_eeprom = 28;
      break;

  }
}


void vigaro_satu() {
  pinMode(TX_PIN, OUTPUT);
  digitalWrite(TX_PIN, LOW);
  delay(70);
  digitalWrite(TX_PIN, HIGH);
  delay(130);
  // delay(50);
  pinMode(TX_PIN, OUTPUT);
  digitalWrite(TX_PIN, LOW);
  delay(70);
  digitalWrite(TX_PIN, HIGH);
  // delay(130);
  delay(200);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(188);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(750);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(270);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(92);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(470);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(92);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(92);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(866);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delay(23);

  // 1e
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(288);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(995);

  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(95);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(385);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(1000);

  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(577);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(403);

  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(385);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(995);

  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(95);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(995);

  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(288);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(995);

  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(288);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(995);

  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(95);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(384);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(1000);

  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(385);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(995);

  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(384);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(995);

  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(95);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(385);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delay(30);

  //2e
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(288);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(995);

  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(95);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(385);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(1000);

  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(577);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(403);

  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(95);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(288);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(288);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(995);

  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(95);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(481);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(995);

  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(288);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(995);

  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(95);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delay(1);

  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(95);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(995);


  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(95);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(385);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(995);

  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(95);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(288);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(995);

  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(289);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, HIGH);
  delay(200);
}

void vigaro_dua() {

  pinMode(TX_PIN, OUTPUT);
  digitalWrite(TX_PIN, LOW);
  delay(70);
  digitalWrite(TX_PIN, HIGH);
  delay(130);
  // delay(50);
  pinMode(TX_PIN, OUTPUT);
  digitalWrite(TX_PIN, LOW);
  delay(70);
  digitalWrite(TX_PIN, HIGH);
  // delay(130);
  delay(200);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(188);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(750);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(270);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(92);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(470);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(92);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(92);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(866);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delay(23);

  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(288);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(480);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(866);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(481);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(480);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, HIGH);
  delay(10);

  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(385);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(480);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(864);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(672);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(576);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(384);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, HIGH);
  delay(50);

  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(481);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(210);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(481);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(210);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(481);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(96);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(288);

  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(995);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(481);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(995);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(867);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(1000);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, HIGH);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, LOW);
  delayMicroseconds(192);
  digitalWrite(TX_PIN, HIGH);
  delay(30);
}
