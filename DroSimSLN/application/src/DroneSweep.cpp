/*
 * DroneSweep.cpp
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#include "DroneSweep.h"
#include "compDroneSweep.h"
// Start of user code  : Additional imports for DroneSweep
#include <iostream>
// End of user code


DroneSweep::DroneSweep(compDroneSweep *container)	{
		myContainer = container;
		rItfEnvironmentSweep = 0;
		rItfManagerSweep = 0;
// Start of user code  : Implementation of constructor method
    // End of user code
	}
DroneSweep::~DroneSweep(){
// Start of user code  : Implementation of destructor method

    // End of user code
	}
void DroneSweep::initialize() {
// Start of user code  : Implementation of initialize method
    // End of user code
	}

void DroneSweep::end() {
// Start of user code  : Implementation of end method

    // End of user code
	}

void DroneSweep::doStep(int nStep) {
// Start of user code  : Implementation of doStep method
	position = SetNextPosition();
	if (!isInZone)
		if (vect2::distance(position,zoneStartPoint) <= movementTolerance) {
			position = zoneStartPoint;
			isInZone = true;
		}
	
	//cout << "SWEEP-" << ID << ": " << position.toString() << '\n';
	
	if (vect2::distance(position,objposition) <= visionRadius
		&& objposition.getX() > 0)
		rItfManagerSweep->signalObjectiveFound(ID);
	
    // End of user code
	}
	
	
// Start of user code  : Additional methods
void DroneSweep::lateinitialize() {
	assignedZone = rItfEnvironmentSweep->getAssignedZone(ID);
	leftYBound = assignedZone.getV1().getY();
	sweepLength = assignedZone.getV2().getY() - leftYBound;
	zoneStartPoint = vect2(assignedZone.getV2().getX(), assignedZone.getV1().getY());
	direction = zoneStartPoint;
	direction.normalize();
}

vect2 DroneSweep::SetNextPosition() {
    if (goesUp && position.getX() >= sweepHeight * heightCount) {
        direction = vect2(0,1.0);
        if (!leftToRight) direction.switchSignY();
        goesUp = false;
        leftToRight = !leftToRight;
    }
    else if (position.getY() - speed < leftYBound
        || position.getY() + speed > sweepLength + leftYBound) {
        direction = vect2(1.0,0);
        if (topToBottom) direction.switchSignX();
        if (!goesUp) heightCount++;
        goesUp = true;
    }

    vect2 nextPosition = position + direction * speed;
    if (GoesOutOfBounds(nextPosition)) {
        if (goesUp) {
            nextPosition = position - direction * speed;
            topToBottom = !topToBottom;
        }
        else if (leftToRight) nextPosition = position + direction * (assignedZone.getV2().getY() - position.getY());
        else nextPosition = position + direction * (position.getY() - assignedZone.getV1().getY());
    }

	return nextPosition;
}

bool DroneSweep::GoesOutOfBounds(vect2& point) {
    return point.getX() < assignedZone.getV2().getX()
        || point.getY() < assignedZone.getV1().getY()
        || point.getX() > assignedZone.getV1().getX()
        || point.getY() > assignedZone.getV2().getY();
}

void DroneSweep::setAssignedZone(wect2 zone) {
    assignedZone = zone;
}

// End of user code
	

void DroneSweep::setObjposition(vect2 arg) {
		objposition = arg;
	}

void DroneSweep::setrItfEnvironmentSweep(ItfEnvironmentInterface *arItfEnvironmentSweep) {
		rItfEnvironmentSweep = arItfEnvironmentSweep;
	}
void DroneSweep::setrItfManagerSweep(ItfManagerInterface *arItfManagerSweep) {
		rItfManagerSweep = arItfManagerSweep;
	}
	// +++++++++++++ Access for ID parameter +++++++++++++
long DroneSweep::getID() {
		return ID;
	}
	
void DroneSweep::setID(long arg) {
		ID = arg;
	}
	// +++++++++++++ Access for speed parameter +++++++++++++
double DroneSweep::getSpeed() {
		return speed;
	}
	
void DroneSweep::setSpeed(double arg) {
		speed = arg;
	}
	// +++++++++++++ Access for position parameter +++++++++++++
vect2 DroneSweep::getPosition() {
		return position;
	}
	
void DroneSweep::setPosition(vect2 arg) {
		position = arg;
	}
	// +++++++++++++ Access for direction parameter +++++++++++++
vect2 DroneSweep::getDirection() {
		return direction;
	}
	
void DroneSweep::setDirection(vect2 arg) {
		direction = arg;
	}
	// +++++++++++++ Access for visionRadius parameter +++++++++++++
double DroneSweep::getVisionRadius() {
		return visionRadius;
	}
	
void DroneSweep::setVisionRadius(double arg) {
		visionRadius = arg;
	}
	// +++++++++++++ Access for sweepHeight parameter +++++++++++++
double DroneSweep::getSweepHeight() {
		return sweepHeight;
	}
	
void DroneSweep::setSweepHeight(double arg) {
		sweepHeight = arg;
	}
	// +++++++++++++ Access for movementTolerance parameter +++++++++++++
double DroneSweep::getMovementTolerance() {
		return movementTolerance;
	}
	
void DroneSweep::setMovementTolerance(double arg) {
		movementTolerance = arg;
	}

