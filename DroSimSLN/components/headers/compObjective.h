/*
 * compObjective.h
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#ifndef compObjective_H_
#define compObjective_H_

#include "LeafComponent.h"
class Objective;

#include "vect2.h"

#include "ItfGeoDataInterface.h"

class compObjective : public LeafComponent {
protected :
    vect2 oldObjposition;
    vect2 newObjposition;

    bool newValue;
    int delay;

    Objective* appli;

public :
    compObjective(double aFrequency);
    virtual ~compObjective();
    void doOneStep();
    int doStep(int nStep);

    virtual void readInputs();
    void initialize();
    void end();

    vect2 getObjposition();
    void setrItfGeoDataObj(ItfGeoDataInterface* arItfGeoDataObj);
    Objective* getAppli();

    // +++++++++++++ Access for speedConstraint parameter +++++++++++++
    double getSpeedConstraint();

    void setSpeedConstraint(double arg);
    // +++++++++++++ Access for position parameter +++++++++++++
    vect2 getPosition();

    void setPosition(vect2 arg);
};
#endif /* compObjective_H_ */
