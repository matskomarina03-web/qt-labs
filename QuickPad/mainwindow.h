#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;

    void openFile();
    void selectAll();
    void cut();
    void paste();
    void copy();
    void saveFile();
    void saveFileAs();
    void newFile();
    void exitApp();
    void aboutApp();
};
#endif // MAINWINDOW_H
