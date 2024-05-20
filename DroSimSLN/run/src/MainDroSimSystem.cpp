/* 
 * Main for simulation
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

//#include "DroSimSystem.h"
#include "ScenarLog.h"
#include "myPositionsLogLogObservationComponent.h"
#include <tuple>
// Start of user code  : Additional imports for testDroSim
#include <string>
// End of user code

/* 
 * MainDroSimSystem for simulation
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

//import cares.framework.JsonSeries;
//import cares.framework.LogComponent;
#include "DroSimSystem.h"
#include "ScenarLog.h"
//#include "PositionsLogLogObservationComponent.h"
// Start of user code  : Additional imports for testDroSim
// End of user code

int main() {
    auto* root = new DroSimSystem();

    cout << "Speed is set to 500 m/s (? km/h)\n"; 
    for (int i = 0; i < 5; i++) {
        root->get_ADroneSpiral()->stop();
        root->initializeForTest_StopsAfterOneStep();
        auto* testScenario = new ScenarLog(root);
        testScenario->setTime(0,1000);
        testScenario->startSimulation();
        root->end();
        testScenario->end();
    }

    cout << "VisionRadius is set to 30000 m (30 km)\n";
    for (int i = 0; i < 5; i++) {
        root->get_ADroneSpiral()->stop();
        root->initializeForTest_FindsInstantly();
        auto* testScenario = new ScenarLog(root);
        testScenario->setTime(0,1000);
        testScenario->startSimulation();
        root->end();
        testScenario->end();
    }

    cout << "WindForce is set to 50 m/s (180 km/h)\n";
    for (int i = 0; i < 5; i++) {
        root->get_ADroneSpiral()->stop();
        root->initializeForTest_TooMuchWind();
        auto* testScenario = new ScenarLog(root);
        testScenario->setTime(0,1000);
        testScenario->startSimulation();
        root->end();
        testScenario->end();
    }
}
