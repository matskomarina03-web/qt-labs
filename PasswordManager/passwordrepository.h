#ifndef PASSWORDREPOSITORY_H
#define PASSWORDREPOSITORY_H
#include <QSqlDatabase>

class PasswordRepository {
public:
    PasswordRepository(const QSqlDatabase &db);

    bool remove(int id);

private:
    QSqlDatabase db;
};
#endif // PASSWORDREPOSITORY_H
