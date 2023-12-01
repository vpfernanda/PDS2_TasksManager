#pragma once

namespace task_manager::core{

//!  Classe Data. 
/*!
  Classe feita para representar datas (dia, mes, ano).
*/
class Data{
    public:
    //! Construtor default da classe Data.
    /*!
      Inicializa com dia, mes e ano iguais a zero.
    */ 
        Data(): _dia(0), _mes(0), _ano(0){};
    //! Construtor da classe Data.
    /*!
      Recebe os parametros dia, mes e ano.
    */ 
        Data(unsigned dia, unsigned mes, unsigned ano);
    //! Operador de igualdade da classe Data
    /*!
      Compara se dia, mês e ano são iguais
    */
        bool operator==(Data other);
    private:
        unsigned _dia; /// Armazena o dia da data
        unsigned _mes; /// Armazena o mes da data
        unsigned _ano; /// Armazena o ano da data
        
};


}

#include "Data.cpp"