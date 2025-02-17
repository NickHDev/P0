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
// create node to insert
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
// insert node
void treeNew::insert(node_t *&nodePtr, node_t *&newNode)
{
    if (nodePtr == nullptr)
        nodePtr = newNode;
    else if (newNode->count < nodePtr->count)
        insert(nodePtr->left, newNode);
    else if (newNode->count > nodePtr->count)
        insert(nodePtr->right, newNode);
}
// This function builds our tree with the given file.
void treeNew::buildTree(string fileName)
{
    fstream dataFile;
    string readingString, subString;
    dataFile.open(fileName);

    while (getline(dataFile, readingString))
    {
        // Parseing characters in file
        for (int x = 0; x < readingString.length(); x++)
        {
            if (!isalpha(readingString[x]))
            {
                if (!subString.empty())
                {
                    insertNode(subString);
                    subString.clear();
                }
                readingString.erase(x, 1);
                x--;
            }
            else
            {
                subString.append(1, readingString[x]);
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
