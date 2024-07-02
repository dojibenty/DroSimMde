/*
 * User.cpp
 *
 * Generated by Cares generator, written with Acceleo
 * Author: pyp
 */

#include "User.h"
#include "compUser.h"
// Start of user code  : Additional imports for User
// End of user code


User::User(compUser* container) {
    myContainer = container;
    // Start of user code  : Implementation of constructor method

    // End of user code
}

User::~User() {
    // Start of user code  : Implementation of destructor method

    // End of user code
}

void User::initialize() {
    // Start of user code  : Implementation of initialize method
    zones = createZones();
    // End of user code
}

void User::end() {
    // Start of user code  : Implementation of end method

    // End of user code
}

ReturnCode User::doStep(int nStep) {
    // Start of user code  : Implementation of doStep method
    return ReturnCode::proceed;
    // End of user code
}

// +++++++++++++ Methods of the pItfManageSimulation interface +++++++++++++
void User::signalObjectiveFound(long droneID) {
    // Start of user code  : Implementation of method signalObjectiveFound
    isObjectiveFound = true;
    if (!isObjectiveFound) cout << "Objective found by drone " << droneID << '\n';
    // End of user code
}

wect2 User::grabAssignedZone(long droneID) {
    return zones[droneID];
}


// Start of user code  : Additional methods
double User::randRange(const double min, const double max) {
    return min + (double)rand()/RAND_MAX * (max - min);
}

double User::roundToDecimal(const double number, const int decimal) {
    if (number == 0.0) return number;
    if (decimal == 0) return number;
    
    const double power = pow(10, decimal);
    double rounded;
    if ((rounded = round(number * power) / power) == 0.0)
        return roundToDecimal(number,decimal+1);
    return rounded;
}

int User::pickInlineZonesNumber(const int n) {
    const int sqrtN = (int)ceil(sqrt(n));
    return sqrtN;
}

vector<wect2> User::createZones() const {
    const int inlineZonesNumber = pickInlineZonesNumber(droneCount);
    const int filledLines = (int)floor((float)droneCount / (float)inlineZonesNumber);
    const int totalLines = (int)ceil((float)droneCount / (float)inlineZonesNumber);
    const int zonesLastLine = droneCount - filledLines * inlineZonesNumber;
    vect2 envSize = rItfGeoDataUser->grabEnvLimits();

    vector<vector<wect2>> localZones;

    // Filled lines
    for (int line = 0; line < filledLines; line++) {
        vector<wect2> Line;
        for (int zone = 0; zone < inlineZonesNumber; zone++) {
            wect2 Zone;

            // Top left point
            Zone.setV1({
                envSize.getX() - (envSize.getX() / totalLines) * line,
                (envSize.getY() / inlineZonesNumber) * zone
            });

            // Bottom right point
            Zone.setV2({
                envSize.getX() - (envSize.getX() / totalLines) * (line + 1),
                (envSize.getY() / inlineZonesNumber) * (zone + 1)
            });

            Line.push_back(Zone);
        }
        localZones.push_back(Line);
    }

    // Last line if excess zones
    if (zonesLastLine != 0) {
        vector<wect2> Line;
        for (int zone = 0; zone < zonesLastLine; zone++) {
            wect2 Zone;

            // Top left point
            Zone.setV1({
                envSize.getX() - (envSize.getX() / totalLines) * filledLines,
                (envSize.getY() / zonesLastLine) * zone
            });

            // Bottom right point
            Zone.setV2({
                0,
                (envSize.getY() / zonesLastLine) * (zone + 1)
            });

            Line.push_back(Zone);
        }
        localZones.push_back(Line);
    }

    vector<wect2> ZonesList;

    for (const auto& line : localZones)
        for (const wect2& zone : line)
            ZonesList.push_back(zone /*+ bottomLeftPoint*/);

    return ZonesList;
}

// End of user code

void User::setrItfGeoDataUser(ItfGeoDataInterface* arItfGeoDataUser) {
    rItfGeoDataUser = arItfGeoDataUser;
}

// +++++++++++++ Access for droneCount calculated attribute +++++++++++++
long User::getDroneCount() {
    return droneCount;
}

void User::setDroneCount(long arg) {
    droneCount = arg;
}
