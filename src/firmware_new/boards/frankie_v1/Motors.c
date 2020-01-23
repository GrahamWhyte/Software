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

void Motor_ToggleBrake(MotorDriver *motor)
{
    // Record the current state of the pin
    // The assumption is that software will use the last recorded state of the pin to decide whether to brake
    motor->brake = HAL_GPIO_ReadPin(GPIOG, Brake_Pin);

    // Toggle the pin
    HAL_GPIO_TogglePin(GPIOG, Brake_Pin);

}

void Motor_ToggleCoast(MotorDriver *motor)
{
    // Record the current state of the pin
    // The assumption is that software will use the last recorded state of the pin to decide whether to coast
    motor->coast = HAL_GPIO_ReadPin(GPIOG, Coast_Pin);

    // Toggle the pin
    HAL_GPIO_TogglePin(GPIOG, Coast_Pin);
}


void Motor_Drive(MotorDriver *motor)
{

    TIM_OC_InitTypeDef sConfigOC;

    unsigned int channel = 0;

    // This is kinda jank but will work for now
    // Send PWM signal to proper channel
    if (motor->id == 1)
    {
        channel = TIM_CHANNEL_1;
    }
    else if (motor->id == 2)
    {
        channel = TIM_CHANNEL_2;
    }
    else if (motor->id == 3)
    {
        channel = TIM_CHANNEL_3;
    }
    else if (motor->id == 4)
    {
        channel = TIM_CHANNEL_4;
    }

    // Populate PWM config struct
    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = motor->pwmVal;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;

    // Start the PWM
    HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, channel);
    HAL_TIM_PWM_Start(&htim4, channel);
}










