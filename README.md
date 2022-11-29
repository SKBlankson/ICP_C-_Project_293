# ICP_Cplus_Project
A C++ program that generates the route taken to travel from one country to another

RouteFinder
=========
C++ version 14
CMakeVersion 3.22

A C++ program that takes in a text file containing the Start and Destination and returns
a solution path as a txt file.<br/>
Since this uses a Breadth-First Search, it always finds the shortest route in terms of number of flights !


### How to use
The main class of this program contains all the necssary function calls.
Eight function calls are required to perform the search. However, to make things easier they have been encapsulated into 
one function call: 

performSearch("testcase.txt");


The performSearch() method performs the following actions:
Step 0 - create instances of all the classes needed to perform the the search
	
	DataReader reader; //Used for reading data and storage of maps
    	RouteFinder findRoute; //Performs all routefinding operations
    	Helpers help; //Contains all helper functions

Step 1 - Read the csv files and create the respective maps 

	1. reader.readFile("airports.csv","airports");
	2. reader.readFile("routes.csv","routes");
	3. reader.readFile("airlines.csv","airlines");

Step 2 - Read the start and end locations from the userinput file:

	4. findRoute.findStartFinish(sourceFile,reader.airportDict);

Step 3 - Generate starting nodes and perform Breadth-First Search

	5. list<Node> startingNodes = findRoute.generateStartingNodes(reader.airportDict);
	6. Node bfsResult = findRoute.bfs(reader.airportDict,reader.routesDict,reader.airportMap);

Step 4 - Generate a solution path and write it to a file

	7. list<Route> solPath = help.solutionPath(bfsResult,findRoute);
	8. help.writeToFile(solPath,findRoute.startCity,findRoute.endCity,findRoute.sol_patchCost);



### Sample Code to Perform the search
Note - To make any changes to the csv filenames, edit them in the defintion of the performSearch() method in main.cpp.
	(Refer to the docstrng for the readfile() method to get more info on the second positional argument.

	- To change the start and end locations, open the "testcase.txt" file, and make the changes there.
```    
        performSearch("testcase.txt");
	// the argument for performSearch() is the name of the file containing user input locationss

```                   

### Notes
1. Always check the console after a search. It will tell you if a solution was found and any other relevant messages.
2. If the search takes more than a few seconds, there is probably no solution path. BFS always tries every possible path 
and thus might take long to run sometimes.
3. MAKE SURE THERE IS NO SPACE BETWEEN THE COMMA THAT SEPARATES A CITY AND A COUNTRY.
e.g make sure your input is not like "Accra, Ghana". Instead it should be "Accra,Ghana"
