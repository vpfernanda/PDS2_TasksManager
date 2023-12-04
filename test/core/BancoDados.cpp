//#pragma once
#include "../doctest.hpp"
#include <string>
#include <vector>
#include "core/BancoDados.hpp"
#include "core/Rotina.hpp"
#include "core/Atividade.hpp"
#include "core/Evento.hpp"
#include "core/Horario.hpp"
#include "core/Data.hpp"

using task_manager::core::BancoDados;
using task_manager::core::Evento;
using task_manager::core::Horario;
using task_manager::core::Data;

namespace task_manager::core{

    TEST_CASE("Testes de Gravação de Evento"){
            BancoDados bd;
            bd.limpar_eventos();
            Evento evento("Aniversário Lulu", Data(20,4,2023), Horario(17,0));
            CHECK(bd.gravar_evento(evento));
            Evento evento2("Casamento João", Data(30,8,2023), Horario(21,0));
            CHECK(bd.gravar_evento(evento2));
            Evento evento3("Jantar com Ana", Data(5,10,2023), Horario(19,0));
            CHECK(bd.gravar_evento(evento3));
            CHECK(bd.deletar_evento("Jantar com Ana", "5/10/2023", "19:00"));
            Evento evento4("Exame Direcao", Data(2,7,2023), Horario(9,0));
            CHECK(bd.gravar_evento(evento4));
            CHECK_FALSE(bd.deletar_evento("Evento nao existente", "xxx", "xxx"));
    }
       

}