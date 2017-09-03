//sets flags for each color


//all
void setRed() {
  setNRed();
  setERed();
  setSRed();
  setWRed();
}

void setGreen() {
  setNGreen();
  setEGreen();
  setSGreen();
  setWGreen();
}

void setBlue() {
  setNBlue();
  setEBlue();
  setSBlue();
  setWBlue();
}

void setWhite() {
  setNWhite();
  setEWhite();
  setSWhite();
  setWWhite();
}

void setCyan() {
  setNCyan();
  setECyan();
  setSCyan();
  setWCyan();
}

void setYellow() {
  setNYellow();
  setEYellow();
  setSYellow();
  setWYellow();
}

void setPurple() {
  setNPurple();
  setEPurple();
  setSPurple();
  setWPurple();
}

void setBlack() {
  setNBlack();
  setEBlack();
  setSBlack();
  setWBlack();
}






//north
void setNRed() {
  nRed = true;
  nGreen = false;
  nBlu = false;
}

void setNGreen() {
  nRed = false;
  nGreen = true;
  nBlu = false;
}

void setNBlue() {
  nRed = false;
  nGreen = false;
  nBlu = true;
}

void setNWhite() {
  nRed = true;
  nGreen = true;
  nBlu = true;
}

void setNCyan() {
  nRed = false;
  nGreen = true;
  nBlu = true;
}

void setNYellow() {
  nRed = true;
  nGreen = true;
  nBlu = false;
}

void setNPurple() {
  nRed = true;
  nGreen = false;
  nBlu = true;
}

void setNBlack() {
  nRed = false;
  nGreen = false;
  nBlu = false;
}



//east
void setERed() {
  eRed = true;
  eGreen = false;
  eBlu = false;
}

void setEGreen() {
  eRed = false;
  eGreen = true;
  eBlu = false;
}

void setEBlue() {
  eRed = false;
  eGreen = false;
  eBlu = true;
}

void setEWhite() {
  eRed = true;
  eGreen = true;
  eBlu = true;
}

void setECyan() {
  eRed = false;
  eGreen = true;
  eBlu = true;
}

void setEYellow() {
  eRed = true;
  eGreen = true;
  eBlu = false;
}

void setEPurple() {
  eRed = true;
  eGreen = false;
  eBlu = true;
}

void setEBlack() {
  eRed = false;
  eGreen = false;
  eBlu = false;
}



//south
void setSRed() {
  sRed = true;
  sGreen = false;
  sBlu = false;
}

void setSGreen() {
  sRed = false;
  sGreen = true;
  sBlu = false;
}

void setSBlue() {
  sRed = false;
  sGreen = false;
  sBlu = true;
}

void setSWhite() {
  sRed = true;
  sGreen = true;
  sBlu = true;
}

void setSCyan() {
  sRed = false;
  sGreen = true;
  sBlu = true;
}

void setSYellow() {
  sRed = true;
  sGreen = true;
  sBlu = false;
}

void setSPurple() {
  sRed = true;
  sGreen = false;
  sBlu = true;
}

void setSBlack() {
  sRed = false;
  sGreen = false;
  sBlu = false;
}



//west
void setWRed() {
  wRed = true;
  wGreen = false;
  wBlu = false;
}

void setWGreen() {
  wRed = false;
  wGreen = true;
  wBlu = false;
}

void setWBlue() {
  wRed = false;
  wGreen = false;
  wBlu = true;
}

void setWWhite() {
  wRed = true;
  wGreen = true;
  wBlu = true;
}

void setWCyan() {
  wRed = false;
  wGreen = true;
  wBlu = true;
}

void setWYellow() {
  wRed = true;
  wGreen = true;
  wBlu = false;
}

void setWPurple() {
  wRed = true;
  wGreen = false;
  wBlu = true;
}

void setWBlack() {
  wRed = false;
  wGreen = false;
  wBlu = false;
}



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



