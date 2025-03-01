

#include <iostream>


struct Node {
    Node* left = NULL;      //smaller child
    Node* right = NULL;     //bigger child
    //Node* parent = NULL;    //
    float key;              //value

    Node(float value) {
        key = value;
    }
};

struct BST {                //member functions need to be filled out
    Node* head;
    BST(Node *node) {
        head = node;
    }
    
    void insert(Node node) {

    }
    void remove(float value) {

    }
    Node* successor(Node* node) {
        return NULL;
    }
    Node* predecessor(Node * node) {
        return NULL;
    }

};

Node* nMax(Node* node) {                 //returns the right most node, which will be the highest value node
    Node *working = node;
    while (working->right != NULL) {
        working = working->right;
    }
    return working;
}
Node* nMin(Node* node) {                 //returns the lowest left side node, which will be the lowest value
    Node* working = node;
    while (working->left != NULL) {
        working = working->left;
    }
    return working;
}

Node* BSearch(Node* root, float key){
    return NULL;
}
unsigned int nSize(Node node){      //returns the size of the sub-tree at this node, inclusive
    unsigned int total = 1;            
    if (node.left != NULL)
        total += nSize(*node.left);
    if (node.right != NULL)
        total += nSize(*node.right);
    return total;
}

Node onlyNode(3.43f);
BST test(&onlyNode);


int main(){
    std::cout << test.head->key;
    
}
