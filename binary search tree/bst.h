#pragma once
struct BST {                //member functions need to be filled out

    Node* head;
    BST(Node* node = NULL);

    void insert(Node* node);//inerts an element into the tree at the correct sorted location

    void display(std::string text = "Your binary search tree:");//prints out the entire tree, from smallest element to largest

    void remove(float value);//removes a value from the tree

    bool search(float value);//checks if a value exists in the tree


    //private functions are helper functions used to deal with tree vs node interactions
    //or for printing data without having to jump through hoops
    Node* removeHelper(Node* root, float value);
    Node* insertHelper(Node* root, Node* node);
    void displayHelper(const Node* root);
    bool searchHelper(Node* root, float value);
    //these two find the best node to replace an empty
    float successor(Node* root);
    float predecessor(Node* root);
};