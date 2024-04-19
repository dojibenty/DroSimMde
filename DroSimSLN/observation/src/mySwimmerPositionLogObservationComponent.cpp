/*
 * mySwimmerPositionLogObservationComponent
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#include "mySwimmerPositionLogObservationComponent.h"
#include <iostream>
using namespace std;

mySwimmerPositionLogObservationComponent::mySwimmerPositionLogObservationComponent(string filename, double aFrequency): LogComponent( filename, aFrequency){
	try{
        WriteFirstLine();
	}
	catch (exception &e) {cerr << "mySwimmerPositionLogObservationComponent : " << e.what() << endl;}
}
mySwimmerPositionLogObservationComponent::~mySwimmerPositionLogObservationComponent(){}

void mySwimmerPositionLogObservationComponent::readInputs() {
    instDroneData = theDroneSweep->getDroneData();
    instDroneData = theDroneSpiral->getDroneData();
    instObjposX = theObjective->getObjposX();
    instObjposY = theObjective->getObjposY();
	}

void mySwimmerPositionLogObservationComponent::WriteFirstLine() {
    string s = "time(ms)";
        s = s + ";" + "Strategy.strategy;ID.ID;PosX.posX;PosY.posY;HasFound.hasFound";
        s = s + ";" + "Strategy.strategy;ID.ID;PosX.posX;PosY.posY;HasFound.hasFound";
        s = s + ";" + "objposX";
        s = s + ";" + "objposY";
		writeNames( s);
		endLine();
	}

void mySwimmerPositionLogObservationComponent::setDroneSweep(DroneSweep *myDroneSweep) {
		theDroneSweep = myDroneSweep;
	}
void mySwimmerPositionLogObservationComponent::setDroneSpiral(DroneSpiral *myDroneSpiral) {
		theDroneSpiral = myDroneSpiral;
	}
void mySwimmerPositionLogObservationComponent::setObjective(Objective *myObjective) {
		theObjective = myObjective;
	}

void mySwimmerPositionLogObservationComponent::doStep(int nStep) {
	Clock *c = Clock::getInstance();
	readInputs();
	//int i = 0;
    long t = c->getCurrentMS();
    string s = to_string( t) + ";";
		try{

			s = s + to_string(instDroneData.getStrategy()) + ";";
			s = s + to_string(instDroneData.getID()) + ";";
			s = s + to_string(instDroneData.getPosX()) + ";";
			s = s + to_string(instDroneData.getPosY()) + ";";
			s = s + to_string(instDroneData.getHasFound()) + ";";		}
		catch (exception &e) {cerr << e.what() << endl;}

		try{

			s = s + to_string(instDroneData.getStrategy()) + ";";
			s = s + to_string(instDroneData.getID()) + ";";
			s = s + to_string(instDroneData.getPosX()) + ";";
			s = s + to_string(instDroneData.getPosY()) + ";";
			s = s + to_string(instDroneData.getHasFound()) + ";";		}
		catch (exception &e) {cerr << e.what() << endl;}

		try{
			s = s + to_string(instObjposX) + ";";
		}
		catch (exception &e) {cerr << e.what() << endl;}

		try{
			s = s + to_string(instObjposY) + ";";
		}
		catch (exception &e) {cerr << e.what() << endl;}

		//on retire le dernier ";" separateur
		//s = s.substring(0, s.length() - 1);
        cout << "mySwimmerPositionLogObservationComponent::doStep : " << s << endl;
		writeNames( s);
		endLine();
    }

