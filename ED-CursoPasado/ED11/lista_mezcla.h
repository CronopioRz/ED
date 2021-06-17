#include"queue_eda.h"
#include <iostream>
#include <fstream>

template <class T> 
class Lista : public queue<T> {
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
        void mezclar(ListaMezcla<T> &lista){
            if(this->empty()){
                //Si lista1 esta vacia, copiamos la lista2 en lista1
                this->prim = lista.prim;
                this->ult = lista.ult;
                this->nelems= lista.nelems;
            }
            else {
                if(!lista.empty()){
                    //Si lista2 esta vacia no hay que hacer nada
                    //Creamos los nodos auxilares que recorreran las colas
                    Nodo * aux = nullptr;
                    Nodo * tmp = nullptr;
                    Nodo * nodo1 = this->prim;
                    Nodo * nodo2 = lista.prim;
                    while (nodo2 != nullptr){
                        //Buscamos en la primera lista el primer elemento mayor
                        // al elemento actual de la segunda lista
                        while((nodo1 != nullptr) && (nodo1->elem < nodo2->elem)){
                            //guardamos el anterior y el actual para luego poder introducir el elemento de 
                            //la lista 2 entre los dos nodos
                            aux = nodo1;
                            nodo1 = nodo1->sig;
                        }
                        //Cuando el primer valor de la lista secundaria es menor al
                        // primero de la principal
                        if (this->prim == nodo1 ) {
                            //El nuevo primero elemento sera el valor de la auxiliar
                            //y el segundo valor es el primero de la principal
                            nodo1 = nodo2;
                            nodo2 = nodo2->sig;
                            nodo1->sig = this->prim;
                            this->prim = nodo1;
                        }
                        else{
                            //Cuando insertamos entre dos elementos en la lista principal
                            aux->sig = nodo2;
                            tmp = nodo2->sig;
                            nodo2->sig = nodo1;

                            //Si estamos en el ultimo elemento de la secundaria y hemos recorrido
                            //la lista principal simplemente apuntamos al nodo2 como ultimo elemento 
                            //de la lista
                            if (nodo2->sig == nullptr && nodo1 == nullptr) this->ult = nodo2;
                            nodo2 = tmp; 
                            aux = aux->sig;
                        }
                    }


                }

            }
            this->nelems += lista.nelems;      
            
            vacia(lista);//Vaciamos la lista auxiliar
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


