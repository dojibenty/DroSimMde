/* 
 * DroSimSystem.cpp
 * Root Component
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */
#include "DroSimSystem.h"
#include "Simulation.h"
#include "Wind.h"
#include "User.h"
#include "GeoZone.h"
#include "Objective.h"
#include "DroneSweep.h"
#include "DroneSpiral.h"

ASimulation* DroSimSystem::get_ASimulation() {
    return instASimulation;
}

AWind* DroSimSystem::get_AWind() {
    return instAWind;
}

AUser* DroSimSystem::get_AUser() {
    return instAUser;
}

AGeoZone* DroSimSystem::get_AGeoZone() {
    return instAGeoZone;
}

AObjective* DroSimSystem::get_AObjective() {
    return instAObjective;
}

ADroneSweep* DroSimSystem::get_ADroneSweep() {
    return instADroneSweep;
}

ADroneSpiral* DroSimSystem::get_ADroneSpiral() {
    return instADroneSpiral;
}

DroSimSystem::DroSimSystem() {
    //leafComponents = new std::vector<LeafComponent*>();
    instASimulation = new ASimulation(1.0);
    leafComponents.push_back(instASimulation);
    instAWind = new AWind(1.0);
    leafComponents.push_back(instAWind);
    instAUser = new AUser(1.0);
    leafComponents.push_back(instAUser);
    instAGeoZone = new AGeoZone(1.0);
    leafComponents.push_back(instAGeoZone);
    instAObjective = new AObjective(1.0);
    leafComponents.push_back(instAObjective);
    instADroneSweep = new ADroneSweep(10.0);
    leafComponents.push_back(instADroneSweep);
    instADroneSpiral = new ADroneSpiral(1.0);
    leafComponents.push_back(instADroneSpiral);
    instADroneSweep->setAObjective(instAObjective);
    instADroneSweep->setAWind(instAWind);
    instADroneSpiral->setAObjective(instAObjective);
    instADroneSpiral->setAWind(instAWind);
    instAUser->setrItfGeoDataUser(instAGeoZone->getAppli());
    instAObjective->setrItfGeoDataObj(instAGeoZone->getAppli());
    instADroneSweep->setrItfManageSimSweep(instAUser->getAppli());
    instADroneSweep->setrItfGeoDataSweep(instAGeoZone->getAppli());
    instADroneSweep->setrItfSimDataSweep(instASimulation->getAppli());
    instADroneSpiral->setrItfManageSimSpiral(instAUser->getAppli());
    instADroneSpiral->setrItfGeoDataSpiral(instAGeoZone->getAppli());
    instADroneSpiral->setrItfSimDataSpiral(instASimulation->getAppli());

    minSpeed = 10.0;
    maxSpeed = 30.0;
    maxNumberOf = 8;
    maxBatCount = 5;
    speedIncrement = 2.0;
    numberOfIncrement = 1;

    // Parametres mutables (initialisation)
    instADroneSweep->setSpeed(minSpeed);
    //instADroneSpiral->setSpeed(minSpeed);
    instADroneSweep->setNumberOf(1);
    instADroneSpiral->setNumberOf(0);
    instADroneSweep->setBatteryCount(maxBatCount);
    //instADroneSpiral->setBatteryCount(maxBatCount);
}

DroSimSystem::~DroSimSystem() {}

void DroSimSystem::initialize() {
    instASimulation->setExpectedEndTime(300000.0);
    instASimulation->setPositionCorrection(1.0);
    //instASimulation->setFrequency(0.0);
    instAWind->setForce(0.0);
    instAWind->setDirection(vect2(0.5, 0.5));
    //instAWind->setFrequency(0.0);
    instAUser->setMaxInlineZones(3);
    //instAUser->setFrequency(0.0);
    instAGeoZone->setEnvSize(vect2(20000.0, 20000.0));
    instAGeoZone->setBottomLeftPoint(vect2(45.0, -5.0));
    //instAGeoZone->setFrequency(0.0);
    instAObjective->setSpeedConstraint(0.0);
    instAObjective->setPosition(vect2(0, 0));
    //instAObjective->setFrequency(1.0);
    instADroneSweep->setMinSpeed(10.0);
    instADroneSweep->setMaxSpeed(30.0);
    instADroneSweep->setVisionRadius(1000.0);
    instADroneSweep->setSweepHeight(2000.0);
    instADroneSweep->setBatteryCapacity(200.0);
    instADroneSweep->setCollisionRadius(5.0);
    //instADroneSweep->setNumberOf(1); -> mutable
    instADroneSweep->setStartingPoint(vect2(0.0, 0.0));
    //instADroneSweep->setFrequency(1.0);
    instADroneSpiral->setMinSpeed(10.0);
    instADroneSpiral->setMaxSpeed(30.0);
    instADroneSpiral->setVisionRadius(100.0);
    instADroneSpiral->setSpiralRadius(200.0);
    instADroneSpiral->setConcentricCircles(false);
    instADroneSpiral->setNbCirclePoints(8);
    instADroneSpiral->setSpiralIncrementFactor(3);
    instADroneSpiral->setWanderSteps(5);
    instADroneSpiral->setBatteryCapacity(900.0);
    instADroneSpiral->setNumberOf(0);
    instADroneSpiral->setStartingPoint(vect2(0.5, 0.5));
    //instADroneSpiral->setFrequency(2.0);

    // Calcultated attributes
    instAUser->setDroneCount(instADroneSweep->getNumberOf() + instADroneSpiral->getNumberOf());

    // Initialization
    if (instASimulation->getIsActive()) instASimulation->initialize();
    if (instAWind->getIsActive()) instAWind->initialize();
    if (instAUser->getIsActive()) instAUser->initialize();
    if (instAGeoZone->getIsActive()) instAGeoZone->initialize();
    if (instAObjective->getIsActive()) instAObjective->initialize();
    if (instADroneSweep->getIsActive()) instADroneSweep->initialize();
    if (instADroneSpiral->getIsActive()) instADroneSpiral->initialize();
    // Start of user code  : Implementation of initialize method DroSimSystem
    // End of user code
}

void DroSimSystem::end() {
    instASimulation->end();
    instAWind->end();
    instAUser->end();
    instAGeoZone->end();
    instAObjective->end();
    instADroneSweep->end();
    instADroneSpiral->end();
    // Start of user code  : Implementation of end method DroSimSystem
    // End of user code
}

void DroSimSystem::mutateParameters(const bool isGroupSuccessful, const double averageTimeToFind) {
    cout << (isGroupSuccessful ? "Success" : "Fail") << endl;

    if (isGroupSuccessful) cout << "Average of " << (int)(averageTimeToFind / 1000 / 60 * 10) << " min to find\n";

    const double groupSpeed = instADroneSweep->getSpeed();
    const int groupNumberOf = instADroneSweep->getNumberOf();
    cBatCount = isGroupSuccessful? calculateMinBatteryCountForGroup(averageTimeToFind) : instADroneSweep->getBatteryCount();
    
    if (!isCurveFound || isGroupSuccessful) {
        // We overwrite the saved config as we don't need it right now
        pSpeed = groupSpeed;
        pBatCount = cBatCount;
        //pBatCount = groupBatCount;
    }

    if (isCurveFound && isMaxFound) {
        if (isGroupSuccessful && groupSpeed - speedIncrement >= minSpeed)
            instADroneSweep->setSpeed(groupSpeed - speedIncrement);
        else {
            slowConfigs.push_back(make_tuple(pSpeed, groupNumberOf, pBatCount));

            instADroneSweep->setNumberOf(groupNumberOf + numberOfIncrement);

            // We save the current config for later comparison
            pSpeed = groupSpeed;
            //pBatCount = groupBatCount;
        }
    }
    else {
        if (!isCurveFound && isGroupSuccessful) {
            // Found the first valid configuration
            slowConfigs.push_back(make_tuple(groupSpeed, groupNumberOf, cBatCount));
            isCurveFound = true;
            cout << "Curve found" << '\n';
        }
        if (groupSpeed + speedIncrement <= maxSpeed)
            instADroneSweep->setSpeed(groupSpeed + speedIncrement);
        else if (isCurveFound) {
            // Found the maximum speed drones need to go at
            fastConfig = make_tuple(groupSpeed, groupNumberOf, cBatCount);
            isMaxFound = true;
            cout << "Max speed found" << '\n';
            instADroneSweep->setNumberOf(groupNumberOf + numberOfIncrement);
            instADroneSweep->setSpeed(groupSpeed - speedIncrement);
        }
        else {
            instADroneSweep->setNumberOf(groupNumberOf + numberOfIncrement);
            instADroneSweep->setSpeed(minSpeed);
        }
    }

    instADroneSweep->setBatteryCount(maxBatCount);
    
    cout << "Trying with " << instADroneSweep->getNumberOf()
    << " drone" << (instADroneSweep->getNumberOf() > 1 ? "s" : "")
    << " at " << instADroneSweep->getSpeed() << " m/s\n";
}

int DroSimSystem::calculateMinBatteryCountForGroup(const double averageTimeToFind) const {
    cout << "attf: " << averageTimeToFind << '\n';
    const double consumption = averageTimeToFind / 1000.0 * 10.0 / 60.0 / 60.0 * pow(instADroneSweep->getSpeed(), 2) * 2.0;
    cout << "conso: " << consumption << '\n';
    int bc = 1;
    while (bc * instADroneSweep->getBatteryCapacity() < consumption) bc++;
    if (bc >= maxBatCount) return maxBatCount;
    return bc;
}

bool DroSimSystem::continueCondition() const {
    return instADroneSweep->getNumberOf() <= maxNumberOf;
}

vector<tuple<double,int,int>> DroSimSystem::getSlowConfigs() {
    return slowConfigs;
}

tuple<double,int,int> DroSimSystem::getFastConfig() {
    return fastConfig;
}