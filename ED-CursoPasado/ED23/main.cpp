// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

// función que resuelve el problema
int resolver(const bintree<int> &tree,int &nResc, int &max_exc) {
   if(tree.empty()){
       return 0;
   }
   else{
        auto iz = resolver(tree.left(),nResc, max_exc);
        auto dr = resolver(tree.right(),nResc, max_exc);

        if( (iz == 0 && dr == 0 && tree.root() > 0) ){
            nResc++;
        }

        if (iz >= max_exc) max_exc = iz + tree.root();
        else if (dr >= max_exc) max_exc = dr + tree.root();
        
        return iz + dr + tree.root();
   }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada 
    int empty = -1;
    bintree<int> tree = leerArbol(empty);
    int numResc = 0;
    int maxEsc = 0;
    // escribir sol
    resolver(tree,numResc,maxEsc);
    std::cout << numResc << " " << maxEsc << std::endl; 
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
