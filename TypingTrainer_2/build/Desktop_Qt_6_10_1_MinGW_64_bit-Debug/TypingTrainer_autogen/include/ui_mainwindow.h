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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QStackedWidget *stackedWidget;
    QWidget *pageStart;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *layoutStartMain;
    QPushButton *pushButton;
    QWidget *pageTraining;
    QFrame *frame;
    QVBoxLayout *verticalLayout_10;
    QTextEdit *textEdit;
    QGridLayout *gridLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_22;
    QPushButton *pushButton_7;
    QPushButton *pushButton_11;
    QPushButton *pushButton_31;
    QPushButton *pushButton_33;
    QPushButton *pushButton_9;
    QPushButton *pushButton_23;
    QPushButton *pushButton_27;
    QPushButton *pushButton_2;
    QPushButton *pushButton_15;
    QPushButton *pushButton_14;
    QPushButton *pushButton_26;
    QPushButton *pushButton_4;
    QPushButton *pushButton_18;
    QPushButton *pushButton_20;
    QPushButton *pushButton_24;
    QPushButton *pushButton_21;
    QPushButton *pushButton_25;
    QPushButton *pushButton_10;
    QPushButton *pushButton_19;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_32;
    QPushButton *pushButton_34;
    QPushButton *pushButton_28;
    QPushButton *pushButton_41;
    QPushButton *pushButton_16;
    QPushButton *pushButton_44;
    QPushButton *pushButton_17;
    QPushButton *pushButton_45;
    QPushButton *pushButton_37;
    QPushButton *pushButton_46;
    QPushButton *pushButton_38;
    QPushButton *pushButton_35;
    QPushButton *pushButton_39;
    QPushButton *pushButton_47;
    QPushButton *pushButton_36;
    QPushButton *pushButton_43;
    QPushButton *pushButton_48;
    QPushButton *pushButton_42;
    QPushButton *pushButton_50;
    QPushButton *pushButton_51;
    QPushButton *pushButton_49;
    QPushButton *pushButton_53;
    QPushButton *pushButton_54;
    QPushButton *pushButton_52;
    QPushButton *pushButton_8;
    QPushButton *pushButton_29;
    QPushButton *pushButton_30;
    QPushButton *pushButton_56;
    QPushButton *pushButton_57;
    QPushButton *pushButton_40;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_55;
    QVBoxLayout *verticalLayout_9;
    QWidget *pageResults;
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
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(40, 30, 1000, 591));
        pageStart = new QWidget();
        pageStart->setObjectName("pageStart");
        verticalLayoutWidget = new QWidget(pageStart);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 991, 551));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(52);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(11, 11, 0, 200);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        layoutStartMain = new QComboBox(verticalLayoutWidget);
        layoutStartMain->addItem(QString());
        layoutStartMain->addItem(QString());
        layoutStartMain->addItem(QString());
        layoutStartMain->addItem(QString());
        layoutStartMain->addItem(QString());
        layoutStartMain->addItem(QString());
        layoutStartMain->setObjectName("layoutStartMain");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(63);
        sizePolicy1.setHeightForWidth(layoutStartMain->sizePolicy().hasHeightForWidth());
        layoutStartMain->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(layoutStartMain);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        verticalLayout->addWidget(pushButton);

        stackedWidget->addWidget(pageStart);
        pageTraining = new QWidget();
        pageTraining->setObjectName("pageTraining");
        frame = new QFrame(pageTraining);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(20, 20, 961, 581));
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
        textEdit = new QTextEdit(frame);
        textEdit->setObjectName("textEdit");

        verticalLayout_10->addWidget(textEdit);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(4);
        gridLayout->setObjectName("gridLayout");
        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName("pushButton_3");

        gridLayout->addWidget(pushButton_3, 1, 2, 1, 2);

        pushButton_22 = new QPushButton(frame);
        pushButton_22->setObjectName("pushButton_22");

        gridLayout->addWidget(pushButton_22, 0, 11, 1, 2);

        pushButton_7 = new QPushButton(frame);
        pushButton_7->setObjectName("pushButton_7");

        gridLayout->addWidget(pushButton_7, 1, 10, 1, 2);

        pushButton_11 = new QPushButton(frame);
        pushButton_11->setObjectName("pushButton_11");

        gridLayout->addWidget(pushButton_11, 1, 0, 1, 2);

        pushButton_31 = new QPushButton(frame);
        pushButton_31->setObjectName("pushButton_31");
        pushButton_31->setIconSize(QSize(10, 10));
        pushButton_31->setAutoRepeatDelay(283);

        gridLayout->addWidget(pushButton_31, 1, 4, 1, 2);

        pushButton_33 = new QPushButton(frame);
        pushButton_33->setObjectName("pushButton_33");

        gridLayout->addWidget(pushButton_33, 1, 6, 1, 2);

        pushButton_9 = new QPushButton(frame);
        pushButton_9->setObjectName("pushButton_9");

        gridLayout->addWidget(pushButton_9, 1, 12, 1, 2);

        pushButton_23 = new QPushButton(frame);
        pushButton_23->setObjectName("pushButton_23");

        gridLayout->addWidget(pushButton_23, 0, 21, 1, 2);

        pushButton_27 = new QPushButton(frame);
        pushButton_27->setObjectName("pushButton_27");

        gridLayout->addWidget(pushButton_27, 0, 17, 1, 2);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 0, 3, 1, 2);

        pushButton_15 = new QPushButton(frame);
        pushButton_15->setObjectName("pushButton_15");

        gridLayout->addWidget(pushButton_15, 1, 8, 1, 2);

        pushButton_14 = new QPushButton(frame);
        pushButton_14->setObjectName("pushButton_14");

        gridLayout->addWidget(pushButton_14, 0, 1, 1, 2);

        pushButton_26 = new QPushButton(frame);
        pushButton_26->setObjectName("pushButton_26");

        gridLayout->addWidget(pushButton_26, 0, 13, 1, 2);

        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName("pushButton_4");

        gridLayout->addWidget(pushButton_4, 0, 25, 1, 1);

        pushButton_18 = new QPushButton(frame);
        pushButton_18->setObjectName("pushButton_18");

        gridLayout->addWidget(pushButton_18, 0, 5, 1, 2);

        pushButton_20 = new QPushButton(frame);
        pushButton_20->setObjectName("pushButton_20");

        gridLayout->addWidget(pushButton_20, 0, 7, 1, 2);

        pushButton_24 = new QPushButton(frame);
        pushButton_24->setObjectName("pushButton_24");

        gridLayout->addWidget(pushButton_24, 0, 19, 1, 2);

        pushButton_21 = new QPushButton(frame);
        pushButton_21->setObjectName("pushButton_21");

        gridLayout->addWidget(pushButton_21, 0, 9, 1, 2);

        pushButton_25 = new QPushButton(frame);
        pushButton_25->setObjectName("pushButton_25");

        gridLayout->addWidget(pushButton_25, 0, 15, 1, 2);

        pushButton_10 = new QPushButton(frame);
        pushButton_10->setObjectName("pushButton_10");

        gridLayout->addWidget(pushButton_10, 0, 0, 1, 1);

        pushButton_19 = new QPushButton(frame);
        pushButton_19->setObjectName("pushButton_19");

        gridLayout->addWidget(pushButton_19, 0, 23, 1, 2);

        pushButton_12 = new QPushButton(frame);
        pushButton_12->setObjectName("pushButton_12");

        gridLayout->addWidget(pushButton_12, 2, 0, 1, 3);

        pushButton_13 = new QPushButton(frame);
        pushButton_13->setObjectName("pushButton_13");
        sizePolicy3.setHeightForWidth(pushButton_13->sizePolicy().hasHeightForWidth());
        pushButton_13->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(pushButton_13, 3, 0, 1, 4);

        pushButton_32 = new QPushButton(frame);
        pushButton_32->setObjectName("pushButton_32");

        gridLayout->addWidget(pushButton_32, 2, 3, 1, 2);

        pushButton_34 = new QPushButton(frame);
        pushButton_34->setObjectName("pushButton_34");

        gridLayout->addWidget(pushButton_34, 2, 5, 1, 2);

        pushButton_28 = new QPushButton(frame);
        pushButton_28->setObjectName("pushButton_28");

        gridLayout->addWidget(pushButton_28, 3, 4, 1, 2);

        pushButton_41 = new QPushButton(frame);
        pushButton_41->setObjectName("pushButton_41");

        gridLayout->addWidget(pushButton_41, 3, 6, 1, 2);

        pushButton_16 = new QPushButton(frame);
        pushButton_16->setObjectName("pushButton_16");

        gridLayout->addWidget(pushButton_16, 2, 7, 1, 2);

        pushButton_44 = new QPushButton(frame);
        pushButton_44->setObjectName("pushButton_44");

        gridLayout->addWidget(pushButton_44, 3, 8, 1, 2);

        pushButton_17 = new QPushButton(frame);
        pushButton_17->setObjectName("pushButton_17");

        gridLayout->addWidget(pushButton_17, 2, 9, 1, 2);

        pushButton_45 = new QPushButton(frame);
        pushButton_45->setObjectName("pushButton_45");

        gridLayout->addWidget(pushButton_45, 3, 10, 1, 2);

        pushButton_37 = new QPushButton(frame);
        pushButton_37->setObjectName("pushButton_37");

        gridLayout->addWidget(pushButton_37, 2, 11, 1, 2);

        pushButton_46 = new QPushButton(frame);
        pushButton_46->setObjectName("pushButton_46");

        gridLayout->addWidget(pushButton_46, 3, 12, 1, 2);

        pushButton_38 = new QPushButton(frame);
        pushButton_38->setObjectName("pushButton_38");

        gridLayout->addWidget(pushButton_38, 2, 13, 1, 2);

        pushButton_35 = new QPushButton(frame);
        pushButton_35->setObjectName("pushButton_35");

        gridLayout->addWidget(pushButton_35, 1, 14, 1, 2);

        pushButton_39 = new QPushButton(frame);
        pushButton_39->setObjectName("pushButton_39");

        gridLayout->addWidget(pushButton_39, 2, 15, 1, 2);

        pushButton_47 = new QPushButton(frame);
        pushButton_47->setObjectName("pushButton_47");

        gridLayout->addWidget(pushButton_47, 3, 14, 1, 2);

        pushButton_36 = new QPushButton(frame);
        pushButton_36->setObjectName("pushButton_36");

        gridLayout->addWidget(pushButton_36, 1, 16, 1, 2);

        pushButton_43 = new QPushButton(frame);
        pushButton_43->setObjectName("pushButton_43");

        gridLayout->addWidget(pushButton_43, 2, 17, 1, 2);

        pushButton_48 = new QPushButton(frame);
        pushButton_48->setObjectName("pushButton_48");

        gridLayout->addWidget(pushButton_48, 3, 16, 1, 2);

        pushButton_42 = new QPushButton(frame);
        pushButton_42->setObjectName("pushButton_42");

        gridLayout->addWidget(pushButton_42, 1, 18, 1, 2);

        pushButton_50 = new QPushButton(frame);
        pushButton_50->setObjectName("pushButton_50");

        gridLayout->addWidget(pushButton_50, 2, 19, 1, 2);

        pushButton_51 = new QPushButton(frame);
        pushButton_51->setObjectName("pushButton_51");

        gridLayout->addWidget(pushButton_51, 3, 18, 1, 2);

        pushButton_49 = new QPushButton(frame);
        pushButton_49->setObjectName("pushButton_49");

        gridLayout->addWidget(pushButton_49, 1, 20, 1, 2);

        pushButton_53 = new QPushButton(frame);
        pushButton_53->setObjectName("pushButton_53");

        gridLayout->addWidget(pushButton_53, 2, 21, 1, 2);

        pushButton_54 = new QPushButton(frame);
        pushButton_54->setObjectName("pushButton_54");

        gridLayout->addWidget(pushButton_54, 3, 20, 1, 2);

        pushButton_52 = new QPushButton(frame);
        pushButton_52->setObjectName("pushButton_52");

        gridLayout->addWidget(pushButton_52, 1, 22, 1, 2);

        pushButton_8 = new QPushButton(frame);
        pushButton_8->setObjectName("pushButton_8");

        gridLayout->addWidget(pushButton_8, 3, 22, 1, 2);

        pushButton_29 = new QPushButton(frame);
        pushButton_29->setObjectName("pushButton_29");

        gridLayout->addWidget(pushButton_29, 4, 0, 1, 3);

        pushButton_30 = new QPushButton(frame);
        pushButton_30->setObjectName("pushButton_30");

        gridLayout->addWidget(pushButton_30, 4, 3, 1, 3);

        pushButton_56 = new QPushButton(frame);
        pushButton_56->setObjectName("pushButton_56");

        gridLayout->addWidget(pushButton_56, 4, 24, 1, 3);

        pushButton_57 = new QPushButton(frame);
        pushButton_57->setObjectName("pushButton_57");

        gridLayout->addWidget(pushButton_57, 4, 21, 1, 3);

        pushButton_40 = new QPushButton(frame);
        pushButton_40->setObjectName("pushButton_40");

        gridLayout->addWidget(pushButton_40, 4, 6, 1, 15);

        pushButton_5 = new QPushButton(frame);
        pushButton_5->setObjectName("pushButton_5");

        gridLayout->addWidget(pushButton_5, 1, 24, 1, 2);

        pushButton_6 = new QPushButton(frame);
        pushButton_6->setObjectName("pushButton_6");

        gridLayout->addWidget(pushButton_6, 2, 23, 1, 3);

        pushButton_55 = new QPushButton(frame);
        pushButton_55->setObjectName("pushButton_55");

        gridLayout->addWidget(pushButton_55, 3, 24, 1, 2);


        verticalLayout_10->addLayout(gridLayout);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");

        verticalLayout_10->addLayout(verticalLayout_9);

        stackedWidget->addWidget(pageTraining);
        pageResults = new QWidget();
        pageResults->setObjectName("pageResults");
        stackedWidget->addWidget(pageResults);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1255, 26));
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
        label->setText(QCoreApplication::translate("MainWindow", "Select a text for the typing exercise:", nullptr));
        layoutStartMain->setItemText(0, QCoreApplication::translate("MainWindow", "Starter Text", nullptr));
        layoutStartMain->setItemText(1, QCoreApplication::translate("MainWindow", "Numbers and Symbols", nullptr));
        layoutStartMain->setItemText(2, QCoreApplication::translate("MainWindow", "Common Words Part 1", nullptr));
        layoutStartMain->setItemText(3, QCoreApplication::translate("MainWindow", "Common Words Part 2", nullptr));
        layoutStartMain->setItemText(4, QCoreApplication::translate("MainWindow", "Python Code Sample", nullptr));
        layoutStartMain->setItemText(5, QCoreApplication::translate("MainWindow", "Lorem Ipsum", nullptr));

        pushButton->setText(QCoreApplication::translate("MainWindow", "Start Training", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Q", nullptr));
        pushButton_22->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "T", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Tab", nullptr));
        pushButton_31->setText(QCoreApplication::translate("MainWindow", "W", nullptr));
        pushButton_33->setText(QCoreApplication::translate("MainWindow", "E", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        pushButton_23->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_27->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_26->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "<-", nullptr));
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_20->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_24->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_21->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_25->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_19->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Caps", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        pushButton_32->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        pushButton_34->setText(QCoreApplication::translate("MainWindow", "S", nullptr));
        pushButton_28->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        pushButton_41->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "D", nullptr));
        pushButton_44->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "F", nullptr));
        pushButton_45->setText(QCoreApplication::translate("MainWindow", "V", nullptr));
        pushButton_37->setText(QCoreApplication::translate("MainWindow", "G", nullptr));
        pushButton_46->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        pushButton_38->setText(QCoreApplication::translate("MainWindow", "H", nullptr));
        pushButton_35->setText(QCoreApplication::translate("MainWindow", "U", nullptr));
        pushButton_39->setText(QCoreApplication::translate("MainWindow", "J", nullptr));
        pushButton_47->setText(QCoreApplication::translate("MainWindow", "N", nullptr));
        pushButton_36->setText(QCoreApplication::translate("MainWindow", "I", nullptr));
        pushButton_43->setText(QCoreApplication::translate("MainWindow", "K", nullptr));
        pushButton_48->setText(QCoreApplication::translate("MainWindow", "M", nullptr));
        pushButton_42->setText(QCoreApplication::translate("MainWindow", "O", nullptr));
        pushButton_50->setText(QCoreApplication::translate("MainWindow", "L", nullptr));
        pushButton_51->setText(QCoreApplication::translate("MainWindow", ",", nullptr));
        pushButton_49->setText(QCoreApplication::translate("MainWindow", "P", nullptr));
        pushButton_53->setText(QCoreApplication::translate("MainWindow", ";", nullptr));
        pushButton_54->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_52->setText(QCoreApplication::translate("MainWindow", "[", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButton_29->setText(QCoreApplication::translate("MainWindow", "Shift", nullptr));
        pushButton_30->setText(QCoreApplication::translate("MainWindow", "Ctrl", nullptr));
        pushButton_56->setText(QCoreApplication::translate("MainWindow", "Ctrl", nullptr));
        pushButton_57->setText(QCoreApplication::translate("MainWindow", "Shift", nullptr));
        pushButton_40->setText(QString());
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "]", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "<-----", nullptr));
        pushButton_55->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
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
