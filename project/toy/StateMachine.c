#include <msp430.h>
#include "StateMachine.h"
#include "SirenStateMachine.h"
#include "BrightToDim.h"
#include "DimToBright.h"
#include "DifferentSirenSM.h"

static State current_state;

void set_state(State state){
  switch(state){

  case SIREN:
    stop_BTD();
    stop_DTB();
    stop_DS();
    break;
  
  case BRIGHTTODIM:
    stop_siren();
    stop_DTB();
    stop_DS();
    break;

  case DIMTOBRIGHT:
    stop_siren();
    stop_BTD();
    stop_DS();
    break;
  case DIFFERENTSIREN:
    stop_siren();
    stop_BTD();
    stop_DTB();
    break;
  }
  current_state = state;
} 

void advance_state(){
  switch(current_state){
  case SIREN:
    advance_siren();
    break;
  case BRIGHTTODIM:
    advance_BTD();
    break;
  case DIMTOBRIGHT:
    advance_DTB();
    break;
  case DIFFERENTSIREN:
    advance_DS();
    break;
  }
}
