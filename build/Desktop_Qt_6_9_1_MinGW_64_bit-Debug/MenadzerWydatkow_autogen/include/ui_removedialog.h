/********************************************************************************
** Form generated from reading UI file 'removedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOVEDIALOG_H
#define UI_REMOVEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_removeDialog
{
public:
    QTableView *removeTableView;
    QLabel *coUsunacLabel;
    QPushButton *pushButton;

    void setupUi(QWidget *removeDialog)
    {
        if (removeDialog->objectName().isEmpty())
            removeDialog->setObjectName("removeDialog");
        removeDialog->resize(452, 552);
        removeTableView = new QTableView(removeDialog);
        removeTableView->setObjectName("removeTableView");
        removeTableView->setGeometry(QRect(30, 50, 391, 431));
        removeTableView->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        removeTableView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        coUsunacLabel = new QLabel(removeDialog);
        coUsunacLabel->setObjectName("coUsunacLabel");
        coUsunacLabel->setGeometry(QRect(120, 10, 201, 31));
        coUsunacLabel->setFrameShape(QFrame::Shape::Box);
        coUsunacLabel->setScaledContents(false);
        pushButton = new QPushButton(removeDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(330, 500, 80, 24));

        retranslateUi(removeDialog);

        QMetaObject::connectSlotsByName(removeDialog);
    } // setupUi

    void retranslateUi(QWidget *removeDialog)
    {
        removeDialog->setWindowTitle(QCoreApplication::translate("removeDialog", "Form", nullptr));
        coUsunacLabel->setText(QCoreApplication::translate("removeDialog", "Wybierz co chcesz usun\304\205\304\207 ", nullptr));
        pushButton->setText(QCoreApplication::translate("removeDialog", "Usu\305\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class removeDialog: public Ui_removeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOVEDIALOG_H
