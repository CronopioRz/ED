
// NOMBRES Y APELLIDOS

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#include "bintree_eda.h"

struct treeInfo{
   int tamMax = 0;
   int tamAct = 0;
};

struct treeInfo caminoPares(bintree<int> arbol) {
   // completar (posiblemente definiendo también otras funciones)
    if(arbol.empty()){
       return {0,0};
   }
   else{
         bool par = false; 
         auto iz = caminoPares(arbol.left());
         auto dr = caminoPares(arbol.right());
         if(arbol.root() %2 == 0){
            par = true;
         }
        return {
            std::max(std::max(iz.tamMax,dr.tamMax),par ? (1 + iz.tamAct + dr.tamAct): 0) ,
            par ? 1 + std::max(iz.tamAct,dr.tamAct) : 0
           };
   }
}

void resuelveCaso() {
   bintree<int> arbol = leerArbol(-1);
   int tamMax;
   cout << caminoPares(arbol).tamMax << '\n';
}


int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   cin >> numCasos;
   for (int i = 0; i < numCasos; ++i) {
      resuelveCaso();
   }

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
#endif
   return 0;
}
