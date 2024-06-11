

---

# Integrantes 
Daniel Ernesto Morales Sigüenza 00139419
David Alejandro Iglesias Moreno - 00047920
Erick Fernando Quinteros Lizama - 00220619
Erick Rickelmy Vásquez Alfaro - 00065520

## Pasos para la Compilación

### Paso 1: Compilación del Código Fuente

```sh
g++ -std=c++11 -g main.cpp Mef/Mef.cpp BinaryTree/BinaryTree.cpp -o hexagonoMesh
```

**Descripción:**
- `g++`: Este es el compilador de C++ de GNU.
- `-std=c++11`: Esta opción especifica que se debe usar el estándar de C++11 para la compilación.
- `-g`: Esta opción agrega información de depuración al ejecutable.
- `main.cpp`: Este es el archivo principal que contiene la función `main()` del programa.
- `Mef/Mef.cpp`: Este archivo contiene la implementación de las funciones relacionadas con el Método de Elementos Finitos (MEF).
- `BinaryTree/BinaryTree.cpp`: Este archivo contiene la implementación de las funciones relacionadas con el Árbol Binario.
- `-o hexagonoMesh`: Esta opción especifica el nombre del archivo ejecutable generado, en este caso `hexagonoMesh`.

### Paso 2: Ejecución del Programa

```sh
./hexagonoMesh
```

**Descripción:**
- `./hexagonoMesh`: Este comando ejecuta el programa compilado. Asegúrate de estar en el directorio donde se encuentra el ejecutable o proporciona la ruta completa al mismo.

