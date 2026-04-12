#ifndef PASSWORDTABLEMODEL_H
#define PASSWORDTABLEMODEL_H
#include <QAbstractTableModel>
#include <QList>
#include "passworditem.h"
#include "passwordrepository.h"

class PasswordTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    PasswordTableModel(QObject *parent = nullptr);

    void setItems(const QList<PasswordItem> &items);
    void setRepository(PasswordRepository *repo);

    int rowCount(const QModelIndex &) const override;
    int columnCount(const QModelIndex &) const override;
    QVariant data(const QModelIndex &, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    bool setData(const QModelIndex &, const QVariant &, int role) override;
    PasswordItem getItem(int row) const;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QList<PasswordItem> getItems() const;

private:
    QList<PasswordItem> items;
    PasswordRepository *repo;
};

#endif // PASSWORDTABLEMODEL_H
