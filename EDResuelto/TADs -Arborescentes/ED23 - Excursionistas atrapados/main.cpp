#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

#include "bintree_eda.h"


struct datos {
	int nRescate;
	int nAtrapados;
};

template <typename T>
datos recorrerArbol(const bintree<T> &bt){
	//Si el arbol no está vacío
	if(!bt.empty()){
		auto iz = recorrerArbol(bt.left());
		auto dr = recorrerArbol(bt.right());
		int nresc;
		int natrap;

		//Si hay gente atrapada en ese nodo
		if(bt.root() > 0){
			natrap = bt.root();
			nresc = 1;
		}
		else {
			nresc = 0;
			natrap = 0;
		}
		//Miramos si hay equipos de recaste en algun lateral
		if(iz.nRescate > 0 || dr.nRescate > 0){
			nresc = iz.nRescate + dr.nRescate;
			natrap += max(iz.nAtrapados,dr.nAtrapados);
		}

		//Calculamos cual es la ruta con mas numero de excursionistas atrapados


		return {
			nresc,natrap
		};

	}
	else{
		return {0,0};
	}
    
}


void resuelveCaso() {
	bintree<int> bt = leerArbol(-1);
	auto sol = recorrerArbol(bt);
	std::cout << sol.nRescate << " " << sol.nAtrapados << std::endl;

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