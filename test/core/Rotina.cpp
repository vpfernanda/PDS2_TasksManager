#include "../doctest.hpp"
#include "core/Rotina.hpp"

using task_manager::core::Rotina;

namespace task_manager::core{

TEST_CASE("Vetor guardando atividades"){
    Atividade cafe_manha("comida", LIVRE, MANHA, 50, SEG);
    Atividade cafe_manha_2("comida", LIVRE, MANHA, 50, SEG);
    Atividade jantar("jantar", LIVRE, NOITE, 30, SEG);
    CHECK(cafe_manha == cafe_manha_2);
    CHECK_FALSE(cafe_manha == jantar);
}

}