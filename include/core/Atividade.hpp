#pragma once
#include <string>

namespace task_manager::core{

enum TIPO_HORARIO{FIXO, LIVRE};

enum TURNO_PREFERENCIA{MANHA, TARDE, NOITE, NENHUM};

enum DIA{DOM, SEG, TER, QUA, QUI, SEX, SAB};

class Atividade{
    public:

        /// @brief - construtor Atividades
        Atividade(std::string nome, TIPO_HORARIO tipo_horario, TURNO_PREFERENCIA turno_preferencia, 
        unsigned duracao_minutos, DIA dia_semana);

        /// @brief - implementação comparação entre atividades
        /// @param other  
        bool operator==(const Atividade& other)const;

        /// @brief - recupera o nome da atividade (_nome)
        std::string get_nome() const;
        /// @brief - recupera o horário da atividade (_horario)
        TIPO_HORARIO get_horario() const;
        /// @brief - recupera a duração atividade (_horario)
        unsigned get_duracao() const;
        /// @brief - recupera o dia da atividade a ser checada (_dia_semana)
        DIA get_dia() const;
        
        /// @brief - recupera o turno de preferencia da atividade (_turno_preferencia)  
        TURNO_PREFERENCIA get_turno() const;

        /// @brief - compara atividades diferentes conforme a sua ordem (dia e turno) 
        static bool comparar_atividades(const Atividade& a, const Atividade& b);

        ///@brief - retorna o horario com base no input do usuario
        static TIPO_HORARIO obter_horario();

        ///@brief - retorna o turno com base no input do usuario
        static TURNO_PREFERENCIA obter_turno();

        ///@brief - retorna o dia com base no input do usuario
        static DIA obter_dia();
        ///@brief - cria atividade
        static Atividade criarAtividade();

    private:
        std::string _nome;
        TIPO_HORARIO _tipo_horario; 
        TURNO_PREFERENCIA _turno_preferencia; 
        unsigned _duracao; 
        DIA _dia_semana; 
};

}