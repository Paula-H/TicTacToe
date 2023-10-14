//
// Created by Paula on 6/18/2023.
//

#ifndef TICTACTOE_GUI_H
#define TICTACTOE_GUI_H

#include "Service.h"
#include <QApplication>
#include <QPushButton>
#include <QObject>
#include <QSignalMapper>
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QFormLayout>
#include <QListWidget>
#include <QString>
#include <QMessageBox>
#include <QTableWidget>
#include <QTableView>
#include <QTableWidgetItem>
#include <QPainter>
#include <QMessageBox>
#include "MyTableWidget.h"
#include <QStringList>
#include <QSlider>
#include <QPainter>
#include <vector>
#include <string>
#include <iostream>
#include <qdebug.h>

class TabelaJoc:public QWidget{
private:
    Joc j;
    Service service;
    std::vector<QPushButton*> butoane;
    QHBoxLayout* main=new QHBoxLayout;
public:
    TabelaJoc(Joc&j,Service&service):j{j},service{service}{
        init();
        connect();
    }
    void init();
    void connect();
};

class GUI:public QWidget{
    Q_OBJECT
private:
    Service service;
    QHBoxLayout* main=new QHBoxLayout();

    MyTableModel* model;
    QTableView* tableview= new QTableView;

    QLineEdit* id=new QLineEdit;
    QLineEdit* dim=new QLineEdit;
    QPushButton* adauga=new QPushButton("Adauga un joc nou.");
    QLineEdit* tabela=new QLineEdit;
    QLineEdit* jucator=new QLineEdit;
    QLineEdit* stare=new QLineEdit;
    QPushButton* modifica=new QPushButton("Modifica un joc deja existent.");
    QPushButton* creeazaTabela=new QPushButton("Deschide Jocul.");



public:
    GUI(Service&service):service{service}{
        init();
        connect();
    }
    ~GUI()=default;
    void init();
    void connect();
    void reloadTable();
};

#endif //TICTACTOE_GUI_H
