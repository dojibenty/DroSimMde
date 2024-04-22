/*
 * vect2
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#ifndef vect2_H_
#define vect2_H_

#include <vector>
#include <iostream>
using namespace std;
// Start of user code  : Additional imports for vect2
// End of user code

class vect2 {
protected :
    double x;
    double y;

public :
    vect2();
    virtual ~vect2();
    vect2(double varx, double vary);

    double getX();

    void setX(double varx);
    double getY();

    void setY(double vary);
    // Start of user code  : Additional methods
    void switchSignX();
    void switchSignY();
    void normalize();
    static double distance(vect2& v1, vect2& v2);
    string toString() const;
    
    vect2 operator+(const vect2& vect2) const;
    vect2 operator*(double arg) const;
    vect2 operator-(const vect2& vect2) const;
    vect2 operator/(double arg) const;
    // End of user code
};
#endif /* vect2_H_ */
