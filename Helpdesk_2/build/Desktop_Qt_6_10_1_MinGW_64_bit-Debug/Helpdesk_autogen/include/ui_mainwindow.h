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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindow
{
public:
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionNew;
    QAction *actionView;
    QAction *actionEdit;
    QAction *actionDelete;
    QAction *actionRefresh;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboStatus;
    QLabel *label_2;
    QPushButton *btnClear;
    QComboBox *comboPriority;
    QLineEdit *lineEdit;
    QVBoxLayout *verticalLayout_4;
    QTableView *tableTickets;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuTicket;
    QMenu *menuView;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *mainwindow)
    {
        if (mainwindow->objectName().isEmpty())
            mainwindow->setObjectName("mainwindow");
        mainwindow->resize(1105, 702);
        mainwindow->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        actionExit = new QAction(mainwindow);
        actionExit->setObjectName("actionExit");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        actionExit->setIcon(icon);
        actionExit->setMenuRole(QAction::MenuRole::NoRole);
        actionAbout = new QAction(mainwindow);
        actionAbout->setObjectName("actionAbout");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::HelpAbout));
        actionAbout->setIcon(icon1);
        actionAbout->setMenuRole(QAction::MenuRole::NoRole);
        actionNew = new QAction(mainwindow);
        actionNew->setObjectName("actionNew");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::DocumentNew));
        actionNew->setIcon(icon2);
        actionNew->setMenuRole(QAction::MenuRole::NoRole);
        actionView = new QAction(mainwindow);
        actionView->setObjectName("actionView");
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen));
        actionView->setIcon(icon3);
        actionView->setMenuRole(QAction::MenuRole::NoRole);
        actionEdit = new QAction(mainwindow);
        actionEdit->setObjectName("actionEdit");
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::EditCut));
        actionEdit->setIcon(icon4);
        actionEdit->setMenuRole(QAction::MenuRole::NoRole);
        actionDelete = new QAction(mainwindow);
        actionDelete->setObjectName("actionDelete");
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete));
        actionDelete->setIcon(icon5);
        actionDelete->setMenuRole(QAction::MenuRole::NoRole);
        actionRefresh = new QAction(mainwindow);
        actionRefresh->setObjectName("actionRefresh");
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::ViewRefresh));
        actionRefresh->setIcon(icon6);
        actionRefresh->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(mainwindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboStatus = new QComboBox(centralwidget);
        comboStatus->addItem(QString());
        comboStatus->addItem(QString());
        comboStatus->addItem(QString());
        comboStatus->addItem(QString());
        comboStatus->setObjectName("comboStatus");

        gridLayout->addWidget(comboStatus, 0, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        btnClear = new QPushButton(centralwidget);
        btnClear->setObjectName("btnClear");

        gridLayout->addWidget(btnClear, 0, 5, 1, 1);

        comboPriority = new QComboBox(centralwidget);
        comboPriority->addItem(QString());
        comboPriority->addItem(QString());
        comboPriority->addItem(QString());
        comboPriority->addItem(QString());
        comboPriority->setObjectName("comboPriority");

        gridLayout->addWidget(comboPriority, 0, 3, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 0, 4, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 1);
        gridLayout->setColumnStretch(3, 1);
        gridLayout->setColumnStretch(4, 3);
        gridLayout->setColumnStretch(5, 1);

        verticalLayout->addLayout(gridLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        tableTickets = new QTableView(centralwidget);
        tableTickets->setObjectName("tableTickets");

        verticalLayout_4->addWidget(tableTickets);


        verticalLayout->addLayout(verticalLayout_4);


        horizontalLayout->addLayout(verticalLayout);

        mainwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainwindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1105, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuTicket = new QMenu(menubar);
        menuTicket->setObjectName("menuTicket");
        menuView = new QMenu(menubar);
        menuView->setObjectName("menuView");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        mainwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(mainwindow);
        statusbar->setObjectName("statusbar");
        mainwindow->setStatusBar(statusbar);
        toolBar = new QToolBar(mainwindow);
        toolBar->setObjectName("toolBar");
        toolBar->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        mainwindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuTicket->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExit);
        menuTicket->addAction(actionDelete);
        menuTicket->addAction(actionEdit);
        menuTicket->addAction(actionView);
        menuTicket->addAction(actionNew);
        menuView->addAction(actionRefresh);
        menuHelp->addAction(actionAbout);
        toolBar->addAction(actionNew);
        toolBar->addSeparator();
        toolBar->addAction(actionView);
        toolBar->addSeparator();
        toolBar->addAction(actionEdit);
        toolBar->addSeparator();
        toolBar->addAction(actionDelete);
        toolBar->addSeparator();
        toolBar->addAction(actionRefresh);

        retranslateUi(mainwindow);

        QMetaObject::connectSlotsByName(mainwindow);
    } // setupUi

    void retranslateUi(QMainWindow *mainwindow)
    {
        mainwindow->setWindowTitle(QCoreApplication::translate("mainwindow", "MainWindow", nullptr));
        actionExit->setText(QCoreApplication::translate("mainwindow", "Exit", nullptr));
        actionAbout->setText(QCoreApplication::translate("mainwindow", "About", nullptr));
        actionNew->setText(QCoreApplication::translate("mainwindow", "New", nullptr));
        actionView->setText(QCoreApplication::translate("mainwindow", "View", nullptr));
        actionEdit->setText(QCoreApplication::translate("mainwindow", "Edit", nullptr));
        actionDelete->setText(QCoreApplication::translate("mainwindow", "Delete", nullptr));
        actionRefresh->setText(QCoreApplication::translate("mainwindow", "Refresh", nullptr));
        label->setText(QCoreApplication::translate("mainwindow", "Status", nullptr));
        comboStatus->setItemText(0, QCoreApplication::translate("mainwindow", "All", nullptr));
        comboStatus->setItemText(1, QCoreApplication::translate("mainwindow", "Open", nullptr));
        comboStatus->setItemText(2, QCoreApplication::translate("mainwindow", "In Progress", nullptr));
        comboStatus->setItemText(3, QCoreApplication::translate("mainwindow", "Closed", nullptr));

        label_2->setText(QCoreApplication::translate("mainwindow", "Priority", nullptr));
        btnClear->setText(QCoreApplication::translate("mainwindow", "Clear", nullptr));
        comboPriority->setItemText(0, QCoreApplication::translate("mainwindow", "All", nullptr));
        comboPriority->setItemText(1, QCoreApplication::translate("mainwindow", "Low", nullptr));
        comboPriority->setItemText(2, QCoreApplication::translate("mainwindow", "Medium", nullptr));
        comboPriority->setItemText(3, QCoreApplication::translate("mainwindow", "High", nullptr));

        menuFile->setTitle(QCoreApplication::translate("mainwindow", "File", nullptr));
        menuTicket->setTitle(QCoreApplication::translate("mainwindow", "Ticket", nullptr));
        menuView->setTitle(QCoreApplication::translate("mainwindow", "View", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("mainwindow", "Help", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("mainwindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainwindow: public Ui_mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
