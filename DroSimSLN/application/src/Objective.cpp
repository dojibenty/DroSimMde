/*
 * Objective.cpp
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#include "Objective.h"
#include "compObjective.h"
// Start of user code  : Additional imports for Objective
#include "User.h"
// End of user code


Objective::Objective(compObjective* container) {
    myContainer = container;
    rItfGeoDataObj = 0;
    // Start of user code  : Implementation of constructor method

    // End of user code
}

Objective::~Objective() {
    // Start of user code  : Implementation of destructor method

    // End of user code
}

void Objective::initialize() {
    // Start of user code  : Implementation of initialize method
    direction = vect2(0, 1.0);
    vect2 envLimits = rItfGeoDataObj->grabEnvLimits();
    const double posX = User::randRange(envLimits.getX() / 2, envLimits.getX());
    const double posY = User::randRange(0, envLimits.getY());

    objposition = position = vect2(posX, posY);
    YLimit = envLimits.getY();
    // End of user code
}

void Objective::end() {
    // Start of user code  : Implementation of end method

    // End of user code
}

int Objective::doStep(int nStep) {
    // Start of user code  : Implementation of doStep method
    if (speedConstraint == 0.0) return 0;

    vect2 nextPosition = position + direction * speedConstraint;

    if (nextPosition.getY() >= 0 && nextPosition.getY() <= YLimit) position = nextPosition;
    else direction.switchSignY();

    objposition = position;

    return 0;
    // End of user code
}


// Start of user code  : Additional methods
// End of user code


vect2 Objective::getObjposition() {
    return objposition;
}

void Objective::setrItfGeoDataObj(ItfGeoDataInterface* arItfGeoDataObj) {
    rItfGeoDataObj = arItfGeoDataObj;
}

// +++++++++++++ Access for speedConstraint parameter +++++++++++++
double Objective::getSpeedConstraint() {
    return speedConstraint;
}

void Objective::setSpeedConstraint(double arg) {
    speedConstraint = arg;
}

// +++++++++++++ Access for position parameter +++++++++++++
vect2 Objective::getPosition() {
    return position;
}

void Objective::setPosition(vect2 arg) {
    position = arg;
}
