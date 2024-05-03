#ifndef LOGCOMPONENT_H_
#define LOGCOMPONENT_H_
#include <fstream>
using namespace std;
#include "TimeableObject.h"

//pyp
class LogComponent : public TimeableObject {
private :
    ofstream outputFile;
    //string dataWriterBuffer;

    int counter;

    int usage;

public :
    LogComponent(string filename, double aFrequency);
    ~LogComponent() override = 0;
    string filePath(string filename);
    void open();
    void WriteFirstLine();
    bool close();
    void writeNames(string names);
    void writeNewValues(double values);
    void writeNewValues(long values);
    void write(string value);
    void endLine();
    void timeStamp(long currentMS);
};
#endif /* LOGCOMPONENT_H_ */
