#ifndef TICKETDIALOG_H
#define TICKETDIALOG_H

#include <QDialog>
#include "ui_ticketdialog.h"
namespace Ui {
class TicketDialog;
}
class TicketDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TicketDialog(QWidget *parent = nullptr);
    ~TicketDialog();

    enum Mode { View, Edit, New };
    void setMode(Mode mode);
    void setTicketData(const QStringList &data);
    QStringList getTicketData() const;

private:
    Ui::TicketDialog *ui;
    Mode currentMode;
};

#endif // TICKETDIALOG_H
