/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

/*
 * Introduce el nombre y apellidos de los/as componentes del grupo:
 *
 * Estudiante 1:
 * Estudiante 2:
 *
 */

#include <iostream>
#include <cassert>
#include <fstream>
#include <map>
#include <list>
#include <vector>
#include <algorithm>  

using namespace std;

int resolver (list<map<string,string>>const& estList, int const& nPreg){
  int size = estList.size();
  map<string,string> pair;
  //Hacemos un vector con cada estudiante que tenga hasta ahora un examen perfecto
  int failed = 0;
  string preg, resp;
  std::vector<bool> perfect(estList.size(), true);
  int i =0;
  //Comprobamos cuantos han acertado todas las preguntas
  while(i < nPreg && failed < size){
    std::cin >> preg >> resp;
    pair.insert({preg,resp});
    auto it = estList.begin();
    //Comprobamos quienes han acertado esas preguntas
    int j = 0;
    while(j < size){
      //Sacamos iterador de la lista de respuestas del estudiante
      //Si el el alumno ya ha fallado una pregunta antes no hace falta mirar
      if(perfect.at(j)){
        auto itPreg = it->find(preg);
        if(itPreg != it->end()){
          if(resp != itPreg->second){
            perfect.at(j) = false;
            failed++;
          } 
        }
      }
      it++;
      j++;
    }
    i++;
  }
  return size-failed;
}

bool tratar_caso()
{
  int nEst, nPregEst, nPregTot;
  int sol = 0;
  string key, value, name;
  list<map<string,string>> lEst;
  cin >> nEst >> nPregEst >> nPregTot;
  if (nEst == 0 && nPregEst == 0 && nPregTot == 0)
    return false;
  for (int i = 0; i < nEst; i++)
  {
    //Almacenamos en una lista el nombre y respuestas de cada estudiante
    map<string, string> student;
    std::cin >> name;
    for (int j = 0; j < nPregEst; j++)
    {
      map<string, string> question;
    //En el resto guardamos en un diccionario el par pregunta/respuesta

          std::cin >> key >> value;
          student.insert({key,value});
      
    }
    lEst.push_back(student);
  }
  sol = resolver(lEst,nPregTot);
  std::cout << sol << std::endl;
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
  // Descomentar si se trabaja en Windows
  // system("PAUSE");
#endif
  return 0;
}
