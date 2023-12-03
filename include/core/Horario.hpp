#ifndef HORARIO_HPP
#define HORARIO_HPP

#pragma once
#include <string>


namespace task_manager::core{

/// @brief Classe horario para abstração de horas e minutos.
class Horario{
    public:
    ///@brief Construtor default da classe Horario. Inicializa as variaveis _hora e _min com valor 0.
        Horario(): _hora(0), _min(0){};
    

    ///@brief Construtor da classe Horario.
    ///@param hora Valor numérico representando a hora.
    ///@param min Valor numérico representando minuto.
        Horario(unsigned hora, unsigned min);
    
    /// @brief Interface para a implementação do operador de comparação para um objeto Horario.
    /// @param other 
    /// @return  verdadeiro ou falso
        bool operator==(const Horario& other) const;

        
    /// @brief Interface para a implementação do operador de menor para um objeto Horario.
    /// @param other 
    /// @return verdadeiro ou falso.            
        bool operator<(const Horario& other) const;

    /// @brief Interface para a implementação do operador de maior para um objeto Horario.
    /// @param other 
    /// @return verdadeiro ou falso.            
        bool operator>(const Horario& other) const;
    /// @brief Interface para a implementação do operador de soma para um objeto Horario
    /// @param other 
    /// @return Novo horário com os minutos           
        Horario operator+(int minutos);
    /// @brief Informa o atributo hora.
    /// @return Retorna o valor de _hora.
        unsigned get_hora() const;

    /// @brief Informa o atributo minuto.
    /// @return Retorna o valor de _min.
        unsigned get_min() const;

    /// @brief Realiza a conversão dos valores hora e minuto para o formato hh:mm
    /// @return Retorna uma string de horario no formato "hh:mm"
        std::string to_String() const;

    /// @brief Faz o cálculo da duração de tempo entre dois horários
    /// @param inicio 
    /// @param fim 
    /// @return Retorna um objeto horario com a duração correspondente.
        Horario calcula_Duracao(Horario fim);

    private:
        unsigned _hora; /// Armazena o campo das horas
        unsigned _min; /// Armazena o campo dos minutos
        std::string _horario;            
};


}

#endif // HORARIO_HPP