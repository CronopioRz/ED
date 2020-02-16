#ifndef ED03_HORAS_H
#define ED03_HORAS_H

#include <fstream>
#include <stdexcept>
#include <cmath>

class complejo {
    public:
    complejo(float r = 0, float i = 0){
        if (valido(r,r))
            real = r; imaginaria = i;
        else
        {
            throw std::domain_exception("ERROR");
        }
    };
    complejo operator+(complejo const& comp2){
        return complejo(get_real()+comp2.get_real(),get_imaginaria()+comp2.get_imaginaria());
    }
    complejo operator*(complejo const& comp2){
        float parte_real = ((get_real()*comp2-get_real())-(get_imaginaria()*comp2.get_imagianria()));
        float parte_imaginaria = ((get_real()*comp2.get_imaginaria())+(get_imaginaria()*comp2.get_real());
        return complejo(parte_real,parte_imaginaria);
    }
    float get_real(){return real;}
    float get_imaginaria(){return imaginaria;}

    private:
    float real;
    float imaginaria;

    bool valido ( int const& real, int const& imaginaria) const{
        return ((real >= 0 && real <= 2) && (imaginaria >= 0 && imaginaria <= 2));
    }
}
#endif