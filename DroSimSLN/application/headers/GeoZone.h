/*
 * GeoZone.h
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */
#ifndef GeoZone_H_
#define GeoZone_H_
class compGeoZone;
#include "vect2.h"

#include "ItfGeoDataInterface.h"
#include "wect2.h"

// Start of user code  : Additional imports for GeoZone
// End of user code

class GeoZone : public ItfGeoDataInterface {
protected :
    compGeoZone* myContainer;

    // Parameters
    vect2 envSize;
    long maxInlineZones;
    vect2 bottomLeftPoint;


    // Start of user code  : Properties of GeoZone
private:
    vector<wect2> Zones;
    int droneCount;
    // End of user code

public :
    GeoZone(compGeoZone* container);
    ~GeoZone();
    void initialize();
    void end();

    void doStep(int nStep);

    // +++++++++++++ Methods of the pItfGeoData interface +++++++++++++
    vect2 grabEnvLimits() override;

    wect2 grabAssignedZone(long droneID) override;

    
    // Start of user code  : Additional methods
private:
    vector<wect2> CreateZones();

public:
    // +++++++++++++ Access for droneCount attribute +++++++++++++
    long getDroneCount();

    void setDroneCount(long arg);
    // End of user code


    // +++++++++++++ Access for envSize parameter +++++++++++++
    vect2 getEnvSize();

    void setEnvSize(vect2 arg);
    // +++++++++++++ Access for maxInlineZones parameter +++++++++++++
    long getMaxInlineZones();

    void setMaxInlineZones(long arg);
    // +++++++++++++ Access for bottomLeftPoint parameter +++++++++++++
    vect2 getBottomLeftPoint();

    void setBottomLeftPoint(vect2 arg);
};
#endif /*  GeoZone_H_ */
