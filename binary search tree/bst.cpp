#include <iostream>
#include "node.h"
#include "bst.h"

    //you will note, there is often a very simple pattern, atleast before including the balanced function of if smaller go left, if bigger go right (or inverse depending on comparison order
    //this commenting might be a bit extreme, but it's for a project, so it might be good to keep for explaining

BST::BST(Node * node) {
    head = node;
}


void BST::insert(Node* node) {                   //we do this here for the first step of insertion so that the BST's is also represented
    head = insertHelper(head, node);        //then we treaat subsequent nodes as if they are heads to other binary search trees
}
void BST::sgInsert(Node* node) {            //want to re-implement this rercusively
    if (head == NULL) {
        head = node;
        return;
    }
    Node* currentNode = head;
    Node* potentialParent = head;
    while (currentNode != NULL) {//stepping through tree iteratively
        potentialParent = currentNode;
        if (node->key < currentNode->key) {
            currentNode = currentNode->left;
        }
        else {
            currentNode = currentNode->right;
        }
    }
    
    node->parent = potentialParent;
    if (node->key < node->parent->key) {
        node->parent->left = node;
    }
    else {
        node->parent->right = node;
    }

    node->left = NULL;
    node->right = NULL;
    size += 1;
    Node* scapegoat = findScapegoat(node);
   
    if (scapegoat == NULL)
        return;
    Node* temp = scapegoat->parent;
    scapegoat = rebalance(scapegoat);   //this will remove the parent from the scape goat, so we will need to re-add it
    scapegoat->parent = temp;
    if(scapegoat->parent != NULL){
        if (scapegoat->key < temp->key) {
            scapegoat->left = scapegoat;
        }
        else {  
            scapegoat->right = scapegoat;
           }
    }

    


}
bool BST::isBalancedAtNode(Node* root){//checks with balancing factor
    int RightSize = nSize(root->left);
    int LeftSize = nSize(root->right);
    int SubTreeSize = RightSize + LeftSize + 1;
    if (RightSize > (balanceFactor * SubTreeSize) || LeftSize > (balanceFactor * SubTreeSize)){
        return false;
    }
    else {
        return true;
    }
}
Node* BST::findScapegoat(Node* root) {
    if (root == head) {
        return NULL;
    }
    while (isBalancedAtNode(root)) { //check if our tree is balanced, going up til we reach the top
        if (root == head) {
            return NULL;
        }
        root = root->parent;
    }
    
    return root;
}
Node* BST::rebalance(Node* root) {//we put all the nodes into a vector in order, then we put them all back into the tree recursively
    std::vector<Node*>flattened;
    
    flatten(root, &flattened);
    for (int i = 0; i < flattened.size(); i++) {//as I am using pointers instead of values I'm erasing the relationships
        Node* a = flattened[i];
        a->left = NULL;
        a->right = NULL;
        a->parent = NULL;
    }
    return buildTreeFromVector(flattened, 0, flattened.size() - 1);
    
}
void BST::flatten(Node* node, std::vector<Node*>* vec) {//puts every node into a vector vec
    if (node == NULL) {
        return;
    }
    flatten(node->left, vec);
    vec->push_back(node);
    flatten(node->right, vec);
    
}
Node* BST::buildTreeFromVector(const std::vector<Node*> flattened, int start, int end, Node* newParent) {
    if (start > end) {
        return NULL;
    }
    int mid = start + (end - start) / 2 + (end - start) % 2;
    Node* thisNode = flattened[mid];
    thisNode->parent = newParent;               
    thisNode->left = buildTreeFromVector(flattened, start, mid - 1, thisNode);
    thisNode->right = buildTreeFromVector(flattened, mid+1, end, thisNode);
    return thisNode;




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
void BST::display(std::string text) {               //calls display helper, passing in the head node, and adding some printing fluff
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
Node* BST::removeHelper(Node* root, float value) {  //this is not a balanced version
    if (root == NULL) { //if we reach the end, where there is no item we go back
        return root;
    }
    else if (value < root->key) { //we compare and see which side we must traverse to
        root->left = removeHelper(root->left, value);
    }
    else if (value > root->key) { //i might swap these around to make it consistent with other comparisons
        root->right = removeHelper(root->right, value);
    }
    else {
        if (root->left == NULL && root->right == NULL) { //if both left and right children are non existent then we don't need to make any chnages to children
            root = NULL;
        }
        else if (root->right != NULL) { //otherwise we shift child nodes into place
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
//next two find the next smaller node, and it's biggest child, or the next bigger node and it's smaller child
//the value returned by either should be the middle value between the current nodes left and right branches
//it's essentially finding the next or previous value in a sorted BST, equivalent of going list[i-1] or list[i+1] IF it were a sorted array
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
bool BST::search(float value) { //exists to pass the head value in, avoids mixing of different structs/classes
    return(searchHelper(head, value));
}

bool BST::searchHelper(Node* root, float value) { //very simple, compare, if it's == it's the node we want, if it's bigger than the current node, it'll be to the left, smaller right etc
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