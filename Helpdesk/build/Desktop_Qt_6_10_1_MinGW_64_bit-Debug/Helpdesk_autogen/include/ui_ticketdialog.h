/********************************************************************************
** Form generated from reading UI file 'ticketdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICKETDIALOG_H
#define UI_TICKETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_TicketDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QPushButton *btnEdit;
    QLabel *label;
    QLineEdit *editId;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *editCreated;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *btnClose;
    QComboBox *comboStatus;
    QLabel *label_5;
    QComboBox *comboPriority;
    QSpacerItem *horizontalSpacer;
    QTextEdit *editDescription;
    QLineEdit *editTitle;
    QPushButton *btnCancel;
    QPushButton *btnSave;

    void setupUi(QDialog *TicketDialog)
    {
        if (TicketDialog->objectName().isEmpty())
            TicketDialog->setObjectName("TicketDialog");
        TicketDialog->resize(853, 574);
        horizontalLayout = new QHBoxLayout(TicketDialog);
        horizontalLayout->setObjectName("horizontalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        btnEdit = new QPushButton(TicketDialog);
        btnEdit->setObjectName("btnEdit");

        gridLayout->addWidget(btnEdit, 7, 2, 1, 1);

        label = new QLabel(TicketDialog);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        editId = new QLineEdit(TicketDialog);
        editId->setObjectName("editId");

        gridLayout->addWidget(editId, 0, 1, 1, 3);

        label_4 = new QLabel(TicketDialog);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_6 = new QLabel(TicketDialog);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        editCreated = new QLineEdit(TicketDialog);
        editCreated->setObjectName("editCreated");

        gridLayout->addWidget(editCreated, 4, 1, 1, 3);

        label_2 = new QLabel(TicketDialog);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(TicketDialog);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        btnClose = new QPushButton(TicketDialog);
        btnClose->setObjectName("btnClose");

        gridLayout->addWidget(btnClose, 7, 3, 1, 1);

        comboStatus = new QComboBox(TicketDialog);
        comboStatus->addItem(QString());
        comboStatus->addItem(QString());
        comboStatus->addItem(QString());
        comboStatus->setObjectName("comboStatus");

        gridLayout->addWidget(comboStatus, 3, 1, 1, 3);

        label_5 = new QLabel(TicketDialog);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        comboPriority = new QComboBox(TicketDialog);
        comboPriority->addItem(QString());
        comboPriority->addItem(QString());
        comboPriority->addItem(QString());
        comboPriority->setObjectName("comboPriority");

        gridLayout->addWidget(comboPriority, 2, 1, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 7, 1, 1, 1);

        editDescription = new QTextEdit(TicketDialog);
        editDescription->setObjectName("editDescription");

        gridLayout->addWidget(editDescription, 6, 0, 1, 4);

        editTitle = new QLineEdit(TicketDialog);
        editTitle->setObjectName("editTitle");

        gridLayout->addWidget(editTitle, 1, 1, 1, 3);

        btnCancel = new QPushButton(TicketDialog);
        btnCancel->setObjectName("btnCancel");

        gridLayout->addWidget(btnCancel, 8, 3, 1, 1);

        btnSave = new QPushButton(TicketDialog);
        btnSave->setObjectName("btnSave");

        gridLayout->addWidget(btnSave, 8, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(TicketDialog);

        QMetaObject::connectSlotsByName(TicketDialog);
    } // setupUi

    void retranslateUi(QDialog *TicketDialog)
    {
        TicketDialog->setWindowTitle(QCoreApplication::translate("TicketDialog", "Dialog", nullptr));
        btnEdit->setText(QCoreApplication::translate("TicketDialog", "Edit", nullptr));
        label->setText(QCoreApplication::translate("TicketDialog", "ID:", nullptr));
        label_4->setText(QCoreApplication::translate("TicketDialog", "Status:", nullptr));
        label_6->setText(QCoreApplication::translate("TicketDialog", "Description", nullptr));
        label_2->setText(QCoreApplication::translate("TicketDialog", "Title:", nullptr));
        label_3->setText(QCoreApplication::translate("TicketDialog", "Priority:", nullptr));
        btnClose->setText(QCoreApplication::translate("TicketDialog", "Close", nullptr));
        comboStatus->setItemText(0, QCoreApplication::translate("TicketDialog", "Open", nullptr));
        comboStatus->setItemText(1, QCoreApplication::translate("TicketDialog", "In Progress", nullptr));
        comboStatus->setItemText(2, QCoreApplication::translate("TicketDialog", "Closed", nullptr));

        label_5->setText(QCoreApplication::translate("TicketDialog", "Created:", nullptr));
        comboPriority->setItemText(0, QCoreApplication::translate("TicketDialog", "Low", nullptr));
        comboPriority->setItemText(1, QCoreApplication::translate("TicketDialog", "Medium", nullptr));
        comboPriority->setItemText(2, QCoreApplication::translate("TicketDialog", "High", nullptr));

        btnCancel->setText(QCoreApplication::translate("TicketDialog", "Cancel", nullptr));
        btnSave->setText(QCoreApplication::translate("TicketDialog", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TicketDialog: public Ui_TicketDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICKETDIALOG_H
