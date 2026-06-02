#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDoubleValidator>
#include <QSignalBlocker>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->editTop->setValidator(new QDoubleValidator(this));
    ui->editBottom->setValidator(new QDoubleValidator(this));

    ui->editTop_2->setValidator(new QDoubleValidator(this));
    ui->editBottom_2->setValidator(new QDoubleValidator(this));
    ui->editTop_3->setValidator(new QDoubleValidator(this));
    ui->editBottom_3->setValidator(new QDoubleValidator(this));
    connect(ui->comboTopUnit_2, &QComboBox::currentTextChanged,
            this, &MainWindow::on_comboTopUnit_2_currentTextChanged);

    connect(ui->comboTopUnit_5, &QComboBox::currentTextChanged,
            this, &MainWindow::on_comboTopUnit_5_currentTextChanged);
    connect(ui->comboTopUnit_3, &QComboBox::currentTextChanged,
            this, &MainWindow::on_comboTopUnit_3_currentTextChanged);

    connect(ui->comboTopUnit_4, &QComboBox::currentTextChanged,
            this, &MainWindow::on_comboTopUnit_4_currentTextChanged);
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::onUnitChanged);
    connect(ui->comboTopUnit, &QComboBox::currentTextChanged,
            this, &MainWindow::on_comboTopUnit_currentTextChanged);

    connect(ui->comboBottomUnit, &QComboBox::currentTextChanged,
            this, &MainWindow::on_comboBottomUnit_currentTextChanged);

    connect(ui->editTop, &QLineEdit::textEdited,
            this, &MainWindow::on_editTop_textEdited);

    connect(ui->editBottom, &QLineEdit::textEdited,
            this, &MainWindow::on_editBottom_textEdited);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_editTop_textEdited(const QString &text)
{
    QSignalBlocker blocker(ui->editBottom);

    double v = text.toDouble();
    QString from = ui->comboTopUnit->currentText();
    QString to   = ui->comboBottomUnit->currentText();

    double res = converter.convert(v, from, to, "Temperature");
    ui->editBottom->setText(QString::number(res));
}

void MainWindow::on_editBottom_textEdited(const QString &text)
{
    QSignalBlocker blocker(ui->editTop);

    double v = text.toDouble();
    QString from = ui->comboBottomUnit->currentText();
    QString to   = ui->comboTopUnit->currentText();

    double res = converter.convert(v, from, to, "Temperature");
    ui->editTop->setText(QString::number(res));
}
void MainWindow::on_editTop_2_textEdited(const QString &text)
{
    QSignalBlocker blocker(ui->editBottom_2);

    double v = text.toDouble();
    QString from = ui->comboTopUnit_2->currentText();
    QString to   = ui->comboTopUnit_5->currentText();

    double res = converter.convert(v, from, to, "Length");
    ui->editBottom_2->setText(QString::number(res));
}

void MainWindow::on_editBottom_2_textEdited(const QString &text)
{
    QSignalBlocker blocker(ui->editTop_2);

    double v = text.toDouble();
    QString from = ui->comboTopUnit_5->currentText();
    QString to   = ui->comboTopUnit_2->currentText();

    double res = converter.convert(v, from, to, "Length");
    ui->editTop_2->setText(QString::number(res));
}
void MainWindow::on_editTop_3_textEdited(const QString &text)
{
    QSignalBlocker blocker(ui->editBottom_3);

    double v = text.toDouble();
    QString from = ui->comboTopUnit_3->currentText();
    QString to   = ui->comboTopUnit_4->currentText();

    double res = converter.convert(v, from, to, "Mass");
    ui->editBottom_3->setText(QString::number(res));
}

void MainWindow::on_editBottom_3_textEdited(const QString &text)
{
    QSignalBlocker blocker(ui->editTop_3);

    double v = text.toDouble();
    QString from = ui->comboTopUnit_4->currentText();
    QString to   = ui->comboTopUnit_3->currentText();

    double res = converter.convert(v, from, to, "Mass");
    ui->editTop_3->setText(QString::number(res));
}
void MainWindow::on_comboTopUnit_2_currentTextChanged(const QString &)
{
    on_editTop_2_textEdited(ui->editTop_2->text());
}

void MainWindow::on_comboTopUnit_5_currentTextChanged(const QString &)
{
    on_editTop_2_textEdited(ui->editTop_2->text());
}
void MainWindow::on_comboTopUnit_3_currentTextChanged(const QString &)
{
    on_editTop_3_textEdited(ui->editTop_3->text());
}

void MainWindow::on_comboTopUnit_4_currentTextChanged(const QString &)
{
    on_editTop_3_textEdited(ui->editTop_3->text());
}
void MainWindow::onUnitChanged()
{
    on_editTop_textEdited(ui->editTop->text());
}
void MainWindow::on_comboTopUnit_currentTextChanged(const QString &)
{
    on_editTop_textEdited(ui->editTop->text());
}

void MainWindow::on_comboBottomUnit_currentTextChanged(const QString &)
{
    on_editBottom_textEdited(ui->editBottom->text());
}
