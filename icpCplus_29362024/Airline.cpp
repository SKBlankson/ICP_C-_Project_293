//
// Created by sblan on 26/11/2022.
//

#include "Airline.h"

/** A constructor for the airline class */
Airline::Airline(int airlineId,  string name,  string iataCode,  string icaoCode,
                  string country) : airlineID(airlineId),
                 name(name),
                 iataCode(iataCode),
                 icaoCode(icaoCode),
                 country(country) {};

Airline::Airline() {};

/** A method that returns a string representation for the airline object */
string Airline::asString(){
    string outputStr;
    outputStr = "Airport{name=" +
                name + "," + "iataCode=" + iataCode + "}";

    return outputStr;
}

// Various getters,setters and equality methods
int Airline::getAirlineId() const {
    return airlineID;
}

void Airline::setAirlineId(int airlineId) {
    airlineID = airlineId;
}

const string &Airline::getName() const {
    return name;
}

void Airline::setName(const string &name) {
    Airline::name = name;
}

const string &Airline::getIataCode() const {
    return iataCode;
}

void Airline::setIataCode(const string &iataCode) {
    Airline::iataCode = iataCode;
}

const string &Airline::getIcaoCode() const {
    return icaoCode;
}

void Airline::setIcaoCode(const string &icaoCode) {
    Airline::icaoCode = icaoCode;
}

const string &Airline::getCountry() const {
    return country;
}

void Airline::setCountry(const string &country) {
    Airline::country = country;
};

bool Airline::operator==(const Airline &rhs) const {
    return airlineID == rhs.airlineID &&
           iataCode == rhs.iataCode;
}

bool Airline::operator!=(const Airline &rhs) const {
    return !(rhs == *this);
}