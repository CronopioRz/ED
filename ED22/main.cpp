// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

// función que resuelve el problema
int resolver(const bintree<char> &tree,int &max_length) {
   if(tree.empty()){
       return 0;
   }
   else{
        auto iz = resolver(tree.left(),max_length);
        auto dr = resolver(tree.right(),max_length);

        if((iz + dr + 1) > max_length){
             max_length = iz + dr + 1;
        }
        return 1 + std::max(iz,dr);
   }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada 
    bintree<char> tree = leerArbol('.');
    int longMax = 0;
    // escribir sol
    int sol = resolver(tree,longMax);
    std::cout << longMax << std::endl; 
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
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
