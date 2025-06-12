#pragma once

#ifndef _SERVOCONTROL_H_
#define _SERVOCONTROL_H_

#include <Arduino.h>
#include <Wire.h>

#define FRONT_SERVO "FT"
#define LEFT_SERVO "LT"
#define RIGHT_SERVO "RT"

void initServos() {
    Wire.begin();
}

void moveServo(String servo, int pos) {
    Serial.println(servo);
    Wire.beginTransmission(4); // transmit to device #4
    Wire.write((servo + " ").c_str());       // sends five bytes
    Wire.write(pos);             // sends one byte
    Wire.write('\n');
    Wire.endTransmission();    // stop transmitting
}

#endif //_SERVOCONTROL_H_