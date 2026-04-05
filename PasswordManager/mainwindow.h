#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QStandardItemModel>
#include <QMainWindow>
#include <QSqlTableModel>
#include "databasemanager.h"
#include "passwordrepository.h"
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
    QSqlTableModel *model;
    DatabaseManager dbManager;
    PasswordRepository *repository;

private slots:
    void onNewTriggered();
    void onEditTriggered();
    void onDeleteTriggered();
    void onSaveTriggered();
};
#endif // MAINWINDOW_H
