/*
 * ItfWindForceInterface.h
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#ifndef ItfWindForceInterface_H_
#define ItfWindForceInterface_H_
#include <iostream>
using namespace std;
#include "vect2.h"

class ItfWindForceInterface {
	public :
           virtual double grabForce() = 0;
           virtual vect2 grabDirection() = 0;
};
#endif /* ItfWindForceInterface_H_ */
