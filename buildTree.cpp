#include <string>
#include <iostream>
#include <fstream>
#include "buildTree.h"
using namespace std;

void treeNew::insertNode(string charNew) // create node to insert
{
    node_t *newNode = nullptr;
    newNode = new node_t;
    newNode->str = charNew;
    newNode->left = newNode->right = nullptr;
    newNode->count = charNew.length();
    insert(root, newNode);
}
void treeNew::insert(node_t *&nodePtr, node_t *&newNode) // insert node
{
    if (nodePtr == nullptr)
        nodePtr = newNode;
    else if (newNode->count < nodePtr->count)
        insert(nodePtr->left, newNode);
    else
        insert(nodePtr->right, newNode);
}
void treeNew::buildTree(string fileName)
{
    fstream dataFile;
    string readingString, subString;
    dataFile.open(fileName);
    while (getline(dataFile, readingString))
    {
        for (int x = 0; x < readingString.length(); x++) // parseing characters in file
        {
            if (!isalpha(readingString[x]))
            {
                readingString.erase(x, 0);
                insertNode(subString);
                subString.clear();
            }
            else
            {
                subString.append(1, readingString[x]);
            }
        }
    }
    dataFile.close();
}

bool treeNew::searchNode(string charToSearch)
{
    node_t *nodePtr = root;
    while (nodePtr)
    {
        if (nodePtr->str == charToSearch)
            return true;
        else if (charToSearch < nodePtr->str)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    return false;
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
