//
// Created by cronopiorz on 2/2/20.
//

#ifndef ED01_HORAS_H
#define ED01_HORAS_H

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <iomanip>

class horas{
    public:
     horas(int h = 0, int m = 0, int s= 0): hora(h), minuto(m), segundo(s){ //parametros = 0 como valores por defecto
        if (valido(h,m,s)) {
                hora = h; minuto = m; segundo = s;
            }
        else { 
                throw std::domain_error("ERROR");
        }
     };

     int get_hora() const { return hora;};
     int get_minuto() const {return minuto;};
     int get_segundo() const {return segundo;};

     bool operator< ( horas const & h) const{
        return ((hora < h.get_hora()) || ( hora == h.get_hora() && minuto < h.get_minuto())||
                    (hora == h.get_hora() && minuto ==  h.get_minuto() && segundo < h.get_segundo()));
     }
     bool operator== (horas const& hora1)const{
        return (hora == hora1.get_hora() && minuto == hora1.get_minuto() && segundo == hora1.get_segundo());
        }
     bool operator <=(horas const& hora1) const{
        return (*this < hora1 || *this == hora1);
     }

        void read(std::istream & in = std::cin ) {
            int h, m, s;
            std::string horario;
            in >> horario;
            h = std::stoi(horario.substr(0,2));
            m = std::stoi(horario.substr(3,2));
            s =std::stoi(horario.substr(6,2));

            if (valido(h,m,s)){
                hora = h; minuto = m; segundo = s;}
            else {
                throw std::domain_error("ERROR");}
        }

        void print(std::ostream & out = std::cout) const{
            out << std::setfill('0') << std::setw(2) << hora  << ':' 
            << std::setfill('0') << std::setw(2) << minuto << ':' 
            << std::setfill('0') << std::setw(2) << segundo;
        }
    private:
    int hora, minuto, segundo;

    bool valido (int h, int m, int s)const{
        return (((0 <= h) && (h < 24)) && ((0 <= m) && (m < 60)) && ((0 <= s) && (s < 60)));
    }

    
};

inline std::ostream & operator<<(std::ostream & out, horas const& h) {
    h.print(out);
    return out;
}

inline std::istream & operator>>(std::istream & in, horas & h){
    h.read(in);
    return in;
}









#endif //ED01_HORAS_
// H
