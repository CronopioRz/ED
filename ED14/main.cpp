// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "deque_eda.h"
#include "stack_eda.h"

bool esVocal(const char& caracter) {

	bool esVocal = false;

	switch (caracter) {
		case 'a': esVocal = true; break;
		case 'A': esVocal = true; break;
		case 'e': esVocal = true; break;
		case 'E': esVocal = true; break;
		case 'i': esVocal = true; break;
		case 'I': esVocal = true; break;
		case 'o': esVocal = true; break;
		case 'O': esVocal = true; break;
		case 'u': esVocal = true; break;
		case 'U': esVocal = true; break;
	}
	return esVocal;
}

std::string resolver(std::string const& mensajeCodificado){
    deque<char> cola;
    stack<char> pila;
    std::string mensajeDescodificado;

    for(int i = 0; i < mensajeCodificado.size(); i++){
        //Si es par se coloca en orden
        if(i % 2 == 0) {
            cola.push_back(mensajeCodificado[i]);
        }
        //Si es impar se invierte con una pila 
        else {
            pila.push(mensajeCodificado[i]);
        }
    }
    //Metemos en la cola los elementos de la pila
    while(!pila.empty()){
        cola.push_back(pila.top());
        pila.pop();
    }
    //Vaciamos la cola introducioendo los mensajes de forma ordenada en un string
    while(!cola.empty()) {
        //Si el valor es vocal se introduce en orden
		if(esVocal(cola.front())) {

			mensajeDescodificado += cola.front();
			cola.pop_front();

		}
        //Si el valor es consonante se meten los valores siguientes en una pila
        //hasta que se encuentre una vocal, para introducirlos de manera inversa 
        else {

			while(!cola.empty() && !esVocal(cola.front())) {

				pila.push(cola.front());
				cola.pop_front();

			}

			while(!pila.empty()) {

				mensajeDescodificado += pila.top();
				pila.pop();

			}

		}

	}
    return mensajeDescodificado;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string message;
    std::getline(std::cin,message);
    if (! std::cin)
        return false;
    // escribir sol
    std:: cout << resolver(message) << std::endl;
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