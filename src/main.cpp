#include <Arduino.h>
#include "Sensors.h"
#include "Motors.h"
#include "LineFollow.h"
#include "ServoControl.h"
#include "Encoders.h"

#include "blue/blue1.h"
#include "blue/blue2.h"
#include "blue/blue3.h"
#include "blue/blue11.h"

void setup()
{
    Serial.begin(9600);
    initEncoders();
    initSensors();
    initMotors();
    initServos();

    Serial.println("Code Running...");
    // moveServo(FRONT_SERVO, 0);
    // moveServo(LEFT_SERVO, 0);
    // moveServo(RIGHT_SERVO, 0);

    // rigthTurnEncoder(780);
    // leftTurnEncoder(780);

    blue3();
}

void loop()
{
    // lineFollowV3('r', 120);
    // sendCommand("FL LT OPEN");
    // delay(1000);
    // sendCommand("FL LT CLOSE");
    // delay(1000);
    printSensorVals(frontSensors);
    // printEncoders();
    // lineFollow('f'); // 'f' for front, 'b' for back, 'l' for left, 'r' for right
    // lineFollowV2('f'); // 'f' for front, 'b' for back, 'l' for left, 'r' for right
    delay(100);
}