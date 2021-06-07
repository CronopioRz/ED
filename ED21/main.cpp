// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda_ext.h"

template <class T>
static T TreeMin(bintree_ext<T> const& tree){
        auto it = tree.begin();

        T menor = *it;

        while(it != tree.end()){
            menor = std::min(menor,*it);
            ++it;
        }
        return menor;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    char cType; 
    std::cin >> cType;
    if(!std::cin)
        return false;
    if (cType == 'N'){
        bintree_ext<int> binInt = leerArbol_ext(-1);
        std::cout << TreeMin(binInt) << std::endl;
    }
    else {
        bintree_ext<std::string> binStr = leerArbol_ext(std::string("#"));
        std::cout << TreeMin(binStr) << std::endl;
    }
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta fel reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while(resuelveCaso());

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     #endif
    
    return 0;
}
