
// E58(USUARIO DEL JUEZ)

// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO


#include <iostream>               
#include <fstream>               
#include <algorithm>
using namespace std;

#include "deque_eda.h"

class ListaParticion : public deque<int> {
    using Nodo = typename deque<int>::Nodo;
public:
   void print(std::ostream& o = std::cout) const {
      // rellenar
        Nodo * aux  = this->fantasma->sig;
        while(aux != this->fantasma) {
            std::cout << aux->elem << " ";
            aux = aux->sig;
        }
            std::cout << std::endl;
      

   }
   
   // produce la partición de la lista respecto al privote
   void particion(int pivote) {
      // rellenar
      Nodo * elemento = this->fantasma->sig;
      Nodo * sig;
      Nodo * ant;
      Nodo * posInsert = elemento;
      Nodo * aux = nullptr;
     if (this->nelems > 1){
         while(elemento != this->fantasma){
           ant = elemento->ant;
           sig = elemento->sig;
           //Vemos si el elemento se mueve a la izquierda 
           if(elemento->elem >= pivote || elemento->ant == this->fantasma || ant->elem < pivote){
              //Si no esta en la primera posicion buscamos el primer elemento menor
              elemento = elemento->sig;
           }
           //Buscamos el siguiente elemento
           else {
                 //Buscamos el anterior elemnto menor para insertar, si no lo insertamos al inicio de la cola
                 while(posInsert != this->fantasma && posInsert->elem >= pivote ){
                    posInsert = posInsert->ant;
                 }
                 if(elemento->sig == this->fantasma){
                    posInsert = posInsert->ant;
                 }
                 //insertamos el elemento
                 //primero unimos los nodos adyacentes al elemento
                 ant->sig = sig;
                 sig->ant = ant;
                 // Insertamos el elemento con su nuevo nodo posterior
                 sig = ant;
                 elemento->sig = sig;
                 sig->ant = elemento;
                 //Insertamos elemento en la posicion anterior
                  posInsert->sig = elemento;
                  elemento->ant = posInsert;
                  posInsert = posInsert->sig;
                  elemento = sig;
                  
           }
        }
     }
      
   }
};



/////////////////////////////////////////////////////////
// de aquí hacia abajo NO se puede modificar nada

inline std::ostream& operator<<(std::ostream & o, ListaParticion const& a) {
   a.print(o);
   return o;
}

bool resuelveCaso() {
   int N, pivote;
   cin >> N >> pivote;
   if (!cin)
      return 0;
   
   ListaParticion lista;
   // leemos la lista de la entrada
   int elem;
   for (int i = 0; i < N; ++i) {
      cin >> elem;
      lista.push_back(elem);
   }
   
   
   lista.particion(pivote);
   
   cout << lista << '\n';
   
   return true;
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   while (resuelveCaso());

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   // system("PAUSE");
#endif
   return 0;
}
