#include <iostream>


#include "DataReader.h"
#include "RouteFinder.h"
#include "Helpers.h"

using namespace std;
/** A method that encapsulates all the necessary function calls necessary
 * for to find the solution path
 * @param sourceFile the name of the file that contains the start and end
 */
void performSearch(string sourceFile){
    DataReader reader;
    RouteFinder findRoute;
    Helpers help;

    // Read the csv files
    reader.readFile("airports.csv","airports");
    reader.readFile("routes.csv","routes");
    reader.readFile("airlines.csv","airlines");

    // get start and end locations
    findRoute.findStartFinish(sourceFile,reader.airportDict);

    // generate starting nodes for bfs
    list<Node> startingNodes = findRoute.generateStartingNodes(reader.airportDict);

    // use bfs to find solutlion node
    Node bfsResult = findRoute.bfs(reader.airportDict,reader.routesDict,reader.airportMap);

    // use solution node to generate solution path
    list<Route> solPath = help.solutionPath(bfsResult,findRoute);

    // write solution to the file
    help.writeToFile(solPath,findRoute.startCity,findRoute.endCity,findRoute.sol_patchCost);
}

int main() {
    performSearch("testcase.txt");

    return 0;
}
