//
// Created by sblan on 26/11/2022.
//

#ifndef ICPCPLUS_29362024_AIRLINE_H
#define ICPCPLUS_29362024_AIRLINE_H
#include <string>
using namespace std;


class Airline {
public:
    int airlineID;
    string name;
    string iataCode;
    string icaoCode;
    string country;


    /** A constructor for the Airline class */
    Airline(int airlineId,  string name,  string iataCode,  string icaoCode,  string country);

    /** A default constructor */
    Airline();

    /** A method that prints the string representation of an airline object */
    string asString();

    // Various getters and setters
    int getAirlineId() const;

    void setAirlineId(int airlineId);

    const string &getName() const;

    void setName(const string &name);

    const string &getIataCode() const;

    void setIataCode(const string &iataCode);

    const string &getIcaoCode() const;

    void setIcaoCode(const string &icaoCode);

    const string &getCountry() const;

    void setCountry(const string &country);

    // Equality operators
    bool operator==(const Airline &rhs) const;

    bool operator!=(const Airline &rhs) const;

};


#endif //ICPCPLUS_29362024_AIRLINE_H
