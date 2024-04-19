/*
 * Manager.h
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */
#ifndef Manager_H_
#define Manager_H_
#include "Clock.h"
class compManager;


// Start of user code  : Additional imports for Manager
// End of user code

class Manager {

	protected :
              compManager *myContainer;

	// Parameters
	          double simSpeed;
	          long sweepNumber;
	          long spiralNumber;


// Start of user code  : Properties of Manager
    private:
        std::vector<std::vector<std::vector<double>>> Zones;
// End of user code

	public :
            Manager(compManager *container);
            ~Manager();
	        void initialize();
	       void end();

	       void doStep(int nStep) ;
	
	
// Start of user code  : Additional methods
    private:
        std::vector<std::vector<std::vector<double>>> CreateZones()
// End of user code
	

	// +++++++++++++ Access for simSpeed parameter +++++++++++++
	    double getSimSpeed();
	
	    void setSimSpeed(double arg);
	// +++++++++++++ Access for sweepNumber parameter +++++++++++++
	    long getSweepNumber();
	
	    void setSweepNumber(long arg);
	// +++++++++++++ Access for spiralNumber parameter +++++++++++++
	    long getSpiralNumber();
	
	    void setSpiralNumber(long arg);
};
#endif /*  Manager_H_ */
