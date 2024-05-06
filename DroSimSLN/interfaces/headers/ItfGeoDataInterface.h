/*
 * ItfGeoDataInterface.h
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#ifndef ItfGeoDataInterface_H_
#define ItfGeoDataInterface_H_
using namespace std;
#include "vect2.h"
#include "wect2.h"

class ItfGeoDataInterface {
public :
    virtual vect2 grabEnvLimits() = 0;
    virtual wect2 grabAssignedZone(long droneID) = 0;
};
#endif /* ItfGeoDataInterface_H_ */
