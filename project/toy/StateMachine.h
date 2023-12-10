#ifndef stateMachine_included
#define stateMachine_included

typedef enum{
  SIREN = 1,
  BRIGHTTODIM = 2,
  DIMTOBRIGHT = 3,
  DIFFERENTSIREN = 4
} State;

void set_state(State state);
void advance_state();

#endif
