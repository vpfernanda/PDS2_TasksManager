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

}