
// MAIN PAGE VIGARO ESP32 FC1

#include "BluetoothSerial.h"
String device_name = "BINTANG_LAUT";
BluetoothSerial SerialBT;

//#include <SoftwareSerial.h>

#include <HardwareSerial.h>
#define debug Serial
#define PACKET_BUFFER_SIZE (128)
#define TX_PIN 17
#define RX_PIN 16
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define upButton 33
#define downButton  32
#define pb  25
//#define led  13


byte d1;
byte d2;
byte d3;
byte d4;
byte d5;
byte d6;
bool d1_1 = false;
bool d6_iacv = false;
bool d6_fpump = false;
bool d6_mrelay = false;

byte menu_live = 1;
byte menudtc = 1;
byte x = 0;
byte menureset = 0;

HardwareSerial bike(2); // RX, TX
byte ECU_WAKEUP_MESSAGE[] = {0xFE, 0x04, 0x72, 0x8C};
//byte ECU_WAKEUP_MESSAGE[] = {0xFE, 0x04, 0xFF, 0xFF};
byte ECU_INIT_MESSAGE[] = {0x72, 0x05, 0x00, 0xF0, 0x99};
int ECU_SUCCESS_CHECKSUM = 0x600;
//int ECU_SUCCESS_CHECKSUM = 0x6FB;
byte id_ecm[] = {0x72, 0x05, 0x71, 0x00, 0x18};
byte aku_aku[] = {0x27, 0x0b, 0xe0, 0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x48, 0x6f, 0x43};
int jk = 0;

unsigned long JEDA50 = 5;
unsigned long JEDA150 = 150;
unsigned long JEDA250 = 250;
unsigned long JEDA4000 = 4000;
unsigned long JEDA2000 = 2000;
unsigned long JEDA1000 = 1000;
unsigned long JEDA100 = 100;
unsigned long SEBELUM = 0;
unsigned long SEBELUM1 = 0;
unsigned long SEBELUM2 = 0;

int rpm = 0;
float tpsv = 0;
int tpsp = 0;
float eotv = 0;
int eotc = 0;
float ectv = 0;
int ectc = 0;
int iatv = 0;
int iatc = 0;
int mapv = 0;
int mapk = 0;
float batv = 0;
float injj = 0 ;
float ckpp = 0;
int spdk = 0;
float oxigenv;
float oxigens;

byte dtc1 = 0;
byte dtc2 = 0;
byte dtc3 = 0;
byte dtc4 = 0;
byte dtc5 = 0;
byte dtc6 = 0;

byte dtca = 0;
byte dtcb = 0;
byte dtcc = 0;
byte dtcd = 0;
byte dtce = 0;
byte dtcf = 0;
byte dtc_sel = 0;
byte dtc_tampil = 0;

byte data_satu = 0;
byte data_dua = 0;
byte data_tiga = 0;
byte data_empat = 0;
byte data_lima = 0;
byte fc_jumlah = 0;
byte fc_jumlah11 = 0;
byte fc_jumlah17 = 0;
byte fc_jumlah17esp = 0;
byte fc_jumlah10 = 0;

byte fc1 = 0;
byte fc2 = 0;
byte fc3 = 0;
byte fc4 = 0;
byte fc5 = 0;
byte fc6 = 0;
byte fc7 = 0;
byte fc8 = 0;

byte display_tampil = 0;
byte mode_eeprom = 1;
byte count_flash = 0;
byte konter = 0;

void setup() {
  unsigned long SEKARANG = millis();

  lcd.init();
  lcd.backlight();
  debug.begin(115200);
  SerialBT.begin(device_name);

  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(pb, INPUT_PULLUP);
  //pinMode(led, OUTPUT);

  bangunkan();
  ecu_detect11();
  ecu_detect17();
  ecu_detect10();

  if ((SEKARANG - SEBELUM <= JEDA2000) && (digitalRead(pb) == LOW)) {
    display_tampil = 10;

    SEBELUM = SEKARANG;
  }
  else  if ((SEKARANG - SEBELUM <= JEDA2000) && (digitalRead(upButton) == LOW) && (digitalRead(downButton) == LOW)) {
    display_tampil = 11;

    SEBELUM = SEKARANG;
  }
  else
  {
    merk_dagang();
  }
  lcd.clear();



}


void loop() {




  unsigned long SEKARANG = millis();


  if (display_tampil == 1) {
    data_11();
    dtcapk();
    data_live();
  } else if (display_tampil == 2) {
    data_17();
    dtcapk();
    data_live();
  } else if (display_tampil == 3) {
    data_17esp();
    dtcapk();
    data_live();
  } else if (display_tampil == 4) {
    dtc();
    data_live();
  } else if (display_tampil == 7) {
    data_11sport();
    data_live();
  }  else if (display_tampil == 8) {
    data_10();
    data_live();
    dtcapk();
  }
  else if ( display_tampil == 10) {
    maintenance_mode();
  } else if ( display_tampil == 11) {
    eeprom_mode();
  } else
  {
    lcd.setCursor(0, 0);
    lcd.print("---- no ECU ----");
    lcd.setCursor(5, 1);
    lcd.print("Detect");
  }

  //
  if (SEKARANG - SEBELUM >= JEDA100 ) {
    String id_ecm =  String(data_satu, HEX) + ";" + String(data_dua, HEX) + ";" + String(data_tiga, HEX) + ";" + String(data_empat, HEX) + ";" +
                     String(data_lima, HEX) + ";" + String(fc_jumlah) + ";";//6
    String data_live = String(rpm) + ";" + String(batv) + ";" + String(tpsp) + ";" +
                       String(tpsv) + ";" + String(eotc) + ";" + String(eotv) + ";" + String(ectc) + ";" + String(ectv) + ";" + String (iatc) + ";" +
                       String(iatv) + ";" + String(mapk) + ";" + String(mapv) + ";" +
                       String(injj) + ";" + String(ckpp) + ";" + String(spdk) + ";"  + String(oxigens) + ";" +
                       String(oxigenv) + ";";//23
    String tabel_d1 = String(d1) + ";" + String(d6) + ";" ;//25
    String tabel_dtc = String(dtca) + ";" + String(dtcb) + ";" + String(dtcc) + ";" + String(dtcd) + ";" + String(dtce) + ";" + String(dtcf) + ";";//31
    String tabel_d1debug = String(d1) + ";" + String(d2) + ";" + String(d3) + ";" + String(d4) + ";" + String(d6) + ";" + String(d5) + ";" + String(display_tampil) + ";"  ; //38
    String fcc = String(fc1) + ";" + String(fc2) + ";" + String(fc3) + ";" + String(fc4) + ";" + String(fc5) + ";" + String(fc6) + ";" + String(fc7) + ";" + String(fc8) + ";"  ; //46



    SerialBT.print(id_ecm);
    SerialBT.print(data_live);
    SerialBT.print(tabel_d1);
    SerialBT.println(tabel_dtc);
    SerialBT.print(tabel_d1debug);
    SerialBT.println(fcc);

    //debug.print(id_ecm);
    // debug.print(data_live);
    // debug.print(tabel_d1);
    // debug.println(tabel_dtc);

    SEBELUM = SEKARANG;
  }



}
