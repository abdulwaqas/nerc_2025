#include <Arduino.h>
#include "Sensors.h"
#include "Motors.h"
#include "LineFollow.h"
#include "ServoControl.h"

void setup()
{
    Serial.begin(9600);
    initSensors();
    initMotors();
    initServos();

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
    // forward();
    // right(80, 80);
    // left(80, 85);
    // linefollowFront();
    // linefollowLeft();
    // printSensorVals();
    // delay(100);
}