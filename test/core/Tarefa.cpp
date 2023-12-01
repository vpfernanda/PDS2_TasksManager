#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.hpp"
#include "core/Tarefa.hpp"

using task_manager::core::Tarefa;

namespace task_manager::core{

TEST_CASE("Operador igualdade funcionando"){
    Data data1(10, 11, 2023);
    Data data2(20, 12, 2023);
    Tarefa tarefa1("Ir ao clube", data1);
    Tarefa tarefa2("Ir ao clube", data1);
    Tarefa tarefa3("Fazer matricula", data2);
    CHECK(tarefa1 == tarefa2);
    CHECK_FALSE(tarefa1 == tarefa3);
}

}