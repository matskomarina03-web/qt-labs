#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showText();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showText()
{
    QString prev = proc.getPreviousLine();
    QString curr = proc.getCurrentLine();
    ui->textDisplayArea->setText(prev + "\n" + curr);
}

void MainWindow::on_btntest_clicked()
{
    proc.nextChar();
    showText();
}
