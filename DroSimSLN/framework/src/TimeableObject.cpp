/*
 * TimeableObject.cpp
 *
 *  Created on: 12 mars 2020
 *      Author: pillain
 */

#include "TimeableObject.h"

TimeableObject::TimeableObject(double aFrequency) {
    if (aFrequency <= 0) {
        frequency = 1;
    }
    else {
        frequency = aFrequency;
    }
}

TimeableObject::~TimeableObject() {}

double TimeableObject::getFrequency() {
    return frequency;
}

void TimeableObject::setFrequency(double freq) {
    frequency = freq;
}

int TimeableObject::doStep(int nStep) { return 0; }
