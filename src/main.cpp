#include <Arduino.h>
#include "Sensors.h"
#include "Motors.h"
#include "LineFollow.h"
#include "ServoControl.h"
#include "Encoders.h"

void heats()
{
    lineFollowStrips(4, 'b');
    delay(1000);
    rigthTurnEncoder(780);
    lineFollow('f', 300);
    delay(200);
    lineFollowStrips(4, 'f');
    delay(200);
    sendCommand("FL LT OPEN");
    moveServo(LEFT_SERVO, 0);
    delay(300);
    leftTurnEncoder(780);
    delay(200);
    lineFollowEncoder(250, 'f', 80);
    delay(500);
    sendCommand("FL LT CLOSE");
    delay(300);
    moveServo(LEFT_SERVO, 70);
    delay(500);

    moveServo(BASE_SERVO, BASE_090 - 5);
    delay(1000);
    sendCommand("FL FT OPEN");
    moveServo(FRONT_SERVO, 0);
    delay(500);
    lineFollowStrips(2, 'f');
    delay(500);
    lineFollowEncoder(350, 'f', 80);
    delay(500);
    sendCommand("FL FT CLOSE");
    delay(300);
    moveServo(FRONT_SERVO, 70);
    delay(500);

    lineFollowStrips(1, 'b');
    moveServo(BASE_SERVO, BASE_180);
    delay(600);
    moveServo(RIGHT_SERVO, 0);
    delay(300);
    rigthTurnEncoder(780);
    delay(100);
    lineFollowEncoder(350, 'f', 80);
    delay(100);
    sendCommand("FL RT CLOSE");
    delay(300);
    moveServo(RIGHT_SERVO, 70);
    delay(500);

    lineFollowStrips(1, 'b');
    delay(300);
    leftTurnEncoder(780);
    lineFollowEncoder(400, 'f');
    lineFollowStrips(2, 'f');
    delay(300);
    leftTurnEncoder(780);
    delay(300);
    
    RedServo redServo = getRedServo();
    if (redServo == RedServo::SERVO_LEFT)
    {
        moveServo(BASE_SERVO, BASE_000);
        delay(1000);
        moveServo(LEFT_SERVO, 0);
        delay(500);
        lineFollowEncoder(400, 'f');
        lineFollowStrips(1, 'f');
        delay(500);
        lineFollowEncoder(600, 'f');
        delay(100);
        sendCommand("FL LT OPEN");
        delay(300);

        lineFollowStrips(5, 'b');
        lineFollowEncoder(400, 'b');
        moveServo(RIGHT_SERVO, 40);
        delay(500);
        sendCommand("FL RT OPEN");
        delay(300);
        lineFollowStrips(1, 'f');
        moveServo(LEFT_SERVO, 70);
        moveServo(RIGHT_SERVO, 70);
        delay(500);
        leftTurnEncoder(780);
        
        lineFollowEncoder(400, 'f');
        moveServo(BASE_SERVO, BASE_090);
        lineFollowStrips(4, 'f');
        delay(300);
        leftTurnEncoder(780);
        delay(300);
        lineFollowEncoder(200, 'f');
        delay(100);
        moveServo(FRONT_SERVO, 0);
        delay(500);
        sendCommand("FL FT OPEN");
        delay(300);
    }
    else if (redServo == RedServo::SERVO_CENT)
    {
        moveServo(BASE_SERVO, BASE_090);
        delay(1000);
        moveServo(FRONT_SERVO, 0);
        delay(500);
        lineFollowEncoder(400, 'f');
        lineFollowStrips(1, 'f');
        delay(500);
        lineFollowEncoder(600, 'f');
        delay(100);
        sendCommand("FL FT OPEN");
        delay(300);
        lineFollowStrips(5, 'b');
        moveServo(FRONT_SERVO, 70);
        delay(500);
        
        moveServo(BASE_SERVO, BASE_000);
        delay(1000);
        lineFollowEncoder(400, 'b');
        moveServo(RIGHT_SERVO, 40);
        delay(500);
        sendCommand("FL RT OPEN");
        delay(300);
        lineFollowStrips(1, 'f');
        moveServo(RIGHT_SERVO, 70);
        delay(500);
        
        leftTurnEncoder(780);
        lineFollowEncoder(400, 'f');
        lineFollowStrips(4);
        delay(300);
        leftTurnEncoder(780);
        delay(300);
        lineFollowEncoder(200, 'f');
        delay(100);
        moveServo(LEFT_SERVO, 0);
        delay(500);
        sendCommand("FL LT OPEN");
        delay(300);
    }
    else if (redServo == RedServo::SERVO_RGHT)
    {
        moveServo(RIGHT_SERVO, 0);
        delay(500);
        lineFollowEncoder(400, 'f');
        lineFollowStrips(1, 'f');
        lineFollowEncoder(600, 'f');
        delay(100);
        sendCommand("FL RT OPEN");
        delay(300);
        lineFollowStrips(5, 'b');
        moveServo(RIGHT_SERVO, 70);
        delay(500);

        lineFollowEncoder(400, 'b');
        moveServo(LEFT_SERVO, 40);
        delay(500);
        sendCommand("FL LT OPEN");
        delay(300);
        lineFollowStrips(1, 'f');
        moveServo(LEFT_SERVO, 70);
        delay(500);

        leftTurnEncoder(780);
        lineFollowEncoder(400, 'f');
        lineFollowStrips(4);
        delay(300);
        leftTurnEncoder(780);
        delay(300);
        lineFollowEncoder(200, 'f');
        delay(100);
        moveServo(LEFT_SERVO, 0);
        delay(500);
        sendCommand("FL LT OPEN");
        delay(300);
    }

    lineFollowStrips(2, 'b');
    delay(300);
    rigthTurnEncoder(780);
    lineFollowEncoder(1600);
}

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

    heats();
    // forward();
}

void loop()
{
    // lineFollowV3('r', 120);
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