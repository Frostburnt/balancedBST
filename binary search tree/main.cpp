//notes
//decided to use floats, as with a randomly generated num
//things to remember is left is always smaller, right is always larger than the current node
//the use of helper functions is just to handle Tree vs Node, or handle some printing
//this is starting out UNBALANCED btw
#include <iostream>
#include <string>
#include "node.h"
#include "bst.h"
#include <random>
#include <fstream>
#include <chrono>
#include <math.h>
#include < windows.h>
//IMPORTANT. if you are looking from the discord link
//this is NOT the only file anymore, look at the others, should be reasonably commented


//it is best to download and run the sln file in the base directory, and look around, this is pretty extensively commented in the other files, mostly the CPP ones
//structs ((classes that are all public by default)) are declared in headerfiles, and defined in CPP files. You might need to view both for context, 
// this has heavy use of pointers as well, as a catch up. '->' is basically  used the same as '.' except it's for pointers so...
//a thing that says node->key is essential just node.key if it was not a pointer
//there is some mixing of stuff here where I probably could have avoided a pointer, or done a const reference, but that's not too important


//limitations: this uses pointers to already existing objects instead of creating new Nodes via entering a value

//Node firstNode(3.43f);
BST test(NULL);

//what i want to do....
//have 4 files. BST time to insert, BST time to search
//and SGT time to insert, time to search
//from this I will make a graph in excel, or another piece of software and map out the timings on a per element basis


int main(){
    srand(time(0));
    for(int i = 0; i < 5; i++){
        const int arraySize = 1000 * pow(2, i) ;
        Node* nodeArray = new Node[arraySize];
        for (int i = 0; i < arraySize; i++) {
            nodeArray[i] = Node(rand());
        }
        for (int i = 0; i < 3; i++) {
           test.balanceFactor = 0.5 + 0.25 * i;
           std::string fileName = std::to_string(arraySize) + "BF" + std::to_string(test.balanceFactor) + "SGT.txt";
           std::ofstream File(fileName);
           for (int i = 0; i < arraySize; i++) {//testing insert for SGT

               auto start = std::chrono::high_resolution_clock::now();
               test.sgInsert(&nodeArray[i]);
               auto end = std::chrono::high_resolution_clock::now();
               auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
               File << duration.count() << ";" << std::endl;
           }
   
           
           auto start = std::chrono::high_resolution_clock::now();
           for (int i = 0; i < arraySize; i++)
               test.search(nodeArray[i].key);
   
           auto end = std::chrono::high_resolution_clock::now();
           auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
           std::cout << std::endl << "Scapegoat search time" << duration.count() << std::endl;
           
        {

           //test.display();

            File.close();
            for (int i = 0; i < arraySize; i++) {
                nodeArray[i].left = NULL;
                nodeArray[i].right = NULL;
                nodeArray[i].parent = NULL;
                nodeArray[i].subTreeDepth = 0;
                //std::cout << nodeArray[i].key << std::endl;
                //std::cout << nodeArray[i].key << std::endl;
                //std::cout << nodeArray[i].parent << std::endl;

        }
        test.head = NULL;
        }
        }
        std::ofstream File2(std::to_string(arraySize) + "BST_Insertion.txt");
        for (int i = 0; i < arraySize; i++) {//testing insert for BST
            auto start = std::chrono::high_resolution_clock::now();
            //std::cout << nodeArray[i].key;
            test.insert(&nodeArray[i]);
       
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            File2 << duration.count() << ";" << std::endl;
        }
    
        File2.close();
    
        {
            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < arraySize; i++)
                test.search(nodeArray[i].key);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            std::cout << std::endl << "Standard BST search time for" << std::to_string(arraySize)<<"elements" << duration.count() << std::endl;
        }
       /* for (int i = 0; i < arraySize; i++) {
            delete nodeArray[i];
        }
        *///test.display();
        //test.display();
        for (int i = 0; i < arraySize; i++) {
            nodeArray[i].left = NULL;
            nodeArray[i].right = NULL;
            nodeArray[i].parent = NULL;
            nodeArray[i].subTreeDepth = 0;
            //std::cout << nodeArray[i].key << std::endl;
            //std::cout << nodeArray[i].key << std::endl;
            //std::cout << nodeArray[i].parent << std::endl;

        }
    }

    //std::cout << test.head->left->key << std::endl;
    //std::cout << test.head->right->key << std::endl;
    //my conclusion is, 
  
    //delete[] nodeArray;
} 
