#include "core/Data.hpp"

namespace task_manager::core{
    Data::Data(unsigned dia, unsigned mes, unsigned ano){
        _dia = dia;
        _mes = mes;
        _ano = ano;
    }
    bool Data::operator==(Data other){
        return this->_dia == other._dia &&
                this->_mes == other._mes &&
                this->_ano == other._ano;
    }
}