//
// Created by cronopiorz on 2/2/20.
//

#ifndef ED01_FECHA_H
#define ED01_FECHA_H

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <iomanip>

const int MAX_H_S = 60;

class fecha{
    public:
     fecha(int y = 0, int m = 1, int d= 1): year(y), month(m), day(d){ //parametros = 0 como valores por defecto
        if (valido(y,m,d)) {
                year = y; month = m; day = d;
        }
        else {
            throw std::domain_error("ERROR");
        }
     };

     int get_year() const { return year;};
     int get_month() const {return month;};
     int get_day() const {return day;};

     bool operator< ( fecha const & h) const{
        return ((year < h.get_year()) || ( year == h.get_year() && month < h.get_month())||
                    (year == h.get_year() && month ==  h.get_month() && day < h.get_day()));
     }
     bool operator== (fecha const& year1)const{
        return (year == year1.get_year() && month == year1.get_month() && day == year1.get_day());
        }
     bool operator <=(fecha const& year1) const{
        return (*this < year1 || *this == year1);
     }
     fecha operator+(fecha const& year2)const {
        int hvar = year+year2.get_year();
        int mvar = month+year2.get_month();
        int svar = day+year2.get_day();
        if (svar >= MAX_H_S) {mvar += svar/MAX_H_S; svar = svar%MAX_H_S;}
        if(mvar >= MAX_H_S) {hvar += mvar/MAX_H_S; mvar = mvar %MAX_H_S;}
        return fecha(hvar, mvar, svar);
     }

        void read(std::istream & in = std::cin ) {
            int y, m, d;
            std::string yearrio;
            in >> yearrio;
            d = std::stoi(yearrio.substr(0,2));
            m = std::stoi(yearrio.substr(3,2));
            y =std::stoi(yearrio.substr(6,4));

            if (valido(y,m,d)){
                year = y; month = m; day = d;}
            else {
                throw std::domain_error("ERROR");}
        }

        void print(std::ostream & out = std::cout) const{
            out << std::setfill('0') << std::setw(2) << day  << '/' 
            << std::setfill('0') << std::setw(2) << month << '/' 
            << std::setfill('0') << std::setw(4) << year;
        }
    private:
    int year, month, day;

    bool valido (int y, int m, int d)const{
        return (((0 <= y) && ((1 <= m) && (m < 13)) && ((1 <= d) && (d < 32))));
    }

    
};

inline std::ostream & operator<<(std::ostream & out, fecha const& h) {
    h.print(out);
    return out;
}

inline std::istream & operator>>(std::istream & in, fecha & h){
    h.read(in);
    return in;
}

#endif //ED01_yearS_
// H
