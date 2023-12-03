#include "../doctest.hpp"
#include "core/Rotina.hpp"
#include <iostream>
using task_manager::core::Rotina;
using task_manager::core::TIPO_HORARIO;
using task_manager::core::DIA;
using task_manager::core::TURNO_PREFERENCIA;
namespace task_manager::core{

TEST_CASE("Testando adicionar_atividade"){
    Rotina rotina1("Rotina universitária");
    // 2 atividades com conflito de horário, apenas a primeira deve ser adicionada
    rotina1.adicionar_atividade(Atividade("Aula PDS2", FIXO, Horario(13, 0), Horario(15, 0), {TER, QUI}));
    rotina1.adicionar_atividade(Atividade("Aula PDS3", FIXO, Horario(12, 0), Horario(14, 0), {TER, QUI}));
    CHECK(rotina1.get_atividades_rotina().size() == 1);
    rotina1.adicionar_atividade(Atividade("Aula Matemática Discreta", FIXO, Horario(12, 0), Horario(15, 0), {SEG, QUA}));
    CHECK(rotina1.get_atividades_rotina().size() == 2);
    rotina1.adicionar_atividade(Atividade("Academia", LIVRE, TARDE, 50, {SEG, QUA}));
    rotina1.gerar_rotina();
    CHECK(rotina1.get_atividades_rotina().size() == 3);
}
}