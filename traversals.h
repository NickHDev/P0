
#ifndef traversals_h
#define traversals_h
#include "node.h"
#include "buildTree.h"
void traverseLevelOrder(node_t *nodeP, int level, std::string fileName);
void traversePreOrder(node_t *nodeP, int level, std::string fileName);
void traversePostOrder(node_t *nodeP, int level, std::string fileName);
#endif
