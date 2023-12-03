#pragma once
#include <string>
#include "Data.hpp"
#include "Horario.hpp"
namespace task_manager::core{
//!  Classe Evento. 
/*!
  Classe feita para representar um Evento, que tem data e horário de início.
*/
class Evento{
    public:
    /// @brief - Construtor da classe evento
    Evento(std::string nome, Data data, Horario horario_inicio): _nome(nome), _data(data), _horario_inicio(horario_inicio){};
    /// @brief - Operador de igualdade
    bool operator==(const Evento& other) const;
    /// @brief - Operador de menor
    bool operator<(const Evento& other) const;
    /// @brief - Operador de maior
    bool operator>(const Evento& other) const;
    /// @brief - Método to_string para imprimir
    std::string to_string() const;
    /// @brief - Getter do nome (_nome)
    std::string get_nome() const;
    /// @brief - Getter da data (_data)
    Data get_data() const;
    /// @brief - Getter do horario (_horario)
    Horario get_horario() const;
    private:
    std::string _nome;
    Data _data;
    Horario _horario_inicio;
};

}
