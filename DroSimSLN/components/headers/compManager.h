/*
 * compManager.h
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#ifndef compManager_H_
#define compManager_H_

#include "LeafComponent.h"
class Manager;




class compManager : public LeafComponent {

	protected :
/*pyp : inutile
*/

	 bool newValue;
	 int delay;


	Manager *appli;

	public :
           compManager(double aFrequency);
           virtual ~compManager();
	       void doOneStep();
	       void doStep(int nStep);

	       virtual void readInputs() ;
	       void initialize();
	       void end();
	
	     Manager *getAppli() ;
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
#endif /* compManager_H_ */