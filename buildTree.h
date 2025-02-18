#ifndef buildTree_h
#define buildTree_h
#include "node.h"
// Source: OR4 Comp Sci 2250
class treeNew
{
private:
    void destroySubTree(node_t *);

public:
    node_t *root = nullptr;
    treeNew()
    {
        root = nullptr;
    }
    ~treeNew()
    {
        destroySubTree(root);
    }
    void insertNode(std::string);
    void insert(node_t *&, node_t *&);
    void buildTree(std::string data);
};

#endif
