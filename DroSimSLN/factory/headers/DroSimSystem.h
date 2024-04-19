/* 
 * DroSimSystem.java
 * Root Component
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */
#ifndef DroSimSystem_H_
#define DroSimSystem_H_

//#include <vector>
//#include "LeafComponent.h"
#include "RootComponent.h"

#include "ADroneSweep.h"
#include "vect2.h"
#include "vect2.h"
#include "ADroneSpiral.h"
#include "vect2.h"
#include "vect2.h"
#include "AObjective.h"
#include "vect2.h"
#include "AManager.h"
#include "AEnvironment.h"
#include "vect2.h"
// Start of user code  : Additional imports for DroSimSystem
// End of user code

class DroSimSystem : public RootComponent {

// generated pointers on child leafComponents
	protected :
              ADroneSweep *instADroneSweep;
              ADroneSpiral *instADroneSpiral;
              AObjective *instAObjective;
              AManager *instAManager;
              AEnvironment *instAEnvironment;


     public :
       DroSimSystem();
       virtual ~DroSimSystem();
// generated getters of child leafComponents
       ADroneSweep *get_ADroneSweep();
       ADroneSpiral *get_ADroneSpiral();
       AObjective *get_AObjective();
       AManager *get_AManager();
       AEnvironment *get_AEnvironment();

      void initialize() ;

      void end() ;
};
#endif /*  DroSimSystem_H_ */
