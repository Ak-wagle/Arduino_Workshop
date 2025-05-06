#include "LedControlMS.h"   // library is available here https://github.com/shaai/Arduino_LED_matrix_sketch
 
#define NBR_MTX 1

LedControl lc=LedControl(12,11, 10, NBR_MTX);   
 
//5v, GND, 10 - CS, 11 - CLK, 12 - DIN

void setup(){
  for (int i=0; i< NBR_MTX; i++)
  {
    lc.shutdown(i,false);
    lc.setIntensity(i,8);
    lc.clearDisplay(i);
    delay(500);
  }
}
 
void loop(){
     lc.writeString(0,"WAGLE");     //send characters to display
     lc.clearAll();                           //clear the display
     delay(1000);
}