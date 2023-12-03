#include "core/Atividade.hpp"
#include "core/Horario.hpp"
#include <iostream>
#include <limits>
#include <algorithm>

template <typename T>
bool compara_vetores(std::vector<T> vec1, std::vector<T> vec2){
    std::sort(vec1.begin(), vec1.end());
    std::sort(vec2.begin(), vec2.end());
    return vec1 == vec2;
}


namespace task_manager::core {

    Atividade::Atividade(std::string nome, TIPO_HORARIO tipo_horario, TURNO_PREFERENCIA turno_preferencia, 
        unsigned duracao_minutos, std::vector<DIA> dias_semana): _horario_inicio(Horario()), _horario_fim(Horario()){
        _nome = nome;
        _tipo_horario = tipo_horario;
        _turno_preferencia = turno_preferencia;
        _duracao = duracao_minutos;
        _dias_semana = dias_semana;
    }
    Atividade::Atividade(std::string nome, TIPO_HORARIO tipo_horario, Horario inicio, Horario fim, std::vector<DIA> dias_semana): _turno_preferencia(NENHUM), _duracao(0){
        _nome = nome;
        _tipo_horario = tipo_horario;
        _horario_inicio = inicio;
        _horario_fim = fim;
        _dias_semana = dias_semana;
    }

    bool Atividade::operator==(const Atividade& other) const{
        return this->_nome == other._nome &&
               this->_tipo_horario == other._tipo_horario &&
               this->_turno_preferencia == other._turno_preferencia &&
               this->_duracao == other._duracao &&
               this->_horario_inicio == other._horario_inicio &&
               compara_vetores(this->_dias_semana, other._dias_semana);
    }

    std::string Atividade::get_nome() const{
        return _nome;
    }
    TIPO_HORARIO Atividade::get_tipo_horario() const{
        return _tipo_horario;
    }
    unsigned Atividade::get_duracao() const{
        return _duracao;
    }
    Horario Atividade::get_horario_inicio() const{
        return _horario_inicio;
    }
    Horario Atividade::set_horario_inicio(Horario inicio){
        _horario_inicio = inicio;
    }
    Horario Atividade::get_horario_fim() const{
        return _horario_fim;
    }
    Horario Atividade::set_horario_fim(Horario fim){
        _horario_fim = fim;
    }
    std::vector<DIA> Atividade::get_dias_semana() const{
        return _dias_semana;
    }

    TURNO_PREFERENCIA Atividade::get_turno() const {
        return _turno_preferencia;
    }

    bool Atividade::comparar_atividades(const Atividade& a, const Atividade& b) {
        return false;
    }

    std::string Atividade::to_string() const{
        std::string str;
        str += _horario_inicio.to_String() + "-" + _horario_fim.to_String() + " " +  _nome;
        return str;
    }

    Horario obter_horario() {
        unsigned horas;
        unsigned minutos;
        std::cout << "Digite a hora (0 a 23):\n";
        std::cin >> horas;
        while (horas < 0 || horas > 23){
            std::cout << "Hora inválida, digite novamente\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> horas;
        }
        std::cout << "Digite os minutos (0 a 59)";
        while (minutos > 59){
            std::cout << "Minutos inválidos, digite novamente\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> minutos;
        }
        return Horario(horas, minutos);
    }
    
    TURNO_PREFERENCIA obter_turno(){
        bool correct = false;
        int escolha;

        while(!correct){
            std::cout << "escolha o turno da atividade, 0 para MANHÃ, 1 para TARDE, 2 para NOITE";
            std::cin >> escolha;

            if(std::cin.fail() || escolha < 0 || escolha > 2){
                std::cout << "turno inválido, escolha novamente\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }else{
                correct = true;
            }

        }
        
        return static_cast<TURNO_PREFERENCIA>(escolha);
    }
    unsigned obter_duracao(){
        unsigned minutos = 0;
        std::cin >> minutos;
        while (minutos > 59){
            std::cout << "Duração inválida, digite novamente\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> minutos;
        }
        return minutos;
    }

    std::vector<DIA> obter_dias(){
        bool sair = false;
        std::vector<DIA> dias_semana_escolhidos;
        int escolha;

        while(sair){
            std::cout << "Escolha os dias da atividade de 0 a 6 (começando do domingo), digite -1 para terminar: ";
            std::cin >> escolha;
            if (escolha == -1) sair = true;
            if(std::cin.fail() || escolha < 0 || escolha > 6){
                std::cout << "dia incorreto, escolha novamente\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }else{
                dias_semana_escolhidos.push_back(static_cast<DIA>(escolha));
            }
        }
        return dias_semana_escolhidos;
    }


     Atividade Atividade::criarAtividade() {
            std::string nome;
            unsigned tipoHorario;
            std::vector<DIA> diasSemana;

            std::cout << "Digite o nome da atividade:\n";
            std::getline(std::cin >> std::ws, nome);

            std::cout << "Esta atividade tem horário fixo? Digite 0 para SIM e 1 para NÃO\n";
            std::cin >> tipoHorario;
            if (tipoHorario == FIXO){
                std::cout << "Digite o horário em que a atividade começa:\n";
                Horario inicio = obter_horario();
                std::cout << "Digite o horário em que a atividade termina:\n";
                Horario fim = obter_horario();
                std::vector<DIA> dias_semana = obter_dias();
                return Atividade(nome, FIXO, inicio, fim, dias_semana);
            }
            else{
                TURNO_PREFERENCIA turnoPreferencia = obter_turno();
                std::cout << "Digite em minutos quanto dura a atividade\n";
                unsigned duracao = obter_duracao();
                std::vector<DIA> dias_semana = obter_dias();
                return Atividade(nome, LIVRE, turnoPreferencia, duracao, dias_semana);
            }
    }
}