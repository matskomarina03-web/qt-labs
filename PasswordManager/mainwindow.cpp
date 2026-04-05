#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QDebug>
#include "databasemanager.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dbManager.open();
    dbManager.init();

    QSqlDatabase db = dbManager.getDB();
    repository = new PasswordRepository(db);
    model = new QSqlTableModel(this, db);
    model->setTable("passwords");
    model->select();

    connect(ui->actionExit_2, &QAction::triggered, this, &QWidget::close);
    ui->tableInfo->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableInfo->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->tableInfo->setEditTriggers(
        QAbstractItemView::DoubleClicked |
        QAbstractItemView::EditKeyPressed |
        QAbstractItemView::SelectedClicked
        );
    connect(ui->actionNew_Entry, &QAction::triggered, this, &MainWindow::onNewTriggered);
    connect(ui->actionEdit, &QAction::triggered, this, &MainWindow::onEditTriggered);
    connect(ui->actionDelete, &QAction::triggered, this, &MainWindow::onDeleteTriggered);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::onSaveTriggered);

    ui->tableInfo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Title");
    model->setHeaderData(2, Qt::Horizontal, "Username");
    model->setHeaderData(3, Qt::Horizontal, "Password");
    model->setHeaderData(4, Qt::Horizontal, "Website");
    model->setHeaderData(5, Qt::Horizontal, "Category");
    model->setHeaderData(6, Qt::Horizontal, "UpdatedAt");
    ui->tableInfo->setModel(model);
}

void MainWindow::onEditTriggered()
{
    QModelIndex current = ui->tableInfo->currentIndex();
    if (!current.isValid()) return;

    ui->tableInfo->edit(current);
}

void MainWindow::onDeleteTriggered()
{
    QModelIndex current = ui->tableInfo->currentIndex();
    if (!current.isValid()) return;

    int row = current.row();
    int id = model->data(model->index(row, 0)).toInt();

    auto answer = QMessageBox::question(
        this,
        "Delete",
        "Delete selected record?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (answer == QMessageBox::Yes)
    {
        repository->remove(id);
        model->select();
    }
}
void MainWindow::onNewTriggered()
{
    int row = model->rowCount();
    model->insertRow(row);
    ui->tableInfo->selectRow(row);
}

void MainWindow::onSaveTriggered()
{
    if (model->submitAll())
    {
        QMessageBox::information(this, "Save", "Saved!");
        model->select();
    }
    else
    {
        QMessageBox::warning(this, "Error", model->lastError().text());
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}

