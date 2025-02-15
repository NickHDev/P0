#include <string>
#include <iostream>
#include <queue>
#include "traversals.h"
using namespace std;

void levelOrder(node_t *nodeP)
{
    if (nodeP == nullptr)
        return;
    levelOrder(nodeP->left);
    cout << nodeP->str << ": " << nodeP->count << endl;
    levelOrder(nodeP->right);
}

void preOrder(node_t *nodeP)
{
    if (nodeP == nullptr)
        return;
    cout << nodeP->str << ": " << nodeP->count << endl;
    preOrder(nodeP->left);
    preOrder(nodeP->right);
}

void postOrder(node_t *nodeP)
{
    if (nodeP == nullptr)
        return;
    postOrder(nodeP->left);
    postOrder(nodeP->right);
    cout << nodeP->str << ": " << nodeP->count << endl;
}
