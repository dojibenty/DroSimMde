/*
 * compDroneSpiral.h
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#ifndef compDroneSpiral_H_
#define compDroneSpiral_H_

#include "DroneSpiral.h"
#include "LeafComponent.h"
class DroneSpiral;

#include "vect2.h"

#include "ItfGeoDataInterface.h"
#include "ItfManageSimInterface.h"
#include "ItfSimDataInterface.h"

class compDroneSpiral : public LeafComponent {
protected :
    /*pyp : inutile
        //inputs source
         LeafComponent ObjpositionSourceComponent;
         String portNameObjposition;
    */
    vect2 oldSpiralposition;
    vect2 newSpiralposition;

    bool newValue;
    int delay;

    DroneSpiral* appli;

public :
    compDroneSpiral(double aFrequency);
    virtual ~compDroneSpiral();
    void doOneStep();
    int doStep(int nStep);

    virtual void readInputs();
    void initialize();
    void end();

    vect2 getSpiralposition();
    void setrItfGeoDataSpiral(ItfGeoDataInterface* arItfGeoDataSpiral);
    void setrItfManageSimSpiral(ItfManageSimInterface* arItfManageSimSpiral);
    void setrItfSimDataSpiral(ItfSimDataInterface* arItfSimDataSpiral);
    DroneSpiral* getAppli();

    double getSpeed() { return appli->getSpeed(); }
    void setSpeed(double arg) { appli->setSpeed(arg); }
    // +++++++++++++ Access for minSpeed parameter +++++++++++++
    double getMinSpeed();

    void setMinSpeed(double arg);
    // +++++++++++++ Access for minSpeed parameter +++++++++++++
    double getMaxSpeed();

    void setMaxSpeed(double arg);
    // +++++++++++++ Access for visionRadius parameter +++++++++++++
    double getVisionRadius();

    void setVisionRadius(double arg);
    // +++++++++++++ Access for spiralRadius parameter +++++++++++++
    double getSpiralRadius();

    void setSpiralRadius(double arg);
    // +++++++++++++ Access for concentricCircles parameter +++++++++++++
    bool getConcentricCircles();

    void setConcentricCircles(bool arg);
    // +++++++++++++ Access for nbCirclePoints parameter +++++++++++++
    long getNbCirclePoints();

    void setNbCirclePoints(long arg);
    // +++++++++++++ Access for spiralIncrementFactor parameter +++++++++++++
    double getSpiralIncrementFactor();

    void setSpiralIncrementFactor(double arg);
    // +++++++++++++ Access for wanderSteps parameter +++++++++++++
    long getWanderSteps();

    void setWanderSteps(long arg);
    // +++++++++++++ Access for batteryCapacity parameter +++++++++++++
    double getBatteryCapacity();

    void setBatteryCapacity(double arg);
    // +++++++++++++ Access for numberOf parameter +++++++++++++
    long getNumberOf();

    void setNumberOf(long arg);
    // +++++++++++++ Access for startingPoint parameter +++++++++++++
    vect2 getStartingPoint();

    void setStartingPoint(vect2 arg);
};
#endif /* compDroneSpiral_H_ */
