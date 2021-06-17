#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
#include "list_eda.h"

int resolver (list<int> &lista, const int &saltos){
    auto it = lista.begin();
    int cont = 0;
    while(lista.size() > 1){
        if(cont == saltos){
            it = lista.erase(it);
            cont = 0;
        }
        else{
            it++;
            cont++;
        }
        if(it == lista.end())
            it = lista.begin();
    }
    return lista.back();
    
}
bool resuelveCaso() {
    int alumnos;
    int saltos;

    cin >> alumnos;
    cin >> saltos;
    if(alumnos == 0 && saltos == 0)
        return false;

    int datos;
    
    list<int> lista;
    for(int i = 1; i <= alumnos; i++){
        lista.push_back(i);
    }

    //Ahora resolvemos, nos devolvera la solucion un int

    cout << resolver(lista,saltos) << endl;

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