#pragma once

#ifndef _SENSORS_H
#define _SENSORS_H

#include <Arduino.h>

#define FRONT_SENSOR A10
#define BACK_SENSOR A11
#define LEFT_SENSOR A8
#define RIGHT_SENSOR A9

void initSensors()
{
    pinMode(FRONT_SENSOR, INPUT);
    pinMode(BACK_SENSOR, INPUT);
    pinMode(LEFT_SENSOR, INPUT);
    pinMode(RIGHT_SENSOR, INPUT);
}

void printSensorVals()
{
    Serial.print(analogRead(FRONT_SENSOR));
    Serial.print(" ");
    Serial.print(analogRead(BACK_SENSOR));
    Serial.print(" ");
    Serial.print(analogRead(LEFT_SENSOR));
    Serial.print(" ");
    Serial.println(analogRead(RIGHT_SENSOR));
}

#endif //_SENSORS_H