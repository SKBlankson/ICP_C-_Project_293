//
// Created by sblan on 26/11/2022.
//

#include "RouteFinder.h"
#include "DataReader.h"
#include "Helpers.h"

RouteFinder::RouteFinder() {};

/** A function that sets the start and finish location variables */
void RouteFinder::findStartFinish(string sourceFile,unordered_map<string, list<Airport>> airportDict) {
    vector<string> locations;
    vector<string> row;
    string line,word,temp;

    // Read the location file
    Helpers help;
    locations = help.readTask(sourceFile);
        // Set relevant locations
        startCity = locations[0];
        startCountry = locations[1];
        endCity = locations[2];
        endCountry = locations[3];

        if(airportDict.count(startCity+startCountry)<=0 || airportDict.count(endCity+endCountry)<=0){
            cout<<endl;
            cout<<"Start or End location is invalid!"<<endl;
            cout<<"MAKE SURE THERE IS NO SPACE BEFORE OR AFTER THE COMMA SEPARATING"
                  " THE CITY AND COUNTRY" <<endl;
            cout<<"Please try again with valid locations or correct your input"<<endl;
            exit(420);
        }
}

/** A function that converts the starting locations into nodes for the BFS tree */
list<Node> RouteFinder::generateStartingNodes(unordered_map<string, list<Airport>>& allAirports) {
    list<Node> startingNodes;
    string newKey = startCity+startCountry;
    list<Airport> startingAirports = allAirports.at(newKey);

    for(Airport airport: startingAirports){
        Node newNode = Node(airport,&dummyNode,0, Route());
        startingNodes.push_back(newNode);
    }
    cout<<"Generated Starting Nodes" <<endl;
    return startingNodes;

}

/** A goal test for the bfs */
bool RouteFinder::goalTest(Node node) {
    if((node.getState().getCity() == endCity) && (node.getState().getCountry() == endCountry)){
        return true;
    }
    return false;
}

/** A method that gives all the possible actions/routes from a given location */
list<Route> RouteFinder::actions(string iata,unordered_map<string, list<Route>>& allRoutes) {
    list<Route> succRoutes;
    if (allRoutes.count(iata) > 0){
        succRoutes = allRoutes.at(iata);
    }
    return succRoutes;
}

/** A Breath first search that is used to find the destination node
 *
 * @param allAirports The address of the map that contains all the airport objects
 * @param allRoutes The address of the map that contains all the route objects
 * @param airportMap The address of the map that matches IATA codes to airport objects
 * @return
 */
Node RouteFinder::bfs(unordered_map<string, list<Airport>>& allAirports,\
unordered_map<string, list<Route>>& allRoutes, unordered_map<string, Airport>& airportMap) {
    //The frontier and explored st for the bfs
    list<Node> frontier;
    unordered_set<string> explored;
    Node dummy;

    // Generate Starting nodes
    startingNodes = generateStartingNodes(allAirports);

    // Put all starting nodes on the frontier
    for (Node startingNode: startingNodes) {
        if (this->goalTest(startingNode)) {
            cout << "Found a solution!, You are already there" << endl;
            return startingNode;
        }
        frontier.push_back(startingNode);
    }

    // BFS Logic
    while (!frontier.empty()) {
        Node currNode = frontier.front();
        curNodeList.push_back(currNode);
        frontier.pop_front();
        explored.insert(currNode.asString());

        //If current node has complete data, expand it.Else, skip it
        list<Route> avlActions = actions(currNode.getState().getIataCode(), allRoutes);

        //For every action, create a node and add its children to the frontier
        for (Route action: avlActions) {
            string destinationIata = action.getDestinationCode();
            if (!(airportMap.find(destinationIata)==airportMap.end())) {
                Airport destinationPort = airportMap.at(destinationIata);
                Node child = Node(destinationPort, &curNodeList.back(), (currNode.getPathCost() + 1), action);
                bool inList = (find(frontier.begin(), frontier.end(), child) != frontier.end());

                //If the child is not on the frontier or explored set, examine it
                if ((explored.count(child.asString()) <= 0) && !inList) {
                    if (goalTest(child)) {
                        cout << "Found a solution" << endl;
                        sol_patchCost = child.getPathCost();
                        cout<<"Final destination: " << child.state.getCountry()<<endl;
                        cout<<"Previous city: " <<child.parent->state.getCity()<<endl;
                        return child;
                    }
                    frontier.push_back(child);
                }
            }
        }
    }
    cout << "No solution path possible!" << endl;
    return dummy;
}


















