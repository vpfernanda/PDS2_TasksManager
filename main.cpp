#include <iostream>
#include "core/Atividade.hpp"
#include "src/core/Atividade.cpp"
int main(){
    task_manager::core::Atividade oi("cafe", task_manager::core::HORARIO_FIXO, task_manager::core::MANHA, 50);
    return 0;
}