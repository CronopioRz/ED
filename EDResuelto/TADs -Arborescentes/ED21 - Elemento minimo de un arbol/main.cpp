
#include <vector>
#include <fstream>
#include <iostream>

#include "bintree_eda.h"
using namespace std;

template <class T>
T recorreArbol (const bintree<T>& bt){
    //Recorremos con iteradores
    auto it = bt.begin();

    //La raiz es el elemento con el valor intermedio
    //a la iz son menores y a la derecha mayores
    T elementoMenor = *it;

    for(;it != bt.end(); ++it){//
        //Comparamos si el menor es el valor del nodo actual
        // o es el mínimo guardado hasta el momento 
        elementoMenor = min(elementoMenor,*it);
    }

    return elementoMenor;

}


bool resuelveCaso() {
    char tipo;
    cin >> tipo;
    if(!cin)
        return false;
    
    if(tipo == 'N')
        cout << recorreArbol(leerArbol(-1)) << endl;
    else{
        cout << recorreArbol(leerArbol(string("#"))) << endl;
    }
}

int main() {

	#ifndef DOMJUDGE
		std::ifstream in("EntradaEjemplo.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	while(resuelveCaso());

	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		// getchar();
	#endif

	return 0;

}