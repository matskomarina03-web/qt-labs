#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "ui_mainwindow.h"
#include "ticket.h"
#include "tickettablemodel.h"
#include "csvticketrepository.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addTicket(const QString &title, const QString &priority);
    void updateTable();

private slots:
    void onNewTicket();
    void onViewTicket();
    void onEditTicket();
    void onDeleteTicket();
    void updateActions();

    void filterTickets();
    void clearFilter();


private:
    Ui::mainwindow *ui;
    TicketTableModel *model;
    csvticketrepository m_repository;
    QList<Ticket> m_tickets;
};

#endif // MAINWINDOW_H
