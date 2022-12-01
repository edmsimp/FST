#ifndef RB_TREE
#define RB_TREE

#include <iostream>
#include <string>
#include <vector>

struct Node {
	std::string data; // Data stored in the node
	Node *parent; // Node's parent
	Node *left; // Node's left son
	Node *right; // Node's right son
	int color; // Node's color (1 -> Red, 0 -> Black)
};

typedef Node *NodePtr;

class RBTree {

public:
    // Class constructor
    RBTree();

    /**
     * @brief Function that returns the RBTree root.
     * @return Pointer to the RBtree root.
     */
    NodePtr getRoot();

    /**
     * @brief Function that prints the RBTree.
     */
	void prettyPrint();

    /**
     * @brief Function to load the dictionary that will
     * be used to construct the RBTree.
     * @param loadVector Vector containing the dictionary
     * to be loaded.
     */
    void loadTree(std::vector<std::string> &loadVector);

    /**
     * @brief Function to store words that match with the input
     * string into a vector, with quantity defined.
     * @param node Node to start the search.
     * @param stringToMatch String to be matched with.
     * @param matchedStrings Strings found on tree that satisfies
     * the input.
     * @param quantityToMatch Quantity of strings the vector should
     * handle.
     */
    void matchStrings(NodePtr node, std::string &stringToMatch, std::vector<std::string> &matchedStrings, int &quantityToMatch);

private:
    /**
     * @brief Function to initialize a node as NULL.
     * @param node Node to be initialized.
     * @param parent Node parent.
     */
    void initializeNULLNode(NodePtr node, NodePtr parent);

    /**
     * @brief Operate a left rotation on a RBTree node.
     * @param x Pivot node to be rotated.
     */
    void leftRotate(NodePtr x);

    /**
     * @brief Operate a right rotation on a RBTree node.
     * @param x Pivot node to be rotated.
     */
    void rightRotate(NodePtr x);

    /**
     * @brief Operate rotations on a RBTree node to fix
     * the insertion of a new node.
     * @param k Node inserted.
     */
    void fixInsert(NodePtr k);

    /**
     * @brief Auxiliary function to print the RBTree.
     * @param root Subtree root to be printed.
     * @param indent String for ident display.
     * @param last Boolean to signal if the node is final.
     */
    void printHelper(NodePtr root, std::string indent, bool last);

    /**
     * @brief Insert a key in the RBTree.
     * @param key Subtree root to be printed.
     */
    void insert(std::string key);

    NodePtr root; // RBTree root.
    NodePtr TNULL; // RBTree NULL node.
};

#endif