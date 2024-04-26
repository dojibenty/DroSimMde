#ifndef LEAFCOMPONENT_H_
#define LEAFCOMPONENT_H_
#include "TimeableObject.h"

class LeafComponent : public TimeableObject {
protected :
    int delayMax;
    bool isActive;

public :
    LeafComponent(double aFrequency);
    virtual ~LeafComponent() = 0;
    virtual void doStep(int nStep) override;

    bool getIsActive();

    int getDelayMax();

    void setDelayMax(int delayMax);

    bool start();

    bool stop();
};
#endif /* LEAFCOMPONENT_H_ */
