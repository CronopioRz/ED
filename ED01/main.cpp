
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>

#include "horas.h"  // propios o los de las estructuras de datos de clase

const int MAX_TRENES = 1000;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...





// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int numTrenes;
    int numHoras;

    std::cin >> numTrenes >> numHoras;
    if ((numTrenes  == 0 && numHoras == 0) || numTrenes > MAX_TRENES)
        return false;
    std::vector<horas> vTrenes(numTrenes);
    
        for (int i = 0; i < numTrenes; i++)
            std::cin >> vTrenes[i];
        for (int i = 0; i < numHoras; i++) {
        try{
            horas h;
            std::cin>>h;
            auto pos = lower_bound(vTrenes.begin(), vTrenes.end(), h);
            if (pos == vTrenes.end()){
                std::cout << "NO\n";
            }
            else 
                std::cout << *pos << '\n';
        }
        catch (std::domain_error &de){
         std::cout << "ERROR\n";
        }

        }     
   
    std::cout << "---" << std::endl;


    return true;
}



int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
