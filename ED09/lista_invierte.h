#include"queue_eda.h"
#include <fstream>

template <class T> 
class ListaInvierte : public queue<T> {
    //Para poder renombrar un nodo 
    using Nodo = typename queue<T>::Nodo;
    public:
        void print(std::ostream& o =std::cout) const{
           if(!this->empty()){
             Nodo * aux = this->prim;
             while(aux != nullptr) {
                 o << aux->elem << " ";
                 aux =aux->sig; 
             }   
           }
        }

        //invierte los nodos de una lista enlazada simple
        void invierte() {
            if(this->nelems > 1){ //La lista no tiene menos de dos elementos
                Nodo * aux1 = this->prim;//Apuntara al nodo siguiente al que se ira modificando
                Nodo * aux2 = aux1->sig;//Apuntara al nodo que modificaremos
                this->ult = this->prim; //El ultimo elemento sera el nuevo primero
                aux1->sig = nullptr; // El ultimo nodo no tiene un siguiente nodo asignado
                while(aux1 != nullptr) {//el siguiente al primero le apuntara, y se desplazaran todos una posicion a la derecha
                    aux1 = aux2->sig; 
                    aux2->sig = this->prim; 
                    this->prim = aux2; 
                    aux2 = aux1; 
                }
            }
        }

        friend std::ostream & operator<<(std::ostream & out, ListaInvierte<T> const& l) {            
            l.print(out);
            return out;
        }
};


