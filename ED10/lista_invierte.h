#include"queue_eda.h"
#include <fstream>

template <class T> 
class ListaInserta : public queue<T> {
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

        //inserta un elemento en una lista enlazada simple
        void inserta(Nodo const&n){
            
        }
       
        friend std::ostream & operator<<(std::ostream & out, ListaInserta<T> const& l) {            
            l.print(out);
            return out;
        }
};


