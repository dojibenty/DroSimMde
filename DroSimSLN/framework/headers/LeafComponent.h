#ifndef LEAFCOMPONENT_H_
#define LEAFCOMPONENT_H_
#include "TimeableObject.h"

#include <string>

class LeafComponent : public TimeableObject {
protected :
    int delayMax;
    bool isActive;
    std::string name;

public :
    LeafComponent(double aFrequency);
    ~LeafComponent() override = 0;
    int doStep(int nStep) override;

    bool getIsActive();

    int getDelayMax();

    std::string getName();

    void setDelayMax(int delayMax);

    bool start();

    bool stop();
};
#endif /* LEAFCOMPONENT_H_ */
