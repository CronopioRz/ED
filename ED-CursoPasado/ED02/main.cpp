
// Nombre y Apellidos

// Comentario general sobre la soluci贸n,
// explicando c贸mo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

#include "pelicula.h"  // propios o los de las estructuras de datos de clase


// resuelve un caso de prueba, leyendo de la entrada la
// configuraci贸n, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int numPelis;


    std::cin >> numPelis;
    std::vector<pelicula> vPeliculas(numPelis);
    if (numPelis == 0)
        return false;
    try {
        for (int i = 0; i < numPelis; i++)
            std::cin >> vPeliculas[i];

        std::sort(vPeliculas.begin(), vPeliculas.end());

        for (pelicula &n: vPeliculas)
            std::cout << n.get_horaFin() << " " << n.get_titulo() << "\n";

    }
    catch (std::invalid_argument &ia) {
        std::cout << ia.what() << std::endl;

    }
    catch (std::domain_error &de){
        std::cout << de.what() << std::endl;
    }
    std::cout << "\n" << "---" << std::endl;

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
