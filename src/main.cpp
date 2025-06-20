#include <Arduino.h>
#include "Sensors.h"
#include "Motors.h"
#include "LineFollow.h"
#include "ServoControl.h"
#include "Encoders.h"

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

    blue13();
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