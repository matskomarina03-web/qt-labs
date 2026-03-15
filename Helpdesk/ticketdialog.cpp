#include "ticketdialog.h"
#include "ui_ticketdialog.h"
#include <QMessageBox>
#include <QDate>

TicketDialog::TicketDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TicketDialog),
    currentMode(New)
{
    ui->setupUi(this);
    setMode(New);

    connect(ui->btnClose, &QPushButton::clicked, this, &QDialog::reject);
    connect(ui->btnEdit, &QPushButton::clicked, [this](){
        setMode(Edit);
    });
    connect(ui->btnSave, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->btnCancel, &QPushButton::clicked, this, &QDialog::reject);

}

void TicketDialog::setMode(Mode mode)
{
    currentMode = mode;

    bool editable = (mode == Edit || mode == New);

    ui->editTitle->setReadOnly(!editable);
    ui->editDescription->setReadOnly(!editable);
    ui->comboStatus->setEnabled(editable);
    ui->comboPriority->setEnabled(editable);

    ui->btnEdit->setVisible(mode == View);
    ui->btnClose->setVisible(mode == View);

    ui->btnSave->setVisible(mode == Edit || mode == New);
    ui->btnCancel->setVisible(mode == Edit || mode == New);
}

void TicketDialog::setTicketData(const QStringList &data)
{
    if(data.size() < 6) return;
    ui->editId->setText(data[0]);
    ui->editTitle->setText(data[1]);
    ui->editDescription->setText(data[2]);
    ui->comboStatus->setCurrentText(data[3]);
    ui->comboPriority->setCurrentText(data[4]);
    ui->editCreated->setText(data[5]);
}

QStringList TicketDialog::getTicketData() const
{
    return {
        ui->editId->text(),
        ui->editTitle->text(),
        ui->editDescription->toPlainText(),
        ui->comboStatus->currentText(),
        ui->comboPriority->currentText(),
        ui->editCreated->text()
    };
}
TicketDialog::~TicketDialog()
{
    delete ui;
}
