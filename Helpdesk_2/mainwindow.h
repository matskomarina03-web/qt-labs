#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "ticket.h"
#include "tickettablemodel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onNewTicket();
    void onViewTicket();
    void onEditTicket();
    void onDeleteTicket();
    void updateActions();

private:
    Ui::mainwindow *ui;
    TicketTableModel *model;
};

#endif // MAINWINDOW_H
