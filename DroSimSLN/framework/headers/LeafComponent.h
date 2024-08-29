#ifndef LEAFCOMPONENT_H_
#define LEAFCOMPONENT_H_
#include "TimeableObject.h"

#include <string>
#include <vector>

#include "Client.h"
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
    virtual void getRequestResponse(const std::string& variable, const std::string& strvalue);
    virtual void getRequestResponseArray(const std::string& variable, const std::vector<std::string>& strvalues);

    bool start();

    bool stop();
};
#endif /* LEAFCOMPONENT_H_ */
