/* 
 * Scenario implementation
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */
#ifndef ScenarLog_H_
#define ScenarLog_H_

#include "scenario.h"
#include "RootComponent.h"
#include "DroSimSystem.h"


class ScenarLog : public Scenario{

	protected :
              DroSimSystem *application;
	
	public :
        ScenarLog(RootComponent *aRoot);
        virtual ~ScenarLog();
	    void eventSimulation() override;
};
#endif /* ScenarLog_H_ */
