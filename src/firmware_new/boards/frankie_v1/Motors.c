//
// Created by graham on 2019-11-16.
//

#include "Motors.h"


// Set the ID of the motor
void Motor_SetID(MotorDriver *motor, unsigned int motorID)
{
    motor->id = motorID;
}

// Set the speed of the motor
// ToDo: Duty cycle conversion within this function
void Motor_SetSpeed(MotorDriver *motor, unsigned int speed)
{
    motor->pwmVal = speed;
}

void Motor_SetBrake(MotorDriver *motor)
{
    // Write to brake pin
    // Figure out a way to abstract this (Probably just HAL lib call)
    if (!motor->brake)
        motor->brake = 1;

    // I guess write to Hal here
}

void Motor_SetCoast(MotorDriver *motor)
{
    // Write to coast pin
    // Figure out a way to abstract this (Probably just HAL lib call)
    if (!motor->coast)
        motor->coast = 1;           // Holy crap

    // I guess write to Hal here + figure out where pins are defined
//    HAL_GPIO_WritePin();
}

void Motor_Drive(MotorDriver *motor)
{
    unsigned int channel = 0;

    // This is kinda jank but will work for now

    if (motor->id == 1)
        channel = TIM_CHANNEL_1;
    else if (motor->id == 2)
        channel = TIM_CHANNEL_2;
    else if (motor->id == 3)
        channel = TIM_CHANNEL_3;
    else if (motor->id == 4)
        channel = TIM_CHANNEL_4;

    HAL_TIM_PWM_Start(&htim4, channel);
}










