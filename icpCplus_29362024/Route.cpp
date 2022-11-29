//
// Created by sblan on 24/11/2022.
//

#include "Route.h"

using namespace std;

/** A constructor for the Route class */
Route::Route(string airlineCode, string airlineId, string sourceAirportCode, string sourceAirportId,
             string destinationCode, string destinationId, string codeShare, int stops, string equipment) :
             airlineCode(airlineCode),
                airlineID(airlineId),
                sourceAirportCode(sourceAirportCode),
                sourceAirportID(sourceAirportId),
                destinationCode(destinationCode),
                destinationID(destinationId),
                codeShare(codeShare),
                stops(stops),
                equipment(equipment) {};

/** A default constructor for the Route class */
Route::Route(){};

/** A function that represents a string representation of the Route object */
string Route::asString() {
    string outputStr;
    outputStr = "Airport{sourceAirportCode=" +
                sourceAirportCode + "," + "destinationCode="
                + destinationCode + "," + "stops=" + to_string(stops) + "}";

    return outputStr;
}

//Various getters and setters
const string &Route::getAirlineCode() const {
    return airlineCode;
}

void Route::setAirlineCode(const string &airlineCode) {
    Route::airlineCode = airlineCode;
}

const string &Route::getAirlineId() const {
    return airlineID;
}

void Route::setAirlineId(const string &airlineId) {
    airlineID = airlineId;
}

const string &Route::getSourceAirportCode() const {
    return sourceAirportCode;
}

void Route::setSourceAirportCode(const string &sourceAirportCode) {
    Route::sourceAirportCode = sourceAirportCode;
}

const string &Route::getSourceAirportId() const {
    return sourceAirportID;
}

void Route::setSourceAirportId(const string &sourceAirportId) {
    sourceAirportID = sourceAirportId;
}

const string &Route::getDestinationCode() const {
    return destinationCode;
}

void Route::setDestinationCode(const string &destinationCode) {
    Route::destinationCode = destinationCode;
}

const string &Route::getDestinationId() const {
    return destinationID;
}

void Route::setDestinationId(const string &destinationId) {
    destinationID = destinationId;
}

const string &Route::getCodeShare() const {
    return codeShare;
}

void Route::setCodeShare(const string &codeShare) {
    Route::codeShare = codeShare;
}

int Route::getStops() const {
    return stops;
}

void Route::setStops(int stops) {
    Route::stops = stops;
}

const string &Route::getEquipment() const {
    return equipment;
}

void Route::setEquipment(const string &equipment) {
    Route::equipment = equipment;
}

// Equality Operators
bool Route::operator==(const Route &rhs) const {
    return sourceAirportCode == rhs.sourceAirportCode &&
           destinationCode == rhs.destinationCode;
}



