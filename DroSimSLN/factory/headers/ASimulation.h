/* 
 * ASimulation.h
 * Root Component
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */
#ifndef ASimulation_H_
#define ASimulation_H_

#include "compSimulation.h"

class ASimulation : public compSimulation {
protected :

public :
    ASimulation(double aFrequency);
    virtual ~ASimulation();


    void readInputs() override;
};
#endif /*  ASimulation_H_ */
