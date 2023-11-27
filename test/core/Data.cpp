#include "../doctest.hpp"
#include "core/Data.hpp"

using task_manager::core::Data;

namespace task_manager::core{

TEST_CASE("Operador igualdade funcionando"){
    Data data1(10, 12, 2007);
    Data data2(10, 12, 2007);
    Data data3(11, 12, 2007);
    CHECK(data1 == data2);
    CHECK_FALSE(data1 == data3);
}

}