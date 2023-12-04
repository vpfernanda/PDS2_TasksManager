#include "core/BancoDados.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include "core/Rotina.hpp"
#include "core/Atividade.hpp"
#include "core/Agenda.hpp"
#include "core/Data.hpp"

namespace task_manager::core{
    
        bool BancoDados::gravar_rotina(Rotina rotina, unsigned rotina_id){
            std::string id;
            switch (rotina_id){
                case 1: id = _r1;
                case 2: id = _r2;
                case 3: id = _r3;
                default: return false;
            }
            std::ofstream arquivo(id);
            if(arquivo.is_open()){
                arquivo << rotina.to_string();
                arquivo.close();
                return true;
            }
                return false;
            
        }

        /// @brief Limpa completamente o arquivo;
        /// @param rotina_id identificador da rotina a ser deletada (deve ser igual a 1,2, ou 3, necessariamente)
        bool BancoDados::deletar_rotina(unsigned rotina_id){
            std::string id;
            switch (rotina_id){
                case 1: id = _r1;
                case 2: id = _r2;
                case 3: id = _r3;
                default: return false;
            }
            std::ofstream arquivo(id, std::ios::trunc);
            if(arquivo.is_open()){
                arquivo.close();
                return true;
            }
            return false;
        }

        //essa é a mais dificil de implementar, deixar por ultimo
        /// @brief Obtém rotina gravada em um arquivo, se esta já tiver sido salva.
        /// @return Um objeto do tipo rotina.
        //Rotina BancoDados::obter_rotina(unsigned rotina_id);

        /// @brief grava evento em um arquivo txt e retorna verdadeiro ou falso a depender do sucesso da operação
        /// @param evento objeto tipo evento
        bool BancoDados::gravar_evento(Evento evento){
            std::ofstream arquivo(_eventos_ano, std::ios::app);
            if(arquivo.is_open()){
                arquivo << evento.to_string_bd();
                arquivo.close();
                return true;
            }
            return false;

        }

        /// @brief Deleta um evento da lista de eventos gravados
        /// @param evento objeto do tipo evento
        /// @return true se a remoção teve sucesso, false se a remoção falhou
        bool BancoDados::deletar_evento(std::string nome_evento, std::string data_evento, std::string horario_evento){
            std::string nome_evento_linha;
            std::string data_evento_linha;
            std::string horario_evento_linha;

            std::string linha;
            std::size_t pos_separador1; 
            std::size_t pos_separador2; 
            std::fstream arquivo(_eventos_ano, std::ios::in | std::ios::out);

            if(arquivo.is_open()){
                while(std::getline(arquivo, linha)){
                    pos_separador1 = linha.find('|');
                    pos_separador2 = linha.find('|', pos_separador1 + 1);
                    if(pos_separador1 != std::string::npos && pos_separador1 != std::string::npos){
                        std::string nome_evento_linha = linha.substr(0, pos_separador1);
                        std::string data_linha = linha.substr(pos_separador1 + 1, pos_separador2 - pos_separador1 - 1);
                        std::string horario_linha = linha.substr(pos_separador2 + 1);
                            if(nome_evento_linha == nome_evento && data_linha == data_evento && horario_linha == horario_evento){
                                std::streampos cursor_arquivo = arquivo.tellg();
                                std::streamoff retorno_inicio = static_cast<std::streamoff>(cursor_arquivo) - linha.length() - 1;
                                arquivo.seekp(retorno_inicio);
                                for(int i=0; i<linha.length(); i++)
                                    arquivo << "#";
                                //arquivo << "\n";
                                arquivo.seekp(0, std::ios::end);
                                arquivo.close();
                                return true;
                            }
                    }
    
                    
                }
            }
            arquivo.seekp(0, std::ios::end);
            arquivo.close();
            return false;
        }


        /// @brief Limpa o banco de dados de eventos em sua totalidade.
        bool BancoDados::limpar_eventos(){
            std::ofstream arquivo(_eventos_ano, std::ios::trunc);
            if(arquivo.is_open()){
                arquivo.close();
                return true;
            }
            return false;
        }
        /// @brief Retorna todos os eventos salvos
        std::vector<Evento> BancoDados::ler_eventos(){
            std::vector<Evento> eventos;
            std::string linha;
            std::size_t pos_separador1; 
            std::size_t pos_separador2; 
            std::fstream arquivo(_eventos_ano, std::ios::in | std::ios::out);
            if(arquivo.is_open()){
                while(std::getline(arquivo, linha)){
                    pos_separador1 = linha.find("|");
                    pos_separador2 = linha.find("|", pos_separador1 + 1);
                    if(pos_separador1 != std::string::npos && pos_separador1 != std::string::npos){
                        std::string nome_evento_linha = linha.substr(0, pos_separador1);
                        std::string data_linha = linha.substr(pos_separador1 + 1, pos_separador2 - pos_separador1 - 1);
                        // Pegando o dia, mes e ano da string
                        std::string horario_linha = linha.substr(pos_separador2 + 1);
                        std::size_t pos_separador_data_1 = data_linha.find("/");
                        std::size_t pos_separador_data_2 = data_linha.find("/", pos_separador_data_1 + 1);
                        unsigned dia = stoi(data_linha.substr(0, pos_separador_data_1));
                        unsigned mes = stoi(data_linha.substr(pos_separador_data_1 + 1, pos_separador_data_2 - 1));
                        unsigned ano = stoi(data_linha.substr(pos_separador_data_2 + 1));
                        // Pegando as horas e minutos do evento
                        std::size_t pos_separador_horario_1 = horario_linha.find(":");
                        unsigned horas = stoi(horario_linha.substr(0, pos_separador_horario_1));
                        unsigned minutos = stoi(horario_linha.substr(pos_separador_horario_1 + 1));
                        // Jogando no vetor o evento lido
                        eventos.push_back(Evento(nome_evento_linha, Data(dia, mes, ano), Horario(horas, minutos)));
                    }
                }
            }
            return eventos;
        }
}