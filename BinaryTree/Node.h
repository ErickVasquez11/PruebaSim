#ifndef NODE_H
#define NODE_H
#include <cstddef>

class Node {
public:
    int id;
    double x, y;
    Node *left;
    Node *right;

    Node() : id(0), x(0), y(0), left(nullptr), right(nullptr) {}
    Node(int id, double x, double y) : id(id), x(x), y(y), left(nullptr), right(nullptr) {}
};

#endif // NODE_H
