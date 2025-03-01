// binary search tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


struct Node {
    Node* left = NULL;      //smaller child
    Node* right = NULL;     //bigger child
    float key;              //value

    Node(float value) {
        key = value;
    }
  


};

struct BST {
    Node* head;
    BST(Node node) {
        head = Node;
    }
    BST() {};
    void insert(Node node) {

    }
    void remove(float value) {

    }
    Node successor(Node* node) {

    }
    Node predecessor(Node * node) {

    }
    Node max() {

    }
    Node min() {

    }
};

Node max(Node node) {
    Node working = node
    while (working.right != NULL) {
        working = working.right
    }
    return working;
}
Node min() {

}

Node* BSearch(Node* root, float key){

}

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
