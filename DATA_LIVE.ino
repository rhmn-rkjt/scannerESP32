

// CODING DI PAGE INI UNTUK MENAMPILKAN DISPLAY LIVE DATA DI LCD



void data_live() {


  if (!digitalRead(downButton)) {
    menu_live--;
    lcd.clear();
    delay(150);
    while (!digitalRead(downButton));
  }
  if (!digitalRead(upButton)) {
    menu_live++;
    lcd.clear();
    delay(150);
    while (!digitalRead(upButton));
  }

  switch (menu_live) {

    case 0:
      menu_live = 13;
      break;

    // RPM
    case 1:
      lcd.setCursor(0, 0);
      lcd.print("RPM =");
      lcd.setCursor(12, 0);
      lcd.print("Rpm");
      lcd.setCursor(6, 0);
      lcd.print(rpm);
      lcd.setCursor(0, 1);
      lcd.print("BAT =");
      lcd.setCursor(6, 1);
      lcd.print(batv, 2);
      lcd.setCursor(12, 1);
      lcd.print("VOLT");
      break;

    // TPS
    case 2:
      lcd.setCursor(0, 0);
      lcd.print("TPS V =");
      lcd.setCursor(8, 0);
      lcd.print(tpsv, 2);
      lcd.setCursor(13, 0);
      lcd.print("Vol");
      lcd.setCursor(0, 1);
      lcd.print("TPS % =");
      lcd.setCursor(8, 1);
      lcd.print(tpsp);
      if ( tpsp < 10 ) {
        lcd.setCursor(9, 1);
        lcd.print("    %");
      }
      else {
        lcd.setCursor(13, 1);
        lcd.print("%");
      }
      break;

    // ECT
    case 3:
      lcd.setCursor(0, 0);
      lcd.print("ECT V =");
      lcd.setCursor(8, 0);
      lcd.print(ectv, 2);
      lcd.setCursor(13, 0);
      lcd.print("Vol");
      lcd.setCursor(0, 1);
      lcd.print("ECT C =");
      lcd.setCursor(8, 1);
      lcd.print(ectc);
      lcd.setCursor(13, 1);
      lcd.print(char(223));
      lcd.setCursor(14, 1);
      lcd.print("C");
      break;

    // EOT
    case 4:
      lcd.setCursor(0, 0);
      lcd.print("EOT V =");
      lcd.setCursor(8, 0);
      lcd.print(eotv, 2);
      lcd.setCursor(13, 0);
      lcd.print("Vol");
      lcd.setCursor(0, 1);
      lcd.print("EOT C =");
      lcd.setCursor(8, 1);
      lcd.print(eotc);
      lcd.setCursor(13, 1);
      lcd.print(char(223));
      lcd.setCursor(14, 1);
      lcd.print("C");
      break;

    // IAT
    case 5:
      lcd.setCursor(0, 0);
      lcd.print("IAT V =");
      lcd.setCursor(8, 0);
      lcd.print(iatv, 2);
      lcd.setCursor(13, 0);
      lcd.print("Vol");
      lcd.setCursor(0, 1);
      lcd.print("IAT C =");
      lcd.setCursor(8, 1);
      lcd.print(iatc);
      lcd.setCursor(13, 1);
      lcd.print(char(223));
      lcd.setCursor(14, 1);
      lcd.print("C");
      break;

    // MAP
    case 6:
      lcd.setCursor(0, 0);
      lcd.print("MAP =");
      lcd.setCursor(6, 0);
      lcd.print(mapv, 2);
      lcd.setCursor(13, 0);
      lcd.print("Vol");
      lcd.setCursor(0, 1);
      lcd.print("MAP =");
      lcd.setCursor(6, 1);
      lcd.print(mapk);
      lcd.setCursor(13, 1);
      lcd.print("KPa");
      break;

    // CKP + INJ
    case 7:
      lcd.setCursor(0, 0);
      lcd.print("CKP =");
      lcd.setCursor(7, 0);
      lcd.print(ckpp, 1);
      lcd.setCursor(11, 0);
      lcd.print(" ");
      lcd.setCursor(13, 0);
      lcd.print(char(223));
      lcd.setCursor(0, 1);
      lcd.print("INJ =");
      lcd.setCursor(7, 1);
      lcd.print(injj, 1);
      lcd.setCursor(11, 1);
      lcd.print("  mS");
      break;

    // O2
    case 8:
      lcd.setCursor(0, 0);
      lcd.print("o2 VOLT =");
      lcd.setCursor(10, 0);
      lcd.print(oxigenv, 2);
      lcd.setCursor(15, 0);
      lcd.print("V");
      lcd.setCursor(0, 1);
      lcd.print("o2 STFT =");
      lcd.setCursor(10, 1);
      lcd.print(oxigens, 2);
      break;

    // SPEED + STANDARD SAMPING
    case 9:
      lcd.setCursor(0, 0);
      lcd.print("SPEED     =");
      lcd.setCursor(12, 0);
      lcd.print(spdk);
      if ( spdk < 10 ) {
        lcd.setCursor(13, 0);
        lcd.print("   ");
      }
      lcd.setCursor(0, 1);
      lcd.print("STDR SMPG =");
      if (d1_1 == true) {
        lcd.setCursor(12, 1);
        lcd.print("ON ");
      } else if (d1_1 == false) {
        lcd.setCursor(12, 1);
        lcd.print("OFF");
      }
      break;

    // IACV + FPUMP
    case 10:
      lcd.setCursor(0, 0);
      lcd.print("FUEL PUMP =");
      if (d6_fpump == true) {
        lcd.setCursor(12, 0);
        lcd.print("ON ");
      }
      else if (d6_fpump == false) {
        lcd.setCursor(12, 0);
        lcd.print("OFF ");
      }
      lcd.setCursor(0, 1);
      lcd.print("IACV      =");
      if (d6_iacv == true) {
        lcd.setCursor(12, 1);
        lcd.print("ON ");
      }
      else if (d6_iacv == false) {
        lcd.setCursor(12, 1);
        lcd.print("OFF ");
      }
      break;

    // TOMBOL STARTER + RELAY STARTER
    case 11:
      lcd.setCursor(0, 0);
      lcd.print("TMBL START =");
      if (d6_mrelay == true) {
        lcd.setCursor(13, 0);
        lcd.print("ON ");
      }
      else if (d6_mrelay == false) {
        lcd.setCursor(13, 0);
        lcd.print("OFF ");
      }
      lcd.setCursor(0, 1);
      lcd.print("RLAY START =");
      if (d6_mrelay == true) {
        lcd.setCursor(13, 1);
        lcd.print("ON ");
      }
      else if (d6_mrelay == false) {
        lcd.setCursor(13, 1);
        lcd.print("OFF ");
      }
      break;

    // VIEW DTC
    case 12:
      lcd.setCursor(0, 0);
      lcd.print("# Lihat DTC");
      lcd.setCursor(1, 1);
      lcd.print("Tekan enter >");
      if ((digitalRead(pb) == LOW) && (menu_live == 12)) {
        menu_live = 15;
        menudtc = 1;
      }
      break;

    // CLEAR DTC
    case 13:
      lcd.setCursor(0, 0);
      lcd.print("# Hapus DTC");
      lcd.setCursor(1, 1);
      lcd.print("Tekan enter >");
      if ((digitalRead(pb) == LOW) && (menu_live == 13)) {
        menu_live = 21;

      }
      break;

    case 14:
      menu_live = 1;
      break;


    ///////////////// GROUP MASUK VIEW DTC ,,, JANGAN DI EDIT/////////
    case 15:
      lcd.clear();
      menu_live = 19;
    case 16:
      x = display_tampil + 50;
      menu_live = 19;
      display_tampil = 4;
      break;
    case 17:
      lcd.clear();
      menu_live = 16;
      break;
    case 18:
      lcd.clear();
      menu_live = 19;
      break;
    case 19:
      display_tampil = 4;
      menu_live = 19;
      break;
    case 20:
      lcd.clear();
      menu_live = 19;
      break;
    /////////////////////////////////////////////////////////////

    /////////// GROUP KELUAR MODE VIEW DTC,, JANGAN DI EDIT /////
    case 21:
      lcd.clear();
      menu_live = 23;
    case 22:
      lcd.clear();
      menu_live = 23;
    case 23:
      if (menu_live == 23) {
        clear_dtc();
      }


    case 24:
      lcd.clear();
      menu_live = 23;

    //////////////////////////////////////////////////////////

    /////////// GROUP CLEAR DTC, JANGAN DI EDIT //////////////
    case 25:

      menu_live = 26;

    case 26:
      lcd.setCursor(1, 0);
      lcd.print("off/on scaner");
      lcd.setCursor(0, 1);
      lcd.print("dan kunci kontak");

    case 27:

      menu_live = 26;

      /////////////////////////////////////////////////////////

  }

}
