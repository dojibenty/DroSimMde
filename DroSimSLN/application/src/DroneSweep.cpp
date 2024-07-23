/*
 * DroneSweep.cpp
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#include "DroneSweep.h"
#include "compDroneSweep.h"
#include "ReturnCode.h"
// Start of user code  : Additional imports for DroneSweep
#include <sstream>
#include "DroSimSystem.h"
#include "User.h"
// End of user code


DroneSweep::DroneSweep(compDroneSweep* container, int ID) {
    myContainer = container;
    this->ID = ID;
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
    goesVertical = true;
    leftToRight = false;
    topToBottom = false;
    heightCount = 1;
    isInZone = false;
    // Start of user code  : Implementation of initialize method
    assignedZone = rItfManageSimSweep->grabAssignedZone(ID);
    const auto rescaledZone = wect2(vect2(assignedZone.getV1().getX() - visionRadius, assignedZone.getV1().getY() + visionRadius),
                              vect2(assignedZone.getV2().getX() + visionRadius, assignedZone.getV2().getY() - visionRadius));
    assignedZone = rescaledZone;
    
    leftYBound = assignedZone.getV1().getY();
    sweepLength = assignedZone.getV2().getY() - leftYBound;

    const auto bottomLeftPoint = vect2(assignedZone.getV2().getX(), assignedZone.getV1().getY());
    zoneStartPoint = bottomLeftPoint + startingPoint * bottomLeftPoint;

    direction = zoneStartPoint;
    direction.normalize();

    movementTolerance = rItfSimDataSweep->grabPositionCorrection();

    battery = batteryCapacity;
    batConsoFactA = 50;
    batConsoFactB = 0.4;
    batteryConsumption = CONSUMPTION(speed);
    cpt = 0;

    // Communication
    systemRef_->AddToMessage("DroneSweep" + to_string(ID));
    
    //printRecap();
    // End of user code
}

void DroneSweep::end() {
    // Start of user code  : Implementation of end method
    cout << "SWE" << ID << " - bat: " << battery << " // " << cpt << " steps\n";
    // End of user code
}

ReturnCode DroneSweep::doStep(int nStep) {
    // Start of user code  : Implementation of doStep method
    cpt++;
    
    // Execute step
    //step(objposition,windForce,windDirection,&sweepposition);
    
    // Return codes
    using enum ReturnCode;
    
    // Is objective found
    if (condObjectiveFound(position,objposition,visionRadius))
        return objective_found;

    // Is battery low
    if (condLowBattery(battery))
        return low_battery;
    
    return proceed;
    // End of user code
}

void DroneSweep::step(const vect2& objposition, const double windForce, const vect2& windDirection, vect2* sweepposition) {
    move(sweepposition);
    consumeBattery(windForce,windDirection);
}

void DroneSweep::move(vect2* sweepposition) {
    if (!isInZone)
        if (zoneStartPoint < position) {
            position = zoneStartPoint;
            isInZone = true;
        }
    
    position = setNextPosition();
    *sweepposition = vect2(position.getX(),position.getY());
}

void DroneSweep::consumeBattery(const double windForce, const vect2& windDirection) {
    const int alignment = direction.alignment(windDirection);
    switch (alignment) {
    case 0: // vent arriere
        batteryConsumption = CONSUMPTION(speed-(windForce*windInfluence));
        break;
    case 1: // vent de cote
        batteryConsumption = CONSUMPTION(speed+(windForce*windInfluence)*0.5);
        break;
    case 2: // vent contraire
        batteryConsumption = CONSUMPTION(speed+(windForce*windInfluence));
        break;
    default:
        break;
    }
    battery -= batteryConsumption;
}

bool DroneSweep::condObjectiveFound(vect2& position, vect2& objposition, const double visionRadius) {
    return vect2::distance(position, objposition) <= visionRadius && objposition.getX() > 0;
}

bool DroneSweep::condLowBattery(double battery) {
    if (battery <= 0) {
        this->battery = 0;
        return true;
    }
    return false;
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

void DroneSweep::printRecap() {
    cout << "*** Drone SWE" << ID << " ***";
    cout << "\nstartingPoint: " << startingPoint.toString();
    cout << "\nspeed: " << speed;
    cout << "\nposition: " << position.toString();
    cout << "\ndirection: " << direction.toString();
    cout << "\nbattery: " << battery;
    cout << "\nbatteryConsumption: " << batteryConsumption;
    cout << endl;
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

void DroneSweep::setSystemRef(DroSimSystem* systemRef) {
    systemRef_ = systemRef;
}