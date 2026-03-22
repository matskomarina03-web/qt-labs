#ifndef CSVTICKETREPOSITORY_H
#define CSVTICKETREPOSITORY_H
#include <QString>
#include <QList>
#include "ticket.h"
class csvticketrepository
{
public:
    csvticketrepository(const QString &filePath);
    QList<Ticket> loadTickets();
    void saveTickets(const QList<Ticket> &tickets);
    int nextId();
private:
    QString m_filePath;
    int m_nextId;
};

#endif // CSVTICKETREPOSITORY_H
