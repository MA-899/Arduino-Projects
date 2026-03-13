String toDigital(int x) {
  int ds = -1;
  int multiplier = 1;
  String result = "0000";

  while (x >= multiplier) {
    multiplier *= 2;
    ds++;
  }

  while (x > 0) {
    multiplier /= 2;
    if (x - multiplier >= 0) {
      result[ds] = '1';
      x -= multiplier;
    }
    ds--;
  }
  
  return result; 
}


void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  for (int i = 0; i < 16; i++) {
    String digital_i = toDigital(i);
    digitalWrite(3, int(digital_i[0] - '0'));
    digitalWrite(4, int(digital_i[1] - '0'));
    digitalWrite(5, int(digital_i[2] - '0'));
    digitalWrite(6, int(digital_i[3] - '0'));
    delay(1000);
  }
}
