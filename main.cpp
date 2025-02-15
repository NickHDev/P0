#include <iostream>
#include <fstream>
#include <string>
#include "traversals.h"
#include "buildTree.h"
using namespace std;

int main(int argc, char *argv[])
{
    string data, subString;
    fstream dataFile;
    treeNew tree;

    int endPoint = 0;
    int count = 0;

    dataFile.open(argv[1]);
    while (getline(dataFile, data))
    {
        for (int x = 0; x < data.length(); x++) // parseing characters in file
        {
            if (!isalpha(data[x]))
            {
                // data.erase(x, 0);
                tree.insertNode(subString);
                subString.clear();
            }
            else
            {
                subString.append(1, data[x]);
            }
        }
    }
    // preOrder(tree.root);
    levelOrder(tree.root);
    // postOrder(tree.root);
    dataFile.close();

    // process command line arguments and make sure file
    // is readable, error otherwise
    // set up keyboard processing so that hereafter the
    // input method is not relevant
    return 0;
}
