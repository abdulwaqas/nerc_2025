#include <Arduino.h>
#include "Sensors.h"
#include "Motors.h"
#include "LineFollow.h"
#include "ServoControl.h"
#include "Encoders.h"

void setup()
{
    Serial.begin(9600);
    initEncoders();
    initSensors();
    initMotors();
    initServos();

    Serial.println("Code Running...");

    backward(80, 80);
    stripCountStraight(1);
    backward();
    stripCountStraight(2);
    backward(80, 80);
    stripCountStraight(1);
    halt();
    delay(1000);
    right(80, 80);
    delay(500);
    stripCountGay(4);
    halt();
    delay(500);
    backward();
    encoderMove(200);
    delay(100);
    moveServo(LEFT_SERVO, 0);
    delay(500);
    linefollowFront();
    encoderMove(500);
    delay(500);
    moveServo(LEFT_SERVO, 90);
    delay(1000);
}

void loop()
{
    // linefollowFront();
    // linefollowLeft();
    // printSensorVals();
    // printEncoders();
    // delay(100);
}