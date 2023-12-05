#pragma once
#include <string>
namespace task_manager::core {

/// @brief Classe feita para representar uma Data (dia, mes, ano).
class Data {
public:
    
    /// @brief Construtor default da classe Data. Inicializa com dia, mes e ano iguais a zero.
    Data() : _dia(0), _mes(0), _ano(0) {};

   
    /// @brief Construtor da classe Data. Recebe os parametros dia, mes e ano.
    Data(unsigned dia, unsigned mes, unsigned ano);

    
    /// @brief Implementa o operador de igualdade da classe Data. Compara se dia, mês e ano são iguais.
    /// @param other 
    /// @return Verdadeiro ou falso.
    bool operator==(const Data& other) const;

    /// @brief Implementação do operador de menor da classe Data. Compara se a data atual é menor que a outra data
    /// @param other 
    /// @return Verdadeiro ou falso.
    bool operator<(const Data& other) const;

  
    /// @brief Implementação do operador de maior da classe Data. Compara se a data atual é maior que a outra data
    /// @param other 
    /// @return Verdadeiro ou falso.
    bool operator>(const Data& other) const;

    /// @brief 
    /// @param other 
    /// @return 
    bool operator>=(const Data& other) const;

    /// @brief 
    /// @param other 
    /// @return 
    bool operator<=(const Data& other) const;

    /// @brief Imprime data no formato dd/mm/aaaa
    /// @return String da data formatada. 
    std::string to_string() const;

    /// @brief Getter do atributo dia.
    /// @return _dia
    unsigned get_dia() const;

    /// @brief Getter do atributo mes.
    /// @return _mes
    unsigned get_mes() const;

    /// @brief Getter do atributo ano.
    /// @return _ano
    unsigned get_ano() const;

private:
    unsigned _dia; /// Armazena o dia da data
    unsigned _mes; /// Armazena o mes da data
    unsigned _ano; /// Armazena o ano da data
};

} 