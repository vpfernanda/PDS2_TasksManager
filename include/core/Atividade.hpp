#pragma once
#include <string>
#include <vector>
#include "Horario.hpp"
namespace task_manager::core{

enum TIPO_HORARIO{FIXO, LIVRE};

enum TURNO_PREFERENCIA{MANHA, TARDE, NOITE, NENHUM};

enum DIA{DOM, SEG, TER, QUA, QUI, SEX, SAB};

class Atividade{
    public:

    /// @brief - construtor Atividade com horário livre
    Atividade(std::string nome, TIPO_HORARIO tipo_horario, TURNO_PREFERENCIA turno_preferencia, 
    unsigned duracao_minutos, std::vector<DIA> dias_semana);
    ///@brief - construtor Atividade com horário fixo
    Atividade(std::string nome, TIPO_HORARIO tipo_horario, 
    Horario inicio, Horario fim, std::vector<DIA> dias_semana);
    /// @brief - implementação comparação entre atividades
    /// @param other  
    bool operator==(const Atividade& other) const;
    /// @brief - recupera o nome da atividade (_nome)
    std::string get_nome() const;
    /// @brief - recupera o horário da atividade (_horario)
    TIPO_HORARIO get_tipo_horario() const;
    /// @brief - recupera a duração atividade (_horario)
    unsigned get_duracao() const;
    /// @brief - recupera o dia da atividade a ser checada (_dia_semana)
    std::vector<DIA> get_dias_semana() const;
    /// @brief - recupera o turno de preferencia da atividade (_turno_preferencia)  
    TURNO_PREFERENCIA get_turno() const;
    /// @brief - recupera o horário de inicio da atividade
    Horario get_horario_inicio() const;
    /// @brief - recupera o horário de termino da atividade
    Horario get_horario_fim() const;
    /// @brief - set o novo horário de inicio
    Horario set_horario_inicio(Horario inicio);
    /// @brief - set o novo horário de fim
    Horario set_horario_fim(Horario fim);
    /// @brief - Devolve o objeto em formato de string
    std::string to_string() const;
    /// @brief - compara atividades diferentes conforme a sua ordem (dia e turno) 
    static bool comparar_atividades(const Atividade& a, const Atividade& b);
    ///@brief - retorna o horario com base no input do usuario
    static Atividade criarAtividade();
    private:
        std::string _nome;
        TIPO_HORARIO _tipo_horario; 
        Horario _horario_inicio;
        Horario _horario_fim;
        TURNO_PREFERENCIA _turno_preferencia; 
        unsigned _duracao;
        std::vector<DIA> _dias_semana; 
};

}