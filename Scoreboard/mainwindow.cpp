#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scoreA(0)
    , scoreB(0)
{
    ui->setupUi(this);

    ui->labelScoreA->setText("0");
    ui->labelScoreB->setText("0");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAPlus_clicked()
{
    scoreA++;
    ui->labelScoreA->setText(QString::number(scoreA));
}

void MainWindow::on_btnAMinus_clicked()
{
    if (scoreA > 0)
        scoreA--;
    ui->labelScoreA->setText(QString::number(scoreA));
}

void MainWindow::on_btnBPlus_clicked()
{
    scoreB++;
    ui->labelScoreB->setText(QString::number(scoreB));
}

void MainWindow::on_btnBMinus_clicked()
{
    if (scoreB > 0)
        scoreB--;
    ui->labelScoreB->setText(QString::number(scoreB));
}

void MainWindow::on_btnReset_clicked()
{
    scoreA = 0;
    scoreB = 0;
    ui->labelScoreA->setText("0");
    ui->labelScoreB->setText("0");
}
