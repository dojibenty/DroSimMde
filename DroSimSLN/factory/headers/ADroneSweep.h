/* 
 * ADroneSweep.h
 * Root Component
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */
#ifndef ADroneSweep_H_
#define ADroneSweep_H_

#include "compDroneSweep.h"
#include "AObjective.h"
#include "AWind.h"

class ADroneSweep : public compDroneSweep {
protected :
    AObjective* attAObjective;
    AWind* attAWind;

public :
    ADroneSweep(double aFrequency, int ID);
    virtual ~ADroneSweep();

    void setAObjective(AObjective* pAObjective);
    void setAWind(AWind* pAWind);

    void readInputs() override;
};
#endif /*  ADroneSweep_H_ */
