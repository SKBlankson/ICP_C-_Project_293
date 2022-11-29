//
// Created by sblan on 26/11/2022.
//

#ifndef ICPCPLUS_29362024_HELPERS_H
#define ICPCPLUS_29362024_HELPERS_H

#include <string>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <iostream>
#include <sstream>
#include "Airport.h"
#include "Node.h"
#include "RouteFinder.h"
//#include "Airpor
using namespace std;

class Helpers {
public:

    Helpers();

    list<Route> solutionPath(Node,RouteFinder);

    void writeToFile(list<Route> &path,string startCity,string endCity,int sol_pathCost);

    vector<string> readTask(string sourceFile);

//    void writeToFile(list<Route>,RouteFinder);

//    template<typename T> static void checkValidity(vector<string> locations,unordered_map<string, list<T>> &dict );
//
//    template<typename T> static vector<string> getStartFinish(string sourceFile,unordered_map<string, list<T>> &dict );

};


#endif //ICPCPLUS_29362024_HELPERS_H
