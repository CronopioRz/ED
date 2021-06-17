#include <queue>
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

vector<int> resolver(const vector<int> &vectSobres, const int &k)
{
    stack<int> pila;
    vector<int> vect;
    int i = 0;
    int j = 0;
    int tam = vectSobres.size();
    //Mientras pueda coger k sobres consecutivos
    for(int i = 0; i < tam-k+1; i++){
        //Miramos cada caso
        for(int j = 0; j < k; j++){
            if(!pila.empty()){
                //Si el elemento miramos es el nuevo mayor
                if(vectSobres[j+i] > pila.top()){
                        pila.pop();
                        pila.push(vectSobres[j+i]);
                }
            }
            else{ //Caso base, el primer elemento es el nuevo mayor
                pila.push(vectSobres[i]);
            }
        }
        vect.push_back(pila.top());
        pila.pop();
    }
    return vect;
}
bool resuelveCaso()
{
    int guardados, entregar;
    cin >> guardados >> entregar;
    if (guardados == 0 && entregar == 0)
        return false;
    int datos;
    vector<int> valorSobres(guardados);
    for (int i = 0; i < guardados; i++)
    {
        cin >> datos;
        valorSobres[i] = datos;
    }

    vector<int> solucion = resolver(valorSobres, entregar);
    for(auto &n: solucion){
        cout << n << " ";
    }
    cout << endl;

    return true;
}
int main()
{

#ifndef DOMJUDGE
    std::ifstream in("EntradaEjemplo.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // getchar();
#endif

    return 0;
}