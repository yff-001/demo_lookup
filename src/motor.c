#include <stdio.h>

#include "motor.h"

struct transition_t {
    enum state_t current_state;
    enum event_t event;
    enum state_t next_state;
    void (*action_function)(void);
};

static struct transition_t transition_matrix[] = {
    {MOTOR_OFF, E_START, MOTOR_ON, &act_motor_start},
    {MOTOR_ON, E_STOP, MOTOR_OFF, &act_motor_stop},
    {MOTOR_ON, E_LOW_BATTERY, MOTOR_DECELERATE, &act_motor_decelerate},
    {MOTOR_DECELERATE, E_DONT_CARE, MOTOR_OFF, &act_motor_stop}
};

void act_motor_start() {
    printf("motor start ...\r\n");
}

void act_motor_stop() {
    printf("motor stop ...\r\n");
}

void act_motor_decelerate() {
    printf("motor decelerate ...\r\n");
}

void run_state_machine(struct state_machine_t* state_machine, enum event_t event) {
    for (int i=0;i<sizeof(transition_matrix)/sizeof(transition_matrix[0]);i++) {
        if (transition_matrix[i].current_state == state_machine -> current_state) {
            if (transition_matrix[i].event == event) {
                (transition_matrix[i].action_function)();
                state_machine->current_state = transition_matrix[i].next_state;
                break;
            }
        }
    }
}
