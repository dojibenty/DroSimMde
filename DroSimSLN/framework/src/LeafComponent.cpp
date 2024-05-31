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

std::string LeafComponent::getName() {
    return name;
}


bool LeafComponent::start() {
    isActive = true;
    return isActive;
}

bool LeafComponent::stop() {
    isActive = false;
    return isActive;
}
