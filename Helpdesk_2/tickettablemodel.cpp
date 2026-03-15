#include "tickettablemodel.h"

TicketTableModel::TicketTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int TicketTableModel::rowCount(const QModelIndex &) const
{
    return tickets.size();
}

int TicketTableModel::columnCount(const QModelIndex &) const
{
    return 5;
}

QVariant TicketTableModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || role != Qt::DisplayRole) return QVariant();

    const Ticket &t = tickets[index.row()];

    switch(index.column())
    {
    case 0: return t.id;
    case 1: return t.title;
    case 2: return t.priority;
    case 3: return t.status;
    case 4: return t.createdAt.toString("yyyy-MM-dd");
    }
    return QVariant();
}

QVariant TicketTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole || orientation != Qt::Horizontal) return QVariant();

    switch(section)
    {
    case 0: return "ID";
    case 1: return "Title";
    case 2: return "Priority";
    case 3: return "Status";
    case 4: return "CreatedAt";
    }
    return QVariant();
}
void TicketTableModel::addTicket(const Ticket &t)
{
    tickets.append(t);
}

void TicketTableModel::updateTicket(int row, const Ticket &t)
{
    if(row < 0 || row >= tickets.size()) return;
    tickets[row] = t;
}
void TicketTableModel::removeTicket(int row)
{
    if(row < 0 || row >= tickets.size()) return;
    tickets.removeAt(row);
}
Ticket TicketTableModel::getTicket(int row) const
{
    if(row < 0 || row >= tickets.size()) return Ticket();
    return tickets[row];
}
