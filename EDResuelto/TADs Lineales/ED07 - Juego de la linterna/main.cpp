
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;


bool resolver(std::vector<int> const& fila, int numSobrinos) {
    std::stack<int> pila;
	int medio = -1;

	//Insertamos el ultimo elemento en la fila:
	pila.push(fila[fila.size() - 1]);

	for (int i = numSobrinos - 2; i >= 0; --i) {
		if (medio > fila[i] && medio < pila.top()) return false;
		else {
			while (!pila.empty() && fila[i] > pila.top()) {
				medio = pila.top();
				pila.pop();
			}
			pila.push(fila[i]);
		}
	}

	return true;  
}

bool resuelveCaso() {
    int numSobrinos;
    cin >> numSobrinos;

    if(!cin) return false;

    std::vector<int> fila(numSobrinos);
    for(int &n: fila){
        cin>>n;
    }

    bool ok = resolver(fila, numSobrinos);

    if(ok) cout << "SIEMPRE PREMIO" << "\n";
    else cout << "ELEGIR OTRA" << '\n';

    return true;

}
int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	//save old buf and redirect std::cin to casos.txt
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
#endif

	return 0;
}