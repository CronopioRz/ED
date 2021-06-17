/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Manuel Montenegro Montes
 *              Facultad de Inform�tica
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

 /*
  * Introduce el nombre y apellidos de los/as componentes del grupo:
  *
  * Estudiante 1: Pablo Rabad�n Arza
  * Estudiante 2: David El�as Pi�eiro
  *
  */
 //Teniendo en cuenta que la función principal es solo evaluar, cada vez que reciba un vector de polinomios tendrá que recorrer todos
//los elementos de uno en uno, siendo siempre el coste O(n).
//El constructor tiene coste constante, ya que se genera siempre el polinomio vacío
//La función anyadir_monomio tiene en el mejor caso O(n) y el peor O(n^2) ya que es un algoritmo de insercción ordenada en un vector
//La función exp en el peor caso es O(n), siendo n el valor del exponente
//

#include <iostream>
#include <cassert>
#include <fstream>
#include <vector>

const int MAX_MONOMIOS = 10000;
  /* Define la clase 'Polinomio' aqu� */
class Polinomio {
private:

	struct monomio {
		long coef;
		long exp;
	};
	
	monomio monomios[MAX_MONOMIOS];
	int num_monomios;


public:
	//Constructor del polinomio vacio
	Polinomio() { num_monomios = 0; }
	
	
	void insertarMonomio(const int &pos,const monomio& insert) {
		for (int i = num_monomios; i > pos;i--) {
			monomios[i] = monomios[i-1];
		}
		monomios[pos] = insert;
		num_monomios++;
	}

	void sumarCoeficientes(const int& pos, const monomio& insert) {
		monomios[pos].coef += insert.coef;
	}
	
	void push_back(const monomio& insert) {
		monomios[num_monomios++] = insert;
	}
	
	void anyadir_monomio(long coef, long exp) {
		monomio aux;
		aux.coef = coef;
		aux.exp = exp;
		bool encontrado = false;
		

		int i = 0;
		while (i < num_monomios && !encontrado) {
			if (aux.exp <= monomios[i].exp) {
				encontrado = true;
			}
			else {
				i++;
			}
		}
		if (i == num_monomios && num_monomios<MAX_MONOMIOS) { //Encontrado antes de finalizar la busqueda
			push_back(aux);
		}
		else {
			if (aux.exp == monomios[i].exp) {
				sumarCoeficientes(i, aux);
			}
			else if (num_monomios <= MAX_MONOMIOS) {
				insertarMonomio(i, aux);
			}
		}
		
	}

	long exp(long valor, long  exp) const {
		long result = 1;
		for (long i = 0; i < exp; i++) {
			result *= valor;
		}
		return result;
	}

	long evaluar(long valor) const {
		long sol = 0;
		for (int i = 0; i < num_monomios; i++) {
			sol += exp(valor, monomios[i].exp) * monomios[i].coef;
		}
		return sol;
	}
};


bool tratar_caso() {
	long tam, val;
	long coef, exp;
	std::cin >> tam >> val;
	if (tam == 0 && val == 0) {
		return false;
	}
	Polinomio pol;
	for (long i = 0; i < tam; i++) {
		std::cin >> coef >> exp;
		pol.anyadir_monomio(coef, exp);
	}
	std::cout << pol.evaluar(val) << std::endl;
	return true;

}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("sample.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (tratar_caso()) {}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
