/*
 * compSimulation.h
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#ifndef compSimulation_H_
#define compSimulation_H_

#include "LeafComponent.h"
class Simulation;

#include "ItfSimDataInterface.h"

class compSimulation : public LeafComponent, public ItfSimDataInterface {
protected :
    /*pyp : inutile
    */

    bool newValue;
    int delay;


    Simulation* appli;

public :
    compSimulation(double aFrequency);
    virtual ~compSimulation();
    void doOneStep();
    void doStep(int nStep);

    virtual void readInputs();
    void initialize();
    void end();

    // +++++++++++++ Methods of the pItfSimData interface +++++++++++++
    double grabExpectedEndTime();

    double grabPositionCorrection();

    Simulation* getAppli();
    // +++++++++++++ Access for expectedEndTime parameter +++++++++++++
    double getExpectedEndTime();

    void setExpectedEndTime(double arg);
    // +++++++++++++ Access for positionCorrection parameter +++++++++++++
    double getPositionCorrection();

    void setPositionCorrection(double arg);
};
#endif /* compSimulation_H_ */
