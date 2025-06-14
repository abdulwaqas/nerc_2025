#pragma once

#ifndef _SERVOCONTROL_H_
#define _SERVOCONTROL_H_

#include <Arduino.h>
#include <Wire.h>

#define FRONT_SERVO "FT"
#define LEFT_SERVO "LT"
#define RIGHT_SERVO "RT"
#define BASE_SERVO "BS"

void initServos() {
    Wire.begin();
}

void moveServo(String servo, int pos) {
    Wire.beginTransmission(4); // transmit to device #4
    Wire.write((servo + " " + String(pos)).c_str());       // sends five bytes
    Wire.endTransmission();    // stop transmitting
}

#endif //_SERVOCONTROL_H_