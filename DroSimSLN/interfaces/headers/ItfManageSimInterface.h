/*
 * ItfManageSimInterface.h
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#ifndef ItfManageSimInterface_H_
#define ItfManageSimInterface_H_
#include <iostream>
using namespace std;

class ItfManageSimInterface {
public :
    virtual void signalObjectiveFound(long droneID) = 0;
    virtual wect2 grabAssignedZone(long droneID) = 0;
};
#endif /* ItfManageSimInterface_H_ */
