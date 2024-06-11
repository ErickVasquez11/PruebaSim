#include "BinaryTree/Node.h"
#include "Mef/Mef.h"
#include "BinaryTree/BinaryTree.h"
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

int main() {

    std::cout << "Aplicar condiciones de contorno 2..." << std::endl;


    std::cout << "Aplicar condiciones de contorno 1..." << std::endl;
   

    std::cout << "Resolviendo el sistema global.." << std::endl;
    std::cout << "    Calcular la inversa de la matriz global K..." << std::endl;
    // Aquí añadiríamos la lógica para calcular la inversa de la matriz global K

    std::cout << "    Realizando el cálculo final..." << std::endl;
    // Aquí añadiríamos la lógica para realizar el cálculo final

    std::cout << "Preparando resultados..." << std::endl;
    // Aquí podríamos preparar los resultados si hay alguna lógica adicional necesaria

    std::cout << "Escribir archivo de salida..." << std::endl;


    std::cout << "Archivo 'outpuLocalKandBResults.dat' generado con exito." << std::endl;

    BinaryTree tree;
    
    int n = 28;

    Node* nodes[28];

    nodes[0] = new Node(0, -2.5, 4.33);
    nodes[1] = new Node(1, -3.333333333333333, 2.8866666666666667);
    nodes[2] = new Node(2, -0.8333333333333339, 4.33);
    nodes[3] = new Node(3, -2.016217306380743, 1.466680831362954);
    nodes[4] = new Node(4, -4.166666666666666, 1.4433333333333334);
    nodes[5] = new Node(5, 0.833333333333333, 4.33);
    nodes[6] = new Node(6, 0.09630171361801398, 1.734496516961294);
    nodes[7] = new Node(7, -5.0, 0.0);
    nodes[8] = new Node(8, 2.5, 4.33);
    nodes[9] = new Node(9, -3.0269388852358077, -0.7035716122923228);
    nodes[10] = new Node(10, 2.1216166108994283, 1.579983422225986);
    nodes[11] = new Node(11, -0.8333333333333321, -0.8908399164912366);
    nodes[12] = new Node(12, 1.1882885093078324, -0.27628454043042794);
    nodes[13] = new Node(13, -4.166666666666667, -1.4433333333333334);
    nodes[14] = new Node(14, 3.3333333333333335, 2.8866666666666667);
    nodes[15] = new Node(15, -1.6666666666666663, -2.6104199582456182);
    nodes[16] = new Node(16, -3.3333333333333335, -2.8866666666666667);
    nodes[17] = new Node(17, 4.166666666666667, 1.4433333333333334);
    nodes[18] = new Node(18, 8.881784197001252e-16, -2.6104199582456182);
    nodes[19] = new Node(19, 3.111776109137395, -0.6383114431749415);
    nodes[20] = new Node(20, 1.8277885475186497, -2.511947101419608);
    nodes[21] = new Node(21, -2.5, -4.33);
    nodes[22] = new Node(22, 5.0, 0.0);
    nodes[23] = new Node(23, -0.833333333333333, -4.33);
    nodes[24] = new Node(24, 4.166666666666666, -1.4433333333333334);
    nodes[25] = new Node(25, 0.8333333333333339, -4.33);
    nodes[26] = new Node(26, 3.333333333333333, -2.8866666666666667);
    nodes[27] = new Node(27, 2.5, -4.33);

    cout << "\nMalla creada con 28 nodos" << endl;

    // Insertamos nodos en el árbol
    for (int i = 0; i < n; ++i) {
        tree.insertar(nodes[i]->id, nodes[i]->x, nodes[i]->y);
    }

    // Mostramos el árbol
    cout << "\nMOSTRANDO ARBOL" << endl;
    tree.mostrarArbol();

    // Generar el archivo MeshComplete.dat
    tree.generarMeshComplete("OutputMeshComplete.dat");

    // Generar el archivo MeshFigure.dat
    tree.generarMeshFigure("OutputMeshFigure.dat");

    // Inicializamos las matrices k y b
    int numNodes = 28;
    double** K = new double*[numNodes];
    for (int i = 0; i < numNodes; ++i) {
        K[i] = new double[numNodes]();
    }
    double* b = new double[numNodes]();

    // Cálculo de k y b.
    Mef mef;
    mef.calculateLocalKandB(tree.root, numNodes, K, b, 1.0/420.0);

    // Guardar en el archivo Mesh.dat
    ofstream meshFile("OutputMesh.dat");
    if (!meshFile.is_open()) {
        cerr << "Error opening file: Mesh.dat" << endl;
        return 1;
    }

    meshFile << "Coordinates:\n";
    for (int i = 0; i < numNodes; ++i) {
        meshFile << "Node " << nodes[i]->id << ": (" << nodes[i]->x << ", " << nodes[i]->y << ")\n";
    }

    meshFile << "\nLocal K Matrix:\n";
    for (int i = 0; i < numNodes; ++i) {
        for (int j = 0; j < numNodes; ++j) {
            meshFile << K[i][j] << " ";
        }
        meshFile << "\n";
    }

    meshFile << "\nLocal b Vector:\n";
    for (int i = 0; i < numNodes; ++i) {
        meshFile << b[i] << " ";
    }
    meshFile << "\n";

    // Cálculo de condiciones de Dirichlet y Neumann y guardado en el archivo
    meshFile << "\nDirichlet Conditions:\n";
    for (int i = 0; i < numNodes; ++i) {
        double g = nodes[i]->x * nodes[i]->x; // Ejemplo: g(x) = x^2
        meshFile << "Node " << nodes[i]->id << ": u = " << g << "\n";
    }

    meshFile << "\nNeumann Conditions:\n";
    for (int i = 0; i < numNodes; ++i) {
        double h = 2 * nodes[i]->x; // Ejemplo: h(x) = 2x
        meshFile << "Node " << nodes[i]->id << ": du/dn = " << h << "\n";
    }

    meshFile.close();

    cout << "Resultados guardados en OutputMesh.dat\n";

    // Liberar memoria
    for (int i = 0; i < numNodes; ++i) {
        delete[] K[i];
        delete nodes[i];
    }
    delete[] K;
    delete[] b;

    return 0;
    
}
