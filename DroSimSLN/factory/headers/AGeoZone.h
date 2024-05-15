/* 
 * AGeoZone.h
 * Root Component
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */
#ifndef AGeoZone_H_
#define AGeoZone_H_

#include "compGeoZone.h"

class AGeoZone : public compGeoZone {
protected :

public :
    AGeoZone(double aFrequency);
    virtual ~AGeoZone();


    void readInputs() override;
};
#endif /*  AGeoZone_H_ */
