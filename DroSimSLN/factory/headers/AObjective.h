/* 
 * AObjective.h
 * Root Component
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */
#ifndef AObjective_H_
#define AObjective_H_

#include "compObjective.h"

class AObjective : public compObjective {
	protected :

	public :

            AObjective(double aFrequency);
            virtual ~AObjective();


	        void readInputs()  override;
};
#endif /*  AObjective_H_ */