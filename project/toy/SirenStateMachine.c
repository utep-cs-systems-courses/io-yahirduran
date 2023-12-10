#include "led.h"
#include "buzzer.h"
#include <msp430.h>

static unsigned int  count = 0;
void advance_siren(){

  if(count < 125){
    toggle_green(0);
    toggle_red(1);
    siren_sound();
  } else if(count < 250){
    toggle_green(1);
    toggle_red(0);
    siren_sound();
  } else count = 0;
  count++;
}

void siren_sound(){
  if(count <125){
    buzzer_set_period(250);
  } else if(count < 250){
    buzzer_set_period(1000);
  }
  // AssemblySirenSound(count);
}
void stop_siren(){
  toggle_green(0);
  toggle_red(0);
  buzzer_set_period(0);

}
