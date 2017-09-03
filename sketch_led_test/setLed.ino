//sets values to be outputted, needs the led number and a color
void setLedFlags(int number, String color) {

  if (color != "red" || "green" || "blue" || "yellow" || "purple" || "cyan" || "white" || "black") {
    reg[number * 3 - 2] = LOW;
    reg[number * 3 - 1] = LOW;
    reg[number * 3 - 0] = LOW;
  }


  if (color == "red") {
    reg[number * 3 - 2] = HIGH;
    reg[number * 3 - 1] = LOW;
    reg[number * 3 - 0] = LOW;
  }

  if (color == "green") {
    reg[number * 3 - 2] = LOW;
    reg[number * 3 - 1] = HIGH;
    reg[number * 3 - 0] = LOW;
  }
  if (color == "blue") {
    reg[number * 3 - 2] = LOW;
    reg[number * 3 - 1] = LOW;
    reg[number * 3 - 0] = HIGH;
  }

  if (color == "yellow") {
    reg[number * 3 - 2] = HIGH;
    reg[number * 3 - 1] = HIGH;
    reg[number * 3 - 0] = LOW;
  }

  if (color == "purple") {
    reg[number * 3 - 2] = HIGH;
    reg[number * 3 - 1] = LOW;
    reg[number * 3 - 0] = HIGH;
  }

  if (color == "cyan") {
    reg[number * 3 - 2] = LOW;
    reg[number * 3 - 1] = HIGH;
    reg[number * 3 - 0] = HIGH;
  }

  if (color == "white") {
    reg[number * 3 - 2] = HIGH;
    reg[number * 3 - 1] = HIGH;
    reg[number * 3 - 0] = HIGH;
  }

  if (color == "black") {
    reg[number * 3 - 2] = LOW;
    reg[number * 3 - 1] = LOW;
    reg[number * 3 - 0] = LOW;
  }







}



