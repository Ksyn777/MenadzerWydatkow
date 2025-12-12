/********************************************************************************
** Form generated from reading UI file 'editdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDIALOG_H
#define UI_EDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_editdialog
{
public:
    QTableView *tableViewEdit;
    QPushButton *editButtomDialog;
    QLabel *labelEdit;

    void setupUi(QWidget *editdialog)
    {
        if (editdialog->objectName().isEmpty())
            editdialog->setObjectName("editdialog");
        editdialog->resize(415, 435);
        tableViewEdit = new QTableView(editdialog);
        tableViewEdit->setObjectName("tableViewEdit");
        tableViewEdit->setGeometry(QRect(50, 50, 311, 331));
        editButtomDialog = new QPushButton(editdialog);
        editButtomDialog->setObjectName("editButtomDialog");
        editButtomDialog->setGeometry(QRect(270, 400, 80, 24));
        labelEdit = new QLabel(editdialog);
        labelEdit->setObjectName("labelEdit");
        labelEdit->setGeometry(QRect(120, 20, 151, 16));

        retranslateUi(editdialog);

        QMetaObject::connectSlotsByName(editdialog);
    } // setupUi

    void retranslateUi(QWidget *editdialog)
    {
        editdialog->setWindowTitle(QCoreApplication::translate("editdialog", "Form", nullptr));
        editButtomDialog->setText(QCoreApplication::translate("editdialog", "Edytuj", nullptr));
        labelEdit->setText(QCoreApplication::translate("editdialog", "Co chcesz edytowa\304\207 ?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editdialog: public Ui_editdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDIALOG_H
