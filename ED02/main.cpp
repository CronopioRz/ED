
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

// funci贸n que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


inline std::istream& operator>>(std::istream & in,horas &hora ) {
    int h, m, s;
    std::string horario;
    in >> horario;
    h = std::stoi(horario.substr(0,2));
    m = std::stoi(horario.substr(3,2));
    s =std::stoi(horario.substr(6,2));

    hora = horas(h,m,s);
    return in;
}

inline std::istream& operator>>(std::istream & in, pelicula & pelicula1) {
    horas horainicio;
    horas horaDur;
    std::string titulo;

    in >> horainicio >> horaDur;
    getline(in,titulo);
    pelicula1 = pelicula(horainicio,horaDur,titulo);
    return in;
}

inline std::ostream& operator<<(std::ostream & out, horas const& hora){
    out << std::setfill('0') << std::setw(2) << hora.get_hora()  << ':' 
        << std::setfill('0') << std::setw(2) << hora.get_minuto()  << ':' 
        << std::setfill('0') << std::setw(2) << hora.get_segundo();
    return out;
}
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

        std::sort(vPeliculas.begin(), vPeliculas.begin() + vPeliculas.size());

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
