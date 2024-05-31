/*
 * TimeableObject.cpp
 *
 *  Created on: 12 mars 2020
 *      Author: pillain
 */

#include "TimeableObject.h"

#include "ReturnCode.h"

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

ReturnCode TimeableObject::doStep(int nStep) { return ReturnCode::proceed; }
