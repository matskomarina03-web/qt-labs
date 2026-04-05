#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QDebug>
#include "databasemanager.h"
#include <QDateTime>
#include <QSortFilterProxyModel>
#include "passwordrepository.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dbManager.open();
    dbManager.init();

    QSqlDatabase db = dbManager.getDB();
    repo = new PasswordRepository(db);

    model = new QSqlTableModel(this, db);
    model->setTable("passwords");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);

    ui->tableInfo->setModel(proxyModel);

    connect(ui->searchline, &QLineEdit::textChanged,
            this, [=](const QString &text)
            {
                proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
                proxyModel->setFilterKeyColumn(-1);
                proxyModel->setFilterRegularExpression(text);
            });

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
    ui->tableInfo->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Title");
    model->setHeaderData(2, Qt::Horizontal, "Username");
    model->setHeaderData(3, Qt::Horizontal, "Password");
    model->setHeaderData(4, Qt::Horizontal, "Website");
    model->setHeaderData(5, Qt::Horizontal, "Category");
    model->setHeaderData(6, Qt::Horizontal, "UpdatedAt");
    connect(ui->ClearBtn, &QPushButton::clicked,
            this, [=]()
            {
                ui->searchline->setText("");
            });
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

    QModelIndex sourceIndex = proxyModel->mapToSource(current);

    int id = model->data(model->index(sourceIndex.row(), 0)).toInt();

    auto answer = QMessageBox::question(
        this,
        "Delete",
        "Delete selected record?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (answer == QMessageBox::Yes)
    {
        if (repo->remove(id)) {
            QMessageBox::information(this, "OK", "Deleted");
            model->select();
        } else {
            QMessageBox::warning(this, "Error", "Delete failed");
        }
    }
}
void MainWindow::onNewTriggered()
{
    int row = model->rowCount();

    model->insertRow(row);

    QModelIndex index = model->index(row, 1);
    proxyModel->invalidate();

    ui->tableInfo->setCurrentIndex(proxyModel->mapFromSource(index));
    ui->tableInfo->edit(ui->tableInfo->currentIndex());
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

