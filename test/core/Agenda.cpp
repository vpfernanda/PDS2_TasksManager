#include "../doctest.hpp"
#include "core/Agenda.hpp"

namespace task_manager::core{
    TEST_CASE("Eventos salvos corretamente"){
        Agenda agenda(NULL);
        Evento ev1("Casamento da Cecília", Data(15, 12, 2023), Horario(15, 30));
        Evento ev2("Casamento da Cecília", Data(15, 12, 2023), Horario(15, 30));
        agenda.adiciona_evento(ev1);
        CHECK(agenda.get_eventos().size() == 1);
        SUBCASE("Eventos repetidos não podem ser aceitos"){
            CHECK(!agenda.adiciona_evento(ev2));
            CHECK(agenda.get_eventos().size() == 1);
        }
    }
    TEST_CASE("Busca de eventos correta"){
        Agenda agenda(NULL);
        Evento ev1("Casamento da Cecília", Data(15, 12, 2023), Horario(15, 30));
        agenda.adiciona_evento(ev1);
        std::vector<Evento> eventos_ano = agenda.buscar_eventos_intervalo(Data(16, 12, 2023), Data(20, 12, 2023));
        CHECK(eventos_ano.size() == 0);
        eventos_ano = agenda.buscar_eventos_intervalo(Data(10, 12, 2023), Data(20, 12, 2023));
        CHECK(eventos_ano.size() == 1);
    }

}