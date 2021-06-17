#include <queue>
#include <stack>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

bool esVocal(const char &c){
    return (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I'
             || c == 'o' || c == 'O' || c == 'u' || c == 'U');
}

string decodificar (const string &mensaje){
    stack<char> invert;
    queue<char> normal;
    bool vocalEncontrada = false;
    for(int i = 0; i < mensaje.size(); ++i){
        //impar
        if(i % 2 != 0){
            invert.push(mensaje[i]);
        }
        else{
            normal.push(mensaje[i]);
        }
    }
    while(!invert.empty()){
        normal.push(invert.top());
        invert.pop();
    }
    //Decodificada la primera parte
    //Debemos buscar dos vocales e invertir los valores entre esa posicion  
    string mensajeDesc;
    while(!normal.empty()){
        if(esVocal(normal.front())){
                //Si hemos encontrado nconsonantes antes sacamos de la pila 
                while(!invert.empty()){
                    mensajeDesc += invert.top();
                    invert.pop();
                }
            
            mensajeDesc += normal.front();
            normal.pop();
        }//Si encontramos consonantes guardamos en pila para invertir
        else{
            invert.push(normal.front());
            normal.pop();
        }
    }
    //Por si acaba la frase sin vocal al final
    while (!invert.empty()){
        mensajeDesc += invert.top();
        invert.pop();
    }

    return mensajeDesc;
}

bool resuelveCaso() {
    string mensaje;
    getline(cin,mensaje);

    if(!cin)
        return false;
    

    //Codificamos de X'' a X'
    string sol = decodificar(mensaje);

    cout << sol << endl;

    return true;


}



int main() {

	#ifndef DOMJUDGE
		std::ifstream in("EntradaEjemplo.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	while(resuelveCaso());

	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		// getchar();
	#endif

	return 0;

}