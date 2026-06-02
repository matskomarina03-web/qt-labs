#include <QFileDialog>
#include <QMessageBox>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTextStream>
#include <QInputDialog>
#include <QLineEdit>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openFile);
    connect(ui->actionSelect_All, &QAction::triggered, this, &MainWindow::selectAll);
    connect(ui->actionCut, &QAction::triggered, this, &MainWindow::cut);
    connect(ui->actionCopy, &QAction::triggered, this, &MainWindow::copy);
    connect(ui->actionPaste, &QAction::triggered, this, &MainWindow::paste);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::saveFile);
    connect(ui->actionSave_As, &QAction::triggered, this, &MainWindow::saveFileAs);
    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::newFile);
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::exitApp);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::aboutApp);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile(){
    auto filename = QFileDialog::getOpenFileName(this,"Select file", "","*.txt");

    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
        return;

    QTextStream in(&file);

    auto text = in.readAll();
    ui->editor->setPlainText(text);
}

void MainWindow::selectAll(){
    ui->editor->selectAll();
}
void MainWindow::cut(){
    ui->editor->cut();
}
void MainWindow::copy(){
    ui->editor->copy();
}
void MainWindow::paste(){
    ui->editor->paste();
}
void MainWindow::saveFile() {
    QMessageBox::information(this,"Save","Ще не збережено");
}

void MainWindow::saveFileAs() {
    QMessageBox::information(this,"Save As","Ще не збережено як новий файл");
}


void MainWindow::newFile() {
    QString name = QInputDialog::getText(this,"New Document","Введіть назву:");
    if(!name.isEmpty()) {
        ui->editor->clear();
        statusBar()->showMessage("Новий документ: " + name);
    }
}

void MainWindow::exitApp() {
    if(QMessageBox::question(this,"Вихід","Вийти з програми?") == QMessageBox::Yes)
        qApp->quit();
}

void MainWindow::aboutApp() {
    QMessageBox::about(this,"Про QuickPad","Простий текстовий редактор\nВерсія 1.0");
}
