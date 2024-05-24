/*
 * DroneSweep.cpp
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#include "compDroneSweep.h"
#include "DroneSweep.h"

compDroneSweep::compDroneSweep(double aFrequency) : LeafComponent(aFrequency) {
    const auto obj = new DroneSweep(this, 0);
    appli.insert(make_pair(appli.size(),obj));
    oldSweepposition.push_back(obj->getSweepposition());
    newSweepposition.push_back(obj->getSweepposition());
    delay = 0;
    delayMax = 0;
    newValue = false;
    isActive = true;
}

compDroneSweep::~compDroneSweep() {}

void compDroneSweep::doOneStep() {
    if (newValue) {
        delay++;
        if (delay == delayMax) {
            oldSweepposition = newSweepposition;
            newValue = false;
        }
    }
}

ReturnCode compDroneSweep::doStep(int nStep) {
    using enum ReturnCode;

    if (newValue) {
        oldSweepposition = newSweepposition;
        newValue = false;
    }

    readInputs();

    unordered_map<DroneSweep*, ReturnCode> returnCodes;

    for (const auto& [id, inst] : appli) {
        
        if (stopCondition(inst)) {
            returnCodes.insert(make_pair(inst,nothing));
            continue;
        }

        const auto rc = inst->doStep(nStep);

        returnCodes.insert(make_pair(inst,rc));
        newSweepposition[inst->getDroneID()] = inst->getSweepposition();
    }

    if (delayMax == 0) {
        oldSweepposition = newSweepposition;
        newValue = false;
    }
    else {
        newValue = true;
        delay = 0;
    }

    const auto rc = makeReturnCode(returnCodes);
    return rc;
}

ReturnCode compDroneSweep::makeReturnCode(const unordered_map<DroneSweep*,ReturnCode>& returnCodes) {
    using enum ReturnCode;

    for (const auto& [inst, code] : returnCodes) {
        if (code == objective_found) return objective_found;
        if (code == other) return other;
        if (code == low_battery) inst->setStatus(false);
    }

    for (const auto& [id, obj] : appli)
        if (obj->getStatus() == true) return nothing;

    return low_battery;
}

bool compDroneSweep::stopCondition(DroneSweep* inst) {
    if (inst->getStatus() == false) return true;

    const auto& collisionRadius = inst->getCollisionRadius();
    auto& position = inst->getPosition();
    const auto& droneID = inst->getDroneID();
    for (const auto& [id, other] : appli)
        if (vect2::distance(position, other->getPosition()) <= collisionRadius) {
            if (droneID == id) continue;
            cout << "drone " << droneID << " collided with drone " << id << '\n';
            inst->setStatus(false);
            other->setStatus(false);
            return true;
        }
            
    return false;
}

void compDroneSweep::updateNumberOfInstances(const unsigned int arg) {
    if (appli.size() == arg) return;
    if (appli.size() < arg) {
        const auto obj = new DroneSweep(this, appli.size());
        appli.insert(make_pair(appli.size(),obj));
        oldSweepposition.push_back(obj->getSweepposition());
        newSweepposition.push_back(obj->getSweepposition());
        obj->setrItfGeoDataSweep(appli[0]->getItfGeoDataInterface());
        obj->setrItfManageSimSweep(appli[0]->getItfManageSimInterface());
        obj->setrItfSimDataSweep(appli[0]->getItfSimDataInterface());
        obj->setSpeed(appli[0]->getSpeed());
    }
    else {
        appli.erase(--appli.end());
        oldSweepposition.pop_back();
        newSweepposition.pop_back();
    }
}

void compDroneSweep::printInstRecap() {
    for (const auto& [id, obj] : appli) {
        obj->printRecap();
    }
}

void compDroneSweep::readInputs() {}

void compDroneSweep::initialize() {
    for (const auto& [id, obj] : appli) {
        obj->setPosition(vect2(0.0,id*10)); // tous les 10m
        obj->initialize();
    }
        
}

void compDroneSweep::end() {
    for (const auto& [id, obj] : appli)
        obj->end();
}

vector<vect2> compDroneSweep::getSweepposition() {
    return oldSweepposition;
}

void compDroneSweep::setrItfGeoDataSweep(ItfGeoDataInterface* arItfGeoDataSweep) {
    for (const auto& [id, obj] : appli)
        obj->setrItfGeoDataSweep(arItfGeoDataSweep);
}

void compDroneSweep::setrItfManageSimSweep(ItfManageSimInterface* arItfManageSimSweep) {
    for (const auto& [id, obj] : appli)
        obj->setrItfManageSimSweep(arItfManageSimSweep);
}

void compDroneSweep::setrItfSimDataSweep(ItfSimDataInterface* arItfSimDataSweep) {
    for (const auto& [id, obj] : appli)
        obj->setrItfSimDataSweep(arItfSimDataSweep);
}

unordered_map<int, DroneSweep*> compDroneSweep::getAppli() {
    return appli;
}

// +++++++++++++ Access for minSpeed parameter +++++++++++++
double compDroneSweep::getMinSpeed() {
    return appli[0]->getMinSpeed();
}

void compDroneSweep::setMinSpeed(double arg) {
    for (const auto& [id, obj] : appli)
        obj->setMinSpeed(arg);
}

// +++++++++++++ Access for minSpeed parameter +++++++++++++
double compDroneSweep::getMaxSpeed() {
    return appli[0]->getMaxSpeed();
}

void compDroneSweep::setMaxSpeed(double arg) {
    for (const auto& [id, obj] : appli)
        obj->setMaxSpeed(arg);
}

// +++++++++++++ Access for visionRadius parameter +++++++++++++
double compDroneSweep::getVisionRadius() {
    return appli[0]->getVisionRadius();
}

void compDroneSweep::setVisionRadius(double arg) {
    for (const auto& [id, obj] : appli)
        obj->setVisionRadius(arg);
}

// +++++++++++++ Access for sweepHeight parameter +++++++++++++
double compDroneSweep::getSweepHeight() {
    return appli[0]->getSweepHeight();
}

void compDroneSweep::setSweepHeight(double arg) {
    for (const auto& [id, obj] : appli)
        obj->setSweepHeight(arg);
}

// +++++++++++++ Access for batteryCapacity parameter +++++++++++++
double compDroneSweep::getBatteryCapacity() {
    return appli[0]->getBatteryCapacity();
}

void compDroneSweep::setBatteryCapacity(double arg) {
    for (const auto& [id, obj] : appli)
        obj->setBatteryCapacity(arg);
}

// +++++++++++++ Access for numberOf parameter +++++++++++++
long compDroneSweep::getNumberOf() {
    return appli[0]->getNumberOf();
}

void compDroneSweep::setNumberOf(long arg) {
    updateNumberOfInstances(arg);
    for (const auto& [id, obj] : appli)
        obj->setNumberOf(arg);
}

// +++++++++++++ Access for startingPoint parameter +++++++++++++
vect2 compDroneSweep::getStartingPoint() {
    return appli[0]->getStartingPoint();
}

void compDroneSweep::setStartingPoint(vect2 arg) {
    for (const auto& [id, obj] : appli)
        obj->setStartingPoint(arg);
}

// +++++++++++++ Access for collisionRadius parameter +++++++++++++
double compDroneSweep::getCollisionRadius() {
    return appli[0]->getCollisionRadius();
}

void compDroneSweep::setCollisionRadius(double arg) {
    for (const auto& [id, obj] : appli)
        obj->setCollisionRadius(arg);
}

// +++++++++++++ Access for speed parameter +++++++++++++
double compDroneSweep::getSpeed() {
    return appli[0]->getSpeed();
}

void compDroneSweep::setSpeed(double arg) {
    for (const auto& [id, obj] : appli)
        obj->setSpeed(arg);
}
