#include "core/Rotina.hpp"

namespace task_manager::core{

    void Rotina::adicionar_atividade(const Atividade& Atividade){
        bool contains = 0;
        for(auto it = _Rotina.begin(); it != _Rotina.end(); ++it){
            if(Atividade == *it){
                std::cout << "atividade ja inclusa.\n";
                contains = 1;
                break;
            }
        }
        if(!contains){
            _Rotina.push_back(Atividade);
        }
    }

    void Rotina::remover_atividade(const Atividade& Atividade){
        bool contains = 0;
        for(auto it = _Rotina.begin(); it != _Rotina.end(); ++it){
            if(Atividade == *it){
                _Rotina.erase(it);
                contains = 1;
            }
        }
        if(!contains){
            std::cout << "atividade nao encontrada.\n";
        }
    }

    void Rotina::gerar_rotina(){
        std::sort(_Rotina.begin(), _Rotina.end(), Atividade::comparar_atividades);            
    }

    std::vector<Atividade> Rotina::get_rotina() const{
        return Rotina::_Rotina;
    }
}