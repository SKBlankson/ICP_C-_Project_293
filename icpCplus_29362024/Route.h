//
// Created by sblan on 24/11/2022.
//

#ifndef ICPCPLUS_29362024_ROUTE_H
#define ICPCPLUS_29362024_ROUTE_H



#include <string>
using namespace std;

class Route {
public:
    string airlineCode;
    string airlineID;
    string sourceAirportCode;
    string sourceAirportID;
    string destinationCode;
    string destinationID;
    string codeShare;
    int stops;
    string equipment;

    Route( string airlineCode,  string airlineId,  string sourceAirportCode,
           string sourceAirportId,  string destinationCode,  string destinationId,
           string codeShare, int stops,  string equipment);

    Route();

    const string &getAirlineCode() const;

    void setAirlineCode(const string &airlineCode);

    const string &getAirlineId() const;

    void setAirlineId(const string &airlineId);

    const string &getSourceAirportCode() const;

    void setSourceAirportCode(const string &sourceAirportCode);

    const string &getSourceAirportId() const;

    void setSourceAirportId(const string &sourceAirportId);

    const string &getDestinationCode() const;

    void setDestinationCode(const string &destinationCode);

    const string &getDestinationId() const;

    void setDestinationId(const string &destinationId);

    const string &getCodeShare() const;

    void setCodeShare(const string &codeShare);

    int getStops() const;

    void setStops(int stops);

    const string &getEquipment() const;

    void setEquipment(const string &equipment);

    string asString();

    bool operator==(const Route &rhs) const;
};


#endif //ICPCPLUS_29362024_ROUTE_H
