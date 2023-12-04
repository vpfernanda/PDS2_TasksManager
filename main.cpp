#include <iostream>
#include "core/Atividade.hpp"
#include "core/Rotina.hpp"
#include "core/Interface.hpp"
#include "core/Evento.hpp"
#include "core/BancoDados.hpp"
using namespace task_manager::core;

int main(){
    BancoDados banco_dados;
    Agenda agenda(banco_dados.ler_eventos());
    Interface interface(&agenda);
    while(1){
        unsigned input;

        interface.imprimir_menu();
        
        std::cin >> input;
        interface.input_menu(input);
        if(!input) break;
    }
    
    return 0;
}
