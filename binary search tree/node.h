#pragma once
struct Node {
    Node* left = NULL;      //smaller child
    Node* right = NULL;     //bigger child
    Node* parent = NULL;    //not using this in the standard BST
    //Node* parent = NULL;  //
    float key;              //value

    Node(float value = 0);
    //Node* operator [](int i);
};
Node* nMax(Node* node);  //returns the right most node, which will be the highest value node
Node* nMin(Node* node);  //returns the lowest left side node, which will be the lowest value
unsigned int nSize(Node* node);