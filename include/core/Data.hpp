#pragma once
#include <string>
namespace task_manager::core {

//! Classe Data.
/*!
  Classe feita para representar datas (dia, mes, ano).
*/
class Data {
public:
    //! Construtor default da classe Data.
    /*!
      Inicializa com dia, mes e ano iguais a zero.
    */
    Data() : _dia(0), _mes(0), _ano(0) {};

    //! Construtor da classe Data.
    /*!
      Recebe os parametros dia, mes e ano.
    */
    Data(unsigned dia, unsigned mes, unsigned ano);

    //! Operador de igualdade da classe Data
    /*!
      Compara se dia, mês e ano são iguais
    */
    bool operator==(const Data& other) const;

    //! Operador de menor da classe Data
    /*!
      Compara se a data atual é menor que a outra data
    */
    bool operator<(const Data& other) const;

    //! Operador de maior da classe Data
    /*!
      Compara se a data atual é maior que a outra data
    */
    bool operator>(const Data& other) const;
    //! Método to_string
    /*!
      Imprime data no formato dd/mm/aaaa
    */
    bool operator>=(const Data& other) const;
    bool operator<=(const Data& other) const;
    std::string to_string() const;
    unsigned get_dia() const;
    unsigned get_mes() const;
    unsigned get_ano() const;

private:
    unsigned _dia; /// Armazena o dia da data
    unsigned _mes; /// Armazena o mes da data
    unsigned _ano; /// Armazena o ano da data
};

} 