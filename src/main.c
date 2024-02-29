// #include <stdio.h>

#include "motor.h"

int main() {
    struct state_machine_t state_machine;
    state_machine.current_state = MOTOR_OFF;

    enum event_t event_q[] = {E_START, E_STOP, E_START, E_LOW_BATTERY, E_DONT_CARE};

    for (int i=0;i<sizeof(event_q)/sizeof(event_q[0]);i++) {
        run_state_machine(&state_machine, event_q[i]);
    }

    return 0;
}
