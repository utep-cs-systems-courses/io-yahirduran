#include "led.h"
#include "buzzer.h"
#include <msp430.h>

void advance_BTD(){
  static int blinkLimit = 0;
  static int blinkCount = 0;
  static int secondCount = 0;
  static int period = 200;
  blinkCount++;

  if(blinkCount >= blinkLimit){
    blinkCount = 0;
    toggle_red(1);
    toggle_green(1);
  } else {
    toggle_red(0);
    toggle_green(0);
  }
  buzzer_set_period(period);
  secondCount++;
  if(secondCount >= 250){
    secondCount = 0;
    blinkLimit++;
    period +=100;
  }
  if(blinkLimit >= 8){
    blinkLimit = 0;
    period = 200;
  }
}  
void stop_BTD(){
  toggle_green(0);
  toggle_red(0);
  buzzer_set_period(0);
}
