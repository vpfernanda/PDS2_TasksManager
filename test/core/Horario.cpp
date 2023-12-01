//#pragma once
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.hpp"
#include <string>
#include "../../include/core/Horario.hpp"

using task_manager::core::Horario;

namespace task_manager::core{

    TEST_CASE("Teste do construtor"){
        SUBCASE("Criando um objeto horário válido"){
            Horario horario_task(5,30);
            CHECK(horario_task.get_hora()==5);
            CHECK(horario_task.get_min()==30);
        }
        /*SUBCASE("Criando um objeto horário inválido"){
            Horario horario_task(90,0);
            CHECK(horario_task.get_hora()==0);
        }*/ //necessario fazer uma exceção para tratar objetos com valores invalidos
        

    }

    TEST_CASE("Teste da função toString"){
        SUBCASE("Horas com valor numérico maior que 10"){
            Horario horario_task(18,45);
            CHECK(horario_task.to_String()=="18:45");
        } 
        SUBCASE("Horas com valor numérico menor que 10"){
            Horario horario_task(7,10);
            CHECK(horario_task.to_String()=="07:10");
        }
    }

    TEST_CASE("Teste do operador de comparação"){
        SUBCASE("Teste 1"){
            Horario h_task(10,30);
            Horario h_task2(10,30);
            CHECK(h_task==h_task2);
        }
        SUBCASE("Teste 1"){
            Horario h_task(5,25);
            Horario h_task2(8,0);
            CHECK_FALSE(h_task==h_task2);
        }


    }

    TEST_CASE("Teste da função calcula_duracao"){
        SUBCASE("Minutos do horario de inicio maior que do horario de fim"){
            Horario h_task(5,30);
            Horario h_task2(7,10);
            Horario duracao(0,0);
            duracao = h_task.calcula_Duracao(h_task2);
            CHECK(duracao.to_String()=="01:40");
        }
        SUBCASE("Minutos iguais"){
            Horario h_task(14,0);
            Horario h_task2(16,0);
            Horario duracao(0,0);
            duracao = h_task.calcula_Duracao(h_task2);
            CHECK(duracao.to_String()=="02:00");
        }
        SUBCASE("Minutos iguais"){
            Horario h_task(21,35);
            Horario h_task2(22,35);
            Horario duracao(0,0);
            duracao = h_task.calcula_Duracao(h_task2);
            CHECK(duracao.to_String()=="01:00");
        }
        SUBCASE("Minutos do horario de inicio menor que do horario de fim"){
            Horario h_task(14,15);
            Horario h_task2(20,55);
            Horario duracao(0,0);
            duracao = h_task.calcula_Duracao(h_task2);
            CHECK(duracao.to_String()=="06:40");
        }
        SUBCASE("Durações envolvendo 0h"){
            Horario h_task(0,20);
            Horario h_task2(9,5);
            Horario duracao(0,0);
            duracao = h_task.calcula_Duracao(h_task2);
            CHECK(duracao.to_String()=="08:45");
        }
        SUBCASE("Durações envolvendo 0h"){
            Horario h_task(22,20);
            Horario h_task2(0,50);
            Horario duracao(0,0);
            duracao = h_task.calcula_Duracao(h_task2);
            CHECK(duracao.to_String()=="02:30");
        }
        SUBCASE("Durações envolvendo 0h"){
            Horario h_task(23,48);
            Horario h_task2(0,10);
            Horario duracao(0,0);
            duracao = h_task.calcula_Duracao(h_task2);
            CHECK(duracao.to_String()=="00:22");
        }
        SUBCASE("Durações envolvendo 0h"){
            Horario h_task(23,48);
            Horario h_task2(0,10);
            Horario duracao(0,0);
            duracao = h_task.calcula_Duracao(h_task2);
            CHECK(duracao.to_String()=="00:22");
        }
        SUBCASE("Horario de fim antes do horario de inicio"){
            Horario h_task(8,30);
            Horario h_task2(6,10);
            Horario duracao(0,0);
            duracao = h_task.calcula_Duracao(h_task2);
            CHECK(duracao.to_String()=="02:20");
        }

        
    }

    TEST_CASE("Teste do operador de maior e menor"){
        SUBCASE("Teste maior/menor com horas iguais e minutos diferentes"){
            Horario h_task(10,20);
            Horario h_task2(10,10);
            CHECK(h_task>h_task2);
            CHECK(h_task2<h_task);
            CHECK_FALSE(h_task2>h_task);
            CHECK_FALSE(h_task<h_task2);
        }
        SUBCASE("Teste maior/menor com horas diferentes e minutos iguais"){
            Horario h_task(17,45);
            Horario h_task2(14,45);
            CHECK(h_task>h_task2);
            CHECK(h_task2<h_task);
            CHECK_FALSE(h_task2>h_task);
            CHECK_FALSE(h_task<h_task2);
        }
         SUBCASE("Teste maior/menor com horas diferentes e minutos diferentes"){
            Horario h_task(23,15);
            Horario h_task2(21,7);
            CHECK(h_task>h_task2);
            CHECK(h_task2<h_task);
            CHECK_FALSE(h_task2>h_task);
            CHECK_FALSE(h_task<h_task2);
        }
    }

}