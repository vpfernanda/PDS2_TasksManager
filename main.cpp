#include <iostream>
#include "core/Atividade.hpp"
#include "core/Rotina.hpp"
#include "core/Interface.hpp"

using namespace task_manager::core;

int main(){
<<<<<<< Updated upstream
    
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
=======
    while(1){
        task_manager::core::Agenda agenda(NULL);
        task_manager::core::Interface interface(NULL);
        interface.imprimir_menu();
        unsigned input;
        std::cin >> input;
        if(!input){
            break;
        }
        interface.input_menu(input);
>>>>>>> Stashed changes
    }
    return 0;
}
