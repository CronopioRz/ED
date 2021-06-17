#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std; 

#include "bintree_eda.h"


struct datos {
    int nodos;
    int hojas; 
    int altura;
};

template <typename T>
datos recorrerArbol(const bintree<T> &bt){
    //Caso base
    if(bt.empty()){
        return {0,0,0};
    }
    else{
        auto iz = recorrerArbol(bt.left());
        auto dr = recorrerArbol(bt.right());

        return {1 + iz.nodos + dr.nodos, (iz.hojas == 0 && dr.hojas ==0)? 1: (iz.hojas + dr.hojas), 1 + max(iz.altura ,dr.altura)};
    }
    
    

}

void resuelveCaso() {
    //Bintree tiene una funcion para leer el arbol
    //Se introduce el valor que represente un arbol vacio
    bintree<char> bt = leerArbol('.');

    auto solucion = recorrerArbol(bt);

    std::cout << solucion.nodos << " " << solucion.hojas << " " << solucion.altura << endl;
}

int main() {

	#ifndef DOMJUDGE
		std::ifstream in("EntradaEjemplo.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	int casos;
	std::cin >> casos;

	for ( ; casos > 0 ; --casos)

		resuelveCaso();

	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		// getchar();
	#endif

	return 0;

}