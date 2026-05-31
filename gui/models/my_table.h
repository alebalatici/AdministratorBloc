#ifndef ADMINISTRATORBLOC_MY_TABLE_H
#define ADMINISTRATORBLOC_MY_TABLE_H
#include <QAbstractTableModel>
#include <vector>
#include "../../domain/locatar.h"
using std::vector;
class MyTableModel : public QAbstractTableModel {
private:
    vector<Locatar> locatari;
public:
    MyTableModel(const vector<Locatar>& _locatari) : locatari(_locatari) {}
    [[nodiscard]] int rowCount(const QModelIndex& parent) const override
    {
        Q_UNUSED(parent);
        return int(locatari.size());
    }
    [[nodiscard]] int columnCount(const QModelIndex& parent) const override
    {
        Q_UNUSED(parent);
        return 4;
    }

    [[nodiscard]] QVariant data(const QModelIndex& index, int role) const override
    {
        if (!index.isValid()) return {};
        if (index.row() < 0 || index.row() >= static_cast<int>(locatari.size())) return {};
        if (role == Qt::DisplayRole)
        {
            auto& l = locatari[static_cast<size_t>(index.row())];
            if (index.column() == 0) return QString::number(l.get_apartment());
            if (index.column() == 1) return QString::fromStdString(l.get_nume());
            if (index.column() == 2) return QString::number(l.get_suprafata());
            if (index.column() == 3) return QString::fromStdString(l.get_tip());
        }
        return {};
    }

    [[nodiscard]] QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override
    {
        if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
        {
            if (section == 0) return "Apartament";
            if (section == 1) return "Nume";
            if (section == 2) return "Suprafata";
            if (section == 3) return "Tip";
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



#endif //ADMINISTRATORBLOC_MY_TABLE_H
