// Nombre del alumno .....
// Usuario del Juez ......


#include <iomanip>
#include <fstream>
#include "lista_inserta.h"



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    ListaInserta<int> cPrin;
    ListaInserta<int> cAux;
    int nElem, val, posInsrt;
    std::cin >> nElem;
    if (! std::cin)
        return false;
    /*Creamos la cola con los elementos en el buffer*/
    for(int i =0; i < nElem; i++){
       std::cin >> val;
       cPrin.push(val);
    }
    std::cin >> nElem;
    std::cin >> posInsrt;
    for(int i = 0; i < nElem; i++) {
        std::cin >>val;
        cAux.push(val);
    }


    // escribir sol
    cPrin.inserta(cAux, posInsrt);
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



    while (resuelveCaso())
        ;

    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     #endif

    return 0;
}
