#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
#include "queue_eda.h"

template <typename T>
class lista: public queue<T> {
    private:
        using Nodo = typename queue<T>::Nodo;
    public:
        void mezclar (lista<T> &secundaria){
            //Si la principal esta vacia simplemente se inserta la secundaria
            if(this->empty()){
                this->prim = secundaria.prim;
                this->ult= secundaria.ult;
            }
            else{
                //Si la lista secundaria esta vacia se mantiene la principal
                if(!secundaria.empty()){
                    Nodo* aux;
                    Nodo* p = this->prim;
                    Nodo* s = secundaria.prim;
                    
                    //Si hay que insertar en el extremo izquierdo
                    if(p->elem >s->elem){
                            this->prim = s;
                            aux = s->sig;
                            s->sig = p;
                            s = aux;
                        }
                    //Mientras haya que insertar
                    while(s != nullptr){
                        //Si insertamos en esta posición o en la siguiente
                        while(p->sig != nullptr && p->sig->elem < s->elem){
                            p = p->sig;
                        }
                        
                        

                        //Conectamos 
                        //(p)->(s)->(p->sig)
                        aux =s->sig;
                        s->sig = p->sig;
                        p->sig = s;

                        //Si s->sig es nulo hemos recorrido s y no lo hemos conectado
                        //a ningun nodo de la cola principal con lo cual s->elem es mayor que p->elem
                        if(s->sig == nullptr){
                            this->ult = s;
                        }
                        s = aux;
                    }
                }
            }
            this->nelems += secundaria.nelems;
            secundaria.prim = nullptr;
            secundaria.ult = nullptr;
            secundaria.nelems = 0;

        }

        void mostrar() {
            Nodo * p = this->prim;
            while (p != nullptr){
                cout << p->elem << " ";
                p = p->sig;
            }
            cout << endl;
        }
};

template<typename T>
void resolver(lista<T> &principal, lista<T> &secundaria){
    principal.mezclar(secundaria);
    principal.mostrar();

} 

void resuelveCaso(){
    int dato;
    lista<int> principal;
    lista<int> secundaria;

    cin >> dato;

    while(dato != 0){
        principal.push(dato);
        cin >> dato;
    }

    cin >> dato;

    while(dato != 0){
        secundaria.push(dato);
        cin >>dato;
    }

    resolver(principal,secundaria);

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