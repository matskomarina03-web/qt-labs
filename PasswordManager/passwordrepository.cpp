#include "passwordrepository.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

PasswordRepository::PasswordRepository(const QSqlDatabase &database)
    : db(database)
{
}

bool PasswordRepository::remove(int id)
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM passwords WHERE id=:id");
    query.bindValue(":id", id);

    return query.exec();
}
