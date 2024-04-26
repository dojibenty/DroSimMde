#ifndef CLOCK_H_
#define CLOCK_H_

class Clock {
protected :
    long startTime = 0; // UTC epoch
    long stepTime = 1; // in ms
    long currentTime = 0; // UTC epoch
    long endTime = 0; // UTC epoch
    bool end;

private :
    static Clock* instance;
    Clock();
    virtual ~Clock();
    int i;

public :
    static Clock* getInstance();
    int cmpt();
    long getEndTime();
    void Init(long oneStartTime, long oneStepTime, long oneEndTime);
    long getStartTime();
    long getStepTime();
    long getCurrentMS();
    double getCurrentSecond();
    void setStepTime(int oneStepTime);
    void doStep();
    void stop();
    bool isFinished();
};
#endif /* CLOCK_H_ */
