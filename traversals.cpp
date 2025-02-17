#include <string>
#include <iostream>
#include <queue>
#include "traversals.h"
using namespace std;

void levelOrder(node_t *nodeP, int level)
{
    if (nodeP == nullptr)
        return;
    levelOrder(nodeP->left, level + 1);
    for (int i = 0;i < ((level - 1) * 4);i++)
    {
        cout << " ";
    }
    cout << " " << level << " " << nodeP->count << " " << nodeP->str << endl;
    levelOrder(nodeP->right, level + 1); 
}

void preOrder(node_t *nodeP, int level)
{
    if (nodeP == nullptr)
        return;
    cout << level << " " << nodeP->count << " " << nodeP->str << endl;
    preOrder(nodeP->left, level + 1);
    preOrder(nodeP->right, level + 1);
}

void postOrder(node_t *nodeP, int level)
{
    if (nodeP == nullptr)
        return;
    postOrder(nodeP->left, level + 1);
    postOrder(nodeP->right, level + 1);
    cout << level << " " << nodeP->count << " " << nodeP->str << endl;
}
