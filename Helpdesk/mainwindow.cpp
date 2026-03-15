#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ticketdialog.h"
#include <QStandardItemModel>
#include <QDate>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainwindow)
{
    ui->setupUi(this);

    QStandardItemModel *model = new QStandardItemModel(this);
    model->setColumnCount(5);
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Title");
    model->setHeaderData(2, Qt::Horizontal, "Status");
    model->setHeaderData(3, Qt::Horizontal, "Priority");
    model->setHeaderData(4, Qt::Horizontal, "Created");

    ui->tableTickets->setModel(model);
    model->appendRow({
        new QStandardItem("1"),
        new QStandardItem("Printer not working"),
        new QStandardItem("Open"),
        new QStandardItem("High"),
        new QStandardItem("2026-03-09")
    });

    connect(ui->actionNew, &QAction::triggered, this, [this, model](){

        TicketDialog dialog(this);

        dialog.setMode(TicketDialog::New);

        dialog.setTicketData({
            QString::number(model->rowCount()+1),
            "",
            "",
            "Open",
            "Medium",
            QDate::currentDate().toString("yyyy-MM-dd")
        });

        if(dialog.exec() == QDialog::Accepted)
        {
            QStringList data = dialog.getTicketData();

            model->appendRow({
                new QStandardItem(data[0]), // ID
                new QStandardItem(data[1]), // Title
                new QStandardItem(data[3]), // Status
                new QStandardItem(data[4]), // Priority
                new QStandardItem(data[5])  // Created
            });
        }
    });

    connect(ui->actionView, &QAction::triggered, this, [this, model](){
        auto selected = ui->tableTickets->selectionModel()->selectedRows();
        if(selected.isEmpty()) return;
        int row = selected.first().row();
        QStringList data;
        for(int c = 0; c < model->columnCount(); ++c)
            data << model->item(row, c)->text();

        TicketDialog dialog(this);
        dialog.setMode(TicketDialog::View);
        dialog.setTicketData(data);
        dialog.show();
    });

    connect(ui->actionEdit, &QAction::triggered, this, [this, model](){
        auto selected = ui->tableTickets->selectionModel()->selectedRows();
        if(selected.isEmpty()) return;
        int row = selected.first().row();
        QStringList data;
        for(int c = 0; c < model->columnCount(); ++c)
            data << model->item(row, c)->text();

        TicketDialog dialog(this);
        dialog.setMode(TicketDialog::Edit);
        dialog.setTicketData(data);
        if(dialog.exec() == QDialog::Accepted) {
            QStringList newData = dialog.getTicketData();
            model->item(row, 1)->setText(newData[1]);
            model->item(row, 2)->setText(newData[3]);
            model->item(row, 3)->setText(newData[4]);
        }
    });
    connect(ui->tableTickets->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, [this](){
                bool hasSelection = !ui->tableTickets->selectionModel()->selectedRows().isEmpty();
                ui->actionView->setEnabled(hasSelection);
                ui->actionEdit->setEnabled(hasSelection);
                ui->actionDelete->setEnabled(hasSelection);
            });

    connect(ui->actionDelete, &QAction::triggered, this, [this, model](){
        auto selected = ui->tableTickets->selectionModel()->selectedRows();
        for(auto index : selected)
            model->removeRow(index.row());
    });

    connect(ui->actionExit, &QAction::triggered, this, &QWidget::close);
    connect(ui->actionAbout, &QAction::triggered, this, [this](){
        QMessageBox::about(this, "About", "Helpdesk system example");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
