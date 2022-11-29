//
// Created by sblan on 26/11/2022.
//

#ifndef ICPCPLUS_29362024_NODE_H
#define ICPCPLUS_29362024_NODE_H
#include "Route.h"
#include "Airport.h"
#include <string>
using namespace std;

class Node {
public:
    Airport state;
    Node* parent;
    int pathCost = 0;
    Route action;

    Node( Airport state,  Node* parent, int pathCost,  Route action);

    Node();

//    Node(Node& sample);

    string asString();

    const Airport &getState() const;

    int getPathCost() const;

    void setPathCost(int pathCost);

    const Route &getAction() const;

    void setAction(const Route &action);

    bool operator==(const Node &rhs) const;

    Node *getParent() const;

    void setParent(Node *parent);

};


#endif //ICPCPLUS_29362024_NODE_H
