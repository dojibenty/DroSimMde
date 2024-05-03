/* 
 * ADroneSpiral.cpp
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#include "ADroneSpiral.h"
#include "DroneSpiral.h"

ADroneSpiral::ADroneSpiral(double aFrequency)	: compDroneSpiral(aFrequency){
		
}
ADroneSpiral::~ADroneSpiral()	{
		
}
void ADroneSpiral::setAObjective(AObjective *pAObjective) {
		attAObjective = pAObjective;
}

void ADroneSpiral::readInputs() {
		appli->setObjposition(attAObjective->getObjposition());
}


