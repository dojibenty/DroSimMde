/*
 * ItfEnvironmentInterface.h
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#ifndef ItfEnvironmentInterface_H_
#define ItfEnvironmentInterface_H_
#include <iostream>
using namespace std;
#include "vect2.h"
#include "wect2.h"

class ItfEnvironmentInterface {
	public :
           virtual vect2 getEnvLimits() = 0;
           virtual wect2 getAssignedZone() = 0;
};
#endif /* ItfEnvironmentInterface_H_ */
