#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->pageStart);
    QSettings settings("TypingTrainer", "App");

    speedMode = settings.value("ui/speedMode", "CPM").toString();

    QString lastLesson = settings.value("ui/lastLesson", "").toString();
    if(!lastLesson.isEmpty())
    {
        proc.loadLesson(lastLesson);
    }
    sessionTimer = new QTimer(this);
    connect(sessionTimer, &QTimer::timeout, this, &MainWindow::updateMetrics);
    ui->centralwidget->setFocusPolicy(Qt::StrongFocus);
    ui->centralwidget->setFocus();

    if(lastLesson.isEmpty())
        proc.loadLesson("lessons/lesson1.txt");
    proc.loadAllLessons();

    loadLessonsIntoComboBox();
    connect(ui->startButton, &QPushButton::clicked, this, [this](){
        proc.lineIndex = 0;
        proc.charIndex = 0;

        totalTyped = 0;
        correctTyped = 0;

        elapsed.restart();
        sessionTimer->start(1000);

        ui->stackedWidget->setCurrentWidget(ui->pageTraining);

        showText();
        ui->centralwidget->setFocus();
    });
    connect(ui->returnButton, &QPushButton::clicked, this, [this](){
        sessionTimer->stop();
        ui->stackedWidget->setCurrentWidget(ui->pageStart);
    });
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::close);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::showAbout);
    connect(ui->restartButton, &QPushButton::clicked, this, [this](){

        sessionTimer->stop();

        totalTyped = 0;
        correctTyped = 0;

        proc.lineIndex = 0;
        proc.charIndex = 0;

        elapsed.restart();
        sessionTimer->start(1000);

        showText();
        ui->stackedWidget->setCurrentIndex(1);
        ui->centralwidget->setFocus();
    });
    connect(ui->finishButton, &QPushButton::clicked, this, [this](){

        sessionTimer->stop();

        ui->resultTime->setText(ui->labelTimeDisplay->text());
        ui->resultSpeed->setText(ui->labelSpeedValue->text());
        ui->resultAccuracy->setText(ui->labelAccuracyValue->text());

        ui->stackedWidget->setCurrentWidget(ui->pageResults);

    });


    connect(ui->layoutStartMain, QOverload<int>::of(&QComboBox::currentIndexChanged),
            [this](int index){
                if(index < 0 || index >= proc.lessons.size()) return;
                QString path = ui->layoutStartMain->currentData().toString();
                if(!path.isEmpty()){
                    proc.loadLesson(path);
                    QSettings settings("TypingTrainer", "App");
                    settings.setValue("ui/lastLesson", path);
                    proc.lineIndex = 0;
                    proc.charIndex = 0;
                    showText();
                }
            });


    connect(ui->randomButton, &QPushButton::clicked, [this](){
        if(proc.lessons.isEmpty()) return;
        int randomIndex = QRandomGenerator::global()->bounded(proc.lessons.size());
        ui->layoutStartMain->setCurrentIndex(randomIndex);
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

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::showAbout()
{
    QMessageBox::about(this,
                       "About",
                       "Typing Trainer\n\n"
                       "Програма для перевірки швидкості та правильності введення тексту.");
}

void MainWindow::loadLessonsIntoComboBox()
{
    ui->layoutStartMain->clear();
    for(const Lesson &l : proc.lessons)
        ui->layoutStartMain->addItem(l.name, l.path);

    if(!proc.lessons.isEmpty()){
        ui->layoutStartMain->setCurrentIndex(0);
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
    QString next = proc.getNextLine();

    QString html;
    html += "<span style='color:gray;'>" + prev.toHtmlEscaped() + "</span><br>";
    for(int i = 0; i < curr.length(); i++)
    {
        QString ch = QString(curr[i]).toHtmlEscaped();
        if(i < proc.charIndex)
        {
            if(i < proc.errorFlags.size() && proc.errorFlags[i])
                html += "<span style='background:#ff6b6b; color:white;'>" + ch + "</span>";
            else
                html += "<span style='color:green;'>" + ch + "</span>";
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
        html += "<span style='background:#ffe08a;'>&nbsp;</span>";
    html += "<br>";
    html += "<span style='color:lightgray;'>" + next.toHtmlEscaped() + "</span>";
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

        totalTyped++;

        if(typedChar == expectedChar){
            correctTyped++;
            proc.nextChar();
            if(proc.lineIndex == proc.lines.size() - 1 &&
                proc.charIndex >= proc.getCurrentLine().length())
            {
                finishSession();
                return;
            }
        } else {
            proc.errorFlags.resize(proc.charIndex + 1);
            proc.errorFlags[proc.charIndex] = true;
            proc.nextChar();
            if(proc.lineIndex == proc.lines.size() - 1 &&
                proc.charIndex >= proc.getCurrentLine().length())
            {
                finishSession();
                return;
            }
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

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    int key = event->key();
    if(keyToButtonMap.contains(key)) {
        keyToButtonMap[key]->setStyleSheet("");
        lastButton = nullptr;
    }
    QMainWindow::keyReleaseEvent(event);
}


void MainWindow::updateMetrics()
{
    qint64 ms = elapsed.elapsed();
    double minutes = ms / 60000.0;
    int seconds = ms / 1000;
    int mm = seconds / 60;
    int ss = seconds % 60;

    ui->labelTimeDisplay->setText(
        QString("%1:%2")
            .arg(mm, 2, 10, QChar('0'))
            .arg(ss, 2, 10, QChar('0'))
        );
    double speed = 0;

    if(minutes > 0)
    {
        if(speedMode == "CPM")
        {
            speed = totalTyped / minutes;
        }
        else
        {
            speed = (totalTyped / 5.0) / minutes;
        }
    }

    ui->labelSpeedValue->setText(QString::number(speed, 'f', 1));
    double accuracy = 0;
    if(totalTyped > 0){
        accuracy = (correctTyped * 100.0) / totalTyped;
        accuracy = qBound(0.0, accuracy, 100.0);
    }

    ui->labelAccuracyValue->setText(QString::number(accuracy, 'f', 1) + "%");

    ui->progressBar->setValue((int)accuracy);
}

void MainWindow::finishSession()
{
    sessionTimer->stop();

    ui->resultTime->setText(ui->labelTimeDisplay->text());
    ui->resultSpeed->setText(ui->labelSpeedValue->text());
    ui->resultAccuracy->setText(ui->labelAccuracyValue->text());

    ui->stackedWidget->setCurrentWidget(ui->pageResults);
}
