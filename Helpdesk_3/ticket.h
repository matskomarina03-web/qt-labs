#ifndef TICKET_H
#define TICKET_H
#include <QString>
#include <QDate>


struct Ticket
    {
        int id;             // ID заявки
        QString title;      // назва проблеми
        QString priority;   // пріоритет
        QString status;     // статус
        QDate createdAt;    // дата створення
};

#endif // TICKET_H
