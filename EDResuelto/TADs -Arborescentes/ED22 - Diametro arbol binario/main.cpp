#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

#include "bintree_eda.h"

struct datos {
    int diametro;
    int caminoMax;
};

template <typename T>
datos recorrerArbol(const bintree<T> &bt){
    if(!bt.empty()){
        datos iz = recorrerArbol(bt.left());
        datos dr = recorrerArbol(bt.right());
        return {
            max(max(iz.diametro,dr.diametro), 1+ iz.caminoMax+dr.caminoMax),
            1 + max(iz.caminoMax,dr.caminoMax)
        };
    }else{
        return {0,0};
    }
}


void resuelveCaso() {

	std::cout << recorrerArbol(leerArbol('.')).diametro << std::endl;

}

int main() {

	#ifndef DOMJUDGE
		std::ifstream in("EntradaEjemplo.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	int casos;
	std::cin >> casos;

	for( ; casos > 0 ; --casos)

		resuelveCaso();

	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		// getchar();
	#endif

	return 0;

}