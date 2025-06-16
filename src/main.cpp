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
    // moveServo(FRONT_SERVO, 0);
    // moveServo(LEFT_SERVO, 0);
    // moveServo(RIGHT_SERVO, 0);


    lineFollowStrips(4, 'b');
    delay(1000);
    lineFollow('r', 100);
    delay(200);
    lineFollowStrips(4, 'r', 100);
    delay(200);
    lineFollowEncoder(600, 'b');
    delay(500);
    moveServo(LEFT_SERVO, 0);
    sendCommand("FL LT OPEN");
    delay(500);
    lineFollowEncoder(850, 'f', 80);
    delay(500);
    sendCommand("FL LT CLOSE");
    delay(300);
    moveServo(LEFT_SERVO, 70);
    delay(1000);
    moveServo(BASE_SERVO, BASE_090-5);
    delay(500);
    moveServo(FRONT_SERVO, 0);
    moveServo(RIGHT_SERVO, 0);
    delay(500);
    lineFollowStrips(2, 'f', 80);
    delay(500);
    lineFollowEncoder(400, 'f', 80);
    delay(500);
    moveServo(FRONT_SERVO, 70);
    delay(500);
    lineFollowStrips(1, 'b', 80);
    delay(500);
    lineFollowEncoder(500, 'l', 80);
    delay(100);
    lineFollowEncoder(750, 'r', 80);
    delay(500);
    moveServo(RIGHT_SERVO, 70);
    delay(100);
    lineFollowEncoder(400, 'l', 80);
    delay(500);
    lineFollow('f');
    delay(500);
    lineFollowStrips(2, 'f');
    delay(500);
}

void loop()
{
    // sendCommand("FL LT OPEN");
    // delay(1000);
    // sendCommand("FL LT CLOSE");
    // delay(1000);
    // printSensorVals(rightSensors);
    // printEncoders();
    // lineFollow('f'); // 'f' for front, 'b' for back, 'l' for left, 'r' for right
    // lineFollowV2('f'); // 'f' for front, 'b' for back, 'l' for left, 'r' for right
    // delay(100);
}