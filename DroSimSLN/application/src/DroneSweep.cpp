/*
 * DroneSweep.cpp
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#include "DroneSweep.h"
#include "compDroneSweep.h"
// Start of user code  : Additional imports for DroneSweep
#include <sstream>
#define M_PER_DEG 111000
// End of user code


DroneSweep::DroneSweep(compDroneSweep* container, int ID) {
    myContainer = container;
    droneID = ID;
    rItfGeoDataSweep = 0;
    rItfManageSimSweep = 0;
    rItfSimDataSweep = 0;
    // Start of user code  : Implementation of constructor method
    // End of user code
}

DroneSweep::~DroneSweep() {
    // Start of user code  : Implementation of destructor method

    // End of user code
}

void DroneSweep::initialize() {
    // Start of user code  : Implementation of initialize method
    assignedZone = rItfManageSimSweep->grabAssignedZone(droneID);

    leftYBound = assignedZone.getV1().getY();
    sweepLength = assignedZone.getV2().getY() - leftYBound;

    position = vect2(0.0, 0.0);

    heightCount = 1;

    const auto bottomLeftPoint = vect2(assignedZone.getV2().getX(), assignedZone.getV1().getY());
    zoneStartPoint = bottomLeftPoint + startingPoint * bottomLeftPoint;

    direction = zoneStartPoint;
    direction.normalize();

    movementTolerance = rItfSimDataSweep->grabPositionCorrection();

    battery = batteryCapacity * batteryCount;
    batteryConsumption = 2 * pow(speed, 2) / 3600.0;
    cout << "############### b:" << battery << " bct:" << batteryCount << " bcs:" << batteryConsumption << '\n' ;
    cpt = 0;
    // End of user code
}

void DroneSweep::end() {
    // Start of user code  : Implementation of end method
    cout << cpt << " steps\n";
    // End of user code
}

int DroneSweep::doStep(int nStep) {
    // Start of user code  : Implementation of doStep method
    cpt++;
    
    // Movement
    if (!isInZone)
        if (vect2::distance(position, zoneStartPoint) <= movementTolerance) {
            position = zoneStartPoint;
            isInZone = true;
        }
    
    position = setNextPosition();
    sweepposition = position;

    //cout << "step:" << cpt << " pos: " << position.toString() << '\n';

    // Objective detection
    if (vect2::distance(position, objposition) <= visionRadius
        && objposition.getX() > 0) {
        //cout << "1bat: " << battery << '\n';
        cout << "pos: " << position.toString() << "obj: " << objposition.toString() << '\n';
        return 1;
    }

    // Battery
    double windInducedConsumption = 2 * pow(windForce,2) / 3600.0;
    const int alignment = direction.alignment(windDirection);
    if (alignment == 0) {
        if (abs(windInducedConsumption) > batteryConsumption) windInducedConsumption = batteryConsumption;
        windInducedConsumption *= -1;
    }
    else if (alignment == 1) windInducedConsumption *= 0;
    if ((battery -= batteryConsumption + windInducedConsumption * windInfluence) <= 0) return 2;

    //cout << "2bat: " << battery << '\n';
    //cout << "bcs: " << batteryConsumption << " // wic+i: " << windInducedConsumption*windInfluence << " // wf: " << windForce << '\n';
    
    return 0;
    // End of user code
}


// Start of user code  : Additional methods
vect2 DroneSweep::setNextPosition() {
    if (!isInZone) return {position + direction * speed};

    const double targetHeight = sweepHeight * heightCount;
    if (goesVertical &&
        (!topToBottom && position.getX() >= targetHeight) || (topToBottom && position.getX() <= targetHeight)) {
        goesVertical = false;
        direction.setX(0.0);
        direction.setY(1.0);
        if (leftToRight) direction.switchSignY();
        leftToRight = !leftToRight;
        if (topToBottom) heightCount--;
        else heightCount++;
    }
    else if (position.getY() - speed < leftYBound
        || position.getY() + speed > sweepLength + leftYBound) {
        goesVertical = true;
        direction.setX(1.0);
        direction.setY(0.0);
        if (topToBottom) direction.switchSignX();
    }

    vect2 nextPosition = position + direction * speed;
    if (goesOutOfBounds(nextPosition)) {
        if (goesVertical) {
            nextPosition = position - direction * speed;
            topToBottom = !topToBottom;
        }
        else if (leftToRight) nextPosition = position + direction * (assignedZone.getV2().getY() - position.getY());
        else nextPosition = position + direction * (position.getY() - assignedZone.getV1().getY());
    }

    return nextPosition;
}

bool DroneSweep::goesOutOfBounds(vect2& point) {
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

void DroneSweep::setWindForce(double arg) {
    windForce = arg;
}

void DroneSweep::setWindDirection(vect2 arg) {
    windDirection = arg;
}

vect2 DroneSweep::getSweepposition() {
    return sweepposition;
}

void DroneSweep::setrItfGeoDataSweep(ItfGeoDataInterface* arItfGeoDataSweep) {
    rItfGeoDataSweep = arItfGeoDataSweep;
}

void DroneSweep::setrItfManageSimSweep(ItfManageSimInterface* arItfManageSimSweep) {
    rItfManageSimSweep = arItfManageSimSweep;
}

void DroneSweep::setrItfSimDataSweep(ItfSimDataInterface* arItfSimDataSweep) {
    rItfSimDataSweep = arItfSimDataSweep;
}

// +++++++++++++ Access for minSpeed parameter +++++++++++++
double DroneSweep::getMinSpeed() {
    return minSpeed;
}

void DroneSweep::setMinSpeed(double arg) {
    minSpeed = arg;
}

// +++++++++++++ Access for minSpeed parameter +++++++++++++
double DroneSweep::getMaxSpeed() {
    return maxSpeed;
}

void DroneSweep::setMaxSpeed(double arg) {
    maxSpeed = arg;
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

// +++++++++++++ Access for batteryCapacity parameter +++++++++++++
double DroneSweep::getBatteryCapacity() {
    return batteryCapacity;
}

void DroneSweep::setBatteryCapacity(double arg) {
    batteryCapacity = arg;
}

// +++++++++++++ Access for numberOf parameter +++++++++++++
long DroneSweep::getNumberOf() {
    return numberOf;
}

void DroneSweep::setNumberOf(long arg) {
    numberOf = arg;
}

// +++++++++++++ Access for startingPoint parameter +++++++++++++
vect2 DroneSweep::getStartingPoint() {
    return startingPoint;
}

void DroneSweep::setStartingPoint(vect2 arg) {
    startingPoint = arg;
}

// +++++++++++++ Access for collisionRadius parameter +++++++++++++
double DroneSweep::getCollisionRadius() {
    return collisionRadius;
}

void DroneSweep::setCollisionRadius(double arg) {
    collisionRadius = arg;
}
