//sends values to leds

void outputPin() {
  digitalWrite(latch, LOW);

  //clockn' some values
  for (int i = 40; i > 0; i--) {
    digitalWrite(clockP, LOW);

    digitalWrite(data, reg[i]);

    digitalWrite(clockP, HIGH);
  }
  digitalWrite(latch, HIGH);
}


