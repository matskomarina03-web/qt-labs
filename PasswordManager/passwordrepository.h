#ifndef PASSWORDREPOSITORY_H
#define PASSWORDREPOSITORY_H
#include <QSqlDatabase>
#include "passworditem.h"

class PasswordRepository {
public:
    PasswordRepository(const QSqlDatabase &db);

    bool remove(int id);
    QList<PasswordItem> getAll();
    bool update(const PasswordItem &item);
    bool add(const PasswordItem &item);

private:
    QSqlDatabase db;
};
#endif // PASSWORDREPOSITORY_H
