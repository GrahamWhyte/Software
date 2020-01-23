//
// Created by graham on 2019-11-16.
//

#ifndef SRC_MOTORS_H
#define SRC_MOTORS_H

#include "stm32h7xx_hal.h"
#include "main.h"

TIM_HandleTypeDef htim4;

typedef struct {

    // THESE SHOULD NOT BE INTS BUT WE NEED TO MAKE A TYPES LIBRARY OR SEE IF IT'S IN THE STM LIB
    unsigned int id, pwmVal;
    GPIO_PinState brake, coast;
    // ToDo: Add variables for status of motor from encoders

}MotorDriver;

// Motor functions
void Motor_SetID(MotorDriver*, unsigned int);
void Motor_SetSpeed(MotorDriver*, unsigned int);
void Motor_ToggleBrake(MotorDriver*);
void Motor_ToggleCoast(MotorDriver*);
void Motor_Drive(MotorDriver*);

#endif //SRC_MOTORS_H
