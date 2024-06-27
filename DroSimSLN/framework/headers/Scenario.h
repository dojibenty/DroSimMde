#ifndef SCENARIO_H_
#define SCENARIO_H_
#include "LeafComponent.h"
#include "RootComponent.h"
#include "LogComponent.h"
#include <vector>

#include "ADroneSweep.h"
#include "Clock.h"

class Scenario {
protected :
    //std::vector<LeafComponent*> &ptLeafComponents;
    vector<LogComponent*> csvLogs; //pyp

    RootComponent* root;
    long min;
    long stepTime;
    long max;

    std::vector<long> periods; // ms

    int simulationNumber;

    vector<tuple<LeafComponent*, ReturnCode, double>> simulationResults;
    bool isSimSuccessful;
    bool doEndSim;

public :
    Scenario(RootComponent* aRoot);
    virtual ~Scenario() =0;

    void setTime(long min, long max);

    tuple<bool, double> startSimulation();
    void computeDoStepResults();
    void checkForCollisions() const;

    virtual void eventSimulation() = 0;
    //pyp
    vector<LogComponent*> getCsvLogs();
    void end();
    void push(LogComponent* logc);

    vector<ADroneSweep*> droneSweepList;
};
#endif /* SCENARIO_H_ */
