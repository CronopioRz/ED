// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "deque_eda.h"

template <typename T> 
class list_decoder : public deque<T>{
    private:
        using Nodo = typename deque<char>::Nodo;
    public:
        void print(){
            Nodo * aux  = this->fantasma->sig;
            while(aux != this->fantasma) {
                std::cout << aux->elem;
                aux = aux->sig;
            }
                std::cout << std::endl;
        }   
        void XdPrima(){

        }
        void Xprima(){

        }



};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    list_decoder<char> lCoded;
    std::string message;
    std::getline(std::cin,message);
    if (! std::cin)
        return false;
    
    
    // escribir sol
    for(char &c: message){
        lCoded.push_back(c);
    }
    lCoded.print();
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