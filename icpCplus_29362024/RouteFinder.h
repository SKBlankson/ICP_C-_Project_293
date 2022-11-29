//
// Created by sblan on 26/11/2022.
//

#ifndef ICPCPLUS_29362024_ROUTEFINDER_H
#define ICPCPLUS_29362024_ROUTEFINDER_H
#include <vector>
#include <string>
#include <unordered_map>
#include <list>
#include "Route.h"
#include "Airport.h"
#include "Node.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
#include <unordered_set>
#include <iterator>
#include <algorithm>
using namespace std;


class RouteFinder {
public:
    string startCity;
    string startCountry;
    string endCity;
    string endCountry;
    unordered_map<string, list<Route>> staticWorldMap;
    int sol_patchCost = 0;
    Airport destinationAirport;
    list<Node> startingNodes;
    list<Node> curNodeList;
    Node dummyNode;

    RouteFinder();
    void findStartFinish(string sourceFile, unordered_map<string, list<Airport>> airportDict);
    list<Node> generateStartingNodes (unordered_map<string,list<Airport>>&);
    bool goalTest(Node);
    list<Route> actions(string,unordered_map<string, list<Route>>&);
    Node bfs(unordered_map<string, list<Airport>>&,unordered_map<string, list<Route>>&,unordered_map<string, Airport>&);

};


#endif //ICPCPLUS_29362024_ROUTEFINDER_H
