#include"queue_eda.h"
#include <iostream>
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
        void inserta(ListaInserta<T> &lista,int const& posIn){
            //Nodo para guardar la direccion del elemento posterior a los insertados
            Nodo * aux = this->prim;
            int i = 0;
            while (i < posIn){
                if(i != 0)
                    aux = aux->sig;
                i++;
            }
            if (posIn == this->nelems) {  //Si se inserta al final
                this->ult = lista.ult;
            }
            if (posIn > 0) {    
                lista.ult->sig = aux->sig;                        // Si se
                                            //inserta en el medio
                aux->sig = lista.prim;
            }
            else {                         //Si se inserta al inicio
                lista.ult->sig = aux;
                this->prim = lista.prim;
            }
             this->nelems += lista.nelems;//Aumentamos el tamanyo de la nueva lista
            vacia(lista);                //Vaciamos la lista auxiliar
        }

        void vacia(ListaInserta<T>&l){
            l.prim=nullptr;
            l.ult = nullptr;
            l.nelems = 0; 
        }
       
        friend std::ostream & operator<<(std::ostream & out, ListaInserta<T>
const& l) {            
            l.print(out);
            return out;
        }
};