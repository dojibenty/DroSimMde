/*
 * TimeableObject.h
 *
 *  Created on: 12 mars 2020
 *      Author: pillain
 */

#ifndef TIMEABLEOBJECT_H_
#define TIMEABLEOBJECT_H_
#include "ReturnCode.h"


class TimeableObject {
protected :
    double frequency;

public:
    TimeableObject(double freq);
    virtual ~TimeableObject() = 0;
    double getFrequency();
    void setFrequency(double freq);
    virtual ReturnCode doStep(int nStep);
};
#endif /* TIMEABLEOBJECT_H_ */
