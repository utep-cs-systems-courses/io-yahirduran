#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "StateMachine.h"

void main(){
  configureClocks();    /* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();    /* enable periodic interrups */
  switch_init();
  led_init();
  buzzer_init();

  or_sr(0x18); // CPU off, GIE on
}

/* Switch on P2 */
void __interrupt_vec(PORT2_VECTOR) Port_2() {
  if (P2IFG & SWITCHES) {    /* did a button cause this interrupt? */
    P2IFG &= ~SWITCHES;    /* clear pending sw interrupts */
    switch_interrupt_handler();    /* single handler for all switches */
  }
}

/* 250 interrupts per second */
void __interrupt_vec(WDT_VECTOR) WDT() {
  advance_state();
}
