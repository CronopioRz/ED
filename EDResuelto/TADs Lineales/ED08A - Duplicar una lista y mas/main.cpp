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
        void duplicar(){
            Nodo* n = nullptr;
            Nodo* p = this->prim;
            
            //Recorremos la lista de nodos
            while(p != nullptr){
                ++this->nelems;
                //creamos un nodo copiando los valores del anterior
                n = new Nodo(p->elem,p->sig);
                
                //El anterior elemento apunta al que acabamos de crear
                p->sig = n;
                //Apuntamos al siguiente elemento no duplicado
                p = p->sig->sig;
            }
            //Asignamos un nuevo valor ultimo ya que
            //debe apuntar al duplicado del ultimo elemento
            this->ult = n;

        }

        void mostrar(){
            Nodo* p = this->prim;

            while (p != nullptr){
                cout << p->elem << " ";
                p = p->sig;
            }
            cout << endl;

        }

};

template <typename T>
void resolver(lista<T> &lista){
    lista.duplicar();
    cout << lista.size() << endl;
    lista.mostrar();

    //Hacemos push incorporando elementos al final de la lista
    int dato;
    cin>> dato;
    while (dato != 0){
        lista.push(dato);
        cin >> dato;
    }

    cin >> dato;

    //Hacemos pop el mismo número de veces que dato
    for(int i = 0; i < dato; ++i){
        lista.pop();
    }

    cout << lista.size() << endl;

    lista.mostrar();


}

bool resuelveCaso() {
    int dato;
    cin >> dato;

    if(!cin)
        return false;
    
    lista<int> miLista;
    while(dato != 0){
        miLista.push(dato);
        cin >> dato;
    }

    resolver(miLista);

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