//
// Created by cronopiorz on 2/2/20.
//

#ifndef ED01_HORAS_H
#define ED01_HORAS_H

#include <iostream>
#include <stdexcept>

class horas{

public:
    horas(int h = 0, int m = 0, int s= 0){ //parametros = 0 como valores por defecto
        if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59)
            throw std::invalid_argument("Error");
        else
            hora = h, minuto = m, segundo = s;
    };

    int get_hora() const { return hora;}
    int get_minuto() const {return minuto;}
    int get_segundo() const {return segundo;}

    bool operator< ( horas const & h) const{
        return ((hora < h.get_hora()) || ( hora == h.get_hora() && minuto < h.get_minuto())||
                (hora == h.get_hora() && minuto ==  h.get_minuto() && segundo < h.get_segundo()));
    }
    bool operator== (horas const& hora1) const{
        return (hora == hora1.get_hora() && minuto == hora1.get_minuto() && segundo == hora1.get_segundo());
    }
    bool operator <=(horas const& hora1) const{
        return (*this < hora1 || *this == hora1);
    }
    horas operator+ (horas const&hora2) const{
        int sumaSeg;
        horas aux;
        sumaSeg = horasToSegundos(hora2) + horasToSegundos(*this);
        aux = segundosToHoras(sumaSeg);
        return aux;
    }

private:
    int hora, minuto, segundo;
    int horasToSegundos(horas const&h) const{
        return (h.get_hora()*3600 + h.get_minuto()*60 + h.get_segundo());
    }

    horas segundosToHoras (int const& segundos) const{
        int h,m,s;
        h = segundos/3600;
        m = (segundos -h*3600) / 60;
        s = segundos - (h*3600 + m*60);
        return horas(h,m,s);
    }
};


#endif //ED01_HORAS_
// H
