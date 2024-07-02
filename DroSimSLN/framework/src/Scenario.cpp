#include "Scenario.h"
#include "TimeableObject.h"
#include "Clock.h"
#include <cmath>
#include <iostream>
#include <tuple>

#include "ADroneSweep.h"

Scenario::Scenario(RootComponent* aRoot) {
    stepTime = 10;
    max = 0;
    min = 0;
    simulationNumber = 0;
    root = aRoot;
    droneSweepList.reserve(10);
    droneSpiralList.reserve(10);
    simStatus = -1;
    doEndSim = false;

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
    stepTime = 10; // n'est pas mis à jour en changeant dans le scn
    max = mx;
}

void Scenario::eventSimulation() {}

tuple<bool, double> Scenario::startSimulation() {
    Clock* c = Clock::getInstance();
    c->Init(min, stepTime, max);
    simulationNumber++;
    while (!c->isFinished()) {
        // scenario events
        eventSimulation();

        // run des composants
        unsigned int j = root->getListLeafComponents().size();
        for (unsigned int i = 0; i < j; i++) {
            LeafComponent* lc = root->getListLeafComponents().at(i);
            if (((c->getCurrentMS() % periods.at(i)) == 0) && lc->getIsActive()) {
                const ReturnCode rc = lc->doStep(lc->getDelayMax());
                simulationResults.emplace_back(lc,rc,c->getCurrentMS());
            }
        }

        computeDoStepResults();

        postStepEvent();
        
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
            //std::cout << (int)(100 * ((double)c->getCurrentMS() / c->getEndTime())) << " %" << std::endl;
        }

        if (simStatus != -1) break;
    }
    return make_tuple(simStatus == 0, c->getCurrentMS());
}

void Scenario::computeDoStepResults() {
    for (const auto& res : simulationResults) {
        if (simStatus != -1) return;

        const auto& lc = get<0>(res);
        const ReturnCode code = get<1>(res);
        const double time = get<2>(res);

        using enum ReturnCode;
        
        switch (code) {
        // continue
        case proceed:
            break;
        // local stop
        case low_battery:
            lc->stop();
            cout << '(' << lc->getObjectCode() << ",low_battery," << time << ')' << '\n';
            break;
        // simulation success
        case objective_found:
            simStatus = 0;
            cout << '(' << lc->getObjectCode() << ",objective_found," << time << ')' << '\n';
            break;
        }
    }
}

void Scenario::postStepEvent() {
    checkDronesStatus();
    checkForCollisions();
}

void Scenario::checkDronesStatus() {
    for (const auto& d : droneSweepList)
        if (d->getIsActive()) return;

    for (const auto& d : droneSpiralList)
        if (d->getIsActive()) return;

    simStatus = 1;
}

void Scenario::checkForCollisions() const {
    for (const auto& d : droneSweepList) {
        if (!d->getIsActive()) continue;
        
        const auto& collisionRadius = d->getCollisionRadius();
        auto& position = d->getPosition();
        const auto& id = d->getID();
        for (const auto& other : droneSweepList)
            if (vect2::distance(position, other->getPosition()) <= collisionRadius) {
                if (id == other->getID()) continue;
                cout << "drone " << id << "collided with drone " << other->getID() << '\n';
                d->stop();
                other->stop();
            }
        for (const auto& other : droneSpiralList)
            if (vect2::distance(position, other->getPosition()) <= collisionRadius) {
                if (id == other->getID()) continue;
                cout << "drone " << id << "collided with drone " << other->getID() << '\n';
                d->stop();
                other->stop();
            }
    }
    for (const auto& d : droneSpiralList) {
        if (!d->getIsActive()) continue;
        
        const auto& collisionRadius = d->getCollisionRadius();
        auto& position = d->getPosition();
        const auto& id = d->getID();
        for (const auto& other : droneSweepList)
            if (vect2::distance(position, other->getPosition()) <= collisionRadius) {
                if (id == other->getID()) continue;
                cout << "drone " << id << "collided with drone " << other->getID() << '\n';
                d->stop();
                other->stop();
            }
        for (const auto& other : droneSpiralList)
            if (vect2::distance(position, other->getPosition()) <= collisionRadius) {
                if (id == other->getID()) continue;
                cout << "drone " << id << "collided with drone " << other->getID() << '\n';
                d->stop();
                other->stop();
            }
    }
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
