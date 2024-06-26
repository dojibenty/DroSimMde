/*
 * Wind.h
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */
#ifndef Wind_H_
#define Wind_H_
#include "Clock.h"
#include "ReturnCode.h"
class compWind;
#include "vect2.h"

// Start of user code  : Additional imports for Wind
// End of user code

class Wind {
protected :
    compWind* myContainer;

    // Outputs
    double windForce;
    vect2 windDirection;
    // Parameters
    double force;
    vect2 direction;
    double maxWindForce = 14.0;


    // Start of user code  : Properties of Wind
    double damp = .98;
    // End of user code

public :
    Wind(compWind* container);
    ~Wind();
    void initialize();
    void end();

    ReturnCode doStep(int nStep);

    double getWindForce();
    vect2 getWindDirection();

    // Start of user code  : Additional methods
    // End of user code

    // +++++++++++++ Access for force parameter +++++++++++++
    double getForce();

    void setForce(double arg);
    // +++++++++++++ Access for direction parameter +++++++++++++
    vect2 getDirection();

    void setDirection(vect2 arg);
};
#endif /*  Wind_H_ */
