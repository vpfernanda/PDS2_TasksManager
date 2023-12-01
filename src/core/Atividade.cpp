#include "core/Atividade.hpp"

namespace task_manager::core {
    Atividade::Atividade(std::string nome, TIPO_HORARIO tipo_horario, TURNO_PREFERENCIA turno_preferencia,
                         unsigned duracao_minutos, DIA dia_semana) {
        _nome = nome;
        _tipo_horario = tipo_horario;
        _turno_preferencia = turno_preferencia;
        _duracao = duracao_minutos;
        _dia_semana = dia_semana;
    }

    bool Atividade::operator==(const Atividade& other) const {
        return this->_nome == other._nome &&
               this->_tipo_horario == other._tipo_horario &&
               this->_turno_preferencia == other._turno_preferencia &&
               this->_duracao == other._duracao &&
               this->_dia_semana == other._dia_semana;
    }

    std::string Atividade::get_nome() const{
        return _nome;
    }
    TIPO_HORARIO Atividade::get_horario() const{
        return _tipo_horario;
    }
    unsigned Atividade::get_duracao() const{
        return _duracao;
    }

    DIA Atividade::get_dia() const {
        return _dia_semana;
    }

    TURNO_PREFERENCIA Atividade::get_turno() const {
        return _turno_preferencia;
    }

    bool Atividade::comparar_atividades(const Atividade& a, const Atividade& b) {
        if (a.get_dia() != b.get_dia()) {
            return a.get_dia() < b.get_dia();
        }

        if (a.get_turno() != b.get_turno()) {
            return a.get_turno() < b.get_turno();
        }
        return a.get_turno() == NENHUM;
    }

    TIPO_HORARIO Atividade::obter_horario() {
        bool correct = false;
        int escolha;

        while (!correct) {
            std::cout << "escolha o tipo da atividade (0 a 1): ";
            std::cin >> escolha;

            if (std::cin.fail() || escolha < 0 || escolha > 1) {
                std::cout << "tipo inexistente, escolha novamente\n";
                std::cin.clear(); // Limpa o estado de erro
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora os caracteres extras no buffer
            } else {
            correct = true;
            }
        }
    return static_cast<TIPO_HORARIO>(escolha);
    }
    
    TURNO_PREFERENCIA Atividade::obter_turno(){
        bool correct = 0;
        int escolha;

        while(!correct){
            std::cout << "escolha o turno da atividade (0 a 3): ";
            std::cin >> escolha;

            if(std::cin.fail() || escolha < 0 || escolha > 3){
                std::cout << "turno incorreto, escolha novamente\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }else{
                correct = 1;
            }

        }
        
        return static_cast<TURNO_PREFERENCIA>(escolha);
    }

    DIA Atividade::obter_dia(){
        bool correct = 0;
        int escolha;

        while(!correct){
            std::cout << "escolha o dia da atividade (0 a 6): ";
            std::cin >> escolha;

            if(std::cin.fail() || escolha < 0 || escolha > 6){
                std::cout << "dia incorreto, escolha novamente\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }else{
                correct = 1;
            }

        }

        return static_cast<DIA>(escolha);
    }

     Atividade Atividade::criarAtividade() {
            std::string nome;
            TIPO_HORARIO tipoHorario;
            TURNO_PREFERENCIA turnoPreferencia;
            unsigned duracaoMinutos;
            DIA diaSemana;

            std::cout <<"digite um nome: ";
            std::getline(std::cin >> std::ws, nome);
            tipoHorario = obter_horario();
            turnoPreferencia = obter_turno();
            
            std::cout <<"qual a duracao em minutos?: ";
            std::cin >> duracaoMinutos;

            diaSemana = obter_dia();
            
            Atividade novaAtividade(nome, tipoHorario, turnoPreferencia, duracaoMinutos, diaSemana);

            return novaAtividade;
        }
}
