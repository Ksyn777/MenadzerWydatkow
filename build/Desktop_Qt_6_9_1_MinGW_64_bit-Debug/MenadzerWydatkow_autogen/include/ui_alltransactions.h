/********************************************************************************
** Form generated from reading UI file 'alltransactions.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLTRANSACTIONS_H
#define UI_ALLTRANSACTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_alltransactions
{
public:
    QTableView *allTableView;
    QComboBox *comboBoxFiltruj;
    QPushButton *filtrujButton;
    QLCDNumber *lcdNumberFiltruj;

    void setupUi(QWidget *alltransactions)
    {
        if (alltransactions->objectName().isEmpty())
            alltransactions->setObjectName("alltransactions");
        alltransactions->resize(483, 479);
        allTableView = new QTableView(alltransactions);
        allTableView->setObjectName("allTableView");
        allTableView->setGeometry(QRect(30, 50, 421, 401));
        comboBoxFiltruj = new QComboBox(alltransactions);
        comboBoxFiltruj->addItem(QString());
        comboBoxFiltruj->addItem(QString());
        comboBoxFiltruj->addItem(QString());
        comboBoxFiltruj->addItem(QString());
        comboBoxFiltruj->addItem(QString());
        comboBoxFiltruj->addItem(QString());
        comboBoxFiltruj->addItem(QString());
        comboBoxFiltruj->setObjectName("comboBoxFiltruj");
        comboBoxFiltruj->setGeometry(QRect(310, 10, 141, 31));
        filtrujButton = new QPushButton(alltransactions);
        filtrujButton->setObjectName("filtrujButton");
        filtrujButton->setGeometry(QRect(180, 10, 121, 31));
        lcdNumberFiltruj = new QLCDNumber(alltransactions);
        lcdNumberFiltruj->setObjectName("lcdNumberFiltruj");
        lcdNumberFiltruj->setGeometry(QRect(30, 10, 141, 31));

        retranslateUi(alltransactions);

        QMetaObject::connectSlotsByName(alltransactions);
    } // setupUi

    void retranslateUi(QWidget *alltransactions)
    {
        alltransactions->setWindowTitle(QCoreApplication::translate("alltransactions", "Form", nullptr));
        comboBoxFiltruj->setItemText(0, QCoreApplication::translate("alltransactions", "Zakupy", nullptr));
        comboBoxFiltruj->setItemText(1, QCoreApplication::translate("alltransactions", "Wp\305\202yw", nullptr));
        comboBoxFiltruj->setItemText(2, QCoreApplication::translate("alltransactions", "Wydatek", nullptr));
        comboBoxFiltruj->setItemText(3, QCoreApplication::translate("alltransactions", "Wyj\305\233cia", nullptr));
        comboBoxFiltruj->setItemText(4, QCoreApplication::translate("alltransactions", "Op\305\202aty", nullptr));
        comboBoxFiltruj->setItemText(5, QCoreApplication::translate("alltransactions", "Raty", nullptr));
        comboBoxFiltruj->setItemText(6, QCoreApplication::translate("alltransactions", "Wszystko", nullptr));

        filtrujButton->setText(QCoreApplication::translate("alltransactions", "Filtruj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class alltransactions: public Ui_alltransactions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLTRANSACTIONS_H
