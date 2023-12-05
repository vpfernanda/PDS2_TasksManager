#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "Atividade.hpp"

namespace task_manager::core{

///@brief Classe feita para representar uma Rotina de 7 dias, organizando de maneira automatizada os horários das atividades.

class Rotina{
    public:
    ///@brief - Construtor da rotina
    ///@param nome - nome da rotina
    Rotina(std::string nome) : _nome(nome), _atividades_rotina(std::vector<Atividade>()){};

    ///@brief - Construtor da rotina
    ///@param nome - nome da rotina
    ///@param atividades_da_rotina - vetor com as atividades da rotina
    Rotina(std::string nome, std::vector<Atividade> atividades_da_rotina) : _nome(nome), _atividades_rotina(atividades_da_rotina){};

    /// @brief - adiciona uma atividade ao vetor _Rotina (se não existir)
    /// @param Atividade - Atividade a ser adicionada na rotina
    void adicionar_atividade(const Atividade& Atividade);

    /// @brief - remove a atividade do vetor _Rotina (se existir)
    /// @param Atividade - Atividade a ser removida do vetor
    void remover_atividade(const Atividade& Atividade);

    /// @brief organiza a rotina conforme os dias e horários 
    /// @return Verdadeiro ou falso.
    bool gerar_rotina();

    /// @brief retorna o vetor guardado na private _Rotina
    /// @return Vector de atividades.
    std::vector<Atividade> get_atividades_rotina() const;

    /// @brief retorna o nome da rotina (_nome)
    /// @return String nome da rotina.
    std::string nome() const;

    /// @brief forma uma string para ser impressa na tela
    /// @return String formatada da Rotina. 
    std::string to_string();
    private:
        std::string _nome;
        std::vector<Atividade> _atividades_rotina;   
    };
}