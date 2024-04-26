/*
 * Manager.cpp
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#include "compManager.h"
#include "Manager.h"

compManager::compManager(double aFrequency) : LeafComponent(aFrequency) {
    appli = new Manager(this);
    delay = 0;
    delayMax = 0;
    newValue = false;
    isActive = true;
}

compManager::~compManager() {}

void compManager::doOneStep() {
    if (newValue) {
        delay++;
        if (delay == delayMax) {}
    }
}

void compManager::doStep(int nStep) {
    if (newValue) {}
    readInputs();
    appli->doStep(nStep);
    if (delayMax == 0) {
        newValue = false;
    }
    else {
        newValue = true;
        delay = 0;
    }
}

void compManager::readInputs() {}

void compManager::initialize() {
    appli->initialize();
}

void compManager::end() {
    appli->end();
}

// +++++++++++++ Methods of the pItfManageSimulation interface +++++++++++++
void compManager::signalObjectiveFound(long droneID) {
    appli->signalObjectiveFound(droneID);
}

Manager* compManager::getAppli() {
    return appli;
}
