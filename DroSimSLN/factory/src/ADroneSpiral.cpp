/* 
 * ADroneSpiral.cpp
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#include "ADroneSpiral.h"

#include "AWind.h"
#include "DroneSpiral.h"

ADroneSpiral::ADroneSpiral(double aFrequency, const int ID) : compDroneSpiral(aFrequency, ID) {}
ADroneSpiral::~ADroneSpiral() {}

void ADroneSpiral::setAObjective(AObjective* pAObjective) {
    attAObjective = pAObjective;
}

void ADroneSpiral::setAWind(AWind* pAWind) {
    attAWind = pAWind;    
}

void ADroneSpiral::readInputs() {
    appli->setObjposition(attAObjective->getObjposition());
    appli->setWindForce(attAWind->getWindForce());
    appli->setWindDirection(attAWind->getWindDirection());
}
