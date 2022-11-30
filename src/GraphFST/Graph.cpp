#include "Graph.h"

/************************************* GRAPH NODE ***************************************/
GraphNode::GraphNode(){
    storedWord = "";
    isFinal = false;
}

GraphNode::GraphNode(std::string word){
    storedWord = word;
    isFinal = false;
}

GraphNode::~GraphNode(){

}


std::string GraphNode::stateOutput(){
    if(isFinal)
        return storedWord;
    else
        return nullptr;
}

bool GraphNode::getFinal(){
    return isFinal;
}

void GraphNode::setFinal(bool condition){
    isFinal = condition;
}

GraphNode* GraphNode::getTransition(char character){
    for(std::list<GraphEdge>::iterator it = transitions.begin(); it != transitions.end(); it++)
        if(character == (*it).getTransitionCharacter())
            return (*it).getTransitionDestination();
    
    return nullptr;
}

void GraphNode::clearState(){
    isFinal = false;
    transitions.clear();
    storedWord = "";
}

bool GraphNode::compareState(GraphNode& otherState){
    if(otherState.id != id)
        return false;
    else return true;
}

std::string GraphNode::stateOutput(){

}
