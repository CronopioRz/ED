#include"queue_eda.h"
#include <iostream>
#include <fstream>

template <class T> 
class ListaMezcla : public queue<T> {
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

        //Mezclamos dos listas ordenadas
        void inserta(ListaMezcla<T> &lista){
            vacia(lista);                //Vaciamos la lista auxiliar
        }

        void vacia(ListaMezcla<T>&l){
            l.prim=nullptr;
            l.ult = nullptr;
            l.nelems = 0; 
        }
       
        friend std::ostream & operator<<(std::ostream & out, ListaMezcla<T> const& l) {            
            l.print(out);
            return out;
        }
};


