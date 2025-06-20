#include <Arduino.h>
#include "Sensors.h"
#include "Motors.h"
#include "LineFollow.h"
#include "ServoControl.h"
#include "Encoders.h"
#include "MapArray.h"

#include "blue/blue1.h"
#include "blue/blue2.h"
#include "blue/blue3.h"
#include "blue/blue4.h"
#include "blue/blue5.h"
#include "blue/blue6.h"
#include "blue/blue7.h"
#include "blue/blue8.h"
#include "blue/blue9.h"
#include "blue/blue10.h"
#include "blue/blue11.h"
#include "blue/blue12.h"
#include "blue/blue13.h"
#include "blue/blue14.h"
#include "blue/blue15.h"
#include "blue/blue16.h"
#include "blue/blue17.h"
#include "blue/blue18.h"
#include "blue/blue19.h"
#include "blue/blue20.h"

#include "red/red1.h"
#include "red/red2.h"
#include "red/red3.h"
#include "red/red4.h"
#include "red/red5.h"
#include "red/red6.h"
#include "red/red7.h"
#include "red/red8.h"
#include "red/red9.h"
#include "red/red10.h"
#include "red/red11.h"
#include "red/red12.h"
#include "red/red13.h"
#include "red/red14.h"
#include "red/red15.h"
#include "red/red16.h"
#include "red/red17.h"
#include "red/red18.h"
#include "red/red19.h"
#include "red/red20.h"

// TODO: update rightTurnEncoder function name after NERC

void blueStart()
{
    forwardStrips(2);
    delay(500);

    int map = readMapBlue();

    if (map == 0)
    {
        while (true)
        {
        }
    }

    lineFollowEncoder(400);
    lineFollowStrips(2, 'f');
    delay(200);
    leftTurnEncoder(770);

    // blue1();
    // while (true)
    //     ;

    if (map == 1)
    {
        // 0 0 1
        // 0 1 0
        // 1 0 0
        blue1();
    }
    else if (map == 2)
    {
        // 1 1 1
        // 0 0 0
        // 0 0 0
        blue2();
    }
    else if (map == 3)
    {
        // 0 0 0
        // 1 1 1
        // 0 0 0
        blue3();
    }
    else if (map == 4)
    {
        // 0 1 0
        // 0 1 1
        // 0 0 0
        blue4();
    }
    else if (map == 5)
    {
        // 0 1 0
        // 1 1 0
        // 0 0 0
        blue5();
    }
    else if (map == 6)
    {
        // 0 1 0
        // 0 0 0
        // 1 0 1
        blue6();
    }
    else if (map == 7)
    {
        // 1 0 1
        // 0 0 0
        // 0 1 0
        blue7();
    }
    else if (map == 8)
    {
        // 1 0 0
        // 0 1 0
        // 0 0 1
        blue8();
    }
    else if (map == 9)
    {
        // 0 1 0
        // 1 0 1
        // 0 0 0
        blue9();
    }
    else if (map == 10)
    {
        // 0 0 0
        // 0 1 0
        // 1 0 1
        blue10();
    }
    else if (map == 11)
    {
        // 1 0 1
        // 0 0 0
        // 0 0 1
        blue11();
    }
    else if (map == 12)
    {
        // 1 0 0
        // 0 0 0
        // 1 0 1
        blue12();
    }
    else if (map == 13)
    {
        // 0 1 0
        // 0 1 0
        // 0 0 1
        blue13();
    }
    else if (map == 14)
    {
        // 0 1 0
        // 0 1 0
        // 1 0 0
        blue14();
    }
    else if (map == 15)
    {
        // 1 0 0
        // 0 0 1
        // 1 0 0
        blue15();
    }
    else if (map == 16)
    {
        // 0 0 1
        // 1 0 0
        // 0 0 1
        blue16();
    }
    else if (map == 17)
    {
        // 0 0 1
        // 0 1 0
        // 0 0 1
        blue17();
    }
    else if (map == 18)
    {
        // 1 0 0
        // 0 1 0
        // 1 0 0
        blue18();
    }
    else if (map == 19)
    {
        // 0 0 1
        // 0 1 0
        // 0 1 0
        blue19();
    }
    else if (map == 20)
    {
        // 1 0 0
        // 0 1 0
        // 0 1 0
        blue20();
    }
}

void redStart()
{
    backwardStrips(2);
    delay(1000);

    int map = readMapRed();

    if (map == 0)
    {
        while (true)
        {
        }
    }

    lineFollowEncoder(400, 'b');
    lineFollowStrips(2, 'b');
    delay(200);
    leftTurnEncoder(780);

    // red1();
    // while (true)
    //     ;

    if (map == 1)
    {
        // 0 0 1
        // 0 1 0
        // 1 0 0
        red1();
    }
    else if (map == 2)
    {
        // 1 1 1
        // 0 0 0
        // 0 0 0
        red2();
    }
    else if (map == 3)
    {
        // 0 0 0
        // 1 1 1
        // 0 0 0
        red3();
    }
    else if (map == 4)
    {
        // 0 1 0
        // 0 1 1
        // 0 0 0
        red4();
    }
    else if (map == 5)
    {
        // 0 1 0
        // 1 1 0
        // 0 0 0
        red5();
    }
    else if (map == 6)
    {
        // 0 1 0
        // 0 0 0
        // 1 0 1
        red6();
    }
    else if (map == 7)
    {
        // 1 0 1
        // 0 0 0
        // 0 1 0
        red7();
    }
    else if (map == 8)
    {
        // 1 0 0
        // 0 1 0
        // 0 0 1
        red8();
    }
    else if (map == 9)
    {
        // 0 1 0
        // 1 0 1
        // 0 0 0
        red9();
    }
    else if (map == 10)
    {
        // 0 0 0
        // 0 1 0
        // 1 0 1
        red10();
    }
    else if (map == 11)
    {
        // 1 0 1
        // 0 0 0
        // 0 0 1
        red11();
    }
    else if (map == 12)
    {
        // 1 0 0
        // 0 0 0
        // 1 0 1
        red12();
    }
    else if (map == 13)
    {
        // 0 1 0
        // 0 1 0
        // 0 0 1
        red13();
    }
    else if (map == 14)
    {
        // 0 1 0
        // 0 1 0
        // 1 0 0
        red14();
    }
    else if (map == 15)
    {
        // 1 0 0
        // 0 0 1
        // 1 0 0
        red15();
    }
    else if (map == 16)
    {
        // 0 0 1
        // 1 0 0
        // 0 0 1
        red16();
    }
    else if (map == 17)
    {
        // 0 0 1
        // 0 1 0
        // 0 0 1
        red17();
    }
    else if (map == 18)
    {
        // 1 0 0
        // 0 1 0
        // 1 0 0
        red18();
    }
    else if (map == 19)
    {
        // 0 0 1
        // 0 1 0
        // 0 1 0
        red19();
    }
    else if (map == 20)
    {
        // 1 0 0
        // 0 1 0
        // 0 1 0
        red20();
    }
}

void setup()
{
    Serial.begin(9600);
    initEncoders();
    initSensors();
    initMotors();
    initServos();
    initMapArray();

    Serial.println("Code Running...");
    // moveServo(FRONT_SERVO, 0);
    // moveServo(LEFT_SERVO, 0);
    // moveServo(RIGHT_SERVO, 0);

    // rigthTurnEncoder(780);
    // leftTurnEncoder(780);

    // blueStart();
    redStart();
}

void loop()
{
    // lineFollowV3('r', 120);
    // sendCommand("FL LT OPEN");
    // delay(1000);
    // sendCommand("FL LT CLOSE");
    // delay(1000);
    // printSensorVals(frontSensors);
    // printEncoders();
    // lineFollow('f'); // 'f' for front, 'b' for back, 'l' for left, 'r' for right
    // lineFollowV2('f'); // 'f' for front, 'b' for back, 'l' for left, 'r' for right
    // readMapSingleSensor(MAP_PINS[0]);
    // checkMap();
    Serial.println(readMapRed());
    delay(500);
}