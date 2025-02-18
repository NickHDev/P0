/*
Author: Nicholas Hieb
Date Created: 2/08/2025
This File uses binary tree traversals to go through our binary tree in certain order and print
the [level] [num of chars] [node string data] according to the traversal.
*/

#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include "traversals.h"
using namespace std;

// We use a stack to go through level order because this is a BWS.
// Source: C1
void traverseLevelOrder(node_t *root, int level, string fileName)
{
    if (root == nullptr)
        return;

    ofstream dataFile(fileName, ios::app);
    queue<node_t *> q;
    vector<vector<int>> res;
    q.push(root);

    while (!q.empty())
    {
        int length = q.size();
        res.push_back({});
        for (int i = 0; i < length; i++)
        {
            node_t *node = q.front();
            q.pop();
            res[level].push_back(node->count);

            dataFile << string(level * 4, ' ') << level << " " << node->count << " " << node->str << endl;

            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        level++;
    }
}
// For pre-order traversal we can use recursion and print before function calls.
// Source: C3
void traversePreOrder(node_t *root, int level, string fileName)
{
    if (root == nullptr)
        return;
    ofstream dataFile(fileName, ios::app);
    dataFile << string(level * 4, ' ') << level << " " << root->count << " " << root->str << endl;
    traversePreOrder(root->left, level + 1, fileName);
    traversePreOrder(root->right, level + 1, fileName);
}
// For post-order traversal we can use recursion and print after function calls.
// Source: C3
void traversePostOrder(node_t *root, int level, string fileName)
{
    if (root == nullptr)
        return;
    ofstream dataFile(fileName, ios::app);
    traversePostOrder(root->left, level + 1, fileName);
    traversePostOrder(root->right, level + 1, fileName);
    dataFile << string(level * 4, ' ') << level << " " << root->count << " " << root->str << endl;
}
