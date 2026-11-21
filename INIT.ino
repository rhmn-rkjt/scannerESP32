

// CODING UNTUK MEMBANGUNKAN ECU DARI TIDUR ( WAKE UP FROM SLEEP MODE)
// DAN MELAKUKAN PROSES INISIALISAI



byte bangunkan() {
  int initSuccess = 0;
  initComms();
  bike.begin(10400, SERIAL_8N1, 16, 17);
//  bike.setRxInvert(false);
  bike.write(ECU_WAKEUP_MESSAGE, sizeof(ECU_WAKEUP_MESSAGE));
  delay(200);
  bike.write(ECU_INIT_MESSAGE, sizeof(ECU_INIT_MESSAGE));
  bike.flush();
  delay(50);

  int initBuffCount = 0;
  byte initBuff[32];
  while ( bike.available() > 0  && initBuffCount < 32 ) {
    initBuff[initBuffCount++] = bike.read();
  }

  int initSum = 0;
  for (int i = 0; i < initBuffCount; i++) {
    initSum += initBuff[i];
  }

  lcd.setCursor(0, 0);
  lcd.print("Conect to Ecu...");
  delay(1000);

  if (initSum == ECU_SUCCESS_CHECKSUM) {

    lcd.setCursor(0, 1);
    lcd.print("Succes..........");
    delay(1000);
    lcd.clear();
    initSuccess = 1;
    return 1;

  }
  else {
    lcd.setCursor(0, 1);
    lcd.print("Ulangi...........");
    delay(1000);
    lcd.clear();
    return 1;
  }
}

int initComms() {
  pinMode(TX_PIN, OUTPUT);
  digitalWrite(TX_PIN, LOW);
  delay(70);
  digitalWrite(TX_PIN, HIGH);
  delay(130);
  delay(50);
  pinMode(TX_PIN, OUTPUT);
  digitalWrite(TX_PIN, LOW);
  delay(70);
  digitalWrite(TX_PIN, HIGH);
  delay(130);
  return 1;
}

uint8_t calcChecksum(const uint8_t* data, uint8_t len) {
  uint8_t cksum = 0;
  for (uint8_t i = 0; i < len; i++)
    cksum -= data[i];
  return cksum;
}
