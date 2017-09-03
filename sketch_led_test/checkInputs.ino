////checks whats being input and set colors accordingly

void led() {


  setLedFlags(1, "black");
  setLedFlags(2, "black");
  setLedFlags(3, "black");
  setLedFlags(4, "black");
  setLedFlags(5, "black");       //defaults to black if nothing is being pressed




  //buttons

  //down b
  if (gcc.b && ay < 0 && mag(axm, aym) > 60 && ang(axm, aym) > 60 && ang(axm, aym) < 130) {
    setLedFlags(1, "cyan");
    setLedFlags(2, "cyan");
    setLedFlags(3, "cyan");
    setLedFlags(4, "cyan");
    setLedFlags(5, "cyan");
  }

  //b
  else if (gcc.b) {
    setLedFlags(1, "red");
    setLedFlags(2, "red");
    setLedFlags(3, "red");
    setLedFlags(4, "red");
    setLedFlags(5, "red");
  }

  //a
  if (gcc.a) {
    setLedFlags(1, "green");
    setLedFlags(2, "green");
    setLedFlags(3, "green");
    setLedFlags(4, "green");
    setLedFlags(5, "green");
  }

  //x || y
  if (gcc.x || gcc.y) {
    setLedFlags(1, "white");
    setLedFlags(2, "white");
    setLedFlags(3, "white");
    setLedFlags(4, "white");
    setLedFlags(5, "white");
  }

  if(gcc.z){
    setLedFlags(1, "purple");
    setLedFlags(2, "purple");
    setLedFlags(3, "purple");
    setLedFlags(4, "purple");
    setLedFlags(5, "purple");
  }

  if(gcc.l){
    setLedFlags(1, "white");
    setLedFlags(2, "white");
  }
  if(gcc.r){
    setLedFlags(4, "white");
    setLedFlags(5, "white");
  }




  //directions  checked last to override any 'main' colors
  //up
  if (ay > 0 && mag(axm, aym) > 50 && ang(axm, aym) > 45 && ang(axm, aym) < 135) {
    setLedFlags(1, "blue");
    setLedFlags(5, "blue");
  }

  //right
  if (ax > 0 && mag(axm, aym) > 50 && ang(axm, aym) > -45 && ang(axm, aym) < 45)
    setLedFlags(2, "yellow");

  //down
  if (ay < 0 && mag(axm, aym) > 50 && ang(axm, aym) > 45 && ang(axm, aym) < 135)
    setLedFlags(3, "green");

  //left
  if (ax < 0 && mag(axm, aym) > 50 && ang(axm, aym) > -45 && ang(axm, aym) < 45)
    setLedFlags(4, "red");
}


