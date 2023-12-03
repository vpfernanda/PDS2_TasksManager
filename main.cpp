#include <iostream>
#include "core/Atividade.hpp"
#include "core/Rotina.hpp"
#include "core/Interface.hpp"

int main(){
    // Inicializando a interface
    task_manager::core::Agenda agenda(NULL);
    task_manager::core::Interface interface(NULL);
    interface.imprimir_menu();
    return 0;
}
