#include "Mef.h"
#include <iostream>
#include <fstream>
#include <cmath>

void Mef::printMessage() {
    std::cout << "Hello from Mef!" << std::endl;
}

void Mef::generateMeshFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    initializeData();

    file << "Coordinates:\n";
    for (const auto& coord : coordinates) {
        for (double value : coord) {
            file << value << " ";
        }
        file << "\n";
    }

    file << "Local K:\n";
    for (const auto& k : localK) {
        for (double value : k) {
            file << value << " ";
        }
        file << "\n";
    }

    file << "Local B:\n";
    for (const auto& b : localB) {
        for (double value : b) {
            file << value << " ";
        }
        file << "\n";
    }

    file.close();
}

void Mef::calculateDirichlet() {
    std::cout << "Calculating Dirichlet conditions...\n";
    // Supongamos que g(x) = x^2 para ilustrar
    for (const auto& coord : coordinates) {
        double g = coord[0] * coord[0]; // Ejemplo: g(x) = x^2
        std::cout << "Dirichlet condition at (" << coord[0] << ", " << coord[1] << "): u = " << g << "\n";
    }
}

void Mef::calculateNeumann() {
    std::cout << "Calculating Neumann conditions...\n";
    // Supongamos que h(x) = 2x para ilustrar
    for (const auto& coord : coordinates) {
        double h = 2 * coord[0]; // Ejemplo: h(x) = 2x
        std::cout << "Neumann condition at (" << coord[0] << ", " << coord[1] << "): du/dn = " << h << "\n";
    }
}

void Mef::calculateLocalKandB(Node* root, int numNodes, double** K, double* b, double factor) {
    if (root == nullptr) {
        return;
    }

    calculateLocalKandB(root->left, numNodes, K, b, factor);

    // Supongamos que los valores se llenan en base a una simple fórmula para ilustrar
    int i = root->id;
    for (int j = 0; j < numNodes; ++j) {
        K[i][j] = factor * (i + j + 1); // Ejemplo de cálculo simple
    }
    b[i] = factor * (i + 1); // Ejemplo de cálculo simple

    calculateLocalKandB(root->right, numNodes, K, b, factor);
}

void Mef::initializeData() {
    // Inicializar datos de coordenadas, K locales y B locales
    coordinates = {{0.0, 0.0}, {1.0, 0.0}, {0.0, 1.0}, {1.0, 1.0}};
    localK = {{1.0, 0.0}, {0.0, 1.0}};
    localB = {{1.0}, {0.0}};
}
