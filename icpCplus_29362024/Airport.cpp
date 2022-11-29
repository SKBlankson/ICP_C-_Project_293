//
// Created by sblan on 24/11/2022.
//



#include "Airport.h"

/** A constructor for the Airport class */
Airport::Airport(int airportId,  string name,  string city,  string country,  string iataCode,
                  string icaoCode) : airportID(airportId),
        name(name),
        city(city),
        country(country),
        iataCode(iataCode),
        icaoCode(icaoCode){};

/** A default constructor for the airport class
 * all values are initialized to 0000
 */
Airport::Airport() : airportID(0000),
                    iataCode("0000"),
                    name("0000"),
                    city("0000"),
                    country("0000"),
                    icaoCode("0000"){};

/** returns a string representation of the instance */
const string Airport::asString(){
    string outputStr;
    outputStr = "Airport{name=" +
                name + "," + "iataCode=" + iataCode + "}";

    return outputStr;
}

// Various getters, setters and equality methods
int Airport::getAirportId() const {
    return airportID;
}

void Airport::setAirportId(int airportId) {
    airportID = airportId;
}

const string &Airport::getName() const {
    return name;
}

void Airport::setName(const string &name) {
    Airport::name = name;
}

const string &Airport::getCity() const {
    return city;
}

void Airport::setCity(const string &city) {
    Airport::city = city;
}

const string &Airport::getCountry() const {
    return country;
}

void Airport::setCountry(const string &country) {
    Airport::country = country;
}

const string &Airport::getIataCode() const {
    return iataCode;
}

void Airport::setIataCode(const string &iataCode) {
    Airport::iataCode = iataCode;
}

const string &Airport::getIcaoCode() const {
    return icaoCode;
}

void Airport::setIcaoCode(const string &icaoCode) {
    Airport::icaoCode = icaoCode;
}


bool Airport::operator==(const Airport &rhs) const {
    return airportID == rhs.airportID &&
           city == rhs.city &&
           country == rhs.country &&
           iataCode == rhs.iataCode;
}

bool Airport::operator!=(const Airport &rhs) const {
    return !(rhs == *this);
}




