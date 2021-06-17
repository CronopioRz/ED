/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 */

/*
 * MUY IMPORTANTE: Para realizar este ejercicio solo podéis
 * modificar el código contenido entre las etiquetas <answer>
 * y </answer>. Toda modificación fuera de esas etiquetas no será
 * corregida.
 *
 * Tampoco esta permitido modificar las líneas que contienen
 * las etiquetas <answer> y </answer>, obviamente :-)
 */

//@ <answer>
/*
 * Introduce el nombre y apellidos de los/as componentes del grupo:
 *
 * Estudiante 1:Pablo Rabadán Arza
 * Estudiante 2: David Elías Piñeiro
 *
 */
//@ </answer>

#include <iostream>
#include <cassert>
#include <fstream>
#include <stack>
#include <deque>

using namespace std;

// Puedes copiar aquí algunas de las implementaciones de los TADs vistos esta semana:

// Pilas: https://github.com/manuelmontenegro/ED-2021/blob/master/lineales/stack_array/stack_array.h
// Colas: https://github.com/manuelmontenegro/ED-2021/blob/master/lineales/queue_array/queue_array.h
// Colas dobles: https://github.com/manuelmontenegro/ED-2021/blob/master/lineales/deque/dequeue.h

// En caso de utilizar alguno de los TADs anteriores, ha de copiarse TAL CUAL, sin realizar ningún cambio
// en sus implementaciones. Para facilitar la corrección, coloca la implementación de estos TADs fuera
// de las etiquetas <answer> y </answer>. El profesor asumirá que tienen la misma implementación que la
// vista en teoría.

// Alternativamente, puedes utilizar las clases de la librería estándar de C++ (stack<T>, queue<T> y deque<T>).

/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Manuel Montenegro Montes
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

// ----------------------------------------------------------------
//@ <answer>
void resolver(std::deque<int> &pilares)
{
  int elem;
  std::stack<int> aux;
  int tam = pilares.size();
  for(int i = 0; i < tam ; i++)
  {
    elem = pilares.front(); //Guardamos el elemento que comprobaremos
    pilares.pop_front();

    //En la cola dobla simplemente sacamos el elemento que queramos comprobar

    //Miramos en la pila auxiliar si hay algun elemento mayor que el elemnto que cabamos de sacar de la cola doble

    //A cada elemento en la pila que sea menor o igual que elem, hacemos pop y no lo guardamos en ningun lado

    //Si no hay ninguno mayor, mostramos "NO HAY", en caso contrario, mostramos el mayor

    //Al final el elem se introduce en la cima de la pila

    //Y en cada iteración vamos cogiendo la cima de la cola doble, hasta que esta quede vacía, eso significará que hemos acabado la búsqueda
    while(!aux.empty() && elem >= aux.top()){
        aux.pop();
    }
    if(aux.empty()){
        std::cout << "NO HAY" << std::endl;
    }
    else{
      std::cout << aux.top() << std::endl;
    }
    aux.push(elem);
  }
  std::cout << "---" << std::endl;
}

bool tratar_caso()
{
  // Completar
  int aux;
  std::cin >> aux;
  if (aux == -1)
    return false;
  std::deque<int> dcola;
  while (aux != -1)
  {
    dcola.push_back(aux);
    std::cin >> aux;
  }
  resolver(dcola);
  return true;
}

//@ </answer>

// ¡No modificar nada debajo de esta línea!
// ----------------------------------------------------------------

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
