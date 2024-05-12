/*
 * compDroneSweep.h
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#ifndef compDroneSweep_H_
#define compDroneSweep_H_

#include "DroneSweep.h"
#include "LeafComponent.h"
class DroneSweep;

#include "vect2.h"

#include "ItfGeoDataInterface.h"
#include "ItfWindForceInterface.h"
#include "ItfManageSimInterface.h"
#include "ItfSimDataInterface.h"

class compDroneSweep : public LeafComponent {
protected :
    /*pyp : inutile
        //inputs source
         LeafComponent ObjpositionSourceComponent;
         String portNameObjposition;
    */
    vector<DroneSweep*> appli;
    vector<int> terminated;
    vector<vect2> oldSweepposition;
    vector<vect2> newSweepposition;

    string name = "DroneSweep"; 

    bool newValue;
    int delay;

public :
    compDroneSweep(double aFrequency, long numberOf);
    virtual ~compDroneSweep();
    void doOneStep();
    int doStep(int nStep);

    virtual void readInputs();
    void initialize();
    void end();

    vector<vect2> getSweepposition();
    void setrItfGeoDataSweep(ItfGeoDataInterface* arItfGeoDataSweep);
    void setrItfWindForceSweep(ItfWindForceInterface* arItfWindForceSweep);
    void setrItfManageSimSweep(ItfManageSimInterface* arItfManageSimSweep);
    void setrItfSimDataSweep(ItfSimDataInterface* arItfSimDataSweep);
    vector<DroneSweep*> getAppli();
    
    string getName() { return name; }
    double getSpeed() { return appli[0]->getSpeed(); }
    void setSpeed(double arg) { for (DroneSweep* obj : appli) obj->setSpeed(arg); }
    // +++++++++++++ Access for minSpeed parameter +++++++++++++
    double getMinSpeed();

    void setMinSpeed(double arg);
    // +++++++++++++ Access for minSpeed parameter +++++++++++++
    double getMaxSpeed();

    void setMaxSpeed(double arg);
    // +++++++++++++ Access for visionRadius parameter +++++++++++++
    double getVisionRadius();

    void setVisionRadius(double arg);
    // +++++++++++++ Access for sweepHeight parameter +++++++++++++
    double getSweepHeight();

    void setSweepHeight(double arg);
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
#endif /* compDroneSweep_H_ */
