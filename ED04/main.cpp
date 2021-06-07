// Nombre del alumno .....
// Usuario del Juez ......

#include "polinomio.h"
#include <iostream>
#include <iomanip>
#include <fstream>




// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int coef;
    int exp;
    int nVar;
    int var;
    polinomio poli;

    std::cin >> coef;
    if (! std::cin)
        return false;
    
    std::cin >> exp;

    while(!(coef == 0 && exp == 0)){
        poli.agregar(coef,exp);
        std::cin >> coef;
        std::cin >> exp;
    }
    
    std::cin >> nVar;

    for(int i = 0; i < nVar; i++){
        std::cin >> var;
        int sol = poli.eval(var);
        std::cout << sol << " ";
    }
    std::cout << std::endl;
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     #endif
    
    return 0;
}