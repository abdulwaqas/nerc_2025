#pragma once

#ifndef _LINEFOLLOW_H_
#define _LINEFOLLOW_H_

#include <Arduino.h>
#include "Sensors.h"
#include "Motors.h"

int targetValFront = 570;
int targetValLeft = 300;
int baseSpeed = 150;

long integral = 0; // Accumulated error

void linefollowFront()
{
    float Kp = 0.09;
    float Ki = 0.001;

    // Sensor and error
    int sensorValue = analogRead(FRONT_SENSOR);
    int error = targetValFront - sensorValue;

    // Integrate error (avoid windup by limiting)
    integral += error;
    integral = constrain(integral, -1000, 1000); // anti-windup

    int correction = (Kp * error) + (Ki * integral);
    Serial.println(correction);

    int leftSpeed = baseSpeed - correction;
    int rightSpeed = baseSpeed + correction;

    // Limit PWM values between 0 and 255
    leftSpeed = constrain(leftSpeed, 0, 255);
    rightSpeed = constrain(rightSpeed, 0, 255);

    forward(leftSpeed, rightSpeed);
}

void linefollowLeft()
{
    float Kp = 0.2;
    float Ki = 0.001;
    int baseSpeedLeft = 70;

    int base_Vx = 0;
    int base_Vy = -baseSpeedLeft; // Negative for leftward movement

    int current_Vy = base_Vy;
    int current_omega = 0;

    // Sensor and error
    int sensorValue = analogRead(LEFT_SENSOR);
    int error = targetValLeft - sensorValue;

    // Integrate error (avoid windup by limiting)
    integral += error;
    integral = constrain(integral, -1000, 1000); // anti-windup

    current_omega = (Kp * error) + (Ki * integral);
    // Serial.println(correction);

    // Calculate individual wheel speeds using inverse kinematics
    int S_FL = abs(base_Vx + current_Vy - (15 + 15) * current_omega);
    int S_FR = abs(base_Vx - current_Vy + (15 + 15) * current_omega);
    int S_RL = abs(base_Vx - current_Vy - (15 + 15) * current_omega);
    int S_RR = abs(base_Vx + current_Vy + (15 + 15) * current_omega);

    // Limit PWM values between 0 and 255
    // leftSpeed = constrain(leftSpeed, 130, 170);
    // rightSpeed = constrain(rightSpeed, 130, 170);
    
    S_FL = constrain(S_FL, 50, 90);
    S_FR = constrain(S_FR, 50, 90);
    S_RL = constrain(S_RL, 50, 90);
    S_RR = constrain(S_RR, 50, 90);
    
    Serial.print(S_FL);
    Serial.print(" ");
    Serial.print(S_FR);
    Serial.print(" ");
    Serial.print(S_RL);
    Serial.print(" ");
    Serial.println(S_RR);

    left2(S_FL, S_RL, S_FR, S_RR);
}

#endif //_LINEFOLLOW_H