/*
Author: Nicholas Hieb
Date Created: 2/08/2025
This is our build tree file where we build our tree from the tree class.
*/
#include <string>
#include <iostream>
#include <fstream>
#include "buildTree.h"
using namespace std;
// We create a node to insert using the data from argument string and insert it with the Insert method.
// Source: C4
void treeNew::insertNode(string charNew)
{
    if (charNew.empty())
        return;
    node_t *newNode = new node_t;
    newNode->str = charNew;
    newNode->left = newNode->right = nullptr;
    newNode->count = charNew.length();
    insert(root, newNode);
}
// Source: C4
void treeNew::insert(node_t *&nodePtr, node_t *&newNode)
{
    if (nodePtr == nullptr)
        nodePtr = newNode;
    else if (newNode->count < nodePtr->count)
        insert(nodePtr->left, newNode);
    else if (newNode->count > nodePtr->count)
        insert(nodePtr->right, newNode);
    else
        insert(nodePtr->left, newNode);
}
// This function builds our tree with the given file and parses the characters each line at a time.
void treeNew::buildTree(string fileName)
{
    fstream dataFile;
    string readingString, subString;
    dataFile.open(fileName);

    try
    {
        if (!dataFile)
        {
            cout << "Error opening file" << endl;
            throw 505;
        }
        while (getline(dataFile, readingString))
        {
            // Parseing characters line by line in file
            for (int x = 0; x < readingString.length(); x++)
            {
                char chr = readingString[x];
                if (isalnum(chr))
                {
                    subString += chr;
                }
                else if (chr >= 33 && chr <= 43)
                {
                    subString += chr;
                }
                else if (isspace(chr))
                {
                    if (!subString.empty())
                    {
                        insertNode(subString);
                        subString.clear();
                    }
                }
                else
                {
                    cout << "Fatal Error in reading file: Unknown Character: " << readingString[x] << endl;
                    throw 505;
                }
            }
            if (!subString.empty())
            {
                insertNode(subString);
                subString.clear();
            }
        }
        dataFile.close();
    }
    catch (...)
    {
        cout << "Closing Program..." << endl;
    }
}
// Source: C4
void treeNew::destroySubTree(node_t *nodePtr)
{
    if (nodePtr)
    {
        if (nodePtr->left)
            destroySubTree(nodePtr->left);
        if (nodePtr->right)
            destroySubTree(nodePtr->right);
        delete nodePtr;
    }
}
