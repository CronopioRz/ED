
// NOMBRES Y APELLIDOS (USUARIO DEL JUEZ)

#include <iostream>                              
#include <fstream>                              
#include <algorithm>
#include <map>
using namespace std;

// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO
using tipo = string;
using hora = string;

string resolver (const std::map<tipo,hora> contTemp){

   string part;
   int number;
   string sol = "--";
   int pos = 1;
   std::cin >> part >> number;
   for (const auto& x : contTemp){
      //si encontramos un elemento y no es la vez que necesitamos
      //acceder miramos en la siguiente posicion
      if(x.first == part && pos < number)
         pos++;
      //si encontramos el valor, lo guardamos
      else if(x.first == part && pos == number)
         sol = x.second;
   }

   return sol;


}

bool resuelveCaso() {
   int N, M;
   std::string parte;
   std::string tiempo;
   std::map<tipo,hora> controlTemp;
   cin >> N >> M;

   if (!cin)
      return false;

   //creamos un mapa con los datos de entrada
   for (int i = 0; i < N; ++i){
         cin >> parte >> tiempo;
         controlTemp[parte] = tiempo;
   }
   //resolvemos cada caso
   for(int r = 0; r < M; r++){
      std::cout << resolver(controlTemp) << " ";
   }
   std::cout << std::endl;
   
   
   return true;
}


int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   while (resuelveCaso());

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
#endif
   return 0;
}
