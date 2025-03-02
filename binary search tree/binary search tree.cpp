//notes
//decided to use floats, as with a randomly generated num
//things to remember is left is always smaller, right is always larger than the current node
//the use of helper functions is just to handle Tree vs Node, or handle some printing
//this is starting out UNBALANCED btw
#include <iostream>
#include "node.h"
#include "bst.h"



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
