#include "LeafComponent.h"

LeafComponent::LeafComponent(double aFrequency) : TimeableObject(aFrequency) {
    delayMax = 0;
    isActive = false;
}

LeafComponent::~LeafComponent() {}

ReturnCode LeafComponent::doStep(int nStep) { return ReturnCode::proceed; }

bool LeafComponent::getIsActive() {
    return isActive;
}

int LeafComponent::getDelayMax() {
    return delayMax;
}

void LeafComponent::setDelayMax(int dm) {
    delayMax = dm;
}

ObjectCode LeafComponent::getObjectCode() const {
    return objectcode_;
}

bool LeafComponent::start() {
    isActive = true;
    return isActive;
}

bool LeafComponent::stop() {
    isActive = false;
    return isActive;
}
