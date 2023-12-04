#include "core/Agenda.hpp"
#include "core/BancoDados.hpp"
namespace task_manager::core {


    std::vector<Evento> Agenda::buscar_eventos_ano(unsigned ano) {
        std::vector<Evento> eventos_ano;
        for (const auto& evento : _eventos) {
            if (evento.get_data().get_ano() == ano) {
                eventos_ano.push_back(evento);
            }
        }
        return eventos_ano;
    }

    std::vector<Evento> Agenda::buscar_eventos_intervalo(Data inicio, Data fim) {
        std::vector<Evento> eventos_intervalo;
        for (const auto& evento : _eventos) {
            if (evento.get_data() >= inicio && evento.get_data() <= fim) {
                eventos_intervalo.push_back(evento);
            }
        }
        return eventos_intervalo;
    }

    Rotina* Agenda::get_rotina() const {
        return _rotina;
    }
    void Agenda::set_rotina(Rotina* rotina){
        _rotina = rotina;
    }
    bool Agenda::adiciona_evento(Evento& evento){
        for (Evento ev : _eventos){
            if (evento == ev) return false;
        }
        _eventos.push_back(evento);
        return true;
    }
    std::vector<Evento> Agenda::get_eventos(){
        return _eventos;
}
}