#include "passwordrepository.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QList>

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

QList<PasswordItem> PasswordRepository::getAll()
{
    QList<PasswordItem> list;
    QSqlQuery query(db);

    query.exec("SELECT * FROM passwords");

    while (query.next()) {
        PasswordItem item;
        item.id = query.value("id").toInt();
        item.title = query.value("title").toString();
        item.username = query.value("username").toString();
        item.password = query.value("password").toString();
        item.website = query.value("website").toString();
        item.category = query.value("category").toString();
        item.updatedAt = query.value("updated_at").toString();

        list.append(item);
    }

    return list;
}
bool PasswordRepository::add(const PasswordItem &item)
{
    QSqlQuery query(db);

    query.prepare(
        "INSERT INTO passwords (title, username, password, website, category, updated_at) "
        "VALUES (:title, :username, :password, :website, :category, :updated_at)"
        );

    query.bindValue(":title", item.title);
    query.bindValue(":username", item.username);
    query.bindValue(":password", item.password);
    query.bindValue(":website", item.website);
    query.bindValue(":category", item.category);
    query.bindValue(":updated_at", item.updatedAt);

    return query.exec();
}

bool PasswordRepository::update(const PasswordItem &item)
{
    QSqlQuery query(db);

    query.prepare(
        "UPDATE passwords SET "
        "title=:title, "
        "username=:username, "
        "password=:password, "
        "website=:website, "
        "category=:category, "
        "updated_at=:updated_at "
        "WHERE id=:id"
        );

    query.bindValue(":id", item.id);
    query.bindValue(":title", item.title);
    query.bindValue(":username", item.username);
    query.bindValue(":password", item.password);
    query.bindValue(":website", item.website);
    query.bindValue(":category", item.category);
    query.bindValue(":updated_at", item.updatedAt);

    return query.exec();
}
