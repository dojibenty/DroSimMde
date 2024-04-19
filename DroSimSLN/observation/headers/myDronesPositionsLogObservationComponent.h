/*
 * myDronesPositionsLogObservationComponent
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */
#ifndef myDronesPositionsLogObservationComponent_H_
#define myDronesPositionsLogObservationComponent_H_

#include "Clock.h"
#include "LogComponent.h"
#include <fstream>
using namespace std;
#include "Objective.h"

class myDronesPositionsLogObservationComponent : public LogComponent {
	
	//pyp : LeafComponent qui g�n�re les donn�es sur le port (OutputPort) 
	protected :
    	Objective  *theObjective;
		//pyp : variables permettant de r�cup�rer les donn�es lues
		double instObjposX;
		double instObjposY;

	
	private :
		bool first = true;
	
	public :
	    myDronesPositionsLogObservationComponent(string filename, double aFrequency);
	    virtual ~myDronesPositionsLogObservationComponent();
		void readInputs();
		void WriteFirstLine();

		void setObjective(Objective *myObjective);
		void doStep(int nStep);
};
#endif /* myDronesPositionsLogObservationComponent */