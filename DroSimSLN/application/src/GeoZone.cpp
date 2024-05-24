/*
 * GeoZone.cpp
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#include "GeoZone.h"
#include "compGeoZone.h"
// Start of user code  : Additional imports for GeoZone
// End of user code


GeoZone::GeoZone(compGeoZone* container) {
    myContainer = container;
    // Start of user code  : Implementation of constructor method

    // End of user code
}

GeoZone::~GeoZone() {
    // Start of user code  : Implementation of destructor method

    // End of user code
}

void GeoZone::initialize() {
    // Start of user code  : Implementation of initialize method
    // End of user code
}

void GeoZone::end() {
    // Start of user code  : Implementation of end method

    // End of user code
}

ReturnCode GeoZone::doStep(int nStep) {
    // Start of user code  : Implementation of doStep method
    return ReturnCode::nothing;
    // End of user code
}

// +++++++++++++ Methods of the pItfGeoData interface +++++++++++++
vect2 GeoZone::grabEnvLimits() {
    // Start of user code  : Implementation of method grabEnvLimits
    return envSize /*+ bottomLeftPoint*/;
    // End of user code
}

vect2 GeoZone::grabBottomLeftPoint() {
    return bottomLeftPoint;
}


// Start of user code  : Additional methods
// End of user code


// +++++++++++++ Access for envSize parameter +++++++++++++
vect2 GeoZone::getEnvSize() {
    return envSize;
}

void GeoZone::setEnvSize(vect2 arg) {
    envSize = arg;
}

// +++++++++++++ Access for bottomLeftPoint parameter +++++++++++++
vect2 GeoZone::getBottomLeftPoint() {
    return bottomLeftPoint;
}

void GeoZone::setBottomLeftPoint(vect2 arg) {
    bottomLeftPoint = arg;
}
