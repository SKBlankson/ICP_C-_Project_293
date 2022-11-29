//
// Created by sblan on 24/11/2022.
//

#include "DataReader.h"

#include <string>
#include <iostream>
#include <vector>
#include "Airport.h"
#include "Airline.h"
#include "Route.h"
#include "Helpers.h"


/** A default constructor for the class */
DataReader::DataReader(){};

/** A method that reads any CSV file. It then calls one of three methods to
 * create an instance of the appropriate class and update its map
 * @param source the name of the csv which is to be read
 * @param type the "type" of data being read, either "airports", "airlines"
 * or "routes"
 */
void DataReader::readFile(const string source, const string type) {
    vector<string> row; // A vector to store the rows
    string line, word; // helper variables

    try {
        fstream fin;
        fin.open(source, ios::in);
        getline(fin, line); // skip the first line

        while (getline(fin, line)) {
            row.clear(); //clear old data from row
            stringstream s(line);

            while (getline(s, word, ',')) {
                row.push_back(word);
            }

            //Call appropriate method depending on type
            if (type == "airports") {
                createAirport(row);
            }else if(type == "airlines") {
                createAirline(row);
            }else if (type == "routes" ){
                createRoute(row);
            }
        }
        cout << "Done processing " + type + "!"<<endl;
        fin.close();
    }
    catch (...) {
        cout << "File not found!!" << endl;
    }
}


/** A method that creates instances of the Airport class and maintains
 * the map of airport objects
 * @param items a string vector passed by the readFile method
 */
void DataReader::createAirport(vector<string> items) {
    //if the line has clean data, create an airport object
    if (items.size() == 14 && !(items[9] == "\\N")) {
        Airport newAirport = Airport(stoi(items[0]),
                                     items[1],
                                     items[2],
                                     items[3],
                                     items[4],
                                     items[5]);

        //Putting the new airport object in the airport mapp
        string city = newAirport.getCity();
        string country = newAirport.getCountry();
        string newKey = city+country;


        // check if map already has the object and act accordingly
        if (containsKey(airportDict, newKey)) {
            this->airportDict.at(newKey).push_back(newAirport);
        } else {
            this->airportDict[newKey].push_back(newAirport);}
            //Updating the iataCode-Airport map
                string newAita = items[4];
                airportMap[newAita] = newAirport;

        }
    }

/** A method that creates instances of the Airline class and maintains
 * the map of airline objects
 * @param items a string vector passed by the readFile method
 */
void DataReader::createAirline(vector<string> items) {
    //if the line has clean data, create an airport object
    if (items.size() ==8 ) {
        Airline newAirline = Airline(stoi(items[0]),
                                     items[1],
                                     items[3],
                                     items[4],
                                     items[6]);

        //Putting the new airline object in the airport mapp
       string newKey = newAirline.getCountry();

       if(containsKey(airlineDict,newKey)){
           this->airlineDict.at(newKey).push_back(newAirline);
       }else{
           this->airlineDict[newKey].push_back(newAirline);
       }
    }
}

/** A method that creates instances of the Route class and maintains
 * the map of Route objects
 * @param items a string vector passed by the readFile method
 */
void DataReader::createRoute(vector<string> items) {
    //If line has clean data, create a Route object
    if (items.size() ==9) {
        Route newRoute = Route(items[0],
                                     items[1],
                                     items[2],
                                     items[3],
                                     items[4],
                                     items[5],
                                     items[6],
                                     stoi(items[7]),
                                     items[8]);

        //Putting the new Route object in the airport mapp
        string newKey = newRoute.getSourceAirportCode();

        // check if hashmap already has the object and act accordingly
        if(containsKey(routesDict,newKey)){
            this->routesDict.at(newKey).push_back(newRoute);
        }else{
            this->routesDict[newKey].push_back(newRoute);
        }
    }
}

/** A function that checks if a map of any type contains a given key
 *
 * @tparam T Generic data type for the list value f the map
 * @param unordMap A map of type<string,list<T>>
 * @param keyValue the key value which is checked for in the map
 * @return boolean value depending on whether the key was found or nor
 */
template<class T>
bool DataReader::containsKey(unordered_map<string, list<T>> &unordMap, string keyValue) {
    if (unordMap.count(keyValue) > 0){
        return true;
    } else{
        return false;
    }
}



