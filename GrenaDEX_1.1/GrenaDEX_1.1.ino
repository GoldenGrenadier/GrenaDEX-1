#include <Bounce.h>
//#include "xinput.h"

Bounce A_button = Bounce(0, 10);
Bounce B_button = Bounce(1, 10);  // 10 = 10 ms debounce time
Bounce C_button = Bounce(2, 10);  // which is appropriate for
Bounce X_button = Bounce(3, 10);  // most mechanical pushbuttons
Bounce Y_button = Bounce(4, 10);
Bounce Z_button = Bounce(5, 10);
Bounce start_button = Bounce(6, 10);
Bounce select_button = Bounce(7, 10);
Bounce home_button = Bounce(8, 10);
Bounce dpad_up = Bounce (23, 10);
Bounce dpad_down = Bounce (22, 10);
Bounce dpad_left = Bounce (21, 10);
Bounce dpad_right = Bounce (20, 10);
int axisY = A2; // this is the raw value the potentiometer gives
int axisYvalue ;// this is the value that is sent to the OS
int axisX = A1;
int axisXvalue ;

void setup() {
  Joystick.useManualSend(true);
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP); 
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  Joystick.hat(-1);// makes the hat switch behave itself


}

void loop() {
  A_button.update();
  B_button.update();
  C_button.update();
  X_button.update();
  Y_button.update();
  Z_button.update();
  start_button.update();
  select_button.update();
  home_button.update();
   
  
  Joystick.Zrotate(512);
  Joystick.Z(512);
  Joystick.sliderLeft(512);
  Joystick.sliderRight(512);
  Joystick.Y (axisYvalue = (((analogRead(axisY) - 90) * 1024) / 875) + 10);  
  
  Joystick.X (axisXvalue = (((analogRead(axisX) - 126) * 1024) / 890) + 10);
  
  if (A_button.fallingEdge()) {
    Joystick.button(1, 1); 
  }
  if (B_button.fallingEdge()) {
    Joystick.button(2, 1);  
  }
  if (C_button.fallingEdge()) {
    Joystick.button(3, 1);
  }
  if (X_button.fallingEdge()) {
    Joystick.button(4, 1);
  }
  if (Y_button.fallingEdge()) {
    Joystick.button(5, 1);
  }
  if (Z_button.fallingEdge()) {
    Joystick.button(6, 1);
  }
  if (start_button.fallingEdge()) {
    Joystick.button(7, 1);
  }
  if (select_button.fallingEdge()) {
    Joystick.button(8, 1);
  }
  if (home_button.fallingEdge()) {
    Joystick.button(9, 1);
  }
  
  

 //Checking to see if buttons are released
  if (A_button.risingEdge()) {
    Joystick.button(1,0);  
  }
  if (B_button.risingEdge()) {
    Joystick.button(2, 0);
  }
  if (C_button.risingEdge()) {
    Joystick.button(3, 0);
  }
  if (X_button.risingEdge()) {
    Joystick.button(4, 0);
  }
  if (Y_button.risingEdge()) {
    Joystick.button(5, 0);
  }
  if (Z_button.risingEdge()) {
    Joystick.button(6, 0);
  }
  if (start_button.risingEdge()) {
    Joystick.button(7, 0);
  }
  if (select_button.risingEdge()) {
    Joystick.button(8, 0);
  }
  if (home_button.risingEdge()) {
    Joystick.button(9, 0);
  }
  Joystick.send_now();
 
}

