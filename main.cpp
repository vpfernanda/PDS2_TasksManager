#include <iostream>
#include "core/Atividade.hpp"
#include "core/Rotina.hpp"
#include "core/Interface.hpp"

using namespace task_manager::core;

int main(){
    
    Interface interface(NULL);
    Agenda agenda(NULL);

    while(1){
    unsigned input;

    interface.imprimir_menu();
    
    std::cin >> input;
    interface.input_menu(input);
        if(!input){
        break;
        }
    }
    return 0;
}
