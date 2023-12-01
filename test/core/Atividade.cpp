#include "../doctest.hpp"
#include "core/Atividade.hpp"

using task_manager::core::Atividade;

namespace task_manager::core{

TEST_CASE("Operador igualdade funcionando"){
    Atividade cafe_manha("comida", HORARIO_LIVRE, MANHA, 50, 1);
    Atividade cafe_manha_2("comida", HORARIO_LIVRE, MANHA, 50, 1);
    Atividade jantar("jantar", HORARIO_LIVRE, NOITE, 30, 1);
    CHECK(cafe_manha == cafe_manha_2);
    CHECK_FALSE(cafe_manha == jantar);
}

}