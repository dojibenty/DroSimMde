/*
 * wect2
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#ifndef wect2_H_
#define wect2_H_

#include <vector>
#include <iostream>
using namespace std;
// Start of user code  : Additional imports for wect2
#include "vect2.h"
// End of user code

class wect2 {
protected :
    vect2 v1;
    vect2 v2;

public :
    wect2();
    virtual ~wect2();
    wect2(vect2 varv1, vect2 varv2);

    vect2 getV1();

    void setV1(vect2 varv1);
    vect2 getV2();

    void setV2(vect2 varv2);
    // Start of user code  : Additional methods

    // End of user code
};
#endif /* wect2_H_ */