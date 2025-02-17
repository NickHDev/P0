#include <iostream>
#include <fstream>
#include <string>
#include "traversals.h"
#include "buildTree.h"
#include "main.h"
using namespace std;

int main(int argc, char *argv[])
{
    string inputData, inputSubString;
    ofstream inputDataFile("inputData.txt", ios::app);
    treeNew tree;
    int level = 0;

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
        tree.buildTree("inputData.txt");
    }
    else 
    {
        perror("Error Reading Data.");
    }

    //preOrder(tree.root, level);
    //cout << "\n";
    levelOrder(tree.root, level);
    //cout << "\n";
    //postOrder(tree.root, level);
    remove("inputData.txt");

    // process command line arguments and make sure file
    // is readable, error otherwise
    // set up keyboard processing so that hereafter the
    // input method is not relevant
    return 0;
}