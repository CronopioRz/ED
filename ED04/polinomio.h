#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <vector>
#include<math.h>

class polinomio {
    private:
    struct monomio{
        int coef;
        int exp;
    };

    std::vector<monomio> polinomio;

    public:
    //Agregamos elemento al final de la lista
    void agregar (int coef, int exp){
        monomio monom;

        monom.coef = coef;
        monom.exp = exp;

        polinomio.push_back(monom);
    }

    int eval(int variable){
        int sol = 0;
        for (monomio&n: polinomio){
            sol += pow(variable,n.exp) * n.coef;
        }
        return sol;
    }

};

#endif 