#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QPushButton>
#include <QKeyEvent>
#include "processor.h"
#include <QTimer>
#include <QElapsedTimer>
#include <QSettings>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QElapsedTimer elapsedTimer;

    processor proc;
    QMap<int, QPushButton*> keyToButtonMap;
    QPushButton *lastButton;

    void loadLessonsIntoComboBox();
    void showText();
    void highlightVirtualKey(int key);
    void finishSession();
    void updateMetrics();
    QTimer *sessionTimer;
    QElapsedTimer elapsed;

    int totalTyped = 0;
    int correctTyped = 0;

    QString speedMode = "CPM";
};

#endif // MAINWINDOW_H
