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

    const int ModeView = 0;
    const int ModeEdit = 1;
    const int ModeNew  = 2;
    void setMode(int mode);
    void setTicketData(const QStringList &data);
    QStringList getTicketData() const;

private:
    Ui::TicketDialog *ui;
    int currentMode;
};

#endif // TICKETDIALOG_H
