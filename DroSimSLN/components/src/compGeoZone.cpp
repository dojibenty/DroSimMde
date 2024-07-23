/*
 * GeoZone.cpp
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#include "compGeoZone.h"
#include "GeoZone.h"

compGeoZone::compGeoZone(double aFrequency) : LeafComponent(aFrequency) {
    appli = new GeoZone(this);
    delay = 0;
    delayMax = 0;
    newValue = false;
    isActive = true;
    objectcode_ = objGeoZone;
}

compGeoZone::~compGeoZone() {}

void compGeoZone::doOneStep() {
    if (newValue) {
        delay++;
        if (delay == delayMax) {}
    }
}

ReturnCode compGeoZone::doStep(int nStep) {
    if (newValue) {}
    readInputs();
    const auto returnCode = appli->doStep(nStep);
    if (delayMax == 0) {
        newValue = false;
    }
    else {
        newValue = true;
        delay = 0;
    }
    return returnCode;
}

void compGeoZone::readInputs() {}

void compGeoZone::initialize() {
    appli->initialize();
}

void compGeoZone::end() {
    appli->end();
}

// +++++++++++++ Methods of the pItfGeoData interface +++++++++++++
vect2 compGeoZone::grabEnvLimits() {
    return appli->grabEnvLimits();
}

vect2 compGeoZone::grabBottomLeftPoint() {
    return appli->grabBottomLeftPoint();
}


GeoZone* compGeoZone::getAppli() {
    return appli;
}

// +++++++++++++ Access for envSize parameter +++++++++++++
vect2 compGeoZone::getEnvSize() {
    return appli->getEnvSize();
}

void compGeoZone::setEnvSize(vect2 arg) {
    appli->setEnvSize(arg);
}

// +++++++++++++ Access for bottomLeftPoint parameter +++++++++++++
vect2 compGeoZone::getBottomLeftPoint() {
    return appli->getBottomLeftPoint();
}

void compGeoZone::setBottomLeftPoint(vect2 arg) {
    appli->setBottomLeftPoint(arg);
}

void compGeoZone::setSystemRef(DroSimSystem* systemRef) {
    appli->setSystemRef(systemRef);
}