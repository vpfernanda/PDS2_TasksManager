#pragma once
#include <string>
#include "Data.hpp"

namespace task_manager::core{

///@brief  Classe feita para representar tarefas que fazem parte de uma Agenda (acontecimentos com dia específico mas sem horário de duração.)

class Tarefa{
    public:
        /// @brief Construtor da classe Tarefa. Recebe os dados para inicialização da classe (nome, data).
        /// @param nome 
        /// @param data 
        Tarefa(std::string nome, Data data);
    
        /// @brief Operador de igualdade da classe Tarefa. Compara duas Tarefas.   
        /// @param other 
        /// @return Verdadeiro ou falso.
        bool operator==(Tarefa other);
        
    private:
        std::string _nome; /// Armazena o nome da tarefa
        Data _data; /// Armazena a Data que irá ocorrer a tarefa
};


}

