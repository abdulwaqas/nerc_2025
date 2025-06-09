#include <Arduino.h>
#include "Sensors.h"
#include "Motors.h"

void setup()
{
    Serial.begin(115200);
    initSensors();
    initMotors();
    delay(1000);
    Serial.println("Code Running...");

    forward();
    stripCountStraight(3);
    delay(1000);
    right();
    stripCountGay(3);
    delay(1000);
    backward();
    stripCountStraight(3);
    delay(1000);
    left();
    stripCountGay(3);
    delay(1000);
}

void loop()
{
    // printSensorVals();
    // delay(100);
    // forward();
}