#include <Arduino.h>
#include "Sensors.h"
#include "Motors.h"
#include "LineFollow.h"

void setup()
{
    Serial.begin(115200);
    initSensors();
    initMotors();
    Serial.println("Code Running...");

    // forward();
    // stripCountStraight(3);
    // delay(1000);
    // right();
    // stripCountGay(3);
    // delay(1000);
    // backward();
    // stripCountStraight(3);
    // delay(1000);
    // left();
    // stripCountGay(3);
    // delay(1000);
}

void loop()
{
    // right(80, 80);
    // left(80, 85);
    linefollowFront();
    // linefollowLeft();
    // printSensorVals();
    // delay(100);
    // forward();
}