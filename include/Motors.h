#pragma once

#ifndef _MOTORS_H_
#define _MOTORS_H_

#include <Arduino.h>
#include "Sensors.h"
#include "Encoders.h"

typedef struct
{
    uint8_t fwd_pin;
    uint8_t rev_pin;
} Motor;

Motor FL = {fwd_pin : 10, rev_pin : 12};
Motor FR = {fwd_pin : 4, rev_pin : 5};
Motor RL = {fwd_pin : 6, rev_pin : 7};
Motor RR = {fwd_pin : 9, rev_pin : 8};

bool prevLine = false;

unsigned long previousMillis = 0; // Store the last time sensor was checked
const unsigned long intervalMillis = 300;

void initMotors()
{
    pinMode(FL.fwd_pin, OUTPUT);
    pinMode(FL.rev_pin, OUTPUT);
    pinMode(FR.fwd_pin, OUTPUT);
    pinMode(FR.rev_pin, OUTPUT);
    pinMode(RL.fwd_pin, OUTPUT);
    pinMode(RL.rev_pin, OUTPUT);
    pinMode(RR.fwd_pin, OUTPUT);
    pinMode(RR.rev_pin, OUTPUT);
}

void moveOneMotor(Motor &motor, int speed)
{
    analogWrite(motor.fwd_pin, speed);
    analogWrite(motor.rev_pin, 0);
}

void forward(int leftSpeed = 150, int rightSpeed = 150)
{
    analogWrite(FL.fwd_pin, leftSpeed);
    analogWrite(FL.rev_pin, 0);

    analogWrite(FR.fwd_pin, rightSpeed);
    analogWrite(FR.rev_pin, 0);

    analogWrite(RL.fwd_pin, leftSpeed);
    analogWrite(RL.rev_pin, 0);

    analogWrite(RR.fwd_pin, rightSpeed);
    analogWrite(RR.rev_pin, 0);
}

void backward(int leftSpeed = 150, int rightSpeed = 150)
{
    analogWrite(FL.fwd_pin, 0);
    analogWrite(FL.rev_pin, leftSpeed);

    analogWrite(FR.fwd_pin, 0);
    analogWrite(FR.rev_pin, rightSpeed);

    analogWrite(RL.fwd_pin, 0);
    analogWrite(RL.rev_pin, leftSpeed);

    analogWrite(RR.fwd_pin, 0);
    analogWrite(RR.rev_pin, rightSpeed);
}

void right(int leftSpeed = 150, int rightSpeed = 150)
{
    analogWrite(FL.fwd_pin, leftSpeed);
    analogWrite(FL.rev_pin, 0);

    analogWrite(FR.fwd_pin, 0);
    analogWrite(FR.rev_pin, rightSpeed);

    analogWrite(RL.fwd_pin, 0);
    analogWrite(RL.rev_pin, leftSpeed);

    analogWrite(RR.fwd_pin, rightSpeed);
    analogWrite(RR.rev_pin, 0);
}

void rightInverse(int leftSpeed = 150, int rightSpeed = 150)
{
    analogWrite(FL.fwd_pin, leftSpeed);
    analogWrite(FL.rev_pin, 0);

    analogWrite(FR.fwd_pin, 0);
    analogWrite(FR.rev_pin, rightSpeed);

    analogWrite(RL.fwd_pin, leftSpeed);
    analogWrite(RL.rev_pin, 0);

    analogWrite(RR.fwd_pin, 0);
    analogWrite(RR.rev_pin, rightSpeed);
}

void rightFreeze(int leftSpeed = 0, int rightSpeed = 150)
{
    analogWrite(FL.fwd_pin, leftSpeed);
    analogWrite(FL.rev_pin, 0);

    analogWrite(FR.fwd_pin, 0);
    analogWrite(FR.rev_pin, rightSpeed);

    analogWrite(RL.fwd_pin, leftSpeed);
    analogWrite(RL.rev_pin, 0);

    analogWrite(RR.fwd_pin, 0);
    analogWrite(RR.rev_pin, rightSpeed);
}

void left(int leftSpeed = 150, int rightSpeed = 150)
{
    analogWrite(FL.fwd_pin, 0);
    analogWrite(FL.rev_pin, leftSpeed);

    analogWrite(FR.fwd_pin, rightSpeed);
    analogWrite(FR.rev_pin, 0);

    analogWrite(RL.fwd_pin, leftSpeed);
    analogWrite(RL.rev_pin, 0);

    analogWrite(RR.fwd_pin, 0);
    analogWrite(RR.rev_pin, rightSpeed);
}

void leftInverse(int leftSpeed = 150, int rightSpeed = 150)
{
    analogWrite(FL.fwd_pin, 0);
    analogWrite(FL.rev_pin, leftSpeed);

    analogWrite(FR.fwd_pin, rightSpeed);
    analogWrite(FR.rev_pin, 0);

    analogWrite(RL.fwd_pin, 0);
    analogWrite(RL.rev_pin, leftSpeed);

    analogWrite(RR.fwd_pin, rightSpeed);
    analogWrite(RR.rev_pin, 0);
}

void leftFreeze(int leftSpeed = 150, int rightSpeed = 0)
{
    analogWrite(FL.fwd_pin, 0);
    analogWrite(FL.rev_pin, leftSpeed);

    analogWrite(FR.fwd_pin, rightSpeed);
    analogWrite(FR.rev_pin, 0);

    analogWrite(RL.fwd_pin, 0);
    analogWrite(RL.rev_pin, leftSpeed);

    analogWrite(RR.fwd_pin, rightSpeed);
    analogWrite(RR.rev_pin, 0);
}

void halt()
{
    noInterrupts();
    analogWrite(FL.fwd_pin, 0);
    analogWrite(FL.rev_pin, 0);

    analogWrite(FR.fwd_pin, 0);
    analogWrite(FR.rev_pin, 0);

    analogWrite(RL.fwd_pin, 0);
    analogWrite(RL.rev_pin, 0);

    analogWrite(RR.fwd_pin, 0);
    analogWrite(RR.rev_pin, 0);
    interrupts();
}

void leftTurnEncoder(uint32_t ticksToMove)
{
    flEncoder.ticks = 0; 
    while (flEncoder.ticks < ticksToMove)
    {
        leftInverse();  
        interrupts();   
    }
    halt();
}

void rigthTurnEncoder(uint32_t ticksToMove)
{
    flEncoder.ticks = 0;  
    while (flEncoder.ticks < ticksToMove)
    {
        rightInverse();  
        interrupts();       
    }
    halt();
}

void encoderMove(uint32_t ticksToMove)
{
    flEncoder.ticks = 0;
    while (flEncoder.ticks < ticksToMove)
    {
        Serial.print("");
        // printEncoders();
        // delay(1);
    }
    halt();
}

#endif //_MOTORS_H