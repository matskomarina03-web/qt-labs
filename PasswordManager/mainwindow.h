#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QStandardItemModel>
#include <QMainWindow>
#include <QSqlTableModel>
#include "databasemanager.h"
#include <QSortFilterProxyModel>
#include "passwordrepository.h"
#include "passwordtablemodel.h"
#include <QFutureWatcher>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    PasswordTableModel *model;
    DatabaseManager dbManager;
    QSortFilterProxyModel *proxyModel;
    PasswordRepository *repo;
    QFutureWatcher<void> *watcher;

    int totalChecks = 0;
    int finishedChecks = 0;
    int safeCount = 0;
    int leakedCount = 0;


private slots:
    void onNewTriggered();
    void onEditTriggered();
    void onDeleteTriggered();
    void onSaveTriggered();
    void PasswordVerification();
    void onCheckAll();
};
#endif // MAINWINDOW_H
