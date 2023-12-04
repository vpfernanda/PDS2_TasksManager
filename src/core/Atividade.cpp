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
        unsigned duracao_minutos, std::vector<DIA> dias_semana): _horario_inicio(Horario()), _horario_fim(Horario()){ // hprario livre
        _nome = nome;
        _tipo_horario = tipo_horario;
        _turno_preferencia = turno_preferencia;
        _duracao = duracao_minutos;
        _dias_semana = dias_semana;
    }
   
    Atividade::Atividade(std::string nome, TIPO_HORARIO tipo_horario, Horario inicio, Horario fim, std::vector<DIA> dias_semana): _turno_preferencia(NENHUM), _duracao(0){ // fixo
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
               this->_dias_semana == other._dias_semana;
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
    void Atividade::set_horario_inicio(Horario inicio){
        _horario_inicio = inicio;
    }
    Horario Atividade::get_horario_fim() const{
        return _horario_fim;
    }
    void Atividade::set_horario_fim(Horario fim){
        _horario_fim = fim;
    }
    std::vector<DIA> Atividade::get_dias_semana() const{
        return _dias_semana;
    }

    TURNO_PREFERENCIA Atividade::get_turno() const {
        return _turno_preferencia;
    }

     void Atividade::sort_dia(std::vector<DIA>& dias){
        std::sort(dias.begin(), dias.end());

        auto it = std::unique(dias.begin(), dias.end());
        dias.erase(it, dias.end());
    }

    bool Atividade::comparar_atividades(const Atividade& a, const Atividade& b) {
        return false;
    }

    std::string Atividade::to_string() const{
        std::string str;
        str += _horario_inicio.to_String() + "-" + _horario_fim.to_String() + " " +  _nome;
        return str;
    }
    
    unsigned obter_duracao(){
        unsigned minutos = 0;
        
        while(true){
            std::cout << "Digite a duracao da atividade: ";
            if(std::cin>>minutos){
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                if(minutos <= 1440){
                    return minutos;
                }else{
                    std::cout<<"Duracao invalida. Digite novamente.\n";
                }
            }else{
                std::cout << "Entrada invalida. Digite corretamente.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }

    Horario obter_horario() {
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

    std::vector<DIA> obter_dias(){
        std::vector<DIA> dias_semana_escolhidos;
        int escolha;

        while(true){
            std::cout << "Escolha os dias da atividade de 0 a 6 (comecando do domingo), digite -1 para terminar: ";
            
            if(std::cin >> escolha){
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if(escolha >= 0 && escolha <= 6){
                    dias_semana_escolhidos.push_back(DIA(escolha));
                    std::cout << "adicionado no dia " << escolha << "\n";
                }
                else if(escolha == -1){
                    Atividade::sort_dia(dias_semana_escolhidos);
                    return dias_semana_escolhidos;
                }else{
                    std::cout << "Entrada invalida. Digite corretamente.\n";
                }
            }else{
                std::cout << "Entrada invalida. Digite corretamente.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }

    TURNO_PREFERENCIA obter_turno(){
        unsigned escolha;

        while(true){
            std::cout << "escolha o turno da atividade, 0 para MANHA, 1 para TARDE, 2 para NOITE: ";

            if(std::cin >> escolha) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if(escolha == 0 || escolha == 1 || escolha == 2){
                    return TURNO_PREFERENCIA(escolha);
                }else{
                    std::cout << "Entrada invalida. Digite corretamente.\n";
                }
            }else{
                std::cout <<"Entrada invalida. Digite corretamente.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }           
        }
        
        return static_cast<TURNO_PREFERENCIA>(escolha);
    }

    Atividade Atividade::criarAtividade() {
        std::string nome;
        TIPO_HORARIO tipoHorario;
        TURNO_PREFERENCIA turno;
        Horario inicio;
        Horario fim;
        unsigned duracao;
        std::vector<DIA> diasSemana;

        unsigned state;

        std::cout << "Digite o nome da atividade:\n";
        std::getline(std::cin >> std::ws, nome);

        while (true) {
            std::cout << "Esta atividade tem horario fixo? 0 = sim, 1 = nao : ";

            if (std::cin >> state) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if (state == 0 || state == 1) {
                    tipoHorario = TIPO_HORARIO(state);
                    break;
                } else {
                    std::cout << "Entrada invalida. Digite 1 ou 0.\n";
                }
            } else {
                std::cout << "Entrada invalida. Digite 1 ou 0.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }

        if (tipoHorario == 0) { // horario fixo
            while (true) {
                std::cout << "Digite o horario que a atividade comeca:\n";
                inicio = obter_horario();
                std::cout << "Digite o horario que a atividade termina:\n";
                fim = obter_horario();
                if (inicio > fim) {
                    std::cout << "Horario de inicio e fim inválido, digite novamente\n";
                } else {
                    break;
                }
            }
            return Atividade(nome, tipoHorario, inicio, fim, diasSemana);
        } else { // horario livre
            turno = obter_turno();
            std::cout << "Digite, em minutos, quanto dura a atividade\n";
            duracao = obter_duracao();
            diasSemana = obter_dias();
            return Atividade(nome, tipoHorario, turno, duracao, diasSemana);
        }
    }
}