#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <QKeyEvent>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFocusPolicy(Qt::StrongFocus);
    this->setFocus();
    ui->centralwidget->setFocus();

    proc.loadLesson("lessons/lesson1.txt");
    proc.loadAllLessons();

    loadLessonsIntoComboBox();

    connect(ui->lessonComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            [this](int index){
                if(index < 0 || index >= proc.lessons.size()) return;
                QString path = ui->lessonComboBox->currentData().toString();
                if(!path.isEmpty()){
                    proc.loadLesson(path);
                    proc.lineIndex = 0;
                    proc.charIndex = 0;
                    showText();
                }
            });

    connect(ui->randomButton, &QPushButton::clicked, [this](){
        if(proc.lessons.isEmpty()) return;
        int randomIndex = QRandomGenerator::global()->bounded(proc.lessons.size());
        ui->lessonComboBox->setCurrentIndex(randomIndex);
    });

    connect(ui->reloadButton, &QPushButton::clicked, [this](){
        proc.loadAllLessons();
        loadLessonsIntoComboBox();
    });

    keyToButtonMap[Qt::Key_A] = ui->btnKeyA;
    keyToButtonMap[Qt::Key_B] = ui->btnKeyB;
    keyToButtonMap[Qt::Key_C] = ui->btnKeyC;
    keyToButtonMap[Qt::Key_D] = ui->btnKeyD;
    keyToButtonMap[Qt::Key_E] = ui->btnKeyE;
    keyToButtonMap[Qt::Key_F] = ui->btnKeyF;
    keyToButtonMap[Qt::Key_G] = ui->btnKeyG;
    keyToButtonMap[Qt::Key_H] = ui->btnKeyH;
    keyToButtonMap[Qt::Key_I] = ui->btnKeyI;
    keyToButtonMap[Qt::Key_J] = ui->btnKeyJ;
    keyToButtonMap[Qt::Key_K] = ui->btnKeyK;
    keyToButtonMap[Qt::Key_L] = ui->btnKeyL;
    keyToButtonMap[Qt::Key_M] = ui->btnKeyM;
    keyToButtonMap[Qt::Key_N] = ui->btnKeyN;
    keyToButtonMap[Qt::Key_O] = ui->btnKeyO;
    keyToButtonMap[Qt::Key_P] = ui->btnKeyP;
    keyToButtonMap[Qt::Key_Q] = ui->btnKeyQ;
    keyToButtonMap[Qt::Key_R] = ui->btnKeyR;
    keyToButtonMap[Qt::Key_S] = ui->btnKeyS;
    keyToButtonMap[Qt::Key_T] = ui->btnKeyT;
    keyToButtonMap[Qt::Key_U] = ui->btnKeyU;
    keyToButtonMap[Qt::Key_V] = ui->btnKeyV;
    keyToButtonMap[Qt::Key_W] = ui->btnKeyW;
    keyToButtonMap[Qt::Key_X] = ui->btnKeyX;
    keyToButtonMap[Qt::Key_Y] = ui->btnKeyY;
    keyToButtonMap[Qt::Key_Z] = ui->btnKeyZ;

    keyToButtonMap[Qt::Key_0] = ui->btnKey10;
    keyToButtonMap[Qt::Key_1] = ui->btnKey1;
    keyToButtonMap[Qt::Key_2] = ui->btnKey2;
    keyToButtonMap[Qt::Key_3] = ui->btnKey3;
    keyToButtonMap[Qt::Key_4] = ui->btnKey4;
    keyToButtonMap[Qt::Key_5] = ui->btnKey5;
    keyToButtonMap[Qt::Key_6] = ui->btnKey6;
    keyToButtonMap[Qt::Key_7] = ui->btnKey7;
    keyToButtonMap[Qt::Key_8] = ui->btnKey8;
    keyToButtonMap[Qt::Key_9] = ui->btnKey9;

    keyToButtonMap[Qt::Key_Space] = ui->btnEmptyExtra;  // пробіл
    keyToButtonMap[Qt::Key_Return] = ui->btnBackspaceLong; // Enter
    keyToButtonMap[Qt::Key_Backspace] = ui->btnBackspace;

    keyToButtonMap[Qt::Key_Period] = ui->btnKeyP_2;      // .
    keyToButtonMap[Qt::Key_Comma] = ui->btnKeyCOMA;      // ,
    keyToButtonMap[Qt::Key_Semicolon] = ui->btnKeySEMICOLON; // ;
    keyToButtonMap[Qt::Key_Minus] = ui->btnMinus;        // -
    keyToButtonMap[Qt::Key_Equal] = ui->btnEqual;        // =
    keyToButtonMap[Qt::Key_BracketLeft] = ui->btnKeyRightBracket; // [
    keyToButtonMap[Qt::Key_BracketRight] = ui->btnKeyLeftBracket; // ]
    keyToButtonMap[Qt::Key_Slash] = ui->btnSlash;        // /
    keyToButtonMap[Qt::Key_AsciiCircum] = ui->btnCaretTop;   // ^
    keyToButtonMap[Qt::Key_AsciiCircum] = ui->btnCaretBottom; // ^ (нижня рядок)
    keyToButtonMap[Qt::Key_CapsLock] = ui->btnKeyCaps;
    keyToButtonMap[Qt::Key_Shift] = ui->btnShiftLeft;    // Shift
    keyToButtonMap[Qt::Key_Control] = ui->btnCtrlLeft;   // Ctrl

    lastButton = nullptr;

    this->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadLessonsIntoComboBox()
{
    ui->lessonComboBox->clear();
    for(const Lesson &l : proc.lessons)
        ui->lessonComboBox->addItem(l.name, l.path);

    if(!proc.lessons.isEmpty()){
        ui->lessonComboBox->setCurrentIndex(0);
        proc.loadLesson(proc.lessons[0].path);
        proc.lineIndex = 0;
        proc.charIndex = 0;
        showText();
    }
}

void MainWindow::showText()
{
    if(proc.lines.isEmpty() || proc.lineIndex >= proc.lines.size()){
        ui->textDisplayArea->clear();
        return;
    }

    QString prev = proc.getPreviousLine();
    QString curr = proc.getCurrentLine();

    QString html;
    html += "<span style='color:gray;'>" + prev.toHtmlEscaped() + "</span><br>";

    for(int i = 0; i < curr.length(); i++)
    {
        QString ch = QString(curr[i]).toHtmlEscaped();

        if(i < proc.charIndex)
        {
            if(i < proc.errorFlags.size() && proc.errorFlags[i])
            {
                html += "<span style='background:#ff6b6b; color:white;'>" + ch + "</span>";
            }
            else
            {
                html += "<span style='color:green;'>" + ch + "</span>";
            }
        }
        else if(i == proc.charIndex)
        {
            html += "<span style='background:#ffe08a;'>" + ch + "</span>";
        }
        else
        {
            html += ch;
        }
    }
    if(proc.charIndex >= curr.length())
    {
        html += "<span style='background:#ffe08a;'>&nbsp;</span>";
    }

    ui->textDisplayArea->setHtml(html);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(proc.lines.isEmpty()) return;

    QString typedChar = event->text();
    QString expectedChar = proc.getCurrentLine().mid(proc.charIndex, 1);

    if(event->key() == Qt::Key_Backspace){
        if(proc.charIndex > 0) {
            proc.charIndex--;
        } else if(proc.lineIndex > 0) {
            proc.lineIndex--;
            proc.charIndex = proc.getCurrentLine().length();
        }
    }
    else if(event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter){
        if(proc.charIndex >= proc.getCurrentLine().length()){
            if(proc.lineIndex < proc.lines.size() - 1){
                proc.lineIndex++;
                proc.charIndex = 0;
            }
        }
    }
    else if(!typedChar.isEmpty()){
        if(typedChar == expectedChar){
            proc.nextChar();
        } else {
            proc.errorFlags.resize(proc.charIndex + 1);
            proc.errorFlags[proc.charIndex] = true;
            proc.nextChar();
        }
    }

    int key = event->key();
    if(keyToButtonMap.contains(key)){
        keyToButtonMap[key]->setStyleSheet("background-color: yellow;");
        lastButton = keyToButtonMap[key];
    }

    showText();

    QMainWindow::keyPressEvent(event);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::KeyPress){
        keyPressEvent(static_cast<QKeyEvent*>(event));
        return true;
    }
    return QMainWindow::eventFilter(obj, event);
}



void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    int key = event->key();
    if(keyToButtonMap.contains(key)) {
        keyToButtonMap[key]->setStyleSheet("");
        lastButton = nullptr;
    }
    QMainWindow::keyReleaseEvent(event);
}
