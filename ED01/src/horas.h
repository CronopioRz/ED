//
// Created by cronopiorz on 2/2/20.
//

#ifndef ED01_HORAS_H
#define ED01_HORAS_H

#include <iostream>
#include <stdexcept>

class horas{

public:
    horas(int h = 0, int m = 0, int s= 0): hora(h), minuto(m), segundo(s){ //parametros = 0 como valores por defecto
        if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59)
            throw std::invalid_argument("Error");
    };

    int get_hora() const { return hora;};
    int get_minuto() const {return minuto;};
    int get_segundo() const {return segundo;};

    bool operator< ( horas const & h) {
        return ((hora < h.get_hora()) || ( hora == h.get_hora() && minuto < h.get_minuto())||
                    (hora == h.get_hora() && minuto ==  h.get_minuto() && segundo < h.get_segundo()));
    }
    bool operator== (horas const& hora1){
        return (hora == hora1.get_hora() && minuto == hora1.get_minuto() && segundo == hora1.get_segundo());
    }
    bool operator <=(horas const& hora1) {
        return (*this < hora1 || *this == hora1);
    }

private:
    int hora, minuto, segundo;
};


#endif //ED01_HORAS_
// H
