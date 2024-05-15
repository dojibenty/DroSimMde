/*
 * User.h
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */
#ifndef User_H_
#define User_H_
#include "Clock.h"
#include "ItfGeoDataInterface.h"
#include "wect2.h"
class compUser;

#include "ItfManageSimInterface.h"

// Start of user code  : Additional imports for User
// End of user code

class User : public ItfManageSimInterface {
protected :
    compUser* myContainer;

    // Parameters
    long maxInlineZones;
    // Calculated attributes
    long droneCount;

    // Required Interfaces
    ItfGeoDataInterface* rItfGeoDataUser;

    // Start of user code  : Properties of User
private:
    vector<wect2> zones;
    bool isObjectiveFound = false;
    // End of user code

public :
    User(compUser* container);
    ~User();
    void initialize();
    void end();

    int doStep(int nStep);

    void setrItfGeoDataUser(ItfGeoDataInterface* arItfGeoDataUser);
        
    // +++++++++++++ Methods of the pItfManageSimulation interface +++++++++++++
    void signalObjectiveFound(long droneID) override;

    wect2 grabAssignedZone(long droneID) override;
    
    // +++++++++++++ Access for maxInlineZones parameter +++++++++++++
    long getMaxInlineZones();

    void setMaxInlineZones(long arg);

    // +++++++++++++ Access for droneCount calculated attribute +++++++++++++
    long getDroneCount();
    
    void setDroneCount(long arg);
    
    // Start of user code  : Additional methods
    static double randRange(double min, double max);
    vector<wect2> createZones() const;
    // End of user code
};
#endif /*  User_H_ */