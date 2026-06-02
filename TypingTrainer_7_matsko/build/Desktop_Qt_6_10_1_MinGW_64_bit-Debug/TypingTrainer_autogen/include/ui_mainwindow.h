/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionAbout;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *pageStart;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *labelSelectText;
    QComboBox *layoutStartMain;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *startButton;
    QWidget *pageTraining;
    QHBoxLayout *horizontalLayout_7;
    QFrame *frame;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelTimeText;
    QLabel *labelTimeDisplay;
    QLabel *labelSpeedText;
    QLabel *labelAccuracyValue;
    QLabel *labelSpeedValue;
    QLabel *labelAccuracyText;
    QProgressBar *progressBar;
    QTextEdit *textDisplayArea;
    QGridLayout *gridLayout;
    QPushButton *btnKeyJ;
    QPushButton *btnCtrlLeft;
    QPushButton *btnShiftLeft;
    QPushButton *btnKeyTab;
    QPushButton *btnKeyK;
    QPushButton *btnKeyQ;
    QPushButton *btnKey8;
    QPushButton *btnKeyS;
    QPushButton *btnKeyCaps;
    QPushButton *btnKeyF;
    QPushButton *btnKeyP_2;
    QPushButton *btnKey7;
    QPushButton *btnKey4;
    QPushButton *btnKeyRightBracket;
    QPushButton *btnKey2;
    QPushButton *btnKeyH;
    QPushButton *btnKeyD;
    QPushButton *btnKey5;
    QPushButton *btnKey6;
    QPushButton *btnKeyPoint;
    QPushButton *btnBackspace;
    QPushButton *btnKeyX;
    QPushButton *btnKeyG;
    QPushButton *btnKeyI;
    QPushButton *btnKeyLeftBracket;
    QPushButton *btnKeyW;
    QPushButton *btnKeyT;
    QPushButton *btnKeyP;
    QPushButton *btnShiftRight;
    QPushButton *btnKeyZ;
    QPushButton *btnKeyV;
    QPushButton *btnEqual;
    QPushButton *btnKey10;
    QPushButton *btnKeyU;
    QPushButton *btnMinus;
    QPushButton *btnKeySEMICOLON;
    QPushButton *btnKeyN;
    QPushButton *btnKeyY;
    QPushButton *btnCtrlRight;
    QPushButton *btnKeyE;
    QPushButton *btnKeyCOMA;
    QPushButton *btnKeyL;
    QPushButton *btnCaretBottom;
    QPushButton *btnKeyC;
    QPushButton *btnCaretTop;
    QPushButton *btnKeyM;
    QPushButton *btnKeyA;
    QPushButton *btnKey9;
    QPushButton *btnKeyR;
    QPushButton *btnBackspaceLong;
    QPushButton *btnKey3;
    QPushButton *btnKeyO;
    QPushButton *btnSlash;
    QPushButton *btnEmptyExtra;
    QPushButton *btnKeyB;
    QPushButton *btnKey1;
    QPushButton *btntest;
    QVBoxLayout *verticalLayout_9;
    QWidget *pageResults;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QGridLayout *gridLayout_4;
    QLabel *labelAccuracy;
    QLabel *labelSessionTitle;
    QTextEdit *textResultsAccuracy;
    QTextEdit *textResultsSpeed;
    QLabel *labelTime;
    QLabel *labelSpeed;
    QTextEdit *textResultsOther;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuSettings;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(1255, 724);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        actionExit->setIcon(icon);
        actionExit->setMenuRole(QAction::MenuRole::NoRole);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::HelpAbout));
        actionAbout->setIcon(icon1);
        actionAbout->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        pageStart = new QWidget();
        pageStart->setObjectName("pageStart");
        horizontalLayout_3 = new QHBoxLayout(pageStart);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(52);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(24, 26, -1, 72);
        verticalSpacer_2 = new QSpacerItem(20, 127, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        labelSelectText = new QLabel(pageStart);
        labelSelectText->setObjectName("labelSelectText");

        verticalLayout->addWidget(labelSelectText);

        layoutStartMain = new QComboBox(pageStart);
        layoutStartMain->addItem(QString());
        layoutStartMain->addItem(QString());
        layoutStartMain->addItem(QString());
        layoutStartMain->addItem(QString());
        layoutStartMain->addItem(QString());
        layoutStartMain->addItem(QString());
        layoutStartMain->setObjectName("layoutStartMain");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(72);
        sizePolicy1.setHeightForWidth(layoutStartMain->sizePolicy().hasHeightForWidth());
        layoutStartMain->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(layoutStartMain);

        verticalSpacer = new QSpacerItem(20, 99, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        startButton = new QPushButton(pageStart);
        startButton->setObjectName("startButton");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(7);
        sizePolicy2.setVerticalStretch(8);
        sizePolicy2.setHeightForWidth(startButton->sizePolicy().hasHeightForWidth());
        startButton->setSizePolicy(sizePolicy2);
        startButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        startButton->setIconSize(QSize(28, 29));

        horizontalLayout->addWidget(startButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout);

        stackedWidget->addWidget(pageStart);
        pageTraining = new QWidget();
        pageTraining->setObjectName("pageTraining");
        horizontalLayout_7 = new QHBoxLayout(pageTraining);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        frame = new QFrame(pageTraining);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy3);
        frame->setMinimumSize(QSize(22, 23));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_10 = new QVBoxLayout(frame);
        verticalLayout_10->setObjectName("verticalLayout_10");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");

        verticalLayout_10->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        labelTimeText = new QLabel(frame);
        labelTimeText->setObjectName("labelTimeText");

        horizontalLayout_6->addWidget(labelTimeText);

        labelTimeDisplay = new QLabel(frame);
        labelTimeDisplay->setObjectName("labelTimeDisplay");
        QFont font;
        font.setBold(true);
        labelTimeDisplay->setFont(font);
        labelTimeDisplay->setScaledContents(false);
        labelTimeDisplay->setWordWrap(false);

        horizontalLayout_6->addWidget(labelTimeDisplay);

        labelSpeedText = new QLabel(frame);
        labelSpeedText->setObjectName("labelSpeedText");

        horizontalLayout_6->addWidget(labelSpeedText);

        labelAccuracyValue = new QLabel(frame);
        labelAccuracyValue->setObjectName("labelAccuracyValue");
        labelAccuracyValue->setFont(font);

        horizontalLayout_6->addWidget(labelAccuracyValue);

        labelSpeedValue = new QLabel(frame);
        labelSpeedValue->setObjectName("labelSpeedValue");

        horizontalLayout_6->addWidget(labelSpeedValue);

        labelAccuracyText = new QLabel(frame);
        labelAccuracyText->setObjectName("labelAccuracyText");

        horizontalLayout_6->addWidget(labelAccuracyText);

        progressBar = new QProgressBar(frame);
        progressBar->setObjectName("progressBar");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy4);
        progressBar->setValue(0);

        horizontalLayout_6->addWidget(progressBar);


        verticalLayout_10->addLayout(horizontalLayout_6);

        textDisplayArea = new QTextEdit(frame);
        textDisplayArea->setObjectName("textDisplayArea");

        verticalLayout_10->addWidget(textDisplayArea);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(4);
        gridLayout->setObjectName("gridLayout");
        btnKeyJ = new QPushButton(frame);
        btnKeyJ->setObjectName("btnKeyJ");

        gridLayout->addWidget(btnKeyJ, 2, 15, 1, 2);

        btnCtrlLeft = new QPushButton(frame);
        btnCtrlLeft->setObjectName("btnCtrlLeft");

        gridLayout->addWidget(btnCtrlLeft, 4, 3, 1, 3);

        btnShiftLeft = new QPushButton(frame);
        btnShiftLeft->setObjectName("btnShiftLeft");

        gridLayout->addWidget(btnShiftLeft, 4, 0, 1, 3);

        btnKeyTab = new QPushButton(frame);
        btnKeyTab->setObjectName("btnKeyTab");

        gridLayout->addWidget(btnKeyTab, 1, 0, 1, 2);

        btnKeyK = new QPushButton(frame);
        btnKeyK->setObjectName("btnKeyK");

        gridLayout->addWidget(btnKeyK, 2, 17, 1, 2);

        btnKeyQ = new QPushButton(frame);
        btnKeyQ->setObjectName("btnKeyQ");

        gridLayout->addWidget(btnKeyQ, 1, 2, 1, 2);

        btnKey8 = new QPushButton(frame);
        btnKey8->setObjectName("btnKey8");

        gridLayout->addWidget(btnKey8, 0, 15, 1, 2);

        btnKeyS = new QPushButton(frame);
        btnKeyS->setObjectName("btnKeyS");

        gridLayout->addWidget(btnKeyS, 2, 5, 1, 2);

        btnKeyCaps = new QPushButton(frame);
        btnKeyCaps->setObjectName("btnKeyCaps");

        gridLayout->addWidget(btnKeyCaps, 2, 0, 1, 3);

        btnKeyF = new QPushButton(frame);
        btnKeyF->setObjectName("btnKeyF");

        gridLayout->addWidget(btnKeyF, 2, 9, 1, 2);

        btnKeyP_2 = new QPushButton(frame);
        btnKeyP_2->setObjectName("btnKeyP_2");

        gridLayout->addWidget(btnKeyP_2, 3, 20, 1, 2);

        btnKey7 = new QPushButton(frame);
        btnKey7->setObjectName("btnKey7");

        gridLayout->addWidget(btnKey7, 0, 13, 1, 2);

        btnKey4 = new QPushButton(frame);
        btnKey4->setObjectName("btnKey4");

        gridLayout->addWidget(btnKey4, 0, 7, 1, 2);

        btnKeyRightBracket = new QPushButton(frame);
        btnKeyRightBracket->setObjectName("btnKeyRightBracket");

        gridLayout->addWidget(btnKeyRightBracket, 1, 22, 1, 2);

        btnKey2 = new QPushButton(frame);
        btnKey2->setObjectName("btnKey2");

        gridLayout->addWidget(btnKey2, 0, 3, 1, 2);

        btnKeyH = new QPushButton(frame);
        btnKeyH->setObjectName("btnKeyH");

        gridLayout->addWidget(btnKeyH, 2, 13, 1, 2);

        btnKeyD = new QPushButton(frame);
        btnKeyD->setObjectName("btnKeyD");

        gridLayout->addWidget(btnKeyD, 2, 7, 1, 2);

        btnKey5 = new QPushButton(frame);
        btnKey5->setObjectName("btnKey5");

        gridLayout->addWidget(btnKey5, 0, 9, 1, 2);

        btnKey6 = new QPushButton(frame);
        btnKey6->setObjectName("btnKey6");

        gridLayout->addWidget(btnKey6, 0, 11, 1, 2);

        btnKeyPoint = new QPushButton(frame);
        btnKeyPoint->setObjectName("btnKeyPoint");

        gridLayout->addWidget(btnKeyPoint, 0, 0, 1, 1);

        btnBackspace = new QPushButton(frame);
        btnBackspace->setObjectName("btnBackspace");

        gridLayout->addWidget(btnBackspace, 0, 25, 1, 1);

        btnKeyX = new QPushButton(frame);
        btnKeyX->setObjectName("btnKeyX");

        gridLayout->addWidget(btnKeyX, 3, 6, 1, 2);

        btnKeyG = new QPushButton(frame);
        btnKeyG->setObjectName("btnKeyG");

        gridLayout->addWidget(btnKeyG, 2, 11, 1, 2);

        btnKeyI = new QPushButton(frame);
        btnKeyI->setObjectName("btnKeyI");

        gridLayout->addWidget(btnKeyI, 1, 16, 1, 2);

        btnKeyLeftBracket = new QPushButton(frame);
        btnKeyLeftBracket->setObjectName("btnKeyLeftBracket");

        gridLayout->addWidget(btnKeyLeftBracket, 1, 24, 1, 2);

        btnKeyW = new QPushButton(frame);
        btnKeyW->setObjectName("btnKeyW");
        btnKeyW->setIconSize(QSize(10, 10));
        btnKeyW->setAutoRepeatDelay(283);

        gridLayout->addWidget(btnKeyW, 1, 4, 1, 2);

        btnKeyT = new QPushButton(frame);
        btnKeyT->setObjectName("btnKeyT");

        gridLayout->addWidget(btnKeyT, 1, 10, 1, 2);

        btnKeyP = new QPushButton(frame);
        btnKeyP->setObjectName("btnKeyP");

        gridLayout->addWidget(btnKeyP, 1, 20, 1, 2);

        btnShiftRight = new QPushButton(frame);
        btnShiftRight->setObjectName("btnShiftRight");

        gridLayout->addWidget(btnShiftRight, 4, 21, 1, 3);

        btnKeyZ = new QPushButton(frame);
        btnKeyZ->setObjectName("btnKeyZ");

        gridLayout->addWidget(btnKeyZ, 3, 4, 1, 2);

        btnKeyV = new QPushButton(frame);
        btnKeyV->setObjectName("btnKeyV");

        gridLayout->addWidget(btnKeyV, 3, 10, 1, 2);

        btnEqual = new QPushButton(frame);
        btnEqual->setObjectName("btnEqual");

        gridLayout->addWidget(btnEqual, 0, 23, 1, 2);

        btnKey10 = new QPushButton(frame);
        btnKey10->setObjectName("btnKey10");

        gridLayout->addWidget(btnKey10, 0, 19, 1, 2);

        btnKeyU = new QPushButton(frame);
        btnKeyU->setObjectName("btnKeyU");

        gridLayout->addWidget(btnKeyU, 1, 14, 1, 2);

        btnMinus = new QPushButton(frame);
        btnMinus->setObjectName("btnMinus");

        gridLayout->addWidget(btnMinus, 0, 21, 1, 2);

        btnKeySEMICOLON = new QPushButton(frame);
        btnKeySEMICOLON->setObjectName("btnKeySEMICOLON");

        gridLayout->addWidget(btnKeySEMICOLON, 2, 21, 1, 2);

        btnKeyN = new QPushButton(frame);
        btnKeyN->setObjectName("btnKeyN");

        gridLayout->addWidget(btnKeyN, 3, 14, 1, 2);

        btnKeyY = new QPushButton(frame);
        btnKeyY->setObjectName("btnKeyY");

        gridLayout->addWidget(btnKeyY, 1, 12, 1, 2);

        btnCtrlRight = new QPushButton(frame);
        btnCtrlRight->setObjectName("btnCtrlRight");

        gridLayout->addWidget(btnCtrlRight, 4, 24, 1, 3);

        btnKeyE = new QPushButton(frame);
        btnKeyE->setObjectName("btnKeyE");

        gridLayout->addWidget(btnKeyE, 1, 6, 1, 2);

        btnKeyCOMA = new QPushButton(frame);
        btnKeyCOMA->setObjectName("btnKeyCOMA");

        gridLayout->addWidget(btnKeyCOMA, 3, 18, 1, 2);

        btnKeyL = new QPushButton(frame);
        btnKeyL->setObjectName("btnKeyL");

        gridLayout->addWidget(btnKeyL, 2, 19, 1, 2);

        btnCaretBottom = new QPushButton(frame);
        btnCaretBottom->setObjectName("btnCaretBottom");

        gridLayout->addWidget(btnCaretBottom, 3, 24, 1, 2);

        btnKeyC = new QPushButton(frame);
        btnKeyC->setObjectName("btnKeyC");

        gridLayout->addWidget(btnKeyC, 3, 8, 1, 2);

        btnCaretTop = new QPushButton(frame);
        btnCaretTop->setObjectName("btnCaretTop");
        sizePolicy3.setHeightForWidth(btnCaretTop->sizePolicy().hasHeightForWidth());
        btnCaretTop->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(btnCaretTop, 3, 0, 1, 4);

        btnKeyM = new QPushButton(frame);
        btnKeyM->setObjectName("btnKeyM");

        gridLayout->addWidget(btnKeyM, 3, 16, 1, 2);

        btnKeyA = new QPushButton(frame);
        btnKeyA->setObjectName("btnKeyA");

        gridLayout->addWidget(btnKeyA, 2, 3, 1, 2);

        btnKey9 = new QPushButton(frame);
        btnKey9->setObjectName("btnKey9");

        gridLayout->addWidget(btnKey9, 0, 17, 1, 2);

        btnKeyR = new QPushButton(frame);
        btnKeyR->setObjectName("btnKeyR");

        gridLayout->addWidget(btnKeyR, 1, 8, 1, 2);

        btnBackspaceLong = new QPushButton(frame);
        btnBackspaceLong->setObjectName("btnBackspaceLong");

        gridLayout->addWidget(btnBackspaceLong, 2, 23, 1, 3);

        btnKey3 = new QPushButton(frame);
        btnKey3->setObjectName("btnKey3");

        gridLayout->addWidget(btnKey3, 0, 5, 1, 2);

        btnKeyO = new QPushButton(frame);
        btnKeyO->setObjectName("btnKeyO");

        gridLayout->addWidget(btnKeyO, 1, 18, 1, 2);

        btnSlash = new QPushButton(frame);
        btnSlash->setObjectName("btnSlash");

        gridLayout->addWidget(btnSlash, 3, 22, 1, 2);

        btnEmptyExtra = new QPushButton(frame);
        btnEmptyExtra->setObjectName("btnEmptyExtra");

        gridLayout->addWidget(btnEmptyExtra, 4, 6, 1, 15);

        btnKeyB = new QPushButton(frame);
        btnKeyB->setObjectName("btnKeyB");

        gridLayout->addWidget(btnKeyB, 3, 12, 1, 2);

        btnKey1 = new QPushButton(frame);
        btnKey1->setObjectName("btnKey1");

        gridLayout->addWidget(btnKey1, 0, 1, 1, 2);


        verticalLayout_10->addLayout(gridLayout);

        btntest = new QPushButton(frame);
        btntest->setObjectName("btntest");

        verticalLayout_10->addWidget(btntest);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");

        verticalLayout_10->addLayout(verticalLayout_9);


        horizontalLayout_7->addWidget(frame);

        stackedWidget->addWidget(pageTraining);
        pageResults = new QWidget();
        pageResults->setObjectName("pageResults");
        verticalLayoutWidget_2 = new QWidget(pageResults);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_4 = new QWidget(pageResults);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(40, 170, 786, 242));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        labelAccuracy = new QLabel(verticalLayoutWidget_4);
        labelAccuracy->setObjectName("labelAccuracy");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(labelAccuracy->sizePolicy().hasHeightForWidth());
        labelAccuracy->setSizePolicy(sizePolicy5);
        labelAccuracy->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout_4->addWidget(labelAccuracy, 1, 2, 1, 1);

        labelSessionTitle = new QLabel(verticalLayoutWidget_4);
        labelSessionTitle->setObjectName("labelSessionTitle");

        gridLayout_4->addWidget(labelSessionTitle, 0, 0, 1, 3);

        textResultsAccuracy = new QTextEdit(verticalLayoutWidget_4);
        textResultsAccuracy->setObjectName("textResultsAccuracy");

        gridLayout_4->addWidget(textResultsAccuracy, 2, 2, 1, 1);

        textResultsSpeed = new QTextEdit(verticalLayoutWidget_4);
        textResultsSpeed->setObjectName("textResultsSpeed");

        gridLayout_4->addWidget(textResultsSpeed, 2, 1, 1, 1);

        labelTime = new QLabel(verticalLayoutWidget_4);
        labelTime->setObjectName("labelTime");

        gridLayout_4->addWidget(labelTime, 1, 0, 1, 1);

        labelSpeed = new QLabel(verticalLayoutWidget_4);
        labelSpeed->setObjectName("labelSpeed");

        gridLayout_4->addWidget(labelSpeed, 1, 1, 1, 1);

        textResultsOther = new QTextEdit(verticalLayoutWidget_4);
        textResultsOther->setObjectName("textResultsOther");

        gridLayout_4->addWidget(textResultsOther, 2, 0, 1, 1);


        horizontalLayout_5->addLayout(gridLayout_4);


        verticalLayout_4->addLayout(horizontalLayout_5);

        stackedWidget->addWidget(pageResults);

        horizontalLayout_2->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1255, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName("menuSettings");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        labelSelectText->setText(QCoreApplication::translate("MainWindow", "Select a text for the typing exercise:", nullptr));
        layoutStartMain->setItemText(0, QCoreApplication::translate("MainWindow", "Starter Text", nullptr));
        layoutStartMain->setItemText(1, QCoreApplication::translate("MainWindow", "Numbers and Symbols", nullptr));
        layoutStartMain->setItemText(2, QCoreApplication::translate("MainWindow", "Common Words Part 1", nullptr));
        layoutStartMain->setItemText(3, QCoreApplication::translate("MainWindow", "Common Words Part 2", nullptr));
        layoutStartMain->setItemText(4, QCoreApplication::translate("MainWindow", "Python Code Sample", nullptr));
        layoutStartMain->setItemText(5, QCoreApplication::translate("MainWindow", "Lorem Ipsum", nullptr));

        startButton->setText(QCoreApplication::translate("MainWindow", "Start Training", nullptr));
        labelTimeText->setText(QCoreApplication::translate("MainWindow", "\360\237\225\220Time:", nullptr));
        labelTimeDisplay->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        labelSpeedText->setText(QCoreApplication::translate("MainWindow", "\342\217\261\357\270\217 Speed:", nullptr));
        labelAccuracyValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelSpeedValue->setText(QCoreApplication::translate("MainWindow", "CPM", nullptr));
        labelAccuracyText->setText(QCoreApplication::translate("MainWindow", "\342\234\205 Accuracy:", nullptr));
        textDisplayArea->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:26pt;\">AAAAAAAAAAAAAAAAAAAA VVVVVVVVVVVVVVVV KKKKKKKKKK JJJJJJJJJJJJJ ggggggggggggg    jjjjjjjjjjjjjjjjjj iiiiiiiiiiiiiiiiii nnnnnnnnnnnn iiiiiiiiiiiiiiii</span></p></body></html>", nullptr));
        btnKeyJ->setText(QCoreApplication::translate("MainWindow", "J", nullptr));
        btnCtrlLeft->setText(QCoreApplication::translate("MainWindow", "Ctrl", nullptr));
        btnShiftLeft->setText(QCoreApplication::translate("MainWindow", "Shift", nullptr));
        btnKeyTab->setText(QCoreApplication::translate("MainWindow", "Tab", nullptr));
        btnKeyK->setText(QCoreApplication::translate("MainWindow", "K", nullptr));
        btnKeyQ->setText(QCoreApplication::translate("MainWindow", "Q", nullptr));
        btnKey8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        btnKeyS->setText(QCoreApplication::translate("MainWindow", "S", nullptr));
        btnKeyCaps->setText(QCoreApplication::translate("MainWindow", "Caps", nullptr));
        btnKeyF->setText(QCoreApplication::translate("MainWindow", "F", nullptr));
        btnKeyP_2->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        btnKey7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        btnKey4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        btnKeyRightBracket->setText(QCoreApplication::translate("MainWindow", "[", nullptr));
        btnKey2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        btnKeyH->setText(QCoreApplication::translate("MainWindow", "H", nullptr));
        btnKeyD->setText(QCoreApplication::translate("MainWindow", "D", nullptr));
        btnKey5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        btnKey6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        btnKeyPoint->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        btnBackspace->setText(QCoreApplication::translate("MainWindow", "<-", nullptr));
        btnKeyX->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        btnKeyG->setText(QCoreApplication::translate("MainWindow", "G", nullptr));
        btnKeyI->setText(QCoreApplication::translate("MainWindow", "I", nullptr));
        btnKeyLeftBracket->setText(QCoreApplication::translate("MainWindow", "]", nullptr));
        btnKeyW->setText(QCoreApplication::translate("MainWindow", "W", nullptr));
        btnKeyT->setText(QCoreApplication::translate("MainWindow", "T", nullptr));
        btnKeyP->setText(QCoreApplication::translate("MainWindow", "P", nullptr));
        btnShiftRight->setText(QCoreApplication::translate("MainWindow", "Shift", nullptr));
        btnKeyZ->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        btnKeyV->setText(QCoreApplication::translate("MainWindow", "V", nullptr));
        btnEqual->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        btnKey10->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btnKeyU->setText(QCoreApplication::translate("MainWindow", "U", nullptr));
        btnMinus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        btnKeySEMICOLON->setText(QCoreApplication::translate("MainWindow", ";", nullptr));
        btnKeyN->setText(QCoreApplication::translate("MainWindow", "N", nullptr));
        btnKeyY->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        btnCtrlRight->setText(QCoreApplication::translate("MainWindow", "Ctrl", nullptr));
        btnKeyE->setText(QCoreApplication::translate("MainWindow", "E", nullptr));
        btnKeyCOMA->setText(QCoreApplication::translate("MainWindow", ",", nullptr));
        btnKeyL->setText(QCoreApplication::translate("MainWindow", "L", nullptr));
        btnCaretBottom->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        btnKeyC->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        btnCaretTop->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        btnKeyM->setText(QCoreApplication::translate("MainWindow", "M", nullptr));
        btnKeyA->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        btnKey9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        btnKeyR->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        btnBackspaceLong->setText(QCoreApplication::translate("MainWindow", "<-----", nullptr));
        btnKey3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        btnKeyO->setText(QCoreApplication::translate("MainWindow", "O", nullptr));
        btnSlash->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        btnEmptyExtra->setText(QString());
        btnKeyB->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        btnKey1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        btntest->setText(QCoreApplication::translate("MainWindow", "test", nullptr));
        labelAccuracy->setText(QCoreApplication::translate("MainWindow", "\342\234\205Accuracy", nullptr));
        labelSessionTitle->setText(QCoreApplication::translate("MainWindow", "Sesion Results", nullptr));
        labelTime->setText(QCoreApplication::translate("MainWindow", "\360\237\225\220Time", nullptr));
        labelSpeed->setText(QCoreApplication::translate("MainWindow", "\342\217\261\357\270\217Speed", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
