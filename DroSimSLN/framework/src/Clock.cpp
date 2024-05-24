#include <Clock.h>

long Clock::getEndTime() {
    return endTime;
}

void Clock::Init(long oneStartTime, long oneStepTime, long oneEndTime) {
    startTime = oneStartTime;
    currentTime = startTime;
    stepTime = oneStepTime;
    endTime = oneEndTime;
    end = false;
}

long Clock::getStartTime() {
    return startTime;
}

long Clock::getStepTime() {
    return stepTime;
}

long Clock::getCurrentMS() {
    return currentTime;
}

double Clock::getCurrentSecond() {
    double result = currentTime / 1000.0;
    return (result);
}

void Clock::setStepTime(int oneStepTime) {
    stepTime = oneStepTime;
}

void Clock::doStep() {
    currentTime += stepTime;
}

void Clock::stop() {
    end = true;
}

bool Clock::isFinished() {
    return ((currentTime > endTime) || end);
}

Clock::Clock() {
    i = 0;
    startTime = 0; // UTC epoch
    stepTime = 10; // in ms
    currentTime = 0; // UTC epoch
    endTime = 0; // UTC epoch
    end = false;
}

Clock::~Clock() {}

Clock* Clock::instance = 0;

Clock* Clock::getInstance() {
    if (instance == 0) {
        instance = new Clock();
    }

    return instance;
}

int Clock::cmpt() {
    return ++i;
}
