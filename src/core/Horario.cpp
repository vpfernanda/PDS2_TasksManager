#include "core/Horario.hpp"
#include <string>

namespace task_manager::core{
    
    ///@brief Construtor da classe Horario.
    ///@param hora Valor numérico representando a hora.
    ///@param min Valor numérico representando minuto.
        Horario::Horario(unsigned hora, unsigned min){
            if((hora>=0 && hora<=23) && (min>=0 && min<=59)){
            this->_hora = hora;
            this->_min = min;
            }
        }
    
    /// @brief Implementação do operador de comparação para um objeto Horario.
    /// @param other 
    /// @return  verdadeiro ou falso
        bool Horario::operator==(const Horario& other) const{
            return this->_hora == other.get_hora() && this->_min == other.get_min();
        }

    /// @brief Interface para a implementação do operador de maior para um objeto Horario. Um horário ser "maior" significa que ele ocorre depois.
    /// @param other 
    /// @return verdadeiro ou falso.            
        bool Horario::operator>(const Horario& other) const{
            unsigned hora = this->_hora;
            

            if(hora > other.get_hora() || 
            (hora == other.get_hora() && this->_min > other.get_min()))
                return true;
            
            return false;
        }

        Horario Horario::operator+(int minutos){
            unsigned novos_minutos = (this->_min + minutos) % 60;
            unsigned nova_hora = this->_hora + ((this->_min + minutos) / 60);
            return Horario(nova_hora, novos_minutos);
        }

    /// @brief Interface para a implementação do operador de menor para um objeto Horario. Um horário ser "menor" significa que ele ocorre antes.
    /// @param other 
    /// @return verdadeiro ou falso.            
        bool Horario::operator<(const Horario& other) const{
            unsigned hora = this->_hora;
            if(this->_hora == 0)
                hora = 24;

            if(hora < other.get_hora() || 
            (hora == other.get_hora() && this->_min <other.get_min()))
                return true;
            
            return false;
        }
        

    /// @brief Informa o atributo hora.
    /// @return Retorna o valor de _hora.
        unsigned Horario::get_hora() const{
            return _hora;
        }

    /// @brief Informa o atributo minuto.
    /// @return Retorna o valor de _min.
        unsigned Horario::get_min() const{
            return _min;
        }

    /// @brief Realiza a conversão dos valores hora e minuto para o formato hh:mm
    /// @return Retorna uma string de horario no formato "hh:mm"
        std::string Horario::to_String() const{
            std::string hora = "";
            std::string min = "";
            if(_hora <= 9){
                hora += "0" + std::to_string(_hora);
            } else {
                hora += std::to_string(_hora);
            }

            if(_min <=9){
                min += "0" + std::to_string(_min);
            } else {
                min += std::to_string(_min);
            }

            return hora + ":" + min;
        }

    /// @brief Faz o cálculo da duração de tempo entre dois horários
    /// @param inicio 
    /// @param fim 
    /// @return Retorna um objeto horario com a duração correspondente.
        Horario Horario::calcula_Duracao(Horario fim){
            if(fim < *this){
                Horario aux(0,0);
                aux = fim;
                fim = *this;
                *this = aux;
            }

            unsigned duracao_horas= fim.get_hora();
            unsigned duracao_minutos=0;

            if(fim.get_hora()==0)
                duracao_horas = 24;

            if(this->get_min()!=0){
                duracao_minutos = (60-(this->get_min())) + fim.get_min();
                duracao_horas = (duracao_horas-this->get_hora())-1; 
            }
            else{
                duracao_minutos = fim.get_min();
                duracao_horas = (duracao_horas-(this->get_hora()));
            }

            if(duracao_minutos>=60){
                duracao_horas += (duracao_minutos/60);
                duracao_minutos = duracao_minutos%60;
            }

            Horario duracao(duracao_horas,duracao_minutos);
            return duracao;
        }

             

}