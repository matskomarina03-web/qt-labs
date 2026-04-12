#ifndef PASSWORDITEM_H
#define PASSWORDITEM_H

#include <QString>

struct PasswordItem
{
    int id = 0;
    QString title;
    QString username;
    QString password;
    QString website;
    QString category;
    QString updatedAt;
};

#endif // PASSWORDITEM_H
