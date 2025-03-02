#include <iostream>
#include "node.h"
#include "bst.h"

    BST::BST(Node * node) {
        head = node;
    }

    void BST::insert(Node* node) {                   //we do this here for the first step of insertion so that the BST's is also represented
        head = insertHelper(head, node);        //then we treaat subsequent nodes as if they are heads to other binary search trees
    }
    Node* BST::insertHelper(Node* root, Node* node) {    //I used "root" instead of "head" here to avoid confusion with the Tree's head, and the current sub-trees head
        float key = node->key;                      //this
        if (root == NULL) {
            return node;
        }
        else if (key < root->key) {                                 //we change where our current working root node is based on where it belongs, left or right
            root->left = insertHelper(root->left, node);
        }
        else {
            root->right = insertHelper(root->right, node);
        }
        return root;
    }
    void BST::displayHelper(const Node* root) {         //traverse the list in sorted order
        if (root != NULL) {                             //first we go all the way left to get the lowest number, then we work our way back up
            displayHelper(root->left);                  //printing the value each time, and recursively calling into the right side as well on the asscent
            std::cout << "->" << root->key;             
            displayHelper(root->right);                 
        }
    }
    void BST::display(std::string text) {
        std::cout << text << std::endl << "||";
        displayHelper(head);
        std::cout << "||";
    }

    void BST::remove(float value) {
        if (search(value)) {
            removeHelper(head, value);
        }
        else {
            std::cout << value << "Item does not exist" << std::endl;
        }
    }
    Node* BST::removeHelper(Node* root, float value) {
        if (root == NULL) {
            return root;
        }
        else if (value < root->key) {
            root->left = removeHelper(root->left, value);
        }
        else if (value > root->key) {
            root->right = removeHelper(root->right, value);
        }
        else {
            if (root->left == NULL && root->right == NULL) {
                root = NULL;
            }
            else if (root->right != NULL) {//
                root->key = successor(root);
                root->right = removeHelper(root->right, root->key);
            }
            else {
                root->key = predecessor(root);
                root->left = removeHelper(root->left, root->key);
            }
        }
        return root;
    }
    float BST::successor(Node* root) {   //check this for pointer fuckery        seems fine
        root = root->right;              
        root = nMin(root);
        return root->key;
    }
    float BST::predecessor(Node* root) {
        root = root->left;
        root = nMax(root);
        return root->key; 

    }
    bool BST::search(float value) {
        return(searchHelper(head, value));
    }

    bool BST::searchHelper(Node* root, float value) {
        if (root == NULL) {
            return false;
        }
        else if (root->key == value) {
            return true;
        }
        else if (root->key > value) {
            return searchHelper(root->left, value);
        }
        else {
            return searchHelper(root->right, value);
        }
    }