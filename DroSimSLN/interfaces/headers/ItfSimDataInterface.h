/*
 * ItfSimDataInterface.h
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#ifndef ItfSimDataInterface_H_
#define ItfSimDataInterface_H_
#include <iostream>
using namespace std;

class ItfSimDataInterface {
	public :
           virtual double grabExpectedEndTime() = 0;
           virtual double grabPositionCorrection() = 0;
};
#endif /* ItfSimDataInterface_H_ */
