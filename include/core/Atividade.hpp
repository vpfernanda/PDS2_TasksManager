#pragma once
#include <string>
#include "../src/core/Atividade.cpp"

namespace task_manager::core{

/** Enum para os possíveis tipos de horário
 *  Guarda os tipos possíveis de horário (Fixo ou livre)
 */
enum TIPO_HORARIO{HORARIO_FIXO, HORARIO_LIVRE};
/** 
 *  Enum para os turnos possíveis de preferência (manha, tarde, noite ou nenhum)
 */
enum TURNO_PREFERENCIA{MANHA, TARDE, NOITE, NENHUM};
//!  Classe Atividade. 
/*!
  Classe feita para representar atividades que fazem parte de uma Rotina, ou seja, tem frequência de realização (diária, semanal etc).
*/
class Atividade{
    public:
    //! Construtor da classe Atividade.
    /*!
      Recebe os dados para inicialização da classe (nome, tipo_horario, duracao_minutos, frequencia_realizacao).
    */    
        Atividade(std::string nome, TIPO_HORARIO tipo_horario, TURNO_PREFERENCIA turno_preferencia, unsigned duracao_minutos, unsigned frequencia_realizacao);
    //! Operador de igualdade da classe Atividade
    /*!
      Compara membro a membro se são iguais.    
    */   
        bool operator==(Atividade other);
    private:
        std::string _nome; /// Armazena o nome da atividade.
        TIPO_HORARIO _tipo_horario; /// Armazena se a atividade tem horario fixo ou livre.
        TURNO_PREFERENCIA _turno_preferencia; /// Armazena se a atividade tem preferência de ser realizada em algum turno.
        unsigned _duracao; /// Armazena em minutos a duração da atividade.
        unsigned _frequencia_realizacao; /// Armazena a frequencia de realizacao da atividade em dias;
};


}

