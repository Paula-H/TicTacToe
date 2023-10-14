//
// Created by Paula on 6/18/2023.
//

#include "Testing.h"
#include "Joc.h"
#include "Repository.h"
#include "Service.h"
#include "Validator.h"
#include <string.h>
#include <cassert>

void Testing::testJoc() {
    Joc joc=Joc(1,3,"X-OXO-XOO","X","Terminat");
    assert(joc.getId()==1);
    assert(joc.getDim()==3);
    assert(joc.getTabela()=="X-OXO-XOO");
    assert(joc.getJucator()=="X");
    assert(joc.getStare()=="Terminat");
    assert(joc.to_string()=="1 3 X-OXO-XOO X Terminat");
}

void Testing::testRepository() {
    Repository repository= Repository("D:\\OOP_Laboratoare\\TicTacToe\\dummiFile.txt");
    assert(repository.numarJocuri()==3);
    assert(repository.listaJocuri().size()==3);

    Joc j=Joc(1,3,"X-OXO-XOO","X","Terminat");
    try{
        repository.adaugaJoc(j);
    }
    catch(std::invalid_argument&msg){
        assert(!strcmp(msg.what(),"Jocul se afla deja in Repository!"));
    }
    Joc j1=Joc(4,3,"X-OXO-XOO","X","Terminat");
    repository.adaugaJoc(j1);
    assert(repository.numarJocuri()==4);
    repository.stergeJoc(4);
    assert(repository.numarJocuri()==3);
    try{
        repository.stergeJoc(4);
    }
    catch(std::invalid_argument&msg){
        assert(!strcmp(msg.what(),"Jocul nu se afla in Repository!"));
    }
    Joc j2=Joc(1,3,"XXOXO-XOO","X","Terminat");
    repository.modificaJoc(j2);
    assert(repository.cautaJoc(1).getTabela()=="XXOXO-XOO");
    assert(repository.cautaJoc(1).getTabela()!="X-OXO-XOO");
    repository.modificaJoc(j);
    try{
        repository.modificaJoc(j1);
    }
    catch(std::invalid_argument&msg){
        assert(!strcmp(msg.what(),"Jocul nu se afla in Repository!"));
    }
    try{
        repository.cautaJoc(4);
    }
    catch(std::invalid_argument&msg){
        assert(!strcmp(msg.what(),"Jocul nu se afla in Repository!"));
    }

}

void Testing::testService() {
    Repository repository= Repository("D:\\OOP_Laboratoare\\TicTacToe\\dummiFile.txt");
    Service service= Service(repository);
    assert(service.listaJocuriSortate().size()==3);
    assert(service.listaJocuriSortate()[0].getId()==3);
    assert(service.listaJocuriSortate()[1].getId()==2);
}

void Testing::testValidator() {
    Joc j1=Joc(1,10,"X-OXO-XOO","X","Terminat");
    try{
        Validator(j1).valideaza();
    }
    catch(std::invalid_argument&msg){
        assert(!strcmp(msg.what(),"Dimensiunea poate fi doar 3, 4 sau 5!\nTabela nu are dimensiune corecta!\n"));
    }
    Joc j2=Joc(1,3,"X-OXO-","X","Terminat");
    try{
        Validator(j2).valideaza();
    }
    catch(std::invalid_argument&msg){
        assert(!strcmp(msg.what(),"Tabela nu are dimensiune corecta!\n"));
    }
}
