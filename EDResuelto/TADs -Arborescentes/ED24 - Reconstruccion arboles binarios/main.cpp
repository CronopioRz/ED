#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

#include "bintree_eda.h"

struct indices {
	//Guardamos los indices del rango [ini,fin] de los vectores
	pair <int,int> in;
	pair <int,int> pre;
};

bintree<int> reconstruirArbol(const std::vector<int>& preorden, const std::vector<int>& inorden, const indices& i) {

	if(i.pre.first > i.pre.second) {

		return {};

	} else {

		int raiz = preorden[i.pre.first];

		int posicionRaizInorden = std::distance(inorden.begin()+i.in.first,std::find(inorden.begin()+i.in.first,inorden.begin()+i.in.second,raiz));

		bintree<int> izq = reconstruirArbol(preorden,inorden,{{i.in.first,i.in.first+posicionRaizInorden-1},{i.pre.first+1,i.pre.first+posicionRaizInorden}});

		bintree<int> der = reconstruirArbol(preorden,inorden,{{i.in.first+posicionRaizInorden+1,i.in.second},{i.pre.first+posicionRaizInorden+1,i.pre.second}});

		return { izq , raiz , der };

	}

}


bool resuelveCaso() {
	string linea;
	getline(cin,linea);
	if(!cin)
		return false;
	
	int dato;
	vector<int> preorden;
	stringstream iss(linea);

	while(iss >> dato){
		preorden.push_back(dato);
	}
	getline(cin,linea);
	vector<int> inorden;
	stringstream iss2(linea);

	while (iss2 >> dato){
		inorden.push_back(dato);
	}
	struct indices i = {
		{0,inorden.size()-1},
		{0,preorden.size()-1}
	};
	vector<int> sol = reconstruirArbol(preorden, inorden,i).postorder();
	
	for(int &n: sol){
		cout << n << " ";
	}
	cout << endl;
	return true;

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