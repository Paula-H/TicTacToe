//
// Created by Paula on 6/18/2023.
//

#ifndef TICTACTOE_SERVICE_H
#define TICTACTOE_SERVICE_H

#include "Repository.h"
#include "Validator.h"

class Service{
private:
    Repository repository;
public:
    Service(Repository& repository): repository{repository}{}
    ~Service()=default;

    std::vector<Joc> listaJocuriSortate(){
        auto lista=this->repository.listaJocuri();
        for(int i=0;i<lista.size();i++){
            for(int j=0;j<lista.size();j++) {
                if (lista[i].getStare() < lista[j].getStare())
                    std::swap(lista[i], lista[j]);

            }
        }
        return lista;
    }

    void adaugaJocNou(int id,int dim){
        std::string tabela;
        if(dim==3)
            tabela="---------";
        else if(dim==4)
            tabela="----------------";
        else if(dim==5)
            tabela="-------------------------";
        else{
            throw std::invalid_argument("Dimensiune incorecta!");
        }
        Joc j=Joc(id,dim,tabela,"X","Neinceput");
        Validator(j).valideaza();
        this->repository.adaugaJoc(j);
    }

    void modificaJoc(int id,int dim,std::string tabela,std::string jucator,std::string stare){
        Joc j= Joc(id,dim,tabela,jucator,stare);
        Validator(j).valideaza();
        this->repository.modificaJoc(j);
    }

    Joc cautaJoc(int id){
        return this->repository.cautaJoc(id);
    }

    void modificaJocDiferit(Joc j){
        this->repository.modificaJoc(j);
    }


};

#endif //TICTACTOE_SERVICE_H
