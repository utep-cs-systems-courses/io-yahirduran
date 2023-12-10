
#include "led.h"
#include "buzzer.h"
#include <msp430.h>
#include <stddef.h>
void advance_DS(){
  static int blinkCount = 0;
  static int blinkLimit = 0;
  static int secondCount = 0;
  static int blinkLimit2 = 8;
  static int blinkCount2 = 0;
  blinkCount ++;
  blinkCount2 ++;
  if (blinkCount >= blinkLimit) {
    blinkCount = 0;
    P1OUT |= LED_GREEN;
  } else {
    P1OUT &= ~LED_GREEN;
  }
  if (blinkCount2 >= blinkLimit2) {
    blinkCount2 = 0;
    P1OUT |= LED_RED;
  } else {
    P1OUT &= ~LED_RED;
  }
  secondCount ++;
  if (secondCount >= 250) {
    secondCount = 0;
    blinkLimit ++;
    blinkLimit2 --;
    if (blinkLimit >= 8)
      blinkLimit = 0;
    if (blinkLimit2 <= 0)
      blinkLimit2 = 8;
  }  
}
void stop_DS(){
  toggle_red(0);
  toggle_green(0);
  buzzer_set_period(0);
}
