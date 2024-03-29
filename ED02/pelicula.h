#include <utility>

//
// Created by cronopiorz on 2/5/20.
//


#ifndef ED02_PELICULA_H
#define ED02_PELICULA_H

#include "horas.h"

class pelicula{

public:
    pelicula(horas hIni = horas(0,0,0), horas dur = horas(0,0,0), std::string titl = ""){
        horaIni = hIni;
        duracion = dur;
        titulo = std::move(titl);
    }

   horas get_horaIni() const{return horaIni;}
   horas get_duracion() const{return duracion;}
   std::string get_titulo() const{return titulo;}
   horas get_horaFin() const { return horaIni + duracion;}

    bool operator< (pelicula const& peli2) const {
        return ((get_horaFin() < peli2.get_horaFin()) || ((get_horaFin() == peli2.get_horaFin()) && (get_titulo() < peli2.get_titulo())));
    }
    bool operator== (pelicula const&peli2) const{
        return get_horaFin() == peli2.get_horaFin() && get_titulo() == peli2.get_titulo();
    }
    bool operator<= (pelicula const&peli2) const{
        return (get_horaFin() == peli2.get_horaFin())
            || (get_horaFin() < peli2.get_horaFin());
    }

private:
    horas horaIni;
    horas duracion;
    std::string titulo;


};

inline std::istream& operator>>(std::istream & in, pelicula & pelicula1) {
    horas horainicio;
    horas horaDur;
    std::string titulo;

    in >> horainicio >> horaDur;
    getline(in,titulo);
    pelicula1 = pelicula(horainicio,horaDur,titulo);
    return in;
}


#endif //ED02_PELICULA_H
