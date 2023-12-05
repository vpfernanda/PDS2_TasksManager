#pragma once
#include <string>
#include "Data.hpp"
#include "Horario.hpp"
namespace task_manager::core{

///@brief Classe feita para representar um Evento, que tem data e horário de início.

class Evento{
    public:
    /// @brief - Construtor da classe evento
    Evento(std::string nome, Data data, Horario horario_inicio): _nome(nome), _data(data), _horario_inicio(horario_inicio){};
    
    /// @brief Implementação do operador de igualdade
    /// @param other 
    /// @return Verdadeiro ou falso.
    bool operator==(const Evento& other) const;
    
    /// @brief Implementação do operador de menor.
    /// @param other 
    /// @return Verdadeiro ou falso.
    bool operator<(const Evento& other) const;


    /// @brief Implementação do operador de maior.
    /// @param other 
    /// @return Verdadeiro ou falso.
    bool operator>(const Evento& other) const;

    /// @brief - Método to_string para imprimir o objeto.
    /// @return String do objeto Evento formatada.
    std::string to_string() const;

    /// @brief  Método "to_string" específico para gravação no banco de dados
    /// @return String formatada de modo específico para manipulação em arquivo.
    std::string to_string_bd() const;

    /// @brief Getter do nome (_nome)
    /// @return String de _nome
    std::string get_nome() const;

    /// @brief Getter da data (_data)
    /// @return Objeto Data.
    Data get_data() const;

    /// @brief Getter do horario (_horario)
    /// @return Objeto Horario.
    Horario get_horario() const;

    private:
    std::string _nome;
    Data _data;
    Horario _horario_inicio;
};

}
