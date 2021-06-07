// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"


// función que resuelve el problema
void resolver(list<int>& lista,const int& numSalt) {
    int aux = 0;

    while(lista.size() != 1){
        auto it = lista.begin();

        while (it != lista.end() && lista.size() != 1){
            if(aux == numSalt){
                aux = 0;
                it = lista.erase(it);
            }

            if(it != lista.end()){
                ++aux;
                ++it;
            }
        }
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nAl, numSalto;
    std::cin >> nAl >> numSalto;
    if (nAl == 0 && numSalto == 0)
        return false;
    
    list<int> listaAlumn;

    //Rellenamos la lista con los elementos
    for(int i = 1; i <= nAl; ++i) listaAlumn.insert(listaAlumn.end(),i);

    if (numSalto != 0){
        resolver(listaAlumn, numSalto);
        std::cout << *listaAlumn.begin() << "\n";
    }
    else 
        std::cout << listaAlumn.back() << "\n";
    
    
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
