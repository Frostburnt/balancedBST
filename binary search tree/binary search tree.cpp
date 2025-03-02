//notes
//decided to use floats, as with a randomly generated num
//things to remember is left is always smaller, right is always larger than the current node
//the use of helper functions is just to handle Tree vs Node, or handle some printing
//this is starting out UNBALANCED btw
#include <iostream>


struct Node {
    Node* left = NULL;      //smaller child
    Node* right = NULL;     //bigger child
    //Node* parent = NULL;  //
    float key;              //value

    Node(float value) {        
        key = value;
    }
    Node* operator [](int i) {
        switch (i) {    //probably don't need break statements if 
        case 0:
            return left;
            break;
        case 1:
            return right;
            break;
        default:
            return NULL;
        }
    }
};
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
struct BST {                //member functions need to be filled out
    Node* head;
    BST(Node *node = NULL) {
        head = node;
    }
    
    void insert(Node *node) {                   //we do this here for the first step of insertion so that the BST's is also represented
        
        head = insertHelper(head, node);        //then we treaat subsequent nodes as if they are heads to other binary search trees
    }
    Node *insertHelper(Node *root, Node *node) {    //I used "root" instead of "head" here to avoid confusion with the Tree's head, and the current sub-trees head
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
    void displayHelper(const Node *root) {
       if (root != NULL) {
           displayHelper(root->left);
           std::cout << "->" << root->key;
           displayHelper(root->right);
        }
    }
    void display(std::string text = "Your binary search tree:"){
        std::cout << text << std::endl << "||";
        displayHelper(head);
        std::cout << "||";
    }
    
    void remove(float value) {
        if (search(value)) {
            removeHelper(head, value);
        }
        else {
            std::cout << value << "Item does not exist" << std::endl;
        }
    }
    Node* removeHelper(Node* root, float value) {
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
            else{
                root->key = predecessor(root);
                root->left = removeHelper(root->left, root->key);
            }
        }
        return root;
    }
    float successor(Node* root) {   //check this for pointer fuckery
        root = root->right;         
        root = nMin(root);
        return root->key;
    }
    float predecessor(Node * root) {
        root = root->left;
        root = nMax(root);
        return root->key;
        
    }
    bool search(float value) {
        return(searchHelper(head, value));
    }

    bool searchHelper(Node *root, float value) {
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

};







Node* bSearch (Node* root, float key){
    return NULL;
}



unsigned int nSize(Node node){          //returns the size of the sub-tree at this node, inclusive. This is the "C variable" in the assigned task
    unsigned int total = 1;             //it takes this nodes count (1)
    if (node.left != NULL)
        total += nSize(*node.left);     //and recursively takes the left branch
    if (node.right != NULL)
        total += nSize(*node.right);    //and right branch's totals too
    return total;
}

Node onlyNode(3.43f);
BST test(&onlyNode);


int main(){
    Node a(5.3);
    Node b(4.3);
    Node c(30.3);
    test.insert(&a);
    test.insert(&b);
    test.insert(&c);
    test.display();
    test.remove(4.3);
    test.display();
    test.remove(5.3);
    test.display();
    std::cout << std::endl << test.search(5.3);
    std::cout << std::endl << test.search(2.3);
   // std::cout << test.head->key << std::endl;
    //std::cout << test.head->left->key << std::endl;
    //std::cout << test.head->right->key << std::endl;
    
}
