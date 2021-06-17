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
#include <fstream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

class AcademiaChino
{
public:
  // Definiciones públicas ¡No olvides el coste!

  AcademiaChino() = default;
  //O(1)
  void nuevo_estudiante(const string &dni, const int &grupo)
  {
    //Si el alumno no existe
    if (academia.find(dni) == academia.end())
    {
      if (grupo_correcto(grupo))
      {
        academia.insert({dni, {grupo, false}});
        novatoxGrupo[grupo] = dni;
      }
    }
    else
    {
      throw std::domain_error("Estudiante existente");
    }
  }

  void promocionar(const string &dni)
  {
    //Si el alumno existe y no está graduado le promocionamos
    infoAlumno &alumno = busqueda_estudiante(dni);
    if (no_graduado(alumno))
    {
      //Si si promociona del nivel 6 se gradua
      if (++alumno.grupo > 6)
      {
        alumno.graduado = true;
      }
      else
      {
        novatoxGrupo[alumno.grupo] = dni;
        if(alumno.grupo > 1)
          novatoxGrupo[alumno.grupo-1].erase();
      }
    }
  }

  int grupo_estudiante(const string &dni)
  {
    infoAlumno &alumno = busqueda_estudiante(dni);
    if (no_graduado(alumno))
    {
      return alumno.grupo;
    }
    return 0;
  }

  vector<string> graduados()
  {
    vector<string> grad;
    for (auto it = academia.begin(); it != academia.end(); it++)
    {
      if (it->second.graduado)
      {
        grad.push_back(it->first);
      }
    }
    return grad;
  }

  string novato(const int &grupo)
  {
    if (grupo_correcto(grupo))
    {
      if(novatoxGrupo[grupo] == ""){
        throw std::domain_error("Grupo vacio");
      }
      return novatoxGrupo[grupo];
    }
  }

private:
  // Definiciones privadas
  struct infoAlumno
  {
    int grupo;
    bool graduado;
  };
  unordered_map<string, infoAlumno> academia;
  unordered_map<int, string> novatoxGrupo;
  

  bool grupo_correcto(const int &grupo)
  {
    if (grupo < 1 || grupo > 6)
    {
      throw std::domain_error("Grupo incorrecto");
    }
    else
    {
      return true;
    }
  }

  infoAlumno &busqueda_estudiante(const string &dni)
  {
    auto it = academia.find(dni);
    if (it != academia.end())
    {
      return it->second;
    }
    else
    {
      throw std::domain_error("Estudiante no existente");
    }
  }

  bool no_graduado(const infoAlumno &alumno)
  {
    if (alumno.graduado)
    {
      throw std::domain_error("Estudiante ya graduado");
    }
    else
    {
      return true;
    }
  }
};

bool tratar_caso()
{
  string funcion;
  cin >> funcion;
  if (cin.eof())
  {
    return false;
  }

  AcademiaChino academia;
  string dni;
  int grupo;
  while (funcion != "FIN")
  {
    try
    {
      if (funcion == "nuevo_estudiante")
      {
        cin >> dni >> grupo;
        academia.nuevo_estudiante(dni, grupo);
      }
      else if (funcion == "grupo_estudiante")
      {
        cin >> dni;
        grupo = academia.grupo_estudiante(dni);
        std::cout << dni << " esta en el grupo" << " " << grupo << endl;
      }
      else if (funcion == "promocionar")
      {
        cin >> dni;
        academia.promocionar(dni);
      }
      else if (funcion == "novato")
      {
        cin >> grupo;
        dni = academia.novato(grupo);
        cout << "Novato de " << grupo << " " << dni << endl;
      }
      else
      { //graduados
        vector<string> alumnosGraduados = academia.graduados();
        cout << "Lista de graduados: ";
        for (auto &n : alumnosGraduados)
        {
          cout << n << " ";
        }
        cout << endl;
      }
    }
    catch(std::exception &e){
      cout << "ERROR: " << e.what() << endl;
    }
    cin >> funcion;
  }
  cout << "---" << endl;
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
