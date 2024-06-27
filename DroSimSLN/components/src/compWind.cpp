/*
 * Wind.cpp
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#include "compWind.h"

#include "ReturnCode.h"
#include "Wind.h"

compWind::compWind(double aFrequency) : LeafComponent(aFrequency) {
    appli = new Wind(this);
    delay = 0;
    delayMax = 0;
    newValue = false;
    isActive = true;
    objectcode_ = objWind;
    oldWindForce = appli->getWindForce();
    newWindForce = appli->getWindForce();
    oldWindDirection = appli->getWindDirection();
    newWindDirection = appli->getWindDirection();
}

compWind::~compWind() {}

void compWind::doOneStep() {
    if (newValue) {
        delay++;
        if (delay == delayMax) {
            oldWindForce = newWindForce;
            oldWindDirection = newWindDirection;
            newValue = false;
        }
    }
}

ReturnCode compWind::doStep(int nStep) {
    if (newValue) {
        oldWindForce = newWindForce;
        oldWindDirection = newWindDirection;
        newValue = false;
    }
    readInputs();
    const auto returnCode = appli->doStep(nStep);
    newWindForce = appli->getWindForce();
    newWindDirection = appli->getWindDirection();
    if (delayMax == 0) {
        oldWindForce = newWindForce;
        oldWindDirection = newWindDirection;
        newValue = false;
    }
    else {
        newValue = true;
        delay = 0;
    }
    return returnCode;
}

void compWind::readInputs() {}

void compWind::initialize() {
    appli->initialize();
}

void compWind::end() {
    appli->end();
}

double compWind::getWindForce() {
    return oldWindForce;
}

vect2 compWind::getWindDirection() {
    return oldWindDirection;
}

Wind* compWind::getAppli() {
    return appli;
}

// +++++++++++++ Access for force parameter +++++++++++++
double compWind::getForce() {
    return appli->getForce();
}

void compWind::setForce(double arg) {
    appli->setForce(arg);
}

// +++++++++++++ Access for direction parameter +++++++++++++
vect2 compWind::getDirection() {
    return appli->getDirection();
}

void compWind::setDirection(vect2 arg) {
    appli->setDirection(arg);
}
