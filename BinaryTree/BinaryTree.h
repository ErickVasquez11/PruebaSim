#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Node.h"
#include <fstream>
#include <iomanip>

class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();
    void insertar(int id, double x, double y);
    void destroyTree();
    void mostrarArbol();
    void generarMeshComplete(const std::string& filename);
    void generarMeshFigure(const std::string& filename); // Nueva función
    
    Node *root;

private:
    void destroyTree(Node *leaf);
    void insertar(int id, double x, double y, Node *leaf);
    void mostrarArbolRecursivo(Node *node);
    void generarMeshCompleteRecursivo(Node *node, std::ofstream &file);
};

#endif // BINARYTREE_H
