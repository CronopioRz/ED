/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 */

/*
 * Introduce el nombre y apellidos de los/as componentes del grupo:
 *
 * Estudiante 1: Pablo Rabadán Arza
 * Estudiante 2: David Elías Piñeiro
 *
 */

#include <iostream>
#include <fstream>
#include <list>

using namespace std;


bool es_toeplitz(const list<list<int>> &matriz)
{
  bool es_toeplitz = true;
  list<list<int>>::const_iterator itMatriz = matriz.begin();
  list<int>::const_iterator itFila1 = itMatriz->begin();
  itMatriz++;
  list<int>::const_iterator itFila2;
  while(itMatriz != matriz.end() && es_toeplitz){ //Falla ultimo caso
    itFila2 = itMatriz->begin();
    itFila2++;
    while(itFila2 != itMatriz->end() && es_toeplitz){
      if(*itFila1 != *itFila2) es_toeplitz = false;
      itFila1++;
      itFila2++;
    }
    itFila1 = itMatriz->begin();
    itMatriz++;
    
  }
  return es_toeplitz;
}

bool tratar_caso()
{
  list<list<int>> matriz;
  list<int> aux;
  int elem;
  std::cin >> elem;

  if (elem == 0)
    return false;

  while (elem != 0)
  {
    while (elem != 0)
    {
      aux.push_back(elem);
      std::cin >> elem;
    }
    matriz.push_back(aux);
    aux.clear();
    std::cin >> elem;
  }
  if (es_toeplitz(matriz))
  {
    std::cout << "SI" << std::endl;
  }
  else
  {
    std::cout << "NO" << std::endl;
  }
  return true;
  // Implementar
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
  // Descomentar si se trabaja en Windows
  // system("PAUSE");
#endif

  return 0;
}