#ifndef MEF_H
#define MEF_H

#include <vector>
#include <string>
#include "../BinaryTree/Node.h" 
#include "../BinaryTree/BinaryTree.h"
#include <cmath>


class Mef {
public:
    void printMessage();
    void generateMeshFile(const std::string& filename);
    void calculateDirichlet();
    void calculateNeumann();
    void calculateLocalKandB(Node* root, int numNodes, double** K, double* b, double factor);

private:
    std::vector<std::vector<double>> coordinates;
    std::vector<std::vector<double>> localK;
    std::vector<std::vector<double>> localB;
    void initializeData();
};

#endif // MEF_H
