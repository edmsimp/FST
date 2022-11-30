#ifndef RB_TREE
#define RB_TREE

#include <iostream>
#include <string>
#include <vector>

struct Node {
	std::string data;
	Node *parent;
	Node *left;
	Node *right;
	int color; // 1 -> Red, 0 -> Black
};

typedef Node *NodePtr;

class RBTree {
private:
	NodePtr root;
	NodePtr TNULL;

	void initializeNULLNode(NodePtr node, NodePtr parent);

    void leftRotate(NodePtr x);

	void rightRotate(NodePtr x);

	void fixInsert(NodePtr k);

	void printHelper(NodePtr root, std::string indent, bool last);

	void insert(std::string key);

public:
	RBTree();

    NodePtr getRoot();

	void prettyPrint();

    void loadTree(std::vector<std::string> &loadVector);

    void matchStrings(NodePtr node, std::string &stringToMatch, std::vector<std::string> &matchedStrings, int &quantityToMatch);
};

#endif