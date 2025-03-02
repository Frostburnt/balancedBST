//notes
//decided to use floats, as with a randomly generated num
//things to remember is left is always smaller, right is always larger than the current node
//the use of helper functions is just to handle Tree vs Node, or handle some printing
//this is starting out UNBALANCED btw
#include <iostream>
#include "node.h"
#include "bst.h"
//IMPORTANT. if you are looking from the discord link
//this is NOT the only file anymore, look at the others, should be reasonably commented


//it is best to download and run the sln file in the base directory, and look around, this is pretty extensively commented in the other files, mostly the CPP ones
//structs ((classes that are all public by default)) are declared in headerfiles, and defined in CPP files. You might need to view both for context, 
// this has heavy use of pointers as well, as a catch up. '->' is basically  used the same as '.' except it's for pointers so...
//a thing that says node->key is essential just node.key if it was not a pointer
//there is some mixing of stuff here where I probably could have avoided a pointer, or done a const reference, but that's not too important


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
