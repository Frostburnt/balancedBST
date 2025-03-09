#pragma once
#include <iostream>

struct Node {
    Node* left = NULL;      //smaller child
    Node* right = NULL;     //bigger child
    Node* parent = NULL;    //not using this in the standard BST
    //Node* parent = NULL;  //
    float key;              //value
    int subTreeDepth;

    Node(float value = 0);
    //Node* operator [](int i);
};

constexpr size_t s = sizeof(Node);

Node* nMax(Node* node);  //returns the right most node, which will be the highest value node
Node* nMin(Node* node);  //returns the lowest left side node, which will be the lowest value
int nSize(Node* node);