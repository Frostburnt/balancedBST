#include <iostream>
#include "node.h"


Node::Node(float value) {
    key = value;
}
Node* nMax(Node* node) {                 //returns the right most node, which will be the highest value node
    Node* working = node;
    while (working->right != NULL) {
        working = working->right;
    }
    return working;
}
Node* nMin(Node* node) {                 //returns the lowest left side node, which will be the lowest value
    Node* working = node;
    while (working->left != NULL) {     //simply loops until there is no next node, this means we've reached the end
        working = working->left;
    }
    return working;
}

int nSize(Node* node){          //returns the size of the sub-tree at this node, inclusive. This is the "C variable" in the assigned task
    
    int total = 1;
    if (node->left != NULL)
        total += nSize(node->left);     //and recursively takes the left branch
    if (node->right != NULL)
        total += nSize(node->right);    //and right branch's totals too
    return total;
}
