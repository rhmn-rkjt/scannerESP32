
// CODING INI BERISI CALCULATION DATA
// DARI ECU UNTUK DITAMPILKAN KE LCD


float calcValueDivide256(float val) {
  return (val * 5) / 256;
}

float kalo2 (float val) {
  return (val * 2) / 256;
}

float calcValueMinus40(int val) {
  return val - 40;
}

float calcValueDivide10(float val) {
  return val / 10;
}

float calcValueDivide16(int val) {
  return (val * 10) / 16;
}

float ckp(float val) {
  return (val * 265.5) / 65.535;
}
float inj(float val) {
  return (val ) / (65535 * 265, 5);
}
