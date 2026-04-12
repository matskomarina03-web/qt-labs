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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Entry;
    QAction *actionEdit;
    QAction *actionDelete;
    QAction *actionCopy_Username;
    QAction *actionCopy_Password;
    QAction *actionSave;
    QAction *actionAbout;
    QAction *actionExit_2;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *searchline;
    QPushButton *ClearBtn;
    QPushButton *AllPasswordsBtn;
    QPushButton *IndividualButton;
    QProgressBar *progressBar;
    QTableView *tableInfo;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEntry;
    QMenu *menuTools;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionNew_Entry = new QAction(MainWindow);
        actionNew_Entry->setObjectName("actionNew_Entry");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentNew));
        actionNew_Entry->setIcon(icon);
        actionNew_Entry->setMenuRole(QAction::MenuRole::NoRole);
        actionEdit = new QAction(MainWindow);
        actionEdit->setObjectName("actionEdit");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::EditCut));
        actionEdit->setIcon(icon1);
        actionEdit->setMenuRole(QAction::MenuRole::NoRole);
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName("actionDelete");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete));
        actionDelete->setIcon(icon2);
        actionDelete->setMenuRole(QAction::MenuRole::NoRole);
        actionCopy_Username = new QAction(MainWindow);
        actionCopy_Username->setObjectName("actionCopy_Username");
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::EditCopy));
        actionCopy_Username->setIcon(icon3);
        actionCopy_Username->setMenuRole(QAction::MenuRole::NoRole);
        actionCopy_Password = new QAction(MainWindow);
        actionCopy_Password->setObjectName("actionCopy_Password");
        actionCopy_Password->setIcon(icon3);
        actionCopy_Password->setMenuRole(QAction::MenuRole::NoRole);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave));
        actionSave->setIcon(icon4);
        actionSave->setMenuRole(QAction::MenuRole::NoRole);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::HelpAbout));
        actionAbout->setIcon(icon5);
        actionAbout->setMenuRole(QAction::MenuRole::NoRole);
        actionExit_2 = new QAction(MainWindow);
        actionExit_2->setObjectName("actionExit_2");
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        actionExit_2->setIcon(icon6);
        actionExit_2->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        searchline = new QLineEdit(centralwidget);
        searchline->setObjectName("searchline");

        gridLayout->addWidget(searchline, 0, 0, 1, 1);

        ClearBtn = new QPushButton(centralwidget);
        ClearBtn->setObjectName("ClearBtn");

        gridLayout->addWidget(ClearBtn, 0, 1, 1, 1);

        AllPasswordsBtn = new QPushButton(centralwidget);
        AllPasswordsBtn->setObjectName("AllPasswordsBtn");

        gridLayout->addWidget(AllPasswordsBtn, 0, 3, 1, 1);

        IndividualButton = new QPushButton(centralwidget);
        IndividualButton->setObjectName("IndividualButton");

        gridLayout->addWidget(IndividualButton, 0, 2, 1, 1);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 0, 4, 1, 1);


        verticalLayout->addLayout(gridLayout);

        tableInfo = new QTableView(centralwidget);
        tableInfo->setObjectName("tableInfo");

        verticalLayout->addWidget(tableInfo);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuEntry = new QMenu(menubar);
        menuEntry->setObjectName("menuEntry");
        menuTools = new QMenu(menubar);
        menuTools->setObjectName("menuTools");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setMouseTracking(false);
        toolBar->setTabletTracking(false);
        toolBar->setAcceptDrops(false);
        toolBar->setAllowedAreas(Qt::ToolBarArea::AllToolBarAreas);
        toolBar->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEntry->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew_Entry);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExit_2);
        menuHelp->addAction(actionAbout);
        toolBar->addAction(actionNew_Entry);
        toolBar->addSeparator();
        toolBar->addAction(actionEdit);
        toolBar->addSeparator();
        toolBar->addAction(actionDelete);
        toolBar->addSeparator();
        toolBar->addAction(actionCopy_Username);
        toolBar->addSeparator();
        toolBar->addAction(actionCopy_Password);
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew_Entry->setText(QCoreApplication::translate("MainWindow", "New Entry", nullptr));
        actionEdit->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        actionDelete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        actionCopy_Username->setText(QCoreApplication::translate("MainWindow", "Copy Username", nullptr));
        actionCopy_Password->setText(QCoreApplication::translate("MainWindow", "Copy Password", "kkk"));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionExit_2->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        ClearBtn->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        AllPasswordsBtn->setText(QCoreApplication::translate("MainWindow", "Check All Passwords", nullptr));
        IndividualButton->setText(QCoreApplication::translate("MainWindow", "individual", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEntry->setTitle(QCoreApplication::translate("MainWindow", "Entry", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
