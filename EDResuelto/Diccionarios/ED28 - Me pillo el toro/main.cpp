#include <map>
#include <fstream>
#include <iostream>

using namespace std;

using calificacion = int;
using alumno = std::string;

std::map<alumno,calificacion> resolver(const int& ejercicios) {
    string nota;
    string nombre;

    map<alumno,calificacion> resultados;

    for(int i = 0; i < ejercicios; ++i){
        getline(cin,nombre);
        getline(cin,nota);

        resultados[nombre] += ((nota.compare("CORRECTO") == 0)? 1 : -1);
    }
    return resultados;
}


bool resuelveCaso() {
    int ejercicios;
    cin >> ejercicios;

    if(ejercicios == 0)
        return false;

    string saltoLinea;
    getline(cin,saltoLinea);
    for(const auto& solucion : resolver(ejercicios))

		if(solucion.second != 0)

			std::cout << solucion.first << ", " << solucion.second << std::endl;

	std::cout << "---" << std::endl;

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
