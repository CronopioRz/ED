#include <vector>
#include<fstream>
#include<iostream>
#include "queue_eda.h"
using namespace std;


template<typename T>
class lista : public queue<T> {

private:

	using Nodo = typename queue<T>::Nodo;
    public:

    void insertar(lista<T> &secundaria,const int &pos){
        int i = 0;
        Nodo* p = this->prim;

        while(i < pos-1){
            p = p->sig;
            ++i;
        }

        this->nelems += secundaria.nelems;

        if(p == this->prim && pos == 0){
            secundaria.ult->sig = this->prim;
            this->prim = secundaria.prim;
        }
        else {
            secundaria.ult->sig = p->sig;
            p->sig = secundaria.prim;
        }

        secundaria.prim = nullptr;
        secundaria.ult = nullptr;
        secundaria.nelems = 0;
    }

    void mostrar() {

		Nodo* p = this->prim;

		while(p != nullptr) {

			std::cout << p->elem << " ";

			p = p->sig;

		}

	}
};

template<typename T>
void resolver(lista<T>&principal, lista<T>&secundaria, const int &pos){
    principal.insertar(secundaria,pos);
    principal.mostrar();
}

bool resuelveCaso() {
    int elementos;
    cin >> elementos;

    if(!cin){
        return false;
    }

    int dato;
    lista<int> principal;

    for(int i = 0; i < elementos;  ++i){
        cin >> dato;
        principal.push(dato);
    }

    int posicion;
    cin >> elementos >> posicion;
    lista<int> secundaria;
    for(int i=0; i < elementos; ++i){
        cin >>dato;
        secundaria.push(dato);
    }

    resolver(principal,secundaria,posicion);
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