#include "../doctest.hpp"
#include "core/Interface.hpp"
#include <iostream>
namespace task_manager::core{
TEST_CASE("Testando interface"){
    Agenda agenda(std::make_shared<Rotina>("Rotina universitária"));
    Interface interface(&agenda);
    interface.get_agenda()->get_rotina()->adicionar_atividade(Atividade("Academia", LIVRE, NOITE, 60, {SEG, QUA, SEX}));
    interface.get_agenda()->get_rotina()->adicionar_atividade(Atividade("Aula PDS2", FIXO, Horario(13, 0), Horario(15, 0), {TER, QUI}));
    interface.get_agenda()->get_rotina()->adicionar_atividade(Atividade("Aula Mat Discreta", FIXO, Horario(12, 0), Horario(15, 0), {SEG, QUA}));
    CHECK(interface.get_agenda()->get_rotina()->get_atividades_rotina().size() == 3);
}
}