#pragma once
#include <string>
#include <vector>
#include "Rotina.hpp"
#include "Data.hpp"
#include "Evento.hpp"
#include <memory>
namespace task_manager::core{


///@brief Classe feita para representar uma Agenda

class Agenda{
    public:
    /// @brief - construtor Agenda com apenas a rotina
    Agenda(std::shared_ptr<Rotina> rotina): Agenda(rotina, std::vector<Evento>()) {};
    /// @brief - construtor Agenda com apenas os eventos.
    Agenda(std::vector<Evento> eventos): Agenda(NULL, eventos) {};
    /// @brief - construtor Agenda com a rotina e os eventos
    Agenda(std::shared_ptr<Rotina> rotina, std::vector<Evento> eventos): _rotina(rotina), _eventos(eventos) {};
    /// @brief - método para buscar todos os eventos em um ano específico
    std::vector<Evento> buscar_eventos_ano(unsigned ano);
    /// @brief - método para buscar todos os eventos em um intervalo
    std::vector<Evento> buscar_eventos_intervalo(Data inicio, Data fim);
    /// @brief - Getter de rotina (_rotina)
    std::shared_ptr<Rotina> get_rotina() const;
    /// @brief - Setter de rotina (_rotina)
    void set_rotina(std::shared_ptr<Rotina> rotina);
    /// @brief - Adiciona um evento a agenda
    bool adiciona_evento(Evento& evento);
    /// @brief - Getter de eventos
    std::vector<Evento> get_eventos();
    private:
        std::shared_ptr<Rotina> _rotina;
        std::vector<Evento> _eventos;
};

}

