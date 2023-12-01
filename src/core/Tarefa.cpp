#include "core/Tarefa.hpp"

namespace task_manager::core{
    Tarefa::Tarefa(std::string nome, Data data){
        _nome = nome;
        _data = data;
    }
    bool Tarefa::operator==(Tarefa other){
        return this->_nome == other._nome &&
                this->_data == other._data;
    }
}