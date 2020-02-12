
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

#include "horas.h"  // propios o los de las estructuras de datos de clase

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
horas resolver(std::vector<horas> const  vTrenes, horas horaBusq, int ini, int fin) {
    if (ini+1 == fin){
        if (horaBusq <= vTrenes[ini]) return vTrenes[ini];
        else if (horaBusq <= vTrenes[fin]) return vTrenes[fin];
        else throw std::domain_error("NO");
    }
    else {
        int m = (ini+fin+1)/2;
        if (horaBusq < vTrenes[m]) return resolver(vTrenes,horaBusq,ini,m);
        else if (horaBusq == vTrenes[m]) return vTrenes[m];
        else return resolver(vTrenes,horaBusq,m,fin);
    }
}

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

inline std::ostream& operator<<(std::ostream & out, horas const& hora){
    out << hora.get_hora() << ':' << hora.get_minuto() << ':' << hora.get_segundo();
    return out;
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int numTrenes;
    int numHoras;

    horas hora1;

    std::cin >> numTrenes >> numHoras;
    std::vector<horas> vTrenes(numTrenes);
    std::vector<horas> vHoras(numHoras);
    if (numTrenes  == 0 && numHoras == 0)
        return false;
    for (int i = 0; i < numTrenes; i++)
        std::cin >> vTrenes[i];
    for (int i = 0; i < numHoras; i++) {
        try{
            std::cin>>vHoras[i];
            hora1 = resolver(vTrenes, vHoras[i], 0, (int)vTrenes.size());
            std::cout << hora1 << std::endl;
        }
        catch (std::invalid_argument &ia) {
            std::cout << ia.what() << std::endl;
        }
        catch (std::domain_error &de){
            std::cout << de.what() << std::endl;
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
