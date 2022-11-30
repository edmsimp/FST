#ifndef GRAPH_FST
#define GRAPH_FST

#include <fstream>
#include <iostream>
#include <list>

#include "Graph.h"

class GraphFST{
public:
    GraphFST();
    GraphFST(std::string filename);
    ~GraphFST();

    GraphNode* dictionaryMember(GraphNode& target);      // FUNCTION MEMBER
    void dictionaryInsert(GraphNode& target);            // FUNCTION INSERT

private:
    void createFST(std::string filename);
    GraphNode initialNode;

    std::list<GraphNode*> dictionary;
};

#endif