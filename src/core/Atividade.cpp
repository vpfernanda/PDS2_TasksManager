#include "core/Atividade.hpp"

namespace task_manager::core{
    Atividade::Atividade(std::string nome, TIPO_HORARIO tipo_horario, TURNO_PREFERENCIA turno_preferencia, unsigned duracao_minutos, unsigned frequencia_realizacao){
        _nome = nome;
        _tipo_horario = tipo_horario;
        _turno_preferencia = turno_preferencia;
        _duracao = duracao_minutos;
        _frequencia_realizacao = frequencia_realizacao;
    }
    bool Atividade::operator==(Atividade other){
        return this->_nome == other._nome &&
             this->_tipo_horario == other._tipo_horario &&
              this->_turno_preferencia == other._turno_preferencia &&
              this->_duracao == other._duracao &&
              this->_frequencia_realizacao = other._frequencia_realizacao;
    }
}