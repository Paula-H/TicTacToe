//
// Created by Paula on 6/18/2023.
//

#ifndef TICTACTOE_MYTABLEWIDGET_H
#define TICTACTOE_MYTABLEWIDGET_H

#include <QAbstractTableModel>
#include <vector>
#include "Joc.h"
#include "Service.h"
#include <QAbstractItemView>
#include <iostream>

class MyTableModel : public QAbstractTableModel {
    std::vector<Joc> jocuri;
    Service service;
public:
    MyTableModel(Service&service) : service{service} {
        this->jocuri=this->service.listaJocuriSortate();
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        return jocuri.size();
    }

    int columnCount(const QModelIndex &parent = QModelIndex()) const override {
        return 5;
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
        if (role == Qt::DisplayRole) {
            Joc prd = jocuri[index.row()];
            if (index.column() == 0) {
                return QString::fromStdString(std::to_string(prd.getId()));
            }
            if (index.column() == 1) {
                return QString::fromStdString(std::to_string(prd.getDim()));
            }
            if (index.column() == 2) {
                return QString::fromStdString(prd.getTabela());
            }
            if (index.column() == 3) {
                return QString::fromStdString(prd.getJucator());
            }
            if (index.column() == 4) {
                return QString::fromStdString(prd.getStare());
            }
        }
        return QVariant{};

    }

    QVariant headerData(int section, Qt::Orientation orientation, int role) const {
        if (orientation == Qt::Horizontal) {
            if (role == Qt::DisplayRole)
                switch (section) {
                    case 0:
                        return "ID";
                        break;
                    case 1:
                        return "Dimensiune";
                        break;
                    case 2:
                        return "Tabela";
                        break;
                    case 3:
                        return "Jucator";
                        break;
                    case 4:
                        return "Stare";
                        break;
                    default:
                        return QString("Column %1").arg(section + 1);
                        break;
                }
        } else if (orientation == Qt::Vertical) {
            if (role == Qt::DisplayRole)
                return section + 1;
        }

        return QVariant();
    }

    Joc getJoc(const QModelIndex &index) {
        return jocuri[index.row()];
    }

    void setProducts(std::vector<Joc> &productss) {
        this->jocuri = productss;
        QModelIndex topLeft = createIndex(0, 0);
        QModelIndex bottomRight = createIndex(rowCount(), columnCount());
        emit dataChanged(topLeft, bottomRight);//notify ca la observer
        emit layoutChanged();
    }

};

#endif //TICTACTOE_MYTABLEWIDGET_H
