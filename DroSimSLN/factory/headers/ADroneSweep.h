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

class ADroneSweep : public compDroneSweep {
	protected :

	public :

            ADroneSweep(double aFrequency);
            virtual ~ADroneSweep();


	        void readInputs()  override;
};
#endif /*  ADroneSweep_H_ */