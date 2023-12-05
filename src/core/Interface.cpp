#include "core/Interface.hpp"
#include <iostream>
#include <limits>
#include "core/Agenda.hpp"
#include "core/BancoDados.hpp"
#include "core/Data.hpp"
using std::make_shared;
namespace task_manager::core{
    Horario obter_horario_evento() {
        unsigned horas;
        unsigned minutos;

        while(true){
            std::cout << "Digite a hora (0 a 23): ";
            if(std::cin >> horas){
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if(horas < 24){
                    break;
                }else{
                    std::cout<<"Hora invalida. Digite novamente.\n";
                }
            }else{
                std::cout << "Entrada invalida. Digite corretamente.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        while(true){
            std::cout << "Digite os minutos (0 a 59): ";
            if(std::cin >> minutos){
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if(minutos < 60){
                    break;
                }else{
                    std::cout<<"Minutos invalidos. Digite novamente.\n";
                }
            }else{
                std::cout << "Entrada invalida. Digite corretamente.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        return Horario(horas,minutos);
    }
    Data obter_data(){
        unsigned dia, mes, ano;
        while(true){
            std::cout << "Digite o dia (1 a 31)";
            if(std::cin >> dia){
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if(dia <= 31)break;
                else{
                    std::cout<<"Dia inválido. Digite novamente.\n";
                }
            }else{
                std::cout << "Entrada invalida. Digite corretamente.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        while(true){
            std::cout << "Digite o mês (1 a 12)";
            if(std::cin >> mes){
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (mes <= 12) break;
                else{
                    std::cout<<"Mês inválido. Digite novamente.\n";
                }
            }else{
                std::cout << "Entrada invalida. Digite corretamente.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        while(true){
            std::cout << "Digite o ano: ";
            if(std::cin >> ano){
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }else{
                std::cout << "Entrada invalida. Digite corretamente.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        return Data(dia, mes, ano);
    }

    void Interface::imprimir_menu(){
        std::cout << "\nTASK - MANAGER PDSII\n";
        std::cout << "selecione a opcao desejada: \n[1] - Imprimir eventos do ano\n[2] - Imprimir eventos em um intervalo de tempo\n[3] - Imprimir rotina\n[4] - Editar rotina\n[5] - Adicionar evento a agenda\n[0] - Finalizar programa\n";
    }

    void Interface::imprimir_eventos_ano(unsigned ano){
        std::vector<Evento> eventos = _agenda->buscar_eventos_ano(ano);
        for (Evento ev: eventos){
            std::cout << ev.to_string();
        }
    }

    void Interface::imprimir_eventos_intervalo(){
        std::cout << "Digite a data inicial da busca\n";
        Data data_inicio = obter_data();
        std::cout << "Digite a data final da busca\n";
        Data data_final = obter_data();
        std::cout << "----------------------\n";

        std::vector<Evento> eventos = _agenda->buscar_eventos_intervalo(data_inicio, data_final);
        for (Evento ev : eventos){
            std::cout << ev.to_string();
        }
        std::cout << "----------------------\n";

        std::cout << "\nVoltando ao menu inicial . . .\n";
    }



    void Interface::imprimir_rotina()  const{
        std::cout << _agenda->get_rotina()->to_string();
    }

 void Interface::criar_rotina() {
    unsigned state;
    std::string nome_rotina;
    std::cout << "Digite o nome da rotina: ";
    std::cin >> nome_rotina;
    auto nova_rotina = make_shared<Rotina>(nome_rotina);
    this->_agenda->set_rotina(nova_rotina);
    while (true) {
        std::cout << "Adicionar atividade? (1 = sim, 0 = nao): ";
        if (std::cin >> state) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (state == 0) break;
            if (state == 1) {
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
    std::cout << this->_agenda->get_rotina()->to_string();
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
        if ((_agenda->get_rotina())){
            std::cout << "Você ainda não criou uma rotina.\n";
            std::cout << "Esta opção está em desenvolvimento...\n";
            editar_rotina();
            break;
        }
        break;

        default:
        std::cout << "opcao invalida, imprimindo opcoes novamente\n";
        editar_rotina();
        break;
    }
}
void Interface::adicionar_evento(){
    std::cout << "Digite o nome do evento: \n";
    std::string nome_evento;
    std::getline(std::cin >> std::ws, nome_evento);
    std::cout << "Digite a data que o evento irá ocorrer: ";
    Data data = obter_data();
    std::cout << "Digite o horário de início do evento: \n";
    Horario horario = obter_horario_evento();
    std::cout <<"Evento " << nome_evento <<" adicionado!\n";
    Evento novo_evento = Evento(nome_evento, data, horario);
    _agenda->adiciona_evento(novo_evento);
    BancoDados bd;
    bd.gravar_evento(novo_evento);
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
        case 5:
        std::cout << "Opcao 5 - Adicionar evento a agenda\n";
        adicionar_evento();
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