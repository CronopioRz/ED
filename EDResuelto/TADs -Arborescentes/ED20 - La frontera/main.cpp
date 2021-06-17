
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
#include "bintree_eda.h"

template<class T>
std::vector<T> recorrerArbol(const bintree<T>& bt){
    //Si 
    if(!bt.empty()){
        //Si estamos en una hoja almacenamos el elemento
        if(bt.left().empty() && bt.right().empty())
            return {bt.root()};
        else{
            vector<T> iz = recorrerArbol(bt.left());
            vector<T> dr = recorrerArbol(bt.right());

            //izq y dr almacenan vectores con sus hojas
            //debemos guardar en iz los elementos de dr para tener el 
            for(int &n: dr){
                iz.push_back(n);
            }

            return iz;
        }
    }
    else {
        return {};
    }

}

void resuelveCaso() {
    bintree<int> bt = leerArbol(-1);
    for(int &i: recorrerArbol(bt)){
        cout << i << " ";
    } 
    cout << endl;

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