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
#include <unordered_map>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;


bool tratar_caso()
{
  int nEst, nPregEst, nPregCat;
  cin >> nEst >> nPregEst >> nPregCat;
  if (nEst == 0 && nPregEst == 0 && nPregCat == 0)
    return false;
  //Creamos un mapa con los datos de los alumnos
  unordered_map<string, unordered_map<string, string>> examMap;
  unordered_set<string> students;
  string estName;
  for (int i = 0; i < nEst; i++)
  {
    cin >> estName;
    students.insert(estName);
    //Creamos una entrada de un examen de cada alumno
    for (int j = 0; j < nPregEst; j++)
    {
      string question, answer;
      cin >> question >> answer;
      //Guardamos un mapa por cada pregunta
      //Nos permite despues buscar con facilidad que usuarios han contestado
      examMap[question].insert({estName,answer});
    }
  }
  //Aquí hacemos los cálculos de las respuestas del exámen
  for(int i = 0; i < nPregCat; i++){
    string question,answer;
    cin >> question >> answer;
    for(const auto &[k,v]: examMap[question]){
      if(v != answer){
        students.erase(k);
      }
    }
  }

  cout << students.size() << endl;

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
