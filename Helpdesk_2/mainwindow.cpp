#include "mainwindow.h"
#include "ticketdialog.h"
#include <QMessageBox>
#include <QDate>
#include <QItemSelectionModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainwindow)
{
    ui->setupUi(this);
    model = new TicketTableModel(this);
    model->addTicket({1, "Printer problem", "High", "Open", QDate::currentDate()});
    model->addTicket({2, "Internet down", "Medium", "Open", QDate::currentDate()});
    model->addTicket({3, "Computer slow", "Low", "Closed", QDate::currentDate()});
    model->addTicket({4, "Keyboard broken", "Medium", "Open", QDate::currentDate()});
    model->addTicket({5, "Software error", "High", "Open", QDate::currentDate()});
    ui->tableTickets->setModel(model);
    ui->tableTickets->setSelectionBehavior(QAbstractItemView::SelectRows);

    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::onNewTicket);
    connect(ui->actionView, &QAction::triggered, this, &MainWindow::onViewTicket);
    connect(ui->actionEdit, &QAction::triggered, this, &MainWindow::onEditTicket);
    connect(ui->actionDelete, &QAction::triggered, this, &MainWindow::onDeleteTicket);
    connect(ui->tableTickets->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &MainWindow::updateActions);

    updateActions();

    connect(ui->actionExit, &QAction::triggered, this, &QWidget::close);
    connect(ui->actionAbout, &QAction::triggered, [this](){
        QMessageBox::about(this, "About", "Helpdesk example with TicketTableModel");
    });
}

void MainWindow::onNewTicket()
{
    TicketDialog dialog(this);
    dialog.setMode(2);
    Ticket t;
    t.id = model->rowCount() + 1;
    t.status = "Open";
    t.priority = "Medium";
    t.createdAt = QDate::currentDate();
    dialog.setTicketData({QString::number(t.id), "", "", t.status, t.priority, t.createdAt.toString("yyyy-MM-dd")});

    if(dialog.exec() == QDialog::Accepted)
    {
        QStringList data = dialog.getTicketData();
        t.title = data[1];
        t.status = data[3];
        t.priority = data[4];
        model->addTicket(t);
    }
}

void MainWindow::onViewTicket()
{
    auto selected = ui->tableTickets->selectionModel()->selectedRows();
    if(selected.isEmpty()) return;

    int row = selected.first().row();
    Ticket t = model->getTicket(row);

    TicketDialog dialog(this);
    dialog.setMode(0);
    dialog.setTicketData({QString::number(t.id), t.title, "", t.status, t.priority, t.createdAt.toString("yyyy-MM-dd")});
    dialog.exec();
}

void MainWindow::onEditTicket()
{
    auto selected = ui->tableTickets->selectionModel()->selectedRows();
    if(selected.isEmpty()) return;

    int row = selected.first().row();
    Ticket t = model->getTicket(row);

    TicketDialog dialog(this);
    dialog.setMode(1);
    dialog.setTicketData({QString::number(t.id), t.title, "", t.status, t.priority, t.createdAt.toString("yyyy-MM-dd")});

    if(dialog.exec() == QDialog::Accepted)
    {
        QStringList data = dialog.getTicketData();
        t.title = data[1];
        t.status = data[3];
        t.priority = data[4];
        model->updateTicket(row, t);
    }
}

void MainWindow::onDeleteTicket()
{
    auto selected = ui->tableTickets->selectionModel()->selectedRows();
    if(selected.isEmpty()) return;

    int row = selected.first().row();
    model->removeTicket(row);
}

void MainWindow::updateActions()
{
    bool hasSelection = !ui->tableTickets->selectionModel()->selectedRows().isEmpty();
    ui->actionView->setEnabled(hasSelection);
    ui->actionEdit->setEnabled(hasSelection);
    ui->actionDelete->setEnabled(hasSelection);
}

MainWindow::~MainWindow()
{
    delete ui;
}
