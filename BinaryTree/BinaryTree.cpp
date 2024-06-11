#include "BinaryTree.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include "Node.h"

BinaryTree::BinaryTree() {
    root = nullptr;
}

BinaryTree::~BinaryTree() {
    destroyTree(root);
}

void BinaryTree::insertar(int id, double x, double y) {
    if (root != nullptr) {
        insertar(id, x, y, root);
    } else {
        root = new Node(id, x, y);
    }
}

void BinaryTree::insertar(int id, double x, double y, Node *leaf) {
    if (id < leaf->id) {
        if (leaf->left != nullptr) {
            insertar(id, x, y, leaf->left);
        } else {
            leaf->left = new Node(id, x, y);
        }
    } else {
        if (leaf->right != nullptr) {
            insertar(id, x, y, leaf->right);
        } else {
            leaf->right = new Node(id, x, y);
        }
    }
}

void BinaryTree::destroyTree(Node *leaf) {
    if (leaf != nullptr) {
        destroyTree(leaf->left);
        destroyTree(leaf->right);
        delete leaf;
    }
}

void BinaryTree::mostrarArbol() {
    mostrarArbolRecursivo(root);
}

void BinaryTree::mostrarArbolRecursivo(Node* node) {
    if (node != nullptr) {
        std::cout << "Nodo ID: " << node->id << " Coordenadas: (" << node->x << ", " << node->y << ")" << std::endl;

        // Mostrar el subárbol izquierdo
        if (node->left != nullptr) {
            std::cout << "Izquierdo de " << node->id << ": " << std::endl;
            mostrarArbolRecursivo(node->left);
        } else {
            std::cout << "Izquierdo de " << node->id << ": NULL" << std::endl;
        }

        // Mostrar el subárbol derecho
        if (node->right != nullptr) {
            std::cout << "Derecho de " << node->id << ": " << std::endl;
            mostrarArbolRecursivo(node->right);
        } else {
            std::cout << "Derecho de " << node->id << ": NULL" << std::endl;
        }
    }
}

void BinaryTree::generarMeshComplete(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    file << "Malla creada con 28 nodos\n";
    generarMeshCompleteRecursivo(root, file);
    file.close();
}

void BinaryTree::generarMeshCompleteRecursivo(Node* node, std::ofstream &file) {
    if (node != nullptr) {
        file << "Nodo ID: " << node->id << " Coordenadas: (" << node->x << ", " << node->y << ")\n";

        // Mostrar el subárbol izquierdo
        if (node->left != nullptr) {
            file << "Izquierdo de " << node->id << ": " << std::endl;
            generarMeshCompleteRecursivo(node->left, file);
        } else {
            file << "Izquierdo de " << node->id << ": NULL\n";
        }

        // Mostrar el subárbol derecho
        if (node->right != nullptr) {
            file << "Derecho de " << node->id << ": " << std::endl;
            generarMeshCompleteRecursivo(node->right, file);
        } else {
            file << "Derecho de " << node->id << ": NULL\n";
        }
    }
}

void BinaryTree::generarMeshFigure(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    // Asumiendo que ya tenemos las coordenadas de los 28 nodos en una estructura de datos
    Node* nodes[28] = {
        new Node(0, -2.5, 4.33),
        new Node(1, -3.333333333333333, 2.8866666666666667),
        new Node(2, -0.8333333333333339, 4.33),
        new Node(3, -2.016217306380743, 1.466680831362954),
        new Node(4, -4.166666666666666, 1.4433333333333334),
        new Node(5, 0.833333333333333, 4.33),
        new Node(6, 0.09630171361801398, 1.734496516961294),
        new Node(7, -5.0, 0.0),
        new Node(8, 2.5, 4.33),
        new Node(9, -3.0269388852358077, -0.7035716122923228),
        new Node(10, 2.1216166108994283, 1.579983422225986),
        new Node(11, -0.8333333333333321, -0.8908399164912366),
        new Node(12, 1.1882885093078324, -0.27628454043042794),
        new Node(13, -4.166666666666667, -1.4433333333333334),
        new Node(14, 3.3333333333333335, 2.8866666666666667),
        new Node(15, -1.6666666666666663, -2.6104199582456182),
        new Node(16, -3.3333333333333335, -2.8866666666666667),
        new Node(17, 4.166666666666667, 1.4433333333333334),
        new Node(18, 8.881784197001252e-16, -2.6104199582456182),
        new Node(19, 3.111776109137395, -0.6383114431749415),
        new Node(20, 1.8277885475186497, -2.511947101419608),
        new Node(21, -2.5, -4.33),
        new Node(22, 5.0, 0.0),
        new Node(23, -0.833333333333333, -4.33),
        new Node(24, 4.166666666666666, -1.4433333333333334),
        new Node(25, 0.8333333333333339, -4.33),
        new Node(26, 3.333333333333333, -2.8866666666666667),
        new Node(27, 2.5, -4.33)
    };

    file << "Mesh Figure with 28 nodes:\n";
    for (int i = 0; i < 28; ++i) {
        file << "Node ID: " << nodes[i]->id << " Coordinates: (" << nodes[i]->x << ", " << nodes[i]->y << ")\n";
    }

    file.close();
}

