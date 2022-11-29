//
// Created by sblan on 26/11/2022.
//

#include "Node.h"
/** A constructor for the Node class
 *
 * @param state An Airport object that represents the current state of the Node
 * @param parent The node that generated the current node
 * @param pathCost The path cost of the Node so far
 * @param action The Route taken to reach the current state/airport
 */
Node::Node( Airport state,  Node* parent, int pathCost,  Route action) : state(state), parent(parent),
                                                                                          pathCost(pathCost),
                                                                                          action(action) {};

/** A default constructor for the Node class
 * It initializes the parent Node to null
 */
Node::Node() {
    parent = nullptr;
}

/** A method that generates a string representation of the Node object */
string Node::asString() {
    string outputStr;
    outputStr= "Node{state=" + state.getIataCode() +
               ", parent=" + parent->state.getIataCode();
    outputStr.append(action.getSourceAirportCode());
    return outputStr;

}

// Various getters and setters
const Airport &Node::getState() const {
    return state;
}

int Node::getPathCost() const {
    return pathCost;
}

void Node::setPathCost(int pathCost) {
    Node::pathCost = pathCost;
}

const Route &Node::getAction() const {
    return action;
}

void Node::setAction(const Route &action) {
    Node::action = action;
}

Node *Node::getParent() const {
    return parent;
}

void Node::setParent(Node *parent) {
    Node::parent = parent;
}

/** An equality operator for the Node class */
bool Node::operator==(const Node &rhs) const {
    return state == rhs.state &&
           parent == rhs.parent &&
           pathCost == rhs.pathCost &&
           action == rhs.action;
}











