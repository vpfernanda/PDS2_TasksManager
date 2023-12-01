#include "core/interface.hpp"

namespace task_manager::core{

void Interface::imprimir_menu(){
    std::cout << "\nTexto inicial \n";
    std::cout << "selecione a opcao desejada: \n[1] - Imprimir eventos do ano\n[2] - Imprimir eventos em um intervalo de tempo\n[3] - Imprimir rotina\n[4] - Criar rotina\n[0] - Finalizar programa\n";
}

void Interface::imprimir_eventos_ano(){ //precisa de acesso aos dados p/ implementar
    std::cout<<"estou em imprimir eventos ano\n";
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
    imprimir_menu();
}

    void Interface::imprimir_rotina() const { // Interface
        std::cout << "\n== Rotina Atual == \n";
        std::vector<Atividade> rotina_atividades = rotina.get_rotina();
        for (const auto& atividade : rotina_atividades) {
            std::cout << "Nome: " << atividade.get_nome() << "\n";
            std::cout << "Horario de preferencia: " << atividade.get_horario() << "\n";
            std::cout << "Turno de preferencia: " << atividade.get_turno() << "\n";
            std::cout << "Duracao: " << atividade.get_duracao() << " minutos\n";
            std::cout << "Dia da semana: " << atividade.get_dia() << "\n";
            std::cout << "------------------------\n";
        }
    }

    void Interface::criar_rotina(){//interface 
        unsigned state;
        while(1){
            std::cout<<"adicionar atividade? (1 = sim, qualquer outra tecla = nao): ";
            std::cin >> state;
            
            if(state != 1){
                break;
            }else{
                Atividade atividade = Atividade::criarAtividade();
                rotina.adicionar_atividade(atividade);
                std::cout <<"Atividade adicionada\n";
            }
        }
        rotina.gerar_rotina();
    }
    

void Interface::editar_rotina(){
    std::cout << "selecione a opcao desejada:\n [1] - criar rotina\n [2] - editar rotina\n [0] - voltar ao menu principal\n";
    unsigned input;
    std::cin >> input;

    switch (input){
        case 0:
        std::cout << "voltando ao menu principal \n";
        //Interface::imprimir_menu();
        break;

        case 1:
        criar_rotina();
        break;

        case 2:
        imprimir_rotina();
        std::cout <<"voce deseja remover / adicionar alguma atividade?\nSla, ve se ta funfando";
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
        imprimir_eventos_ano();
        break;

        case 2:
        std::cout << "Opcao 2 - Imprimir eventos em um intervalo de tempo \n";
        imprimir_eventos_intervalo();
        break;

        case 3:
        std::cout << "Opcao 3 - Acessar rotina\n";
        imprimir_rotina();
        break;

        case 4:
        std::cout << "Opcao 4 - Criar rotina\n";
        editar_rotina();
        break;

        default:
        std::cout << "\nOPCAO INVALIDA - voltando ao menu inicial\n";
        imprimir_menu();
        break;
    }

}
}