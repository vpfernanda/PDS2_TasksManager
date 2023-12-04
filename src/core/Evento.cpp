#include "core/Evento.hpp"
#include "core/Horario.hpp"
#include "core/Data.hpp"
#include <string>
namespace task_manager::core{
    bool Evento::operator==(const Evento& other) const{
        return (_nome == other._nome) && (_data == other._data) && (_horario_inicio == other._horario_inicio);
    }

    bool Evento::operator<(const Evento& other) const{
        if (_data < other._data) return true;
        if (_data > other._data) return false;

        return _horario_inicio < other._horario_inicio;
    }

    bool Evento::operator>(const Evento& other) const{
        if (_data > other._data) return true;
        if (_data < other._data) return false;

        return _horario_inicio > other._horario_inicio;
    }

    std::string Evento::to_string() const{
        std::string str;
        str += "Nome: " + _nome + "\n";
        str += "Data: " + _data.to_string() + "\n";
        str += "Horario: " + _horario_inicio.to_String() + "\n";
        return str;
    }
    std::string Evento::get_nome() const{
        return _nome;
    }
    Data Evento::get_data() const{
        return _data;
    }
    Horario Evento::get_horario() const{
        return _horario_inicio;
    }
}