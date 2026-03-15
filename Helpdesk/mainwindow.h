#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setTicketData(const QStringList &data);
    QStringList getTicketData() const;

private:
    Ui::mainwindow *ui;
};

#endif // MAINWINDOW_H
