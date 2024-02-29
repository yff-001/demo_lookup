#ifndef MOTOR_H
#define MOTOR_H

enum state_t {
    MOTOR_ON,
    MOTOR_OFF,
    MOTOR_DECELERATE
};

enum event_t {
    E_START,
    E_STOP,
    E_LOW_BATTERY,
    E_DONT_CARE
};

struct state_machine_t {
    enum state_t current_state;
};

void act_motor_start();
void act_motor_stop();
void act_motor_decelerate();
void run_state_machine(struct state_machine_t* state_machine, enum event_t event);

#endif
