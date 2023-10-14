//
// Created by Paula on 6/18/2023.
//

#ifndef TICTACTOE_JOC_H
#define TICTACTOE_JOC_H
#include <string>

class Joc{
private:
    int id;
    int dim;
    std::string tabela;
    std::string jucator;
    std::string stare;
public:
    Joc(int id,int dim,std::string tabela,std::string jucator,std::string stare):id{id},dim{dim},tabela{tabela},jucator{jucator},stare{stare}{}
    ~Joc()=default;

    int getId(){
        return this->id;
    }

    int getDim(){
        return this->dim;
    }

    std::string getTabela(){
        return this->tabela;
    }

    std::string getJucator(){
        return this->jucator;
    }

    void setJucator(std::string jucator){
        this->jucator=jucator;
    }

    std::string getStare(){
        return this->stare;
    }

    std::string to_string(){
        return std::to_string(this->id)+" "+std::to_string(this->dim)+" "+this->tabela+" "+this->jucator+" "+this->stare;
    }
};


#endif //TICTACTOE_JOC_H
