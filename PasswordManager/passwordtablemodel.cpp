#include "passwordtablemodel.h"

PasswordTableModel::PasswordTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}
QVariant PasswordTableModel::headerData(int section,
                                        Qt::Orientation orientation,
                                        int role) const
{
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole)
        return {};

    switch (section)
    {
    case 0: return "ID";
    case 1: return "Title";
    case 2: return "Username";
    case 3: return "Password";
    case 4: return "Website";
    case 5: return "Category";
    case 6: return "Updated";
    }

    return {};
}
void PasswordTableModel::setItems(const QList<PasswordItem> &list)
{
    beginResetModel();
    items = list;
    endResetModel();
}

void PasswordTableModel::setRepository(PasswordRepository *r)
{
    repo = r;
}

int PasswordTableModel::rowCount(const QModelIndex &) const
{
    return items.size();
}

int PasswordTableModel::columnCount(const QModelIndex &) const
{
    return 7;
}

QVariant PasswordTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return {};

    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return {};

    const PasswordItem &item = items[index.row()];

    switch (index.column())
    {
    case 0: return item.id;
    case 1: return item.title;
    case 2: return item.username;
    case 3: return item.password;
    case 4: return item.website;
    case 5: return item.category;
    case 6: return item.updatedAt;
    }

    return {};
}


bool PasswordTableModel::setData(const QModelIndex &index,
                                 const QVariant &value,
                                 int role)
{
    if (!index.isValid() || role != Qt::EditRole)
        return false;

    PasswordItem &item = items[index.row()];

    switch (index.column())
    {
    case 1: item.title = value.toString(); break;
    case 2: item.username = value.toString(); break;
    case 3: item.password = value.toString(); break;
    case 4: item.website = value.toString(); break;
    case 5: item.category = value.toString(); break;
    default: return false;
    }

    if (repo)
        repo->update(item);
    if (index.row() < 0 || index.row() >= items.size())
        return false;
    if (value.toString().isEmpty())
        return false;

    emit dataChanged(index, index);
    return true;
}
PasswordItem PasswordTableModel::getItem(int row) const
{
    return items[row];
}
QModelIndex PasswordTableModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    return createIndex(row, column);
}
Qt::ItemFlags PasswordTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    if (index.column() == 0)
        return Qt::ItemIsSelectable | Qt::ItemIsEnabled;

    return Qt::ItemIsSelectable |
           Qt::ItemIsEnabled |
           Qt::ItemIsEditable;
}
QList<PasswordItem> PasswordTableModel::getItems() const
{
    return items;
}
