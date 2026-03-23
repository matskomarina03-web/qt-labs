#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    model = new QStandardItemModel(0, 7, this);

    model->setHorizontalHeaderLabels({
        "ID", "Title", "Username", "Password","Website", "Category", "UpdatedAt"
    });

    ui->tableInfo->setModel(model);
    ui->tableInfo->horizontalHeader()->setStretchLastSection(true);
    ui->tableInfo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
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
    auto answer = QMessageBox::question(
        this,
        "Delete",
        "Delete selected record?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (answer == QMessageBox::Yes)
    {
        model->removeRow(row);
    }
}
void MainWindow::onNewTriggered()
{
    QList<QStandardItem*> row;
    for (int i = 0; i < 7; i++)
    {
        row.append(new QStandardItem(""));
    }
    model->appendRow(row);
    int newRow = model->rowCount() - 1;
    ui->tableInfo->selectRow(newRow);
    ui->tableInfo->edit(model->index(newRow, 1));
}

void MainWindow::onSaveTriggered()
{
    QMessageBox::information(this, "Save", "Save test");
}
MainWindow::~MainWindow()
{
    delete ui;
}

