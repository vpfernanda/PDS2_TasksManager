#pragma once
#include <iostream>
#include <string>
#include "Rotina.hpp"
#include "Atividade.hpp"
#include "Agenda.hpp"
#include "BancoDados.hpp"
namespace task_manager::core{
//!  Classe Interface. 
/*!
  Classe feita para representar a Interface gráfica, responsável por imprimir os menus e receber os inputs do usuário.
*/
class Interface{
    public:
    // @brief Construtor
    Interface(Agenda* agenda) : _agenda(agenda){};
    /// @brief Imprime o menu
    void imprimir_menu();

    /// @brief funcao para alterar o que será impresso na tela / opcao que o usuario se encontra
    /// @param input input do usuario (numero / opcao escolhida)
    void input_menu(unsigned input);

    /// @brief Imprime todos os eventos no ano escolhido
    /// @param ano representa o ano para ser feito a busca
    void imprimir_eventos_ano(unsigned ano);

    /// @brief - Imprime os eventos entre os intervalos dados pelo usuário
    void imprimir_eventos_intervalo();
    
    /// @brief  - Adiciona um evento a agenda
    void adicionar_evento();
    
    /// @brief Imprime a rotina atual / escolhida
    void imprimir_rotina() const;
    
    /// @brief Cria uma rotina
    void criar_rotina();
    
    ///@brief opcao de editar / criar a rotina do usuario
    void editar_rotina();
    
    ///@brief Atribui uma rotina ao atributo _rotina
    ///@param agenda Ponteiro para a agenda
    void set_agenda(Agenda* agenda);

    ///@brief Getter da agneda
    Agenda* get_agenda() const;
    
    private:
        Agenda* _agenda;
};
}