#pragma once
#include <iostream>
#include <string>
#include "Rotina.hpp"
#include "Atividade.hpp"

namespace task_manager::core{

class Interface{
    public:

    /// @brief Imprime o menu
    void imprimir_menu();

    /// @brief funcao para alterar o que será impresso na tela / opcao que o usuario se encontra
    /// @param input input do usuario (numero / opcao escolhida)
    void input_menu(unsigned input);

    /// @brief Imprime todos os eventos do Ano
    void imprimir_eventos_ano();

    /// @brief - TBD - necessário classe Agenda p/ implementar 
    void imprimir_eventos_intervalo();

    /// @brief Imprime a rotina atual / escolhida
    void imprimir_rotina() const;
    /// @brief Cria uma rotina
    void criar_rotina();
    ///@brief opcao de editar / criar a rotina do usuario
    void editar_rotina();    

    private:
    Rotina _rotina;
};
}