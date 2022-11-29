//
// Created by sblan on 24/11/2022.
//

#ifndef ICPCPLUS_29362024_DATAREADER_H
#define ICPCPLUS_29362024_DATAREADER_H

#include <string>
#include <iostream>
#include <system_error>
#include <filesystem>
#include <fstream>
#include <vector>
#include <sstream>
#include <list>
#include <unordered_map>
#include "Airport.h"
#include "Airline.h"
#include "Route.h"


using namespace std;

class DataReader {
public:
    unordered_map<string, list<Airport>> airportDict;
    unordered_map<string, list<Airline>> airlineDict;
    unordered_map<string, list<Route>> routesDict;
    unordered_map<string, Airport> airportMap;


    DataReader();

    void readFile(string, string);
    void createAirport(vector<string>);
    void createAirline(vector<string>);
    void createRoute(vector<string>);
    template<class T> bool containsKey(unordered_map<string,list<T>>&unordMap, string keyValue);



};
#endif //ICPCPLUS_29362024_DATAREADER_H
