/*
 * DroneSweep.cpp
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#include "compDroneSweep.h"
#include "DroneSweep.h"
compDroneSweep::compDroneSweep(double aFrequency) : LeafComponent( aFrequency) {
		appli = new DroneSweep( this);
		delay = 0;
		delayMax = 0;
		newValue = false;
		isActive = true;
	}
compDroneSweep::~compDroneSweep()	{}

void compDroneSweep::doOneStep() {
		if (newValue) {
			delay++;
			if (delay == delayMax) {
			}
		}
	}

void compDroneSweep::doStep(int nStep) {	
		if (newValue) {
		}
		readInputs();
		appli->doStep(nStep);
		if (delayMax == 0) {
			newValue = false;
		} else {
			newValue = true;
			delay = 0;
		}
	}

void compDroneSweep::readInputs() {
	}
void compDroneSweep::initialize() {
		appli->initialize();
	}
void compDroneSweep::lateinitialize() {
	appli->lateinitialize();
}

void compDroneSweep::end() {
		appli->end();
	}
	
void compDroneSweep::setrItfEnvironmentSweep(ItfEnvironmentInterface *arItfEnvironmentSweep) {
		appli->setrItfEnvironmentSweep(arItfEnvironmentSweep);
	}
DroneSweep *compDroneSweep::getAppli() {
		return appli;
	}
	// +++++++++++++ Access for ID parameter +++++++++++++
long compDroneSweep::getID() {
		return appli->getID();
	}
	
void compDroneSweep::setID(long arg) {
		appli->setID(arg);
	}
	// +++++++++++++ Access for speed parameter +++++++++++++
double compDroneSweep::getSpeed() {
		return appli->getSpeed();
	}
	
void compDroneSweep::setSpeed(double arg) {
		appli->setSpeed(arg);
	}
	// +++++++++++++ Access for position parameter +++++++++++++
vect2 compDroneSweep::getPosition() {
		return appli->getPosition();
	}
	
void compDroneSweep::setPosition(vect2 arg) {
		appli->setPosition(arg);
	}
	// +++++++++++++ Access for direction parameter +++++++++++++
vect2 compDroneSweep::getDirection() {
		return appli->getDirection();
	}
	
void compDroneSweep::setDirection(vect2 arg) {
		appli->setDirection(arg);
	}
	// +++++++++++++ Access for visionRadius parameter +++++++++++++
double compDroneSweep::getVisionRadius() {
		return appli->getVisionRadius();
	}
	
void compDroneSweep::setVisionRadius(double arg) {
		appli->setVisionRadius(arg);
	}
	// +++++++++++++ Access for sweepHeight parameter +++++++++++++
double compDroneSweep::getSweepHeight() {
		return appli->getSweepHeight();
	}
	
void compDroneSweep::setSweepHeight(double arg) {
		appli->setSweepHeight(arg);
	}
	// +++++++++++++ Access for movementTolerance parameter +++++++++++++
double compDroneSweep::getMovementTolerance() {
		return appli->getMovementTolerance();
	}
	
void compDroneSweep::setMovementTolerance(double arg) {
		appli->setMovementTolerance(arg);
	}

