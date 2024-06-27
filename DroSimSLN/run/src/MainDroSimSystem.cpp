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

namespace {
    void initRandom() {
        srand(time(nullptr));
        for (int i = 0; i < 5; i++) rand();
    }

    void initRandom(const int& shuffles) {
        srand(time(nullptr));
        for (int i = 0; i < shuffles; i++) rand();
    }
}

int main() {
    auto* root = new DroSimSystem();
    initRandom(20);
    int simCount = 15;
    double summedTimesToFind;
    int successfulSims;
    do {
        summedTimesToFind = 0;
        successfulSims = 0;
        for (int i = 0; i < simCount; i++) {
            //pyp : configuration des switches et autres actions
            for (const auto& inst : root->get_ADroneSpiral()) inst->stop();
            root->initialize();
            //pyp : run des observations
            auto* simulatedScenario = new ScenarLog(root);
            /*
            string si = to_string(i);
            string fileName = "PositionsLog";
            const string completeFileName = fileName + si;
            auto* PositionsLogLogObservationComponent = new
                myPositionsLogLogObservationComponent(completeFileName, 1.0);
            PositionsLogLogObservationComponent->setObjective(root->get_AObjective()->getAppli());
            PositionsLogLogObservationComponent->setDroneSweep(root->get_ADroneSweep()->getAppli());
            simulatedScenario->push(PositionsLogLogObservationComponent);
            */

            simulatedScenario->setTime(0, 360000);
            for (const auto& inst : root->get_ADroneSweep())
                simulatedScenario->droneSweepList.push_back(inst);
            auto simResult = simulatedScenario->startSimulation();
            if (get<0>(simResult)) {
                successfulSims++;
                summedTimesToFind += get<1>(simResult);
            }
            root->end();
            simulatedScenario->end();
        }
        root->mutateParameters(successfulSims >= simCount / 2, summedTimesToFind/successfulSims); 
    } while (root->continueCondition());

    const auto slowConfigs = root->getSlowConfigs();
    const auto fastConfig = root->getFastConfig();

    cout << "Fast config:\n";
    cout << "speed:" << get<0>(fastConfig) << " ; minNumberOf: " << get<1>(fastConfig) << " ; batteryCap: " << get<2>(fastConfig) << '\n';
    cout << "\nSlow configs:\n";
    for (auto t : slowConfigs)
        cout << "speed:" << get<0>(t) << " ; numberOf: " << get<1>(t) << " ; batteryCap: " << get<2>(t) << '\n';
    
    // Start of user code  : Additional code main for testDroSim
    // End of user code
}
