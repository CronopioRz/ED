/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Manuel Montenegro Montes
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

/*
  * Introduce el nombre y apellidos de los/as componentes del grupo:
  *
  * Estudiante 1: Pablo Rabadán Arza
  * Estudiante 2: David Elías Piñeiro
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

/* Define la clase 'Polinomio' aquí */
class Polinomio
{
private:
	struct monomio
	{
		long coef;
		long exp;
	};
	std::vector<monomio> polinomio;

public:
	//Constructor del polinomio vacio
	Polinomio(){};
	void anyadir_monomio(long coef, long exp)
	{
		monomio aux;
		aux.coef = coef;
		aux.exp = exp;
		bool encontrado = false;
		std::vector<monomio> v;
		if (aux.coef != 0)
		{
			int i = 0;
			while (i < (long)polinomio.size() && !encontrado)
			{
				if (aux.exp <= polinomio[i].exp)
				{
					encontrado = true;
				}
				else
				{
					i++;
				}
			}
			if (i == (long)polinomio.size() && polinomio.size() <= MAX_MONOMIOS)
			{ //El exponente de aux es mayor que todos los exponentes del polinomio
				polinomio.push_back(aux);
			}
			else
			{
				if (aux.exp == (long)polinomio[i].exp)
				{
					polinomio[i].coef += aux.coef; //Hay un monomio con el mismo exponente, con lo cual se suman
				}
				else if(polinomio.size() <= MAX_MONOMIOS)
				{
					polinomio.insert(polinomio.begin() + i, aux); //Insertamos en la posición de manera ordenada
				}
			}
		}
	}

	long exp(long const &valor, long const &exp) const
	{
		long result = 1;
		for (long i = 0; i < exp; i++)
		{
			result *= valor;
		}
		return result;
	}

	long evaluar(long valor) const
	{
		long sol = 0;
		for (long i = 0; i < (long)polinomio.size(); i++)
		{
			sol += exp(valor, polinomio[i].exp) * polinomio[i].coef;
		}
		return sol;
	}
};

bool tratar_caso()
{
	int tam, val;
	long coef, exp;
	std::cin >> tam >> val;
	if (tam == 0 && val == 0)
	{
		return false;
	}
	Polinomio pol;
	for (long i = 0; i < tam; i++)
	{
		std::cin >> coef >> exp;
		pol.anyadir_monomio(coef, exp);
	}
	std::cout << pol.evaluar(val) << std::endl;
	return true;
}

int main()
{
#ifndef DOMJUDGE
	std::ifstream in("sample.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (tratar_caso())
	{
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
#endif
	return 0;
}
