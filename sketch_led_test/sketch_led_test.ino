/*
   profiles
   1. default-dashback, maxvectors
   2. hax-    dashback, maxvectors, perfectangles, shielddrop
   3. push-   dashback, maxvectors, shielddrop, lcancel
   4. lulz-   dashback, maxvectors, perfectangles, shielddrop, smashdi
   5. hacker- dashback, maxvectors, perfectangles, shielddrop, wobble
*/



#include "Nintendo.h"
CGamecubeController controller(3); //D3 for internal
CGamecubeConsole console(4);
Gamecube_Report_t gcc;             //structure for controller state
bool shield, tilt, dolphin = 0, off = 0, wobbleState, set, last_state;
byte axm, aym, cxm, cym, cycles;
char ax, ay, cx, cy, buf;
float swang, seang;
word mode, toggle;
unsigned long n;
int last_x, profile;
float last_t, last_l, current_t;

int wRed_led = 4, wGreen_led = 5, wBlu_led = 6;     //west(left) led
int sRed_led = 7, sGreen_led = 8, sBlu_led = 9;     //south(down) led
int eRed_led = 10, eGreen_led = 11, eBlu_led = 12;  //east(right) led
int nRed_led = 15, nGreen_led = 16, nBlu_led = 17;     //north(up) led

int data = 5, latch = 6, clockP = 7;
boolean reg[40];


bool wRed, wGreen, wBlu, sRed, sGreen, sBlu, eRed, eGreen, eBlu, nRed, nGreen, nBlu;



void convertinputs() {

  switch (profile) {
    case 1: //default
      //backdash();
      //maxvectors();
      break;

    case 2: //hax
      perfectangles();
      maxvectors();
      shieldDrop();
      backdash();

      break;

    case 3: //push
      perfectangles();
      maxvectors();
      shieldDrop();
      backdash();
      lCancel();
      //dashDance();
      break;


    case 4: //lulz
      perfectangles();
      maxvectors();
      shieldDrop();
      backdash();
      smashDI();
      break;

    case 5: //hacker
      perfectangles();
      maxvectors();
      shieldDrop();
      backdash();
      wobble();
      break;

    default:
      off = off;
      break;

  }


  dolphinfix();



  /*
    perfectangles(); //reduces deadzone of cardinals and gives steepest/shallowest angles when on or near the gate
    maxvectors();    //snaps sufficiently high cardinal inputs to vectors of 1.0 magnitude of analog stick and c stick
    shielddrops();   //allows shield drops down and gives a 6 degree range of shield dropping centered on SW and SE gates
    backdash();      //fixes dashback by imposing a 1 frame buffer upon tilt turn values
    dolphinfix();    //ensures close to 0 values are reported as 0 on the sticks to fix dolphin calibration and allows user to switch to dolphin mode for backdash
    nocode();        //function to disable all code if dpad left is held for 10 seconds
    smashDI();      //smash di macro
    icDysyncJump(); //causes popo to only jump
    wobble();       //hits A at 200bpm(ish) while moving the stick in the tapped direction
  */
} //more mods to come!

void perfectangles() {
  if (axm > 75) {
    gcc.xAxis = (ax > 0) ? 204 + (3 * dolphin) : 50 - (3 * dolphin);
    if (aym < 25)
      gcc.yAxis = (ay > 0) ? 151 + (1 * dolphin) : 105 - (1 * dolphin);
  }
  if (aym > 75) {
    gcc.yAxis = (ay > 0) ? 204 + (3 * dolphin) : 50 - (3 * dolphin);
    if (axm < 23)
      gcc.xAxis = (ax > 0) ? 151 + (1 * dolphin) : 105 - (1 * dolphin);
  }
}

void maxvectors() {
  if (axm > 75 && aym < 5) {
    gcc.xAxis  = (ax > 0) ? 255 : 1;
    gcc.yAxis  = 128;
  }
  if (aym > 75 && axm < 9) {
    gcc.yAxis  = (ay > 0) ? 255 : 1;
    gcc.xAxis  = 128;
  }
  if (cxm > 75 && cym < 23) {
    gcc.cxAxis = (cx > 0) ? 255 : 1;
    gcc.cyAxis = 128;
  }
  if (cym > 75 && cxm < 23) {
    gcc.cyAxis = (cy > 0) ? 255 : 1;
    gcc.cxAxis = 128;
  }
}


void backdash() {
  if (aym < 23) {
    if (axm < 23)buf = cycles;
    if (buf > 0) {
      buf--;
      if (axm < 64) gcc.xAxis = 128 + ax * (axm < 23);
    }
  } else buf = 0;
}

void dolphinfix() {
  if (axm < 5 && aym < 5) {
    gcc.xAxis  = 128;
    gcc.yAxis  = 128;
  }
  if (cxm < 5 && cym < 5) {
    gcc.cxAxis = 128;
    gcc.cyAxis = 128;
  }
  if (gcc.dright && mode < 2500) {
    dolphin = dolphin || (mode++ > 2000);
  }
  else mode = 0;
  cycles = 3 + (6 * dolphin);
}

void smashDI() {


  if (gcc.y) {

    //up
    if (gcc.xAxis > 65 && gcc.xAxis < 200 && gcc.yAxis > 200) {
      if (millis() - last_t < 4) {
        gcc.xAxis = 215;
        gcc.yAxis = 180;
      } else if (millis() - last_t < 7) {
        gcc.xAxis = 170;
        gcc.yAxis = 220;
      } else if (millis() - last_t < 10) {
        gcc.xAxis = 90;
        gcc.yAxis = 220;
      } else if (millis() - last_t < 14) {
        gcc.xAxis = 50;
        gcc.yAxis = 180;
        last_t = millis();
      } else {
        last_t = millis();
      }

    } else if (gcc.xAxis > 65 && gcc.xAxis < 200 && gcc.yAxis < 65) {

      //down
      if (millis() - last_t < 4) {
        gcc.xAxis = 215;
        gcc.yAxis = 100;
      } else if (millis() - last_t < 7) {
        gcc.xAxis = 170;
        gcc.yAxis = 50;
      } else if (millis() - last_t < 10) {
        gcc.xAxis = 90;
        gcc.yAxis = 50;
      } else if (millis() - last_t < 14) {
        gcc.xAxis = 50;
        gcc.yAxis = 100;
        last_t = millis();
      } else {
        last_t = millis();
      }


    } else if (gcc.xAxis < 65) {

      //left
      if (millis() - last_t < 4) {
        gcc.xAxis = 90;
        gcc.yAxis = 180;
      } else if (millis() - last_t < 7) {
        gcc.xAxis = 50;
        gcc.yAxis = 165;
      } else if (millis() - last_t < 10) {
        gcc.xAxis = 50;
        gcc.yAxis = 100;
      } else if (millis() - last_t < 14) {
        gcc.xAxis = 90;
        gcc.yAxis = 50;
        last_t = millis();
      } else {
        last_t = millis();
      }

    } else if (gcc.xAxis > 200) {

      //right
      if (millis() - last_t < 4) {
        gcc.xAxis = 170;
        gcc.yAxis = 180;
      } else if (millis() - last_t < 7) {
        gcc.xAxis = 200;
        gcc.yAxis = 180;
      } else if (millis() - last_t < 10) {
        gcc.xAxis = 215;
        gcc.yAxis = 95;
      } else if (millis() - last_t < 14) {
        gcc.xAxis = 170;
        gcc.yAxis = 50;
        last_t = millis();
      } else {
        last_t = millis();
      }
    }
  }
  gcc.y = 0;

}



void icDysyncJump() {
  if (gcc.y) {
    gcc.yAxis = 185;
    gcc.xAxis = 128;
    gcc.y = 0;
  }
}


void wobble() {
  if (gcc.y) {
    if (wobbleState) {
      wobbleState = 0;
      delay(100);
    }

    else if (!wobbleState) {
      wobbleState = 1;
      delay(100);
    }
  } else {

    if (millis() - last_t < 40 && wobbleState) {
      gcc.a = 0;
      gcc.b = 0;
      gcc.x = 0;
      gcc.z = 0;
    } else if (millis() - last_t < 55 && wobbleState) {
      gcc.a = 1;
      gcc.b = 0;
      gcc.x = 0;
      gcc.z = 0;
    } else {
      last_t = millis();
    }
    //right
    if (wobbleState) {
      if (gcc.xAxis > 135 && last_x == 128)
        last_x = 136;
      if (last_x > 135 && last_x < 255 )
        last_x++;
      if (last_x != 128)
        gcc.xAxis = last_x;


      //left
      if (gcc.xAxis < 120 && last_x == 128)
        last_x = 110;
      if (last_x > 0 && last_x < 121)
        last_x--;
      if (last_x != 128)
        gcc.xAxis = last_x;
    } else {
      last_x = 128;
    }

  }
  gcc.y = 0;
}


void profileSwitcher() {
  if (gcc.ddown) {

    if (gcc.a && set == 0)                      //set to default "nocode"
    {
      profile = 1;
      set = 1;
    }
    if (gcc.b && set == 0)                      //set to normal "hax" code   (b)
    {
      profile = 2;
      set = 1;
    }
    if (gcc.x && set == 0)                      //set to "push" for testing  (x)
    {
      profile = 3;
      set = 1;
    }
    if (gcc.z && set == 0)                      //set to "lulz" for smashdi  (x)
    {
      profile = 3;
      set = 1;
    }


    gcc.x = 0;
    gcc.y = 0;
    gcc.a = 0;
    gcc.b = 0;
    gcc.ddown = 0;
    if (n == 0)
      n = millis();

    gcc.ddown = (millis() - n > 300);
  } else if (gcc.dright) {
    if (gcc.a && set == 0)    //turns on dolphin mode for backdash
    {
      dolphin = 0;
      set = 1;
    }
    if (gcc.b && set == 0)   //turns off dolphin mode for backdash
    {
      dolphin = 1;
      set = 1;
    }

    gcc.x = 0;
    gcc.y = 0;
    gcc.a = 0;
    gcc.b = 0;
    gcc.dright = 0;

    gcc.dright = (millis() - n > 300);

  } else {
    set = 0;
    n = 0;
  }
}


void shieldDrop() {
  shield = gcc.l || gcc.r || gcc.left > 74 || gcc.right > 74 || gcc.z;
  if (shield) {
    if (ay < 0 && mag(ax, ay) > 75) {

      if (ax < 0 && ang(axm, aym) > 35 && ang(axm, aym) < 55) {
        gcc.yAxis = 73 - (3 * dolphin);
        gcc.xAxis =  73;
        //Serial.println(mag(ax, ay));
      }
      if (ax > 0 && ang(axm, aym) > 35 && ang(axm, aym) < 55) {
        gcc.yAxis = 73 - (3 * dolphin);
        gcc.xAxis = 183;
        //Serial.println(mag(ax, ay));
        //Serial.println("SE");
      }
    }
  }
}


void lCancel() {
  if (gcc.l) {
    gcc.l = 0;

    if (millis() - last_l < 4)
      gcc.left = 75;
    if (millis() - last_l >= 4) {
      gcc.left = 0;
      last_l = millis();
    }
  }
}



float ang(float xval, float yval) {
  return atan(yval / xval) * 57.2958; //function to return angle in degrees when given x and y components
}
float mag(char  xval, char  yval) {
  return sqrt(sq(xval) + sq(yval)); //function to return vector magnitude when given x and y components
}

void setup() {
  gcc.origin = 0; gcc.errlatch = 0; gcc.high1 = 0; gcc.errstat = 0; profile = 1; //init values
  
 // Serial.begin(9600);

  pinMode(nRed_led, OUTPUT); pinMode(nGreen_led, OUTPUT); pinMode(nBlu_led, OUTPUT);
  pinMode(eRed_led, OUTPUT); pinMode(eGreen_led, OUTPUT); pinMode(eBlu_led, OUTPUT);
  pinMode(sRed_led, OUTPUT); pinMode(sGreen_led, OUTPUT); pinMode(sBlu_led, OUTPUT);
  pinMode(wRed_led, OUTPUT); pinMode(wGreen_led, OUTPUT); pinMode(wBlu_led, OUTPUT);
}

void loop() {
  controller.read();
  gcc = controller.getReport();
  ax = gcc.xAxis - 128; ay = gcc.yAxis - 128; //offsets from nuetral position of analog stick
  cx = gcc.cxAxis - 128; cy = gcc.cyAxis - 128; //offsets from nuetral position of c stick
  axm = abs(ax); aym = abs(ay);             //magnitude of analog stick offsets
  cxm = abs(cx); cym = abs(cy);             //magnitude of c stick offsets
  profileSwitcher();

  //picks colors
  led();

  //Serial.println(profile);
  if (!off) convertinputs();                //implements all the fixes (remove this line to unmod the controller)

  //sends chosen colors
  outputPin();
  console.write(gcc);                       //sends controller data to the console

}
