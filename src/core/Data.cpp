#include "core/Data.hpp"
#include <iostream>
#include <string>
#include <sstream>
namespace task_manager::core {

    Data::Data(unsigned dia, unsigned mes, unsigned ano) : _dia(dia), _mes(mes), _ano(ano) {}

    bool Data::operator==(const Data& other) const{
        return (_dia == other._dia) && (_mes == other._mes) && (_ano == other._ano);
    }

    bool Data::operator<(const Data& other) const{
        if (_ano < other._ano) return true;
        if (_ano > other._ano) return false;

        if (_mes < other._mes) return true;
        if (_mes > other._mes) return false;

        return _dia < other._dia;
    }

    bool Data::operator>(const Data& other) const{

        if (_ano > other._ano) return true;
        if (_ano < other._ano) return false;

        if (_mes > other._mes) return true;
        if (_mes < other._mes) return false;

        return _dia > other._dia;
    }
    bool Data::operator>=(const Data& other) const{
        if (_ano >= other._ano) return true;

        if (_mes >= other._mes) return true;;

        return _dia > other._dia;
    }
    bool Data::operator<=(const Data& other) const{
        if (_ano < other._ano) return true;

        if (_mes <= other._mes) return true;

        return _dia <= other._dia;
    }

    std::string Data::to_string() const{
        std::stringstream str_stream;
        str_stream << _dia << "/" << _mes << "/" << _ano;
        return str_stream.str();
    }
    unsigned Data::get_dia() const{
        return _dia;
    }
    unsigned Data::get_mes() const{
        return _mes;
    }
    unsigned Data::get_ano() const{
        return _ano;
    }

}