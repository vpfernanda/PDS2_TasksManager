#include "../doctest.hpp"
#include "core/Evento.hpp"
#include <iostream>
namespace task_manager::core{

TEST_CASE("Operador igualdade funcionando"){
    Evento ev1("Casamento da Cecília", Data(15, 12, 2023), Horario(15, 30));
    Evento ev2("Casamento da Cecília", Data(15, 12, 2023), Horario(15, 30));
    CHECK(ev1 == ev2);
}

}