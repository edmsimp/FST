#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

#include <string>
#include <list>

class GraphEdge{
public:
    GraphEdge();
    ~GraphEdge();

    char getTransitionCharacter();
    GraphNode* getTransitionDestination();

private:
    GraphNode* destinationNode;
    char transitionCharacter;
};

class GraphNode{
public:
    // Constructors and destructor.
    GraphNode();
    GraphNode(std::string word);
    ~GraphNode();

    // Auxiliary functions
    GraphNode* getTransition(char transitionCharacter);
    
    bool getFinal();                                                            // FUNCTION FINAL
    void setFinal(bool condition);                                              // PROCEDURE SET_FINAL

    void clearState();                                                          // FUNCTION CLEAR_STATE
    bool compareState(GraphNode& otherState);                                   // FUNCTION COMPARE_STATES

    std::string stateOutput();                                                  // FUNCTION STATE_OUTPUT
private:
    // Word in the current state.
    std::string storedWord;
    
    // Determines if a state is final or not.
    bool isFinal;

    // Identification of the state
    int id;
    
    /**
     * @brief List containing the valid transitions for the current state.
     */
    std::list<GraphEdge> transitions;                                           // FUNCTION TRANSITION

    void addTransition(char transitionCharacter, GraphNode* destinationNode);   // PROCEDURE SET_TRANSITION
};

#endif