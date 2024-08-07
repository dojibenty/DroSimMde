/*
 * Simulation.cpp
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#include "Simulation.h"
#include "compSimulation.h"
// Start of user code  : Additional imports for Simulation
// End of user code


Simulation::Simulation(compSimulation* container) {
    myContainer = container;
    // Start of user code  : Implementation of constructor method

    // End of user code
}

Simulation::~Simulation() {
    // Start of user code  : Implementation of destructor method

    // End of user code
}

void Simulation::initialize() {
    // Start of user code  : Implementation of initialize method

    // End of user code
}

void Simulation::end() {
    // Start of user code  : Implementation of end method

    // End of user code
}

ReturnCode Simulation::doStep(int nStep) {
    // Start of user code  : Implementation of doStep method
    return ReturnCode::proceed;
    // End of user code
}

// +++++++++++++ Methods of the pItfSimData interface +++++++++++++
double Simulation::grabExpectedEndTime() {
    // Start of user code  : Implementation of method grabExpectedEndTime
    return expectedEndTime;
    // End of user code
}

double Simulation::grabPositionCorrection() {
    // Start of user code  : Implementation of method grabPositionCorrection
    return positionCorrection;
    // End of user code
}


// Start of user code  : Additional methods

// End of user code


// +++++++++++++ Access for expectedEndTime parameter +++++++++++++
double Simulation::getExpectedEndTime() {
    return expectedEndTime;
}

void Simulation::setExpectedEndTime(double arg) {
    expectedEndTime = arg;
}

// +++++++++++++ Access for positionCorrection parameter +++++++++++++
double Simulation::getPositionCorrection() {
    return positionCorrection;
}

void Simulation::setPositionCorrection(double arg) {
    positionCorrection = arg;
}
