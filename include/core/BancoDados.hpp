#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Rotina.hpp"
#include "Atividade.hpp"
#include "Agenda.hpp"
#include "Evento.hpp"

namespace task_manager::core{
    /// @brief Classe para persistência dos dados em arquivo texto.
    class BancoDados{
        public:
        /// @brief construtor da classe já seta os nomes dos arquivos correspondentes.
        BancoDados(): _r1("rot1.txt"), _r2("rot2.txt"), _r3("rot3.txt"), _eventos_ano("eventos.txt"){};

        /// @brief Grava a rotina em um arquivo .txt e retorna verdadeiro ou falso a depender do sucesso da operação.
        /// @param rotina objeto do tipo rotina
        bool gravar_rotina(Rotina rotina, unsigned rotina_id);

        /// @brief Limpa completamente o arquivo;
        /// @param rotina_id identificador da rotina a ser deletada (deve ser igual a 1,2, ou 3, necessariamente)
        bool deletar_rotina(unsigned rotina_id);

        /// @brief Obtém rotina gravada em um arquivo, se esta já tiver sido salva.
        /// @return Um objeto do tipo rotina.
        //Rotina obter_rotina(unsigned rotina_id);

        /// @brief grava evento em um arquivo txt
        /// @param evento objeto tipo evento
        bool gravar_evento(Evento evento);


        /// @brief Deleta um evento da lista de eventos gravados
        /// @param nome_evento 
        /// @param data_evento 
        /// @param horario_evento 
        /// @return true se a remoção teve sucesso, false se a remoção falhou
        bool deletar_evento(std::string nome_evento, std::string data_evento, std::string horario_evento);


        /// @brief Limpa o banco de dados de eventos em sua totalidade.
        bool limpar_eventos();

        /// @brief Retorna todos os eventos salvos
        std::vector<Evento> ler_eventos();

        private:
        std::string _r1; 
        std::string _r2; 
        std::string _r3; 
        std::string _eventos_ano;
        

    };

}