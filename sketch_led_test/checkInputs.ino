////checks whats being input and set colors accordingly

void led() {


  setLedFlags(1, "black");
  setLedFlags(2, "black");
  setLedFlags(3, "black");
  setLedFlags(4, "black");
  setLedFlags(5, "black");       //defaults to black if nothing is being pressed
  setLedFlags(6, "black");
  setLedFlags(7, "black");
  setLedFlags(8, "black");
  setLedFlags(9, "black");
  setLedFlags(10, "black");
  setLedFlags(11, "black");
  setLedFlags(12, "black");
  reg[37] = LOW;
  reg[38] = LOW;
  reg[39] = LOW;
  reg[40] = LOW;


  //buttons

  //down b
  if (gcc.b && ay < 0 && mag(axm, aym) > 60 && ang(axm, aym) > 60 && ang(axm, aym) < 130) {
    setLedFlags(1, "cyan");
    setLedFlags(2, "cyan");
    setLedFlags(3, "cyan");
    setLedFlags(4, "cyan");
    setLedFlags(5, "cyan");
    setLedFlags(6, "cyan");
    setLedFlags(7, "cyan");
    setLedFlags(8, "cyan");
    setLedFlags(9, "cyan");
    setLedFlags(10, "cyan");
    setLedFlags(11, "cyan");
    setLedFlags(12, "cyan");
  }

  //b
  else if (gcc.b) {
    setLedFlags(1, "red");
    setLedFlags(2, "red");
    setLedFlags(3, "red");
    setLedFlags(4, "red");
    setLedFlags(5, "red");
    setLedFlags(6, "red");
    setLedFlags(7, "red");
    setLedFlags(8, "red");
    setLedFlags(9, "red");
    setLedFlags(10, "red");
    setLedFlags(11, "red");
    setLedFlags(12, "red");
  }

  //a
  if (gcc.a) {
    setLedFlags(1, "green");
    setLedFlags(2, "green");
    setLedFlags(3, "green");
    setLedFlags(4, "green");
    setLedFlags(5, "green");
    setLedFlags(6, "green");
    setLedFlags(7, "green");
    setLedFlags(8, "green");
    setLedFlags(9, "green");
    setLedFlags(10, "green");
    setLedFlags(11, "green");
    setLedFlags(12, "green");
  }

  //x || y
  if (gcc.x || gcc.y) {
    setLedFlags(1, "white");
    setLedFlags(2, "white");
    setLedFlags(3, "white");
    setLedFlags(4, "white");
    setLedFlags(5, "white");
    setLedFlags(6, "white");
    setLedFlags(7, "white");
    setLedFlags(8, "white");
    setLedFlags(9, "white");
    setLedFlags(10, "white");
    setLedFlags(11, "white");
    setLedFlags(12, "white");
  }

  if (gcc.z) {
    setLedFlags(1, "purple");
    setLedFlags(2, "purple");
    setLedFlags(3, "purple");
    setLedFlags(4, "purple");
    setLedFlags(5, "purple");
    setLedFlags(6, "purple");
    setLedFlags(7, "purple");
    setLedFlags(8, "purple");
    setLedFlags(9, "purple");
    setLedFlags(10, "purple");
    setLedFlags(11, "purple");
    setLedFlags(12, "purple");
  }

  if (gcc.l) {
    setLedFlags(1, "white");
    setLedFlags(2, "white");
    setLedFlags(3, "white");
  }
  if (gcc.r) {
    setLedFlags(10, "white");
    setLedFlags(11, "white");
    setLedFlags(12, "white");
  }




  //directions  checked last to override any 'main' colors
  //up
  if (ay > 0 && mag(axm, aym) > 50 && ang(axm, aym) > 45 && ang(axm, aym) < 135) {
    setLedFlags(1, "blue");
    setLedFlags(2, "blue");
    setLedFlags(3, "blue");
  }

  //right
  if (ax > 0 && mag(axm, aym) > 50 && ang(axm, aym) > -45 && ang(axm, aym) < 45) {
    setLedFlags(4, "yellow");
    setLedFlags(5, "yellow");
    setLedFlags(6, "yellow");
  }

  //down
  if (ay < 0 && mag(axm, aym) > 50 && ang(axm, aym) > 45 && ang(axm, aym) < 135) {
    setLedFlags(7, "green");
    setLedFlags(8, "green");
    setLedFlags(9, "green");
  }

  //left
  if (ax < 0 && mag(axm, aym) > 50 && ang(axm, aym) > -45 && ang(axm, aym) < 45) {
    setLedFlags(10, "red");
    setLedFlags(11, "red");
    setLedFlags(12, "red");
  }
}


