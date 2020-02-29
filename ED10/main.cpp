// Nombre del alumno .....
// Usuario del Juez ......


#include <iomanip>
#include <fstream>
#include "lista_invierte.h"



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    ListaInvierte<int> cola;
    int elem;
    std::cin >> elem;
    if (! std::cin)
        return false;
    /*Creamos la cola con los elementos en el buffer*/
    while(elem != 0){
       cola.push(elem);
       std::cin >> elem;
    }

    // escribir sol
    cola.invierte();
    std::cout << cola << std::endl;
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
