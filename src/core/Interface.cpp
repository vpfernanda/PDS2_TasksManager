#include "core/Interface.hpp"
#include <iostream>
#include <limits>

namespace task_manager::core{

void Interface::imprimir_menu(){
    std::cout << "\nTASK - MANAGER PDSII\n";
    std::cout << "selecione a opcao desejada: \n[1] - Imprimir eventos do ano\n[2] - Imprimir eventos em um intervalo de tempo\n[3] - Imprimir rotina\n[4] - Editar rotina\n[0] - Finalizar programa\n";
}

void Interface::imprimir_eventos_ano(unsigned ano){
    _agenda->buscar_eventos_ano(ano);
    std::cout<<"imprimindo eventos...\n";
}

void Interface::imprimir_eventos_intervalo(){
    std::string data_inicial;
    std::cout << "Digite a data inicial: ";
    std::cin >> data_inicial;
    std::cout << std::endl;
    std::string data_final;
    std::cout << "Digite a data final: ";
    std::cin >> data_final;
    //procurar eventos no banco de dados no período informado
       
    std::cout << "intervalo: " << data_inicial << " ate " << data_final <<"\n";

    //imprimir eventos durante o periodo - precisa da classe agenda

    std::cout << "\nvoltando ao menu inicial . . .\n";
}

    void Interface::imprimir_rotina()  const{
        std::cout << _agenda->get_rotina()->to_string();
    }

 void Interface::criar_rotina() {
    unsigned state;
    
    while (true) {
        std::cout << "Adicionar atividade? (1 = sim, 0 = nao): ";

        if (std::cin >> state) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (state == 0) {
                std::cout << "\nImprimindo a sua rotina atual . . . \n";
                imprimir_rotina();
                break;
            } else if (state == 1) {
                Atividade atividade = Atividade::criarAtividade();
                _agenda->get_rotina()->adicionar_atividade(atividade);
                std::cout << "Atividade adicionada\n";
            } else {
                std::cout << "Entrada invalida. Digite 1 ou 0.\n";
            }
        } else {
            std::cout << "Entrada invalida. Digite 1 ou 0.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
    

void Interface::editar_rotina(){
    std::cout << "selecione a opcao desejada:\n  [1] - criar rotina\n  [2] - editar rotina\n  [0] - voltar ao menu principal\n";
    unsigned input;
    std::cin >> input;

    switch (input){
        case 0:
        std::cout << "voltando ao menu principal \n";
        break;

        case 1:
        criar_rotina();
        break;

        case 2:
        imprimir_rotina();
        std::cout <<"voce deseja remover / adicionar alguma atividade?\n";
        break;

        default:
        std::cout << "opcao invalida, imprimindo opcoes novamente\n";
        editar_rotina();
        break;
    }
}

void Interface::input_menu(unsigned input){
    switch (input){
        case 0:
        std::cout << "Programa finalizado \n";
        break; 

        case 1:
        std::cout << "Opcao 1 - Imprimir eventos do ano\n";
        unsigned ano_selecionado;
        std::cout << "Digite o ano: ";
        std::cin >> ano_selecionado;
        imprimir_eventos_ano(ano_selecionado);
        break;

        case 2:
        std::cout << "Opcao 2 - Imprimir eventos em um intervalo de tempo \n";
        imprimir_eventos_intervalo();
        break;

        case 3:
        std::cout << "Opcao 3 - Imprimir rotina\n";
        imprimir_rotina();
        break;

        case 4:
        std::cout << "Opcao 4 - Editar rotina\n";
        editar_rotina();
        break;

        default:
        std::cout << "\nOPCAO INVALIDA - voltando ao menu inicial\n";
        break;
    }
}
    void Interface::set_agenda(Agenda* agenda){
        _agenda = agenda;
    }
    Agenda* Interface::get_agenda() const{
        return _agenda;
    }
}