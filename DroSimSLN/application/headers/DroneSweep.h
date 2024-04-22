/*
 * DroneSweep.h
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */
#ifndef DroneSweep_H_
#define DroneSweep_H_
#include "Clock.h"
class compDroneSweep;
	// Inputs
#include "vect2.h"
#include "vect2.h"
#include "vect2.h"

#include "ItfEnvironmentInterface.h"
#include "vect2.h"
#include "wect2.h"

// Start of user code  : Additional imports for DroneSweep
// End of user code

class DroneSweep {

	protected :
              compDroneSweep *myContainer;

	// Inputs
	          vect2 objposition;
	// Parameters
	          long ID;
	          double speed;
	          vect2 position;
	          vect2 direction;
	          double visionRadius;
	          double sweepHeight;
	          double movementTolerance;

	// Required Interfaces
	          ItfEnvironmentInterface *rItfEnvironmentSweep;

// Start of user code  : Properties of DroneSweep
protected:
    wect2 assignedZone;

private:
    vect2 destination;
    bool goesUp = true;
    bool leftToRight = true;
    bool topToBottom = false;
    long heightCount = 0;
    double sweepLength;
    double leftYBound;
    // End of user code

	public :
            DroneSweep(compDroneSweep *container);
            ~DroneSweep();
	        void initialize();
	       void end();

	       void doStep(int nStep);


              // Start of user code  : Additional methods
private:
    void SetDestination();
    bool GoesOutOfBounds();
public:
	void setAssignedZone(wect2 zone);
	void lateinitialize();
    // End of user code
	

	     void setObjposition(vect2 arg) ;

	    void setrItfEnvironmentSweep(ItfEnvironmentInterface *arItfEnvironmentSweep);
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
	// +++++++++++++ Access for movementTolerance parameter +++++++++++++
	    double getMovementTolerance();
	
	    void setMovementTolerance(double arg);
};
#endif /*  DroneSweep_H_ */
