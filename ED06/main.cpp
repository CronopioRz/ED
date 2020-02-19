// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "stack.h"

bool correct(char const& simbol) {
        return simbol == '(' || simbol  == ')' || simbol == '[' || simbol == ']' || simbol == '{' || simbol == '}';
}

bool cierre(char const& aux){
    return ((aux == ']') || (aux == ')') || (aux == '}'));
}
bool apertura (char const& aux){
    return ((aux == '[') || (aux == '(') || (aux == '{'));
}

bool balanced(char const& aux,stack<char> const&datos){
    if(datos.empty()) return !cierre(aux);
    else if (aux == ')') return (datos.top() == '(' || cierre(datos.top()));
    else if (aux == ']') return (datos.top() == '[' || cierre(datos.top()));
    else if (aux == '}') return (datos.top() == '{' || cierre(datos.top()));
    else return apertura(aux);
}


// función que resuelve el problema
bool resolver(stack<char> datos) {
    char aux;
    bool equil = true;
   
    while(equil && !datos.empty()) {
        aux = datos.top();
        datos.pop();
        if (!balanced(aux,datos) ){
            equil = false;
        }
        
    }
    return equil;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    stack<char> charStack;
    std::string frase;
    std::getline(std::cin,frase);
    if (!std::cin)
        return false;
    for(char &c: frase){
        if(correct(c))
            charStack.push(c);
    }
    if(resolver(charStack))
        std::cout << "SI" << std::endl;
    else 
        std::cout << "NO" << std::endl;
    
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("casos.txt");
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