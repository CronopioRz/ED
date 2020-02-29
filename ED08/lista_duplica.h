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
            ListaDuplica<T> aux;
            int i = 0;
            while(!this->empty()) {
               aux.push(this->front());
               if(i % 2 != 0)
                  this->pop();
               i++;
            }
            this->copia(aux);
        }

        friend std::ostream & operator<<(std::ostream & out, ListaDuplica<T> const& l) {
            l.print(out);
            return out;
        }
};


