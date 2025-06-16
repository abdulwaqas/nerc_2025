#pragma once

#ifndef _SERVOCONTROL_H_
#define _SERVOCONTROL_H_

#include <Arduino.h>
#include <Wire.h>

#define BASE_000 10  // LEFT AT FRONT
#define BASE_090 70  // CENTER AT FRONT
#define BASE_180 135 // RIGHT AT FRONT

#define FRONT_SERVO "FT"
#define LEFT_SERVO "LT"
#define RIGHT_SERVO "RT"
#define BASE_SERVO "BS"

void initServos()
{
    Wire.begin();
}

void sendCommand(String cmd)
{
    Wire.beginTransmission(4);
    Wire.write(cmd.c_str());
    Wire.endTransmission();
}

void moveServo(String servo, int pos)
{
    sendCommand(servo + " " + String(pos));
}

#endif //_SERVOCONTROL_H_