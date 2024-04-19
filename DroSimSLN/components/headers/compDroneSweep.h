/*
 * compDroneSweep.h
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#ifndef compDroneSweep_H_
#define compDroneSweep_H_

#include "LeafComponent.h"
class DroneSweep;

#include "vect2.h"
#include "vect2.h"


#include "ItfEnvironmentInterface.h"
#include "vect2.h"
#include "wect2.h"
#include "ItfTargetObjectInterface.h"

class compDroneSweep : public LeafComponent {

	protected :
/*pyp : inutile
*/

	 bool newValue;
	 int delay;


	DroneSweep *appli;

	public :
           compDroneSweep(double aFrequency);
           virtual ~compDroneSweep();
	       void doOneStep();
	       void doStep(int nStep);

	       virtual void readInputs() ;
	       void initialize();
	       void end();
	
	     void setrItfEnvironmentSweep(ItfEnvironmentInterface *arItfEnvironmentSweep);
	     void setrItfTargetObjectSweep(ItfTargetObjectInterface *arItfTargetObjectSweep);
	     DroneSweep *getAppli() ;
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
	// +++++++++++++ Access for sweepHeight parameter +++++++++++++
	     double getSweepHeight();
	
	     void setSweepHeight(double arg);
};
#endif /* compDroneSweep_H_ */
