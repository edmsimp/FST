#include "RBTree.h"

void RBTree::initializeNULLNode(NodePtr node, NodePtr parent) {
    node->data = "";
    node->parent = parent;
    node->left = nullptr;
    node->right = nullptr;
    node->color = 0;
}

void RBTree::leftRotate(NodePtr x) {
    NodePtr y = x->right;
    x->right = y->left;
    if (y->left != this->TNULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        this->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void RBTree::rightRotate(NodePtr x) {
    NodePtr y = x->left;
    x->left = y->right;
    if (y->right != this->TNULL) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        this->root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

void RBTree::fixInsert(NodePtr k){
    NodePtr u;
    while (k->parent->color == 1) {
        if (k->parent == k->parent->parent->right) {
            u = k->parent->parent->left;
            if (u->color == 1) {
                u->color = 0;
                k->parent->color = 0;
                k->parent->parent->color = 1;
                k = k->parent->parent;
            } else {
                if (k == k->parent->left) {
                    k = k->parent;
                    this->rightRotate(k);
                }
                k->parent->color = 0;
                k->parent->parent->color = 1;
                this->leftRotate(k->parent->parent);
            }
        } else {
            u = k->parent->parent->right;

            if (u->color == 1) {
                u->color = 0;
                k->parent->color = 0;
                k->parent->parent->color = 1;
                k = k->parent->parent;	
            } else {
                if (k == k->parent->right) {
                    k = k->parent;
                    this->leftRotate(k);
                }
                k->parent->color = 0;
                k->parent->parent->color = 1;
                this->rightRotate(k->parent->parent);
            }
        }
        if (k == this->root) {
            break;
        }
    }
    this->root->color = 0;
}

void RBTree::printHelper(NodePtr root, std::string indent, bool last) {
    if (root != this->TNULL) {
        std::cout<<indent;
        if (last) {
            std::cout<<"R----";
            indent += "     ";
        } else {
            std::cout<<"L----";
            indent += "|    ";
        }
        
        std::string sColor = root->color?"RED":"BLACK";
        std::cout<<root->data<<"("<<sColor<<")"<<std::endl;
        this->printHelper(root->left, indent, false);
        this->printHelper(root->right, indent, true);
    }
}

void RBTree::insert(std::string key) {
    NodePtr node = new Node;
    node->parent = nullptr;
    node->data = key;
    node->left = this->TNULL;
    node->right = this->TNULL;
    node->color = 1;

    NodePtr y = nullptr;
    NodePtr x = this->root;

    while (x != this->TNULL) {
        y = x;
        if ((node->data).compare(x->data) < 0) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    node->parent = y;
    if (y == nullptr) {
        this->root = node;
    } else if ((node->data).compare(y->data) < 0) {
        y->left = node;
    } else {
        y->right = node;
    }

    if (node->parent == nullptr){
        node->color = 0;
        return;
    }

    if (node->parent->parent == nullptr) {
        return;
    }

    this->fixInsert(node);
    this->numberOfNodes++;
}

RBTree::RBTree() {
    this->TNULL = new Node;
    this->TNULL->color = 0;
    this->TNULL->left = nullptr;
    this->TNULL->right = nullptr;
    this->root = this->TNULL;
}

NodePtr RBTree::getRoot() {
    return this->root;
}

int RBTree::getNumberOfNodes() {
    return this->numberOfNodes;
}

void RBTree::prettyPrint() {
    if (this->root) {
        this->printHelper(this->root, "", true);
    }
}

void RBTree::loadTree(std::vector<std::string> &loadVector) {
    for (auto it = loadVector.begin(); it != loadVector.end(); it++) {
        this->insert(*it);
    }
}

void RBTree::matchStrings(NodePtr node, std::string &stringToMatch, std::vector<std::string> &matchedStrings, int &quantityToMatch) {
    if (quantityToMatch == 0 or stringToMatch == "") {
        return;
    }
    if (stringToMatch.compare((node->data).substr(0, stringToMatch.size())) <= 0 and node->left != this->TNULL) {
        this->matchStrings(node->left, stringToMatch, matchedStrings, quantityToMatch);
    }
    if (stringToMatch.compare((node->data).substr(0, stringToMatch.size())) == 0 and quantityToMatch != 0) {
        matchedStrings.push_back(node->data);
        quantityToMatch--;
    }
    if (stringToMatch.compare((node->data).substr(0, stringToMatch.size())) >= 0 and node->right != this->TNULL) {
        this->matchStrings(node->right, stringToMatch, matchedStrings, quantityToMatch);
    }
}