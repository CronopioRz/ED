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
    if(datos.empty()) return false;
    if (aux == ')') return (datos.top() == '(');
    if (aux == ']') return (datos.top() == '[');
    if (aux == '}') return (datos.top() == '{');
    return true;
}


// función que resuelve el problema
bool resolver(std::string frase) {
    bool equil = true;
    stack<char> stack;
    int tam = frase.length();
    int i = 0;

    while(i < tam && equil){
        if(apertura(frase[i]))
            stack.push(frase[i]);
        else if(cierre(frase[i])){
            equil = balanced(frase[i],stack);
            if(!stack.empty())
             stack.pop();
        }
        i++;
    }
    return equil && stack.empty();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string frase;
    std::getline(std::cin,frase);
    if (!std::cin)
        return false;
    if(resolver(frase))
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