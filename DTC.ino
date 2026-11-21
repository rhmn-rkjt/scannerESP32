
// CODING UNTUK MENAMPILKAN DATA KERUSAKAN(DTC)


void dtc() {

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

  if ((dtc_sel == 1) || (dtc_sel == 7)) {
    dtc1 = (buff[10]) ;
    dtc2 = (buff[12]);
    dtc3 = (buff[14]);
    dtc4 = (buff[9]) ;
    dtc5 = (buff[11]);
    dtc6 = (buff[13]);
  } else

    if (dtc_sel == 2) {
      dtc1 = (buff[10]) ;
      dtc2 = (buff[12]);
      dtc3 = (buff[14]);
      dtc4 = (buff[11]) ;
      dtc5 = (buff[13]);
      dtc6 = (buff[15]);
    } else

      if (dtc_sel == 3) {
        dtc1 = (buff[10]) ;
        dtc2 = (buff[12]);
        dtc3 = (buff[14]);
        dtc4 = (buff[11]) ;
        dtc5 = (buff[13]);
        dtc6 = (buff[15]);
      } else if (dtc_sel == 8) {
        dtc1 = (buff[12]) ;
        dtc2 = (buff[14]);
        dtc3 = (buff[10]);

        dtc4 = (buff[13]) ;
        dtc5 = (buff[15]);
        dtc6 = (buff[11]);
      }




  if (!digitalRead(downButton)) {
    menudtc--;
    lcd.clear();

    delay(150);
    while (!digitalRead(downButton));
  }
  if (!digitalRead(upButton)) {
    menudtc++;
    lcd.clear();

    delay(150);
    while (!digitalRead(upButton));
  }


  switch (menudtc) {


    case 0:
      menudtc = 1;
      break;
    case 1:
      lcd.setCursor(3, 0);
      lcd.print("Sensor MAP");
      if (dtc3 == 1) {
        lcd.setCursor(0, 1);
        lcd.print("> Error MIL (1)");
      }
      else if (dtc6 == 1) {
        lcd.setCursor(0, 1);
        lcd.print("> Error MIL (1)");
      } else {
        lcd.setCursor(5, 1);
        lcd.print("> OK <");
      }
      break;

    case 2:
      lcd.setCursor(3, 0);
      lcd.print("Sensor EOT");
      if (dtc1 == 7) {
        lcd.setCursor(0, 1);
        lcd.print("> Error MIL (7)");
      }
      else if (dtc4 == 7) {
        lcd.setCursor(0, 1);
        lcd.print("> Error MIL (7)");
      } else {
        lcd.setCursor(5, 1);
        lcd.print("> OK <");
      }
      break;


    case 3:
      lcd.setCursor(3, 0);
      lcd.print("Sensor ECT");
      if (dtc1 == 7) {
        lcd.setCursor(0, 1);
        lcd.print("> Error MIL (7)");
      }
      else if (dtc4 == 7) {
        lcd.setCursor(0, 1);
        lcd.print("> Error MIL (7)");
      } else {
        lcd.setCursor(5, 1);
        lcd.print("> OK <");
      }
      break;

    case 4:
      lcd.setCursor(3, 0);
      lcd.print("Sensor TPS");
      if (dtc2 == 8) {
        lcd.setCursor(0, 1);
        lcd.print("> Error MIL (8)");
      } else if (dtc5 == 8) {
        lcd.setCursor(0, 1);
        lcd.print("> Error MIL (8)");
      } else
      {
        lcd.setCursor(5, 1);
        lcd.print("> OK <");
      }
      break;

    case 5:
      lcd.setCursor(4, 0);
      lcd.print("Injector");
      if (dtc3 == 12) {
        lcd.setCursor(0, 1);
        lcd.print("> Error MIL (12)");
      }
      else if (dtc6 == 12) {
        lcd.setCursor(0, 1);
        lcd.print("> Error MIL (12)");
      } else {
        lcd.setCursor(5, 1);
        lcd.print("> OK <");
      }
      break;

    case 6:
      lcd.setCursor(3, 0);
      lcd.print("Sensor O2");
      lcd.setCursor(5, 1);
      lcd.print("> OK <");
      break;

    case 7:
      lcd.setCursor(6, 0);
      lcd.print("IACV");
      lcd.setCursor(5, 1);
      lcd.print("> OK <");
      break;

    case 8:
      lcd.setCursor(7, 0);
      lcd.print("ECU");
      lcd.setCursor(5, 1);
      lcd.print("> OK <");
      break;

    case 9:
      lcd.setCursor(3, 0);
      lcd.print("Sensor CKP");
      lcd.setCursor(5, 1);
      lcd.print("> OK <");
      break;

    case 10:
      lcd.setCursor(3, 0);
      lcd.print("Sensor BAS");
      lcd.setCursor(5, 1);
      lcd.print("> OK <");
      break;

    case 11:
      lcd.setCursor(0, 0);
      lcd.print("Kembali ke Menu");
      lcd.setCursor(0, 1);
      lcd.print("Tekan Enter >");
      if ((digitalRead(pb) == LOW) && (menudtc == 11)) {
        lcd.clear();
        menu_live = 1;
        menudtc = 0;
        display_tampil = x - 50 ;
      }
      break;

    case 12:
      menudtc = 11;
      break;

    case 13:
      lcd.clear();

      menudtc = 1;
      break;

    case 14:
      menudtc = 1;
      break;
  }

}
