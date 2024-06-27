/* 
 * ADroneSpiral.h
 * Root Component
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */
#ifndef ADroneSpiral_H_
#define ADroneSpiral_H_

#include "compDroneSpiral.h"
#include "AObjective.h"
class AWind;
class AObjective;

class ADroneSpiral : public compDroneSpiral {
protected :
    AObjective* attAObjective;
    AWind* attAWind;

public :
    ADroneSpiral(double aFrequency, int ID);
    virtual ~ADroneSpiral();

    void setAObjective(AObjective* pAObjective);
    void setAWind(AWind* pAWind);

    void readInputs() override;
};
#endif /*  ADroneSpiral_H_ */
