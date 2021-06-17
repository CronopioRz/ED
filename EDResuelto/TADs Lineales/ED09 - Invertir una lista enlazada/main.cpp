#include <vector>
#include <fstream>
#include <iostream>

#include "queue_eda.h"

template<typename T>
class lista: public queue<T> {
    private:
        using Nodo = typename queue<T>::Nodo;
    public:

    void invertir(){
        //Si la lista no está vacía
        if(this->prim != nullptr){
            Nodo* prev = this->prim;
            Nodo* pos = this->prim->sig;
            Nodo* med = this->prim->sig;

            prev->sig = nullptr;

            while(pos != nullptr){
                //Guardamos el siguiente elemento en la auxiliar
                pos = pos->sig;
                //Hacemos que el valor del medio aunte al anterior
                med->sig = prev;

                //Guardamos avanzamos una posición
                //sig se guarda al incio del siguiente caso para evitar excepciones
                //al llegar al final de la lista
                prev = med;
                med = pos;
            }
            //Una vez invertido actualizamos los valores 
            //ult y prim que se han intercambiado
            std::swap(this->ult,this->prim);
        }

    }

    void mostrar(){
        Nodo *n = this->prim;

        while(n != nullptr){
            std::cout << n->elem << " ";
            n = n->sig; 
        }
    }

};

template<typename T>
void resolver (lista<T> &lista){
    lista.invertir();
    lista.mostrar();
}

bool resuelveCaso() {

	int dato;
	std::cin >> dato;

	if(!std::cin)

		return false;

	lista<int> miLista;

	while(dato != 0) {

		miLista.push(dato);

		std::cin >> dato;

	}

	resolver(miLista);

	std::cout << std::endl;

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