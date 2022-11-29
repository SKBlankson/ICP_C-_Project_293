//
// Created by sblan on 24/11/2022.
//

#ifndef ICPCPLUS_29362024_AIRPORT_H
#define ICPCPLUS_29362024_AIRPORT_H
#include <string>
using namespace std;

class Airport {
public:
    int airportID;
    string name;
    string city;
    string country;
    string iataCode;
    string icaoCode;

    /** A constructor for the Airport class */
    Airport(int airportId,  string name,  string city,  string country,  string iataCode,string icaoCode);

    /** A default constructor for the airport class */
    Airport();

    // Equality Operators
    bool operator==(const Airport &rhs) const;

    bool operator!=(const Airport &rhs) const;

    /** A custom method that returns a string representation of the Airport object */
    const string asString();

    //Various getters and setters
    int getAirportId() const;

    void setAirportId(int airportId);

    const string &getName() const;

    void setName(const string &name);

    const string &getCity() const;

    void setCity(const string &city);

    const string &getCountry() const;

    void setCountry(const string &country);

    const string &getIataCode() const;

    void setIataCode(const string &iataCode);

    const string &getIcaoCode() const;

    void setIcaoCode(const string &icaoCode);


};


#endif //ICPCPLUS_29362024_AIRPORT_H
