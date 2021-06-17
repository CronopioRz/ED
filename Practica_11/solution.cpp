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
#include <stdexcept>
#include <cassert>
#include <fstream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <map>

using namespace std;

class ConteoVotos
{
public:
  ConteoVotos() = default;
  //O(1)
  void nuevo_estado(const string &nombre, int num_compromisarios)
  {
    if (this->mapEstados.count(nombre) != 1)
    {
      this->mapEstados.insert({nombre, {num_compromisarios,}});
    }
    else
    {
      std::domain_error("Estado ya existente");
    }
  }
  //O(log P) donde P es el número de partidos
  void sumar_votos(const string &estado, const string &partido, int num_votos)
  {
    infoEstado &datosEstado = busqueda_estado(estado);
    datosEstado.partidos[partido] += num_votos;
    //Para evitar hacer calculos complejos en ganador, cada vez que 
    //metamos más votos miraremos si hay un nuevo máximo
    if(datosEstado.partidos[partido] > datosEstado.votos_ganador){
      string ant_ganador = datosEstado.ganador;
      datosEstado.votos_ganador = datosEstado.partidos[partido];
      datosEstado.ganador = partido;
      if(ant_ganador != ""){
        partidos[ant_ganador] -= datosEstado.compromisarios;
        if(partidos[ant_ganador] == 0){
          partidos.erase(ant_ganador);
        }
      }
      partidos[partido] += datosEstado.compromisarios;
    }
  }
  //O(1)
  string ganador_en(const string &estado) const
  {
    return busqueda_estado(estado).ganador;
  }
  //O(P) donde P es el número de partidos
  vector<pair<string, int>> resultados() const
  {
    vector<pair<string,int>> sol;
    for(const auto &part: partidos){
      sol.push_back({part.first,part.second});
    }
    return sol;
  }

private:
  struct infoEstado
  {
    int compromisarios;
    unordered_map<string, int> partidos;
    string ganador;
    int votos_ganador;

    infoEstado(int compromisairos): compromisarios(compromisairos), ganador(""), votos_ganador(-1) {}
  };
  unordered_map<string, infoEstado> mapEstados;
  map<string,int> partidos;

  infoEstado &busqueda_estado(const string &nombre)
  {
    auto it = mapEstados.find(nombre);
    if (it == mapEstados.end())
    {
      throw std::domain_error("Estado no encontrado");
    }
    else
    {
      return it->second;
    }
  }

  const infoEstado &busqueda_estado(const string &nombre) const
  {
    auto it = mapEstados.find(nombre);
    if (it == mapEstados.end())
    {
      throw std::domain_error("Estado no encontrado");
    }
    else
    {
      return it->second;
    }
  }
};

bool tratar_caso()
{
  ConteoVotos votos;
  string funcion;
  cin >> funcion;
  if(cin.eof()){
    return false;
  }
  while (funcion != "FIN")
  {
    try
    {
      string estado;
      if (funcion == "nuevo_estado")
      {
        int compromisarios;
        cin >> estado >> compromisarios;
        try
        {
          votos.nuevo_estado(estado, compromisarios);
        }
        catch (domain_error)
        {
        }
      }
      else if (funcion == "sumar_votos")
      {
        string partido;
        int nVotos;
        cin >> estado >> partido >> nVotos;
        votos.sumar_votos(estado, partido, nVotos);
      }
      else if (funcion == "ganador_en")
      {
        cin >> estado;
        string nombre_ganador = votos.ganador_en(estado);
        cout << "Ganador en " << estado << ": " << nombre_ganador << endl;
      }
      else
      { // funcion == resultados
        vector<pair<string, int>> result;
        result = votos.resultados();
        for (const auto &n : result)
        {
          cout << n.first << " " << n.second << endl;
        }
      }
    }
    catch (std::exception &e)
    {
      cout << e.what() << endl;
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
