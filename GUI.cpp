//
// Created by Paula on 6/18/2023.
//

#include "GUI.h"

void GUI::init(){
    setLayout(main);

    QVBoxLayout* adaugare=new QVBoxLayout;
    main->addLayout(adaugare);
    adaugare->addWidget(new QLabel("ID:"));
    adaugare->addWidget(id);
    adaugare->addWidget(new QLabel("Dimensiune:"));
    adaugare->addWidget(dim);
    adaugare->addWidget(new QLabel("---"));
    adaugare->addWidget(new QLabel("Tabela noua:"));
    adaugare->addWidget(tabela);
    adaugare->addWidget(new QLabel("Jucator nou:"));
    adaugare->addWidget(jucator);
    adaugare->addWidget(new QLabel("Stare noua:"));
    adaugare->addWidget(stare);
    adaugare->addWidget(adauga);
    adaugare->addWidget(modifica);
    adaugare->addWidget(creeazaTabela);




    model=new MyTableModel(service);
    tableview->setModel(model);

    main->addWidget(tableview);
}

void GUI::reloadTable() {
    auto vect=this->service.listaJocuriSortate();
    model->setProducts(vect);
}

void GUI::connect() {
    QObject::connect(adauga,&QPushButton::clicked,[&](){
        int idc=id->text().toInt();
        int dimc=dim->text().toInt();
        this->service.adaugaJocNou(idc,dimc);
        reloadTable();
    });
    QObject::connect(modifica,&QPushButton::clicked,[&](){
        int idc=id->text().toInt();
        int dimc=dim->text().toInt();
        std::string tabelac=tabela->text().toStdString();
        std::string jucatorc=jucator->text().toStdString();
        std::string starec=stare->text().toStdString();

        this->service.modificaJoc(idc,dimc,tabelac,jucatorc,starec);
        reloadTable();
    });

    QObject::connect(creeazaTabela,&QPushButton::clicked,[&](){
        int idc=id->text().toInt();
        auto j=this->service.cautaJoc(idc);
        TabelaJoc* tj=new TabelaJoc(j,service);
        id->clear();
        tj->show();
    });

}

void TabelaJoc::init() {
    setLayout(main);
    int index=0;
    for(int i=0;i<j.getDim();i++) {
        QVBoxLayout *c1 = new QVBoxLayout;
        main->addLayout(c1);
        for(int k=0;k<j.getDim();k++){
            auto semn=j.getTabela()[index+k];
            std::string str;
            str.push_back(semn);
            QPushButton* b=new QPushButton(QString::fromStdString(str));
            c1->addWidget(b);
            butoane.push_back(b);
        }
        index+=j.getDim();
    }
}

void TabelaJoc::connect(){
    for(int i=0;i<butoane.size();i++){
        QObject::connect(butoane[i],&QPushButton::clicked,[=](){
            if(butoane[i]->text()=="X" or butoane[i]->text()=="O"){
                QMessageBox::information(nullptr,"Eroare!","Nu poti selecta un buton inscriptionat deja cu X sau O.");
            }
            else{
                butoane[i]->setText(QString::fromStdString(j.getJucator()));
                if(j.getJucator()=="X")
                    j.setJucator("O");
                else
                    j.setJucator("X");
                this->service.modificaJocDiferit(j);
            }

        });

    }
}