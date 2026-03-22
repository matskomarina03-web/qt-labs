#include "mainwindow.h"
#include "ticketdialog.h"
#include <QMessageBox>
#include <QDate>
#include <QItemSelectionModel>
#include <QTableWidgetItem>

class TicketSortProxy : public QSortFilterProxyModel
{
protected:
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const override
    {
        QVariant leftData = sourceModel()->data(left);
        QVariant rightData = sourceModel()->data(right);

        if(left.column() == 0)
            return leftData.toInt() < rightData.toInt();

        if(left.column() == 4)
            return QDate::fromString(leftData.toString(), "yyyy-MM-dd") <
                   QDate::fromString(rightData.toString(), "yyyy-MM-dd");

        return leftData.toString().toLower() < rightData.toString().toLower();
    }
};
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),m_repository("tickets.csv")
    , ui(new Ui::mainwindow)
{
    ui->setupUi(this);

    model = new TicketTableModel(this);

    ui->tableTickets->setModel(model);
    ui->tableTickets->setSelectionBehavior(QAbstractItemView::SelectRows);

    QVector<Ticket> tickets = m_repository.loadTickets();
    if(tickets.isEmpty()) {
        model->addTicket({1, "Printer problem", "High", "Open", QDate::currentDate()});
        model->addTicket({2, "Internet down", "Medium", "Open", QDate::currentDate()});
        model->addTicket({3, "Computer slow", "Low", "Closed", QDate::currentDate()});
        model->addTicket({4, "Keyboard broken", "Medium", "Open", QDate::currentDate()});
        model->addTicket({5, "Software error", "High", "Open", QDate::currentDate()});
        m_repository.saveTickets(model->getTickets());
    } else {
        for(auto &t : tickets)
            model->addTicket(t);
    }
    ui->tableTickets->setModel(model);
    ui->tableTickets->setSelectionBehavior(QAbstractItemView::SelectRows);

    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::onNewTicket);
    connect(ui->actionView, &QAction::triggered, this, &MainWindow::onViewTicket);
    connect(ui->actionEdit, &QAction::triggered, this, &MainWindow::onEditTicket);
    connect(ui->actionDelete, &QAction::triggered, this, &MainWindow::onDeleteTicket);
    connect(ui->tableTickets->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &MainWindow::updateActions);

    updateActions();

    connect(ui->actionExit, &QAction::triggered, this, &QWidget::close);
    connect(ui->actionAbout, &QAction::triggered, [this](){
        QMessageBox::about(this, "About", "Helpdesk example with TicketTableModel");
    });
    connect(ui->comboStatus, &QComboBox::currentTextChanged,
            this, &MainWindow::filterTickets);

    connect(ui->comboPriority, &QComboBox::currentTextChanged,
            this, &MainWindow::filterTickets);

    connect(ui->lineEdit, &QLineEdit::textChanged,
            this, &MainWindow::filterTickets);

    connect(ui->btnClear, &QPushButton::clicked,
            this, &MainWindow::clearFilter);
    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);
    proxyModel->setSortCaseSensitivity(Qt::CaseInsensitive);
    ui->tableTickets->setModel(proxyModel);
    ui->tableTickets->setSortingEnabled(true);
}

void MainWindow::onNewTicket()
{
    TicketDialog dialog(this);
    dialog.setMode(2);
    Ticket t;
    t.id = model->rowCount() + 1;
    t.status = "Open";
    t.priority = "Medium";
    t.createdAt = QDate::currentDate();
    dialog.setTicketData({QString::number(t.id), "", "", t.status, t.priority, t.createdAt.toString("yyyy-MM-dd")});

    if(dialog.exec() == QDialog::Accepted)
    {
        QStringList data = dialog.getTicketData();
        t.title = data[1];
        t.status = data[3];
        t.priority = data[4];
        model->addTicket(t);
    }
    m_repository.saveTickets(model->getTickets());
}

void MainWindow::onViewTicket()
{
    auto selected = ui->tableTickets->selectionModel()->selectedRows();
    ui->tableTickets->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableTickets->setEditTriggers(QAbstractItemView::NoEditTriggers);
    if(selected.isEmpty()) return;

    int row = selected.first().row();
    Ticket t = model->getTicket(row);

    TicketDialog dialog(this);
    dialog.setMode(0);
    dialog.setTicketData({QString::number(t.id), t.title, "", t.status, t.priority, t.createdAt.toString("yyyy-MM-dd")});
    dialog.exec();
    m_repository.saveTickets(model->getTickets());
}

void MainWindow::onEditTicket()
{
    auto selected = ui->tableTickets->selectionModel()->selectedRows();
    if(selected.isEmpty()) return;

    int row = selected.first().row();
    Ticket t = model->getTicket(row);

    TicketDialog dialog(this);
    dialog.setMode(1);
    dialog.setTicketData({QString::number(t.id), t.title, "", t.status, t.priority, t.createdAt.toString("yyyy-MM-dd")});

    if(dialog.exec() == QDialog::Accepted)
    {
        QStringList data = dialog.getTicketData();
        t.title = data[1];
        t.status = data[3];
        t.priority = data[4];
        model->updateTicket(row, t);
    }
     m_repository.saveTickets(model->getTickets());
}

void MainWindow::onDeleteTicket()
{
    auto selected = ui->tableTickets->selectionModel()->selectedRows();
    if(selected.isEmpty()) return;

    int row = selected.first().row();

    auto result = QMessageBox::question(
        this,
        "Delete",
        "Delete selected ticket?",
        QMessageBox::Yes | QMessageBox::No
        );

    if(result == QMessageBox::Yes)
    {
        model->removeTicket(row);
    }
     m_repository.saveTickets(model->getTickets());
}

void MainWindow::updateActions()
{
    bool hasSelection = !ui->tableTickets->selectionModel()->selectedRows().isEmpty();
    ui->actionView->setEnabled(hasSelection);
    ui->actionEdit->setEnabled(hasSelection);
    ui->actionDelete->setEnabled(hasSelection);
}
void MainWindow::filterTickets()
{
    QString status = ui->comboStatus->currentText();
    QString priority = ui->comboPriority->currentText();
    QString text = ui->lineEdit->text().toLower();

    for(int i = 0; i < model->rowCount(); i++)
    {
        Ticket t = model->getTicket(i);

        bool show = true;

        if(status != "All" && t.status != status)
            show = false;

        if(priority != "All" && t.priority != priority)
            show = false;

        if(!text.isEmpty() && !t.title.toLower().contains(text))
            show = false;

        ui->tableTickets->setRowHidden(i, !show);
    }
}
void MainWindow::clearFilter()
{
    ui->comboStatus->setCurrentIndex(0);
    ui->comboPriority->setCurrentIndex(0);
    ui->lineEdit->clear();

    for(int i = 0; i < model->rowCount(); i++)
    {
        ui->tableTickets->setRowHidden(i, false);
    }
}

void MainWindow::addTicket(const QString &title, const QString &priority)
{
    Ticket t;
    t.id = m_repository.nextId();
    t.title = title;
    t.priority = priority;
    t.status = "Open";
    t.createdAt = QDate::currentDate();

    model->addTicket(t);
    m_repository.saveTickets(model->ticketsList());
}

void MainWindow::sortBySearch()
{
    QString text = ui->lineEdit->text().toLower();

    if(text.isEmpty()) return;

    QVector<Ticket> matched;
    QVector<Ticket> others;

    for(int i = 0; i < model->rowCount(); i++)
    {
        Ticket t = model->getTicket(i);

        if(t.title.toLower().contains(text))
            matched.push_back(t);
        else
            others.push_back(t);
    }

    while(model->rowCount() > 0)
    {
        model->removeTicket(0);
    }

    for(auto &t : matched)
        model->addTicket(t);

}

MainWindow::~MainWindow()
{
    delete ui;
}
