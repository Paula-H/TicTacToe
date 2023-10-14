//
// Created by Paula on 6/18/2023.
//

#ifndef TICTACTOE_VALIDATOR_H
#define TICTACTOE_VALIDATOR_H

#include "Joc.h"
#include <stdexcept>
class Validator{
private:
    Joc j;
public:
    Validator(Joc&j):j{j}{}
    ~Validator()=default;
    void valideaza(){
        std::string erori;
        if(j.getDim()!=3 && j.getDim()!=4 && j.getDim()!=5)
            erori+="Dimensiunea poate fi doar 3, 4 sau 5!\n";
        if(j.getTabela().size()!=j.getDim()*j.getDim())
            erori+="Tabela nu are dimensiune corecta!\n";
        if(j.getJucator()!="X" && j.getJucator()!="O")
            erori+="Jucator invalid!\n";
        if(j.getStare()!="Terminat"&&j.getStare()!="Neinceput"&&j.getStare()!="In-derulare")
            erori+="Stare invalida!\n";
        if(!erori.empty())
            throw std::invalid_argument(erori);
    }
};

#endif //TICTACTOE_VALIDATOR_H
