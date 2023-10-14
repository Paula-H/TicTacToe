//
// Created by Paula on 6/18/2023.
//

#ifndef TICTACTOE_REPOSITORY_H
#define TICTACTOE_REPOSITORY_H

#include <map>
#include <fstream>
#include <vector>
#include "Joc.h"
class Repository{
private:
    std::map<int,Joc> jocuri;
    std::string fisier;
public:
    Repository(std::string fisier):fisier{fisier}{
        citesteDinFisier();
    }
    ~Repository()=default;

    void citesteDinFisier(){
        std::ifstream f(fisier);
        int idc;
        int dimc;
        std::string tabelac;
        std::string jucatorc;
        std::string starec;
        while(f>>idc>>dimc>>tabelac>>jucatorc>>starec){
            Joc j=Joc(idc,dimc,tabelac,jucatorc,starec);
            jocuri.insert(std::make_pair(idc,j));
        }
        f.close();
    }

    void scriereInFisier(){
        std::ofstream f(fisier);
        f.clear();
        for(auto&el:jocuri){
            f<<el.second.to_string()<<std::endl;
        }
        f.close();
    }

    int numarJocuri(){
        return this->jocuri.size();
    }

    std::vector<Joc> listaJocuri(){
        std::vector<Joc> jocs;
        for(auto&el:this->jocuri)
            jocs.push_back(el.second);
        return jocs;
    }

    void adaugaJoc(Joc j){
        auto it=this->jocuri.find(j.getId());
        if(it!=jocuri.end())
            throw std::invalid_argument("Jocul se afla deja in Repository!");
        this->jocuri.insert(std::make_pair(j.getId(),j));
        scriereInFisier();
    }

    void stergeJoc(int id){
        auto it=this->jocuri.find(id);
        if(it==jocuri.end())
            throw std::invalid_argument("Jocul nu se afla in Repository!");
        this->jocuri.erase(id);
        scriereInFisier();
    }

    void modificaJoc(Joc j){
        auto it=this->jocuri.find(j.getId());
        if(it==jocuri.end())
            throw std::invalid_argument("Jocul nu se afla in Repository!");
        this->jocuri.erase(j.getId());
        this->jocuri.insert(std::make_pair(j.getId(),j));
        scriereInFisier();
    }

    Joc cautaJoc(int id){
        auto it=this->jocuri.find(id);
        if(it==jocuri.end())
            throw std::invalid_argument("Jocul nu se afla in Repository!");
        auto j=*it;
        return j.second;
    }

};

#endif //TICTACTOE_REPOSITORY_H
