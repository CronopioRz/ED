#ifndef ED03_HORAS_H
#define ED03_HORAS_H

#include <fstream>
#include <stdexcept>
#include <cmath>
#include <stdexcept>
#include <iostream>

const float CUADRADO = 2.0;
class complejo {
    public:
    complejo(float r = 0, float i = 0){
        real = r; imaginaria = i; 
    };
    complejo operator+(complejo const& comp2)const{
        return complejo(get_real()+comp2.get_real(),get_imaginaria()+comp2.get_imaginaria());
    }
    complejo operator*(complejo const& comp2)const{
        float parte_real = ((get_real()*comp2.get_real())-(get_imaginaria()*comp2.get_imaginaria()));
        float parte_imaginaria = ((get_real()*comp2.get_imaginaria())+(get_imaginaria()*comp2.get_real()));

        return complejo(parte_real,parte_imaginaria);
    }

    float mod()const{
        return sqrt(pow(real, CUADRADO) + pow(imaginaria, CUADRADO));
    }

    bool sDiverge(int nIter, complejo const&c){
        complejo sumComp = c;
        bool diverge = false;
        int i = 0;
        while ((nIter >  i) && (!diverge)){
            if(sumComp.mod() > 2) { 
                diverge = true;
            }
            else {
                sumComp = sumComp*sumComp + c;
                i++;
            }
        }
        if (nIter == 0) 
            diverge = true;
        return diverge;
    }
    float get_real()const{
        return real;
        }
    float get_imaginaria()const{
        return imaginaria;
    }

     void read(std::istream & in = std::cin ) {
        float r, i;
            in >> r >> i;
                real = r; 
                imaginaria = i;
        }
    

    private:
    float real;
    float imaginaria;

    
};

inline std::istream & operator>>(std::istream & in, complejo & c){
    c.read(in);
    return in;
}
#endif
