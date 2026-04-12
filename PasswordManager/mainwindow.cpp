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
#include "passwordchecker.h"
#include <QAbstractTableModel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dbManager.open();
    dbManager.init();

    QSqlDatabase db = dbManager.getDB();
    repo = new PasswordRepository(db);

    model = new PasswordTableModel(this);
    model->setRepository(repo);
    model->setItems(repo->getAll());

    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);

    ui->tableInfo->setModel(proxyModel);

    connect(ui->searchline, &QLineEdit::textChanged,
            this, [=](const QString &text)
            {
                proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
                proxyModel->setFilterKeyColumn(0);
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

    connect(ui->ClearBtn, &QPushButton::clicked,
            this, [=]()
            {
                ui->searchline->setText("");
            });
    connect(ui->IndividualButton, &QPushButton::clicked,
            this, &MainWindow::PasswordVerification);
    ui->tableInfo->setSortingEnabled(true);
    proxyModel->setDynamicSortFilter(true);
    proxyModel->setSortCaseSensitivity(Qt::CaseInsensitive);
    ui->progressBar->setValue(0);   // старт
    ui->progressBar->setValue(50);  // середина
    ui->progressBar->setValue(100); // кінець
    connect(ui->AllPasswordsBtn, &QPushButton::clicked,
            this, &MainWindow::onCheckAll);
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

    int id = model->getItem(sourceIndex.row()).id;

    auto answer = QMessageBox::question(
        this,
        "Delete",
        "Delete selected record?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (answer == QMessageBox::Yes)
    {
        if (repo->remove(id)) {
            QMessageBox::information(this, "OK", "Видалено");
            model->setItems(repo->getAll());
        } else {
            QMessageBox::warning(this, "Error", "Видалити не вдалося");
        }
    }
}
void MainWindow::onNewTriggered()
{


    PasswordItem item;

    repo->add(item);
    model->setItems(repo->getAll());

    int row = model->rowCount(QModelIndex()) - 1;
    QModelIndex index = model->index(row, 0);

    proxyModel->invalidate();

    ui->tableInfo->setCurrentIndex(proxyModel->mapFromSource(index));
    ui->tableInfo->edit(ui->tableInfo->currentIndex());
    if (item.title.isEmpty() ||
        item.username.isEmpty() ||
        item.password.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Заповніть всі поля");
        return;
    }
}

void MainWindow::onSaveTriggered()
{
    QMessageBox::information(this, "Save", "Збережено автоматично");
}


void MainWindow::PasswordVerification()
{
    QModelIndex current = ui->tableInfo->currentIndex();
    if (!current.isValid()) return;


    QModelIndex sourceIndex = proxyModel->mapToSource(current);

    QString password = model->data(
                                model->index(sourceIndex.row(), 3),
                                Qt::DisplayRole
                                ).toString();

    PasswordChecker *checker = new PasswordChecker(this);

    connect(checker, &PasswordChecker::checkFinished, this,
            [=](bool found, int count)
            {
                if (found)
                {
                    QMessageBox::warning(this, "Warning",
                                         "Пароль знайдено у витоках! Кількість: " + QString::number(count));
                }
                else
                {
                    QMessageBox::information(this, "Норма", "Пароль безпечний");
                }
            });

    connect(checker, &PasswordChecker::checkError, this,
            [=](const QString &err)
            {
                QMessageBox::warning(this, "Error", err);
            });

    checker->check(password);
}

void MainWindow::onCheckAll()
{
    QList<PasswordItem> items = model->getItems();

    totalChecks = 0;
    finishedChecks = 0;
    safeCount = 0;
    leakedCount = 0;

    for (const auto &item : items)
        if (!item.password.isEmpty())
            totalChecks++;

    ui->progressBar->setValue(0);

    for (const auto &item : items)
    {
        if (item.password.isEmpty())
            continue;

        auto *checker = new PasswordChecker(this);

        connect(checker, &PasswordChecker::checkFinished,
                this, [=](bool found, int count)
                {
                    finishedChecks++;

                    if (found)
                        leakedCount++;
                    else
                        safeCount++;

                    int percent = (finishedChecks * 100) / totalChecks;
                    ui->progressBar->setValue(percent);

                    if (finishedChecks == totalChecks)
                    {
                        QMessageBox::information(this, "Done",
                                                 "Готово!\nБезпечний: " + QString::number(safeCount) +
                                                     "\nВитік: " + QString::number(leakedCount));
                    }

                    checker->deleteLater();
                });

        connect(checker, &PasswordChecker::checkError,
                this, [=](const QString &err)
                {
                    finishedChecks++;

                    int percent = (finishedChecks * 100) / totalChecks;
                    ui->progressBar->setValue(percent);

                    checker->deleteLater();
                });

        checker->check(item.password);
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}



