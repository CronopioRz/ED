// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "conjunto.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    char type;
    size_t maxVal;

    std::cin >> type >> maxVal;
    
    if (! std::cin)
        return false;
    
    if(type == 'N'){
        int aux;
        set<int> intTad;
        //Solo insertamos k-mayores
        while(intTad.size() < maxVal){
            std::cin >> aux;
            intTad.insert(aux);
        }

        while( aux != -1){
            if(!intTad.contains(aux) && aux > intTad.showMin()){
                intTad.deleteMin();
                intTad.insert(aux);
            }
            std::cin >> aux; 
        }
        //Muetsra el conjunto final
        while (!intTad.empty()){
            std::cout << intTad.showMin() << " ";
            intTad.deleteMin();
        }
        std::cout << std::endl;
    } 
    
    else { 
        std::string str;
        set<std::string> intTad;
        //Solo insertamos k-mayores
        while(intTad.size() < maxVal){
            std::cin >> str;
            intTad.insert(str);
        }

        while( str != "FIN"){
            if(!intTad.contains(str) && str > intTad.showMin()){
                intTad.deleteMin();
                intTad.insert(str);
            }
            std::cin >> str; 
        }
        //Muetsra el conjunto final
        while (!intTad.empty()){
            std::cout << intTad.showMin() << " ";
            intTad.deleteMin();
        }
        std::cout << std::endl;
    }

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