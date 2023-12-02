#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "Atividade.hpp"

namespace task_manager::core{

class Rotina{
    public:

    /// @brief - adiciona uma atividade ao vetor _Rotina (se não existir)
    /// @param Atividade - Atividade a ser adicionada na rotina
    void adicionar_atividade(const Atividade& Atividade);

    /// @brief - remove a atividade do vetor _Rotina (se existir)
    /// @param Atividade - Atividade a ser removida do vetor
    void remover_atividade(const Atividade& Atividade);

    /// @brief - organiza a rotina conforme os dias e horários (dia da semana menor = primeiro, horaririo de preferencia menor = primeiro...)
    void gerar_rotina();

    ///@brief - retorna o vetor guardado na private _Rotina
    std::vector<Atividade> get_rotina() const;

    private:
        std::vector<Atividade> _Rotina;    
    };
}