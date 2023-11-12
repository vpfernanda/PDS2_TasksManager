#pragma once
#include <string>
#include "Data.hpp"

namespace task_manager::core{

//!  Classe Tarefa. 
/*!
  Classe feita para representar tarefas que fazem parte de uma Agenda (acontecimentos com dia específico mas sem horário de duração.)
*/
class Tarefa{
    public:
    //! Construtor da classe Tarefa.
    /*!
      Recebe os dados para inicialização da classe (nome, data).
    */  
        Tarefa(std::string nome, Data data);
    //! Operador de igualdade da classe Tarefa
    /*!
      Compara se o nome e a data são iguais.    
    */  
        bool operator==(Tarefa other);
    private:
        std::string _nome; /// Armazena o nome da tarefa
        Data _data; /// Armazena a Data que irá ocorrer a tarefa
};


}

#include "Tarefa.cpp"