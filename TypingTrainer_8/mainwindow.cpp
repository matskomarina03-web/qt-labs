#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    proc.loadAllLessons();
    ui->lessonComboBox->clear();
    for (const Lesson &l : proc.lessons) {
        ui->lessonComboBox->addItem(l.name, l.path);
    }
    if (!proc.lessons.isEmpty()) {
        ui->lessonComboBox->setCurrentIndex(0);
        proc.loadLesson(proc.lessons[0].path);
        showText();
    }

    connect(ui->lessonComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            [this](int index){
                if (index < 0 || index >= proc.lessons.size()) return;
                QString path = ui->lessonComboBox->currentData().toString();
                if (!path.isEmpty()) {
                    proc.loadLesson(path);
                    showText();
                }
            });

    connect(ui->randomButton, &QPushButton::clicked, [this](){
        if (proc.lessons.isEmpty()) return;
        int randomIndex = QRandomGenerator::global()->bounded(proc.lessons.size());
        ui->lessonComboBox->setCurrentIndex(randomIndex);
    });

    connect(ui->reloadButton, &QPushButton::clicked, [this](){
        proc.loadAllLessons();
        ui->lessonComboBox->clear();
        for (const Lesson &l : proc.lessons) {
            ui->lessonComboBox->addItem(l.name, l.path);
        }
        if (!proc.lessons.isEmpty()) {
            ui->lessonComboBox->setCurrentIndex(0);
            proc.loadLesson(proc.lessons[0].path);
            showText();
        }
    });
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

void MainWindow::on_reloadButton_clicked()
{
    proc.loadAllLessons();
    ui->lessonComboBox->clear();
    for (const Lesson &l : proc.lessons) {
        ui->lessonComboBox->addItem(l.name, l.path);
    }
    if (!proc.lessons.isEmpty()) {
        ui->lessonComboBox->setCurrentIndex(0);
        proc.loadLesson(proc.lessons[0].path);
        showText();
    }
}




