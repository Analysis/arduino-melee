//sends values to leds

void outputColor() {

  //north
  if (nRed)
    digitalWrite(nRed_led, HIGH);
  else
    digitalWrite(nRed_led, LOW);

  if (nGreen)
    digitalWrite(nGreen_led, HIGH);
  else
    digitalWrite(nGreen_led, LOW);

  if (nBlu)
    digitalWrite(nBlu_led, HIGH);
  else
    digitalWrite(nBlu_led, LOW);


  //east
  if (eRed)
    digitalWrite(eRed_led, HIGH);
  else
    digitalWrite(eRed_led, LOW);

  if (eGreen)
    digitalWrite(eGreen_led, HIGH);
  else
    digitalWrite(eGreen_led, LOW);

  if (eBlu)
    digitalWrite(eBlu_led, HIGH);
  else
    digitalWrite(eBlu_led, LOW);


  //south
  if (sRed)
    digitalWrite(sRed_led, HIGH);
  else
    digitalWrite(sRed_led, LOW);

  if (sGreen)
    digitalWrite(sGreen_led, HIGH);
  else
    digitalWrite(sGreen_led, LOW);

  if (sBlu)
    digitalWrite(sBlu_led, HIGH);
  else
    digitalWrite(sBlu_led, LOW);


  //west
  if (wRed)
    digitalWrite(wRed_led, HIGH);
  else
    digitalWrite(wRed_led, LOW);

  if (wGreen)
    digitalWrite(wGreen_led, HIGH);
  else
    digitalWrite(wGreen_led, LOW);

  if (wBlu)
    digitalWrite(wBlu_led, HIGH);
  else
    digitalWrite(wBlu_led, LOW);


}




void outputPin() {
  digitalWrite(latch, LOW);

  //clockn' some values
  for (int i = 16; i > 0; i--) {
    digitalWrite(clockP, LOW);

    digitalWrite(data, reg[i]);

    digitalWrite(clockP, HIGH);
  }
  digitalWrite(latch, HIGH);
}


