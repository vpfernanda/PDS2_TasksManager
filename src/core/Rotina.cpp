#include "core/Rotina.hpp"
#include <sstream>
#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>
using std::setw;
using std::left;
namespace task_manager::core{
    
    bool comparar_atividades(const Atividade& a, const Atividade& b) {
        return a.get_horario_inicio() < b.get_horario_inicio();
    }

    bool conflito_horario(Horario inicio_atv1, Horario fim_atv1, Horario inicio_atv2, Horario fim_atv2){
        // A nova atividade a ser adicionada não pode ter intercessão de horário com outra atividade de horario fixo, ou seja,
        // não pode começar antes de outra e terminar depois do inicio de outra, e não pode começar entre o inicio e fim de outra
        if ((fim_atv1 > inicio_atv2 && fim_atv1 < fim_atv2) || (inicio_atv1 > inicio_atv2 && inicio_atv1 < fim_atv2)) return true;
        return false;
    }

    bool intersecao_dias(Atividade atv1, Atividade atv2){
        std::vector<DIA> dias1 = atv1.get_dias_semana();
        std::vector<DIA> dias2 = atv2.get_dias_semana();
        for (DIA d1: dias1){
            for (DIA d2: dias2) if (d1 == d2) return true;
        }
        return false;
    }
    void Rotina::adicionar_atividade(const Atividade& atividade){
        bool valido = true;
        for(Atividade atv : _atividades_rotina){
            if(atividade == atv){
                std::cout << "Atividade ja inclusa.\n";
                valido = false;
                break;
            }
            if (atividade.get_tipo_horario() == FIXO && intersecao_dias(atividade, atv)){
                if (conflito_horario(atividade.get_horario_inicio(), atividade.get_horario_fim(), atv.get_horario_inicio(), atv.get_horario_fim())){
                    valido = false;
                    std::cout << "Ha um conflito de horario com essa atividade\n";
                }
            }
        }

        if(valido){
            _atividades_rotina.push_back(atividade);
        }
    }

    void Rotina::remover_atividade(const Atividade& Atividade){
        bool contains = false;
        for(auto it = _atividades_rotina.begin(); it != _atividades_rotina.end(); ++it){
            if(Atividade == *it){
                _atividades_rotina.erase(it);
                contains = true;
                break;
            }
        }
        if(!contains){
            std::cout << "atividade nao encontrada.\n";
        }
    }
    bool alocar_atividade_livre(Rotina* rotina, Atividade atividade, Horario inicio_turno, Horario fim_turno){
        auto atividades_rotina = rotina->get_atividades_rotina();
        Horario possivel_horario_inicio = inicio_turno;
        Horario possivel_horario_fim = possivel_horario_inicio + atividade.get_duracao();
        bool alocacao_horario_valida = true;
        do{
            alocacao_horario_valida = true;
            for (Atividade atv: atividades_rotina){
                if (atv == atividade) continue;
                if (conflito_horario(possivel_horario_inicio, possivel_horario_fim, atv.get_horario_inicio(), atv.get_horario_fim())){
                    alocacao_horario_valida = false;
                    break;
                }
            }
            if (!alocacao_horario_valida){
                possivel_horario_inicio = possivel_horario_inicio + 10;
                possivel_horario_fim = possivel_horario_fim + 10;
            }
            if (possivel_horario_fim > fim_turno){
                return false;
            }
        }while(!alocacao_horario_valida);
        if (alocacao_horario_valida){
            rotina->remover_atividade(atividade);
            atividade.set_horario_inicio(possivel_horario_inicio);
            atividade.set_horario_fim(possivel_horario_fim);
            rotina->adicionar_atividade(atividade);
        }
        return alocacao_horario_valida;
        return false;
    }
    bool Rotina::gerar_rotina(){
        std::vector<Atividade> atividades_livres;
        for (Atividade atv: _atividades_rotina) if (atv.get_tipo_horario() == LIVRE) atividades_livres.push_back(atv);
        for (Atividade atv: atividades_livres){
            switch (atv.get_turno()){
                case MANHA:
                {
                    Horario comeco_manha(6, 0);
                    Horario fim_manha(12, 0);
                    return alocar_atividade_livre(this, atv, comeco_manha, fim_manha);
                }break;
                case TARDE:
                {
                    Horario comeco_tarde(12, 0);
                    Horario fim_tarde(19, 0);
                    return alocar_atividade_livre(this, atv, comeco_tarde, fim_tarde);
                }break;
                case NOITE:
                {
                    Horario comeco_noite(19, 0);
                    Horario fim_noite(23, 59);
                    return alocar_atividade_livre(this, atv, comeco_noite, fim_noite);
                }break;
                default:
                    return true;
                break;
            }
        }
        return true;
    }
    std::vector<Atividade> Rotina::get_atividades_rotina() const{
        return _atividades_rotina;
    }
    std::string Rotina::nome() const{
        return _nome;
    }
    std::string Rotina::to_string(){
        std::stringstream strstream;
        if (!gerar_rotina()) strstream << "Esta rotina e impossivel\n";
        else{
            strstream << setw(35) << left << "Domingo" << setw(35) << left << "Segunda" << setw(35) << left << "Terca" << setw(35) << left << "Quarta" << setw(35) << left << "Quinta" << setw(35) << left << "Sexta" << setw(35) << left << "Sábado" << "\n";
            std::vector<Atividade> atividades_por_dia[7];
            for (Atividade &atv: _atividades_rotina){
                std::vector<DIA> dias_semana_ocorre = atv.get_dias_semana();
                for(DIA &dia : dias_semana_ocorre){
                    atividades_por_dia[static_cast<unsigned>(dia)].push_back(atv);
                }
            }
            unsigned tamanho_maior_vetor = 0;
            for (auto vec : atividades_por_dia) if (tamanho_maior_vetor < vec.size()){
                tamanho_maior_vetor = vec.size();
                std::sort(vec.begin(), vec.end(), comparar_atividades);
            }
            for (unsigned i = 0; i < tamanho_maior_vetor; i++){
                for (unsigned j = 0; j < 7; j++){
                    if (atividades_por_dia[j].size() <= i) strstream << setw(35) << left << "";
                    else strstream << setw(35) << left << atividades_por_dia[j][i].to_string();
                }
                strstream << "\n";
            }
        }
        return strstream.str();
    }

}