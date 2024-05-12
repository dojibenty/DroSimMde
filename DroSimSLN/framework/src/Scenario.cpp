#include "Scenario.h"
#include "TimeableObject.h"
#include "Clock.h"
#include <cmath>
#include <iostream>

Scenario::Scenario(RootComponent* aRoot) {
    stepTime = 1;
    max = 0;
    min = 0;
    simulationNumber = 0;
    root = aRoot;

    unsigned int j = aRoot->getListLeafComponents().size();
    for (unsigned int i = 0; i < j; i++) {
        long period;
        LeafComponent* lc = aRoot->getListLeafComponents().at(i);
        if (lc->getFrequency() <= 0) {
            period = 1;
        }
        else {
            period = round(1000.0 / (lc->getFrequency()));
        }
        periods.push_back(period);
    }

    simulationNumber = 0;

    //do not manage JSON files : jsonLogs = new ArrayList<JsonSeries>();
}

Scenario::~Scenario() {}

void Scenario::setTime(long m, long mx) {
    min = m;
    stepTime = 1;
    max = mx;
}

void Scenario::eventSimulation() {}

bool Scenario::startSimulation() {
    Clock* c = Clock::getInstance();
    c->Init(min, stepTime, max);
    simulationNumber++;
    bool isSimSuccessful = false;
    while (!c->isFinished()) {
        // scenario events
        eventSimulation();

        // run des composants
        unsigned int j = root->getListLeafComponents().size();
        int returnCode;
        bool doEndSim = false;
        for (unsigned int i = 0; i < j; i++) {
            LeafComponent* lc = root->getListLeafComponents().at(i);
            if (((c->getCurrentMS() % periods.at(i)) == 0) && lc->getIsActive()) {
                returnCode = lc->doStep(lc->getDelayMax());
                string str;
                switch (returnCode) {
                case 1:
                    str = "objective found," + lc->getName();
                    isSimSuccessful = true;
                    break;
                case 2:
                    str = "drones batteries are empty";
                    break;
                default:
                    str = "other," + lc->getName();
                }
                if (returnCode != 0) {
                    cout << '(' <<  c->getCurrentMS() << ',' << str << ')' << '\n';
                    doEndSim = true;
                }
                
            }
        }
        //pyp : run des observations
        j = getCsvLogs().size();
        for (unsigned int i = 0; i < j; i++) {
            LogComponent* lc = getCsvLogs().at(i);
            long periode = (long)(1 / lc->getFrequency()) * 1000L; //ms
            //cout << "Scenario::startSimulation : periode : " << periode << " freq : " << lc->getFrequency() << endl;
            if ((c->getCurrentMS() % periode) == 0) {
                lc->doStep(0);
            }
        }
        /*
        for( TimeableObject lc : getJsonLogs()){
            long periode = (long)( 1 / lc.getFrequency()) * 1000L;//ms
            if ((Clock.getCurrentMS() % periode) == 0){
                
                lc.doStep( 0);
            }
        }
*/
        //fin pyp
        c->doStep();
        if (c->getCurrentMS() % (c->getEndTime() / 10) == 0) {
            std::cout << (int)(100 * ((double)c->getCurrentMS() / c->getEndTime())) << " %" << std::endl;
        }
        if (doEndSim) break;
    }
    return isSimSuccessful;
}

//pyp
vector<LogComponent*> Scenario::getCsvLogs() {
    return csvLogs;
}

/* do not manage JSON files :
public List<JsonSeries> getJsonLogs() {
    return jsonLogs;
}
*/
void Scenario::push(LogComponent* logc) {
    csvLogs.push_back(logc);
}

void Scenario::end() {}
