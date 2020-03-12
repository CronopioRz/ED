// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda_ext.h"

template <typename T>
void TreeInfo(bintree_ext<T> tree){
        std::vector<int> vFront;
        tree.frontier(vFront);
        for(int &i: vFront)
            std::cout << i << " ";
        std::cout << std::endl;

}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    bintree_ext<int> bintr = leerArbol_ext(-1);

    
    TreeInfo(bintr);
    // escribir sol
    
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta fel reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     #endif
    
    return 0;
}
