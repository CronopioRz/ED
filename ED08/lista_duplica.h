#include"queue_eda.h"
#include <fstream>

template <class T> 
class ListaDuplica : public queue<T> {
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

        //duplicar los nodos de una lista enlazada simple
        void duplica() {
            Nodo * nodo1 = this->prim;
            Nodo * aux;
            while(nodo1 != nullptr){
                aux = new Nodo(nodo1->elem);
                aux->sig = nodo1->sig;
                nodo1->sig = aux;
                nodo1 = aux->sig;
            }
            this->ult = aux;
            this->nelems += this->nelems;
        }

        friend std::ostream & operator<<(std::ostream & out, ListaDuplica<T> const& l) {
            l.print(out);
            return out;
        }
};


