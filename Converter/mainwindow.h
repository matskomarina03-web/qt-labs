#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "converter.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onUnitChanged();
    void on_editTop_3_textEdited(const QString &text);
    void on_editBottom_3_textEdited(const QString &text);
    void on_editTop_2_textEdited(const QString &text);
    void on_editTop_textEdited(const QString &text);
    void on_editBottom_2_textEdited(const QString &text);
    void on_editBottom_textEdited(const QString &text);
    void on_comboTopUnit_2_currentTextChanged(const QString &);
    void on_comboTopUnit_5_currentTextChanged(const QString &);
    void on_comboTopUnit_3_currentTextChanged(const QString &);
    void on_comboTopUnit_4_currentTextChanged(const QString &);
    void on_comboTopUnit_currentTextChanged(const QString &);
    void on_comboBottomUnit_currentTextChanged(const QString &);
private:
    Ui::MainWindow *ui;
    Converter converter;
};

#endif // MAINWINDOW_H
