// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "deque_eda.h"


template <typename T>
class deque_short : public deque<T> {
    private:
        using Nodo = typename deque<int>::Nodo;
    public:

        void print(){
            Nodo * aux  = this->fantasma->sig;
            while(aux != this->fantasma) {
                std::cout << aux->elem << " ";
                aux = aux->sig;
            }
                std::cout << std::endl;
        }   

            // función que resuelve el problema 

        void shorting() {
            Nodo * nodoPrin = this->fantasma->sig;
            Nodo * auxAnt;
            Nodo * auxPos;
            //Recorremos y cuando encontremos un elemento negativo
            // lo colocamos en el final 
            while (nodoPrin != this->fantasma){
                //Si encontramos un elemento menor que 0
                if(nodoPrin->elem < 0){
                    //Conectamos los dos nodos entre el valor negativo
                    auxAnt = nodoPrin->ant;
                    auxPos = nodoPrin->sig;
                    auxAnt->sig = auxPos;
                    auxPos->ant = auxAnt;
                    //Movemos el elemento libre al final de la cola
                    auxAnt = this->fantasma->sig;
                    //Conectamos los nodos iniciales con el elemento
                    nodoPrin->ant = this->fantasma;
                    nodoPrin->sig = auxAnt;
                    auxAnt->ant = nodoPrin;
                    this->fantasma->sig = nodoPrin;
                    //Continuamos en el siguiente elemento
                    nodoPrin = auxPos;
                }
                else //En caso contrario miramos en el siguiente elemento 
                    nodoPrin = nodoPrin->sig;
            }
        }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nCasos, aux;
    std::cin >> nCasos;
    deque_short<int> dq;
    if (nCasos == 0)
        return false;
    for(int i = 0; i < nCasos; i++){
        std::cin >> aux;
        dq.push_back(aux);
    }
    //TipoSolucion sol = resolver(datos);
    
    // escribir sol
    dq.shorting();
    dq.print();
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     #endif
    
    return 0;
}
