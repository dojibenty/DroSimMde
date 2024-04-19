/*
 * compDroneSpiral.h
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#ifndef compDroneSpiral_H_
#define compDroneSpiral_H_

#include "LeafComponent.h"
class DroneSpiral;

#include "vect2.h"
#include "vect2.h"


#include "ItfEnvironmentInterface.h"
#include "vect2.h"
#include "wect2.h"
#include "ItfTargetObjectInterface.h"

class compDroneSpiral : public LeafComponent {

	protected :
/*pyp : inutile
*/

	 bool newValue;
	 int delay;


	DroneSpiral *appli;

	public :
           compDroneSpiral(double aFrequency);
           virtual ~compDroneSpiral();
	       void doOneStep();
	       void doStep(int nStep);

	       virtual void readInputs() ;
	       void initialize();
	       void end();
	
	     void setrItfEnvironmentSpiral(ItfEnvironmentInterface *arItfEnvironmentSpiral);
	     void setrItfTargetObjectSpiral(ItfTargetObjectInterface *arItfTargetObjectSpiral);
	     DroneSpiral *getAppli() ;
	// +++++++++++++ Access for ID parameter +++++++++++++
	     long getID();
	
	     void setID(long arg);
	// +++++++++++++ Access for speed parameter +++++++++++++
	     double getSpeed();
	
	     void setSpeed(double arg);
	// +++++++++++++ Access for position parameter +++++++++++++
	     vect2 getPosition();
	
	     void setPosition(vect2 arg);
	// +++++++++++++ Access for direction parameter +++++++++++++
	     vect2 getDirection();
	
	     void setDirection(vect2 arg);
	// +++++++++++++ Access for visionRadius parameter +++++++++++++
	     double getVisionRadius();
	
	     void setVisionRadius(double arg);
	// +++++++++++++ Access for spiralRadius parameter +++++++++++++
	     double getSpiralRadius();
	
	     void setSpiralRadius(double arg);
	// +++++++++++++ Access for concentricCircles parameter +++++++++++++
	     bool getConcentricCircles();
	
	     void setConcentricCircles(bool arg);
	// +++++++++++++ Access for nbCirclePoints parameter +++++++++++++
	     long getNbCirclePoints();
	
	     void setNbCirclePoints(long arg);
};
#endif /* compDroneSpiral_H_ */