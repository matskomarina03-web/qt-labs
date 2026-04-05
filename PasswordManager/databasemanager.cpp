#include "databasemanager.h"

DatabaseManager::DatabaseManager() {}

bool DatabaseManager::open()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("passwords.db");

    if (!db.open()) {
        qDebug() << "DB error:" << db.lastError().text();
        return false;
    }
    return true;
}

void DatabaseManager::init()
{
    QSqlQuery q(db);
    q.exec(
        "CREATE TABLE IF NOT EXISTS passwords ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "title TEXT,"
        "username TEXT,"
        "password TEXT,"
        "website TEXT,"
        "category TEXT,"
        "updated_at TEXT)"
        );
}

QSqlDatabase DatabaseManager::getDB() const
{
    return db;
}
