#pragma once
#include <vector>

//naming convetnions:
//when treating a node as a root of a tree, I call it root.
//when treating the node as a node, to be inserted, I call it node


struct BST {                //member functions need to be filled out

        Node* head;
        int size;//not used in standard BST
        int maxSize;
        float balanceFactor = 0.75; //0.5 is perfectly balanced, 1 is completely imbalanced

        BST(Node* node = NULL);
        BST(float value);
        void insert(Node* node);//inerts an element into the tree at the correct sorted location
        void sgInsert(Node* node);//value insertion will be done for scape goat
        void display(std::string text = "Your binary search tree:");//prints out the entire tree, from smallest element to largest

        void remove(float value);//removes a value from the tree

        bool search(float value);//checks if a value exists in the tree



        //private functions are helper functions used to deal with tree vs node interactions
        //or for printing data without having to jump through hoops
        Node* removeHelper(Node* root, float value);
        Node* insertHelper(Node* root, Node* node);
        //* sgInsertHelper(Node* root, Node* node);

        void displayHelper(const Node* root);
        bool searchHelper(Node* root, float value);
        //these two find the best node to replace an empty
        float successor(Node* root);
        float predecessor(Node* root);
        bool isBalancedAtNode(Node* root);
        Node* findScapegoat(Node* root);
        Node* rebalance(Node* root);
        void flatten(Node* node, std::vector<Node*>* vec);
        Node* buildTreeFromVector(const std::vector<Node*> flattened, int start, int end, Node* newParent = NULL);


};