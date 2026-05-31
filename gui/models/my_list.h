//
// Created by Alexandra on 5/22/2026.
//

#ifndef ADMINISTRATORBLOC_MY_LIST_H
#define ADMINISTRATORBLOC_MY_LIST_H

#include <QAbstractListModel>
#include <vector>
#include <QDebug>
#include "../../domain/locatar.h"
#include <iostream>
using std::vector;

class MyListModel : public QAbstractListModel {
private:
    vector<Locatar> locatari;
public:
    MyListModel(const vector<Locatar>& _locatari) : locatari(_locatari) {}

    [[nodiscard]] int rowCount(const QModelIndex& parent = QModelIndex()) const override
    {
        Q_UNUSED(parent);
        return static_cast<int>(locatari.size());
    }

    [[nodiscard]] QVariant data(const QModelIndex& index, int role) const override
    {
        //std::cout<<"data called\n";
        qDebug()<<"data called\n";
        if (!index.isValid()) return {};
        if (index.row() < 0 || index.row() >= static_cast<int>(locatari.size())) return {};

        if (role == Qt::DisplayRole)
        {
            auto& l = locatari[static_cast<size_t>(index.row())];
            QString text = QString("%1 | %2 | %3 | %4")
            .arg(l.get_apartment())
            .arg(QString::fromStdString(l.get_nume()))
            .arg(l.get_suprafata())
            .arg(QString::fromStdString(l.get_tip()));

            return text;
        }
        return {};
    }

    [[nodiscard]] QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override
    {
        if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
        {
            if (section == 0)
            {
                return "Lista Locatari";
            }
        }
        return {};
    }

    void setLocatari(const vector<Locatar>& new_locatari)
    {
        beginResetModel();
        locatari = new_locatari;
        endResetModel();
    }
};

#endif //ADMINISTRATORBLOC_MY_LIST_H
