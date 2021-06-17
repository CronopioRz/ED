// Nombre del alumno .....
// Usuario del Juez ......


#include <iomanip>
#include <fstream>
#include "lista_mezcla.h"



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    ListaMezcla<int> cPrin;
    ListaMezcla<int> cAux;
    int val;
    std::cin >> val;
    if (! std::cin)
        return false;
    /*Creamos la cola con los elementos en el buffer*/
    while(val != 0){
        cPrin.push(val);
       std::cin >> val;
    }
    std::cin >> val;
    while(val != 0) {
        cAux.push(val);
        std::cin >> val;
    }


    // escribir sol
    cPrin.mezclar(cAux);
    std::cout << cPrin << std::endl;
    return true;

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
    for(int i = 0; i < numCasos; i ++)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     #endif

    return 0;
}
