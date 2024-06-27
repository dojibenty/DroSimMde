#ifndef LEAFCOMPONENT_H_
#define LEAFCOMPONENT_H_
#include "TimeableObject.h"

#include <string>

#include "ObjectCode.h"

class LeafComponent : public TimeableObject {
protected :
    int delayMax;
    bool isActive;
    ObjectCode objectcode_;

public :
    LeafComponent(double aFrequency);
    ~LeafComponent() override = 0;
    ReturnCode doStep(int nStep) override;

    bool getIsActive();

    int getDelayMax();

    void setDelayMax(int delayMax);

    ObjectCode getObjectCode() const;

    bool start();

    bool stop();
};
#endif /* LEAFCOMPONENT_H_ */
