#pragma once

#ifndef _LINEFOLLOW_H
#define _LINEFOLLOW_H

#include <Arduino.h>
#include "Sensors.h"
#include "Motors.h"

void linefollow() {
    // white 0
    // black 1
    int value = readSingleSensor(FRONT.channel) < 25000 ? 1 : 0;

    if (value) {
        
    }
}

#endif //_LINEFOLLOW_H