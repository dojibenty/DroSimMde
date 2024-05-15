/*
 * myPositionsLogLogObservationComponent
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#include "myPositionsLogLogObservationComponent.h"
#include <iostream>
#include <string>

#include "Clock.h"
using namespace std;

myPositionsLogLogObservationComponent::myPositionsLogLogObservationComponent(string filename, double aFrequency): LogComponent( filename, aFrequency){
	try{
        WriteFirstLine();
	}
	catch (exception &e) {cerr << "myPositionsLogLogObservationComponent : " << e.what() << endl;}
}
myPositionsLogLogObservationComponent::~myPositionsLogLogObservationComponent(){}

void myPositionsLogLogObservationComponent::readInputs() {
    instObjposition = theObjective->getObjposition();
	instSweepposition.clear();
	for (DroneSweep* obj : theDroneSweep)
		instSweepposition.push_back(obj->getSweepposition());
	}

void myPositionsLogLogObservationComponent::WriteFirstLine() {
    string s = "time(ms)";
        s = s + ";" + "X.x;Y.y";
        s = s + ";" + "X.x;Y.y";
		writeNames( s);
		endLine();
	}

void myPositionsLogLogObservationComponent::setObjective(Objective *myObjective) {
		theObjective = myObjective;
	}
void myPositionsLogLogObservationComponent::setDroneSweep(vector<DroneSweep*> myDroneSweep) {
		theDroneSweep = myDroneSweep;
	}

int myPositionsLogLogObservationComponent::doStep(int nStep) {
	Clock *c = Clock::getInstance();
	readInputs();
	//int i = 0;
    long t = c->getCurrentMS();
    string s = "time:" + to_string( t) + ';' + '\n';
		try{
			s += "OBJECTIVE:\n";
			s += to_string(instObjposition.getX()) + ';';
			s += to_string(instObjposition.getY()) + ';';
			s += '\n';
		}
		catch (exception &e) {cerr << e.what() << endl;}

		try{
			for (vect2 pos : instSweepposition) {
				s += "DRONESWEEP:\n";
				s += to_string(pos.getX()) + ';';
				s += to_string(pos.getY()) + ';';
				s += '\n';
			}
		}
		catch (exception &e) {cerr << e.what() << endl;}

		//on retire le dernier ";" separateur
		//s = s.substring(0, s.length() - 1);
        //cout << "mySwimmerPositionLogObservationComponent::doStep : " << '\n' << s << endl;
		writeNames( s);
		endLine();

		return 0;
    }
