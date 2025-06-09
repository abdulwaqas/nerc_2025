#pragma once

#ifndef _SENSORS_H
#define _SENSORS_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_ADS1X15.h>

typedef struct
{
    uint8_t channel;
    int16_t value;
} Sensor;

MbedI2C newWire(26, 27);
Adafruit_ADS1115 ads; /* Use this for the 16-bit version */

Sensor FRONT = {channel : 2, value : 0};
Sensor BACK = {channel : 3, value : 0};
Sensor LEFT = {channel : 0, value : 0};
Sensor RIGHT = {channel : 1, value : 0};

void initSensors()
{
    newWire.begin();

    if (!ads.begin(72, &newWire))
    {
        Serial.println("Failed to initialize ADS.");
        while (1)
        {
        }
    }

    ads.setDataRate(860);
}

int16_t readSingleSensor(uint8_t channel) {
    return ads.readADC_SingleEnded(channel);
}

void readSensors()
{
    FRONT.value = ads.readADC_SingleEnded(FRONT.channel);
    BACK.value = ads.readADC_SingleEnded(BACK.channel);
    LEFT.value = ads.readADC_SingleEnded(LEFT.channel);
    RIGHT.value = ads.readADC_SingleEnded(RIGHT.channel);
}

void printSensorVals()
{
    readSensors();
    Serial.print(FRONT.value);
    Serial.print(" ");
    Serial.print(BACK.value);
    Serial.print(" ");
    Serial.print(LEFT.value);
    Serial.print(" ");
    Serial.println(RIGHT.value);
}

#endif //_SENSORS_H