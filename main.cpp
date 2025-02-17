/*
Author: Nicholas Hieb
Date Created: 2/08/2025
This is our main file to get input from the user or file and parse the file and output the traversal files.
*/
#include <iostream>
#include <fstream>
#include <string>
#include "traversals.h"
#include "buildTree.h"
#include "main.h"
using namespace std;

int main(int argc, char *argv[])
{
    string inputData;
    string preOrder = ".preorder", postOrder = ".postorder", levelOrder = ".levelorder";
    ofstream inputDataFile("out.txt", ios::app);
    treeNew tree;
    int level = 0;

    preOrder = argv[1] + preOrder;
    postOrder = argv[1] + postOrder;
    levelOrder = argv[1] + levelOrder;
    // Removing any last used data files.
    remove(preOrder.c_str());
    remove(postOrder.c_str());
    remove(levelOrder.c_str());
    
    if (argv[1] && argc == 2)
    {
        tree.buildTree(argv[1]);
    }
    else if (argc < 2)
    {
        cout << "Keep typeing until 'ctrl + d' is entered to end input: \n";
        while (getline(cin, inputData))
        {
            inputDataFile << inputData;
        }
        inputDataFile.close();
        tree.buildTree("out.txt");
    }
    else
    {
        cout << "Fatal: Improper usage \n" << "Usage: P0 [filename] \n";
    }
        
    traversePreOrder(tree.root, level, preOrder);
    traverseLevelOrder(tree.root, level, levelOrder);
    traversePostOrder(tree.root, level, postOrder);
    remove("out.txt");

    return 0;
}