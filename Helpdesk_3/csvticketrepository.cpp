#include "csvticketrepository.h"
#include <QFile>
#include <QTextStream>
#include <QDate>
csvticketrepository::csvticketrepository(const QString &filePath)
    : m_filePath(filePath), m_nextId(1)
{
}

QVector<Ticket> csvticketrepository::loadTickets()
{
    QVector<Ticket> tickets;
    QFile file(m_filePath);

    if(!file.exists())
    {
        if(file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file);
            out << "ID,Title,Priority,Status,CreatedAt\n";
            file.close();
        }
        return tickets;
    }

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return tickets;

    QTextStream in(&file);
    in.setEncoding(QStringConverter::Utf8);
    QString header = in.readLine();

    while(!in.atEnd())
    {
        QString line = in.readLine();
        if(line.isEmpty()) continue;
        QStringList fields = line.split(",");
        if(fields.size() < 5) continue;

        Ticket t;
        t.id = fields[0].toInt();
        t.title = fields[1];
        t.priority = fields[2];
        t.status = fields[3];
        t.createdAt = QDate::fromString(fields[4], "yyyy-MM-dd");
        tickets.append(t);
    }

    return tickets;
}

void csvticketrepository::saveTickets(const QVector<Ticket> &tickets)
{
    QFile file(m_filePath);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8);
    out << "ID,Title,Priority,Status,CreatedAt\n";
    for(const Ticket &t : tickets)
    {
        out << t.id << "," << t.title << "," << t.priority << ","
            << t.status << "," << t.createdAt.toString("yyyy-MM-dd") << "\n";
    }
    file.close();
}



int csvticketrepository::nextId()
{
    return m_nextId++;
}
