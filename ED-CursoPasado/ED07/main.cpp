// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "stack_eda.h"
#include "fecha.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
typedef struct {
    fecha year;
    int nCasualties;
}flight;

inline std::ostream & operator<<(std::ostream & out, flight const& f) {
    out << f.year << " "<<f.nCasualties;
    return out;
}

inline std::istream & operator>>(std::istream & in, flight & f){
    in >> f.year >> f.nCasualties;
    return in;
}

bool resuelveCaso() {
    // leer los datos de la entrada

    int numCasos;
    std::cin >> numCasos;
    if(!std::cin )
        return false;
    flight aux;
    stack<flight> pila;
    for (int i = 0; i < numCasos; ++i){

        bool found = false;
        std::cin >> aux;
        while(!pila.empty() && !found) {
            if(aux.nCasualties < pila.top().nCasualties) {
                found = true;
            }
            else  {
                pila.pop();
            }
        }
        if(found){
            std::cout << pila.top().year << std::endl;
        }
        else {
            std::cout << "NO HAY" << std::endl;
        }
        pila.push(aux);
        aux = pila.top();
    }
    std::cout << "---" << std::endl;
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
