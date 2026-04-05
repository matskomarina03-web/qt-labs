#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
class DatabaseManager
{
public:
    DatabaseManager();
    bool open();
    void init();
    QSqlDatabase getDB() const;

private:
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
