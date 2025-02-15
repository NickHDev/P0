#ifndef node_h
#define node_h

struct node_t
{
    std::string str = "";
    int count = 0;
    node_t *left = nullptr;
    node_t *right = nullptr;
};
#endif
