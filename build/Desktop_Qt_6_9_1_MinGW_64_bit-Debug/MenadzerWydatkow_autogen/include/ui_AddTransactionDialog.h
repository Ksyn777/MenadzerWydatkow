/********************************************************************************
** Form generated from reading UI file 'AddTransactionDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTRANSACTIONDIALOG_H
#define UI_ADDTRANSACTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddTransactionDialog
{
public:
    QLabel *kategoriaLabel;
    QComboBox *kategoriaBox;
    QLabel *kwotaLabel;
    QLabel *opisLabel;
    QLineEdit *descriptionEdit;
    QDateEdit *dataBox;
    QLabel *dataLabel;
    QLabel *typLabel;
    QComboBox *wydatkiBox;
    QPushButton *dodajButton;
    QDoubleSpinBox *kwotaEdit;

    void setupUi(QWidget *AddTransactionDialog)
    {
        if (AddTransactionDialog->objectName().isEmpty())
            AddTransactionDialog->setObjectName("AddTransactionDialog");
        AddTransactionDialog->resize(379, 320);
        kategoriaLabel = new QLabel(AddTransactionDialog);
        kategoriaLabel->setObjectName("kategoriaLabel");
        kategoriaLabel->setGeometry(QRect(20, 20, 101, 31));
        kategoriaLabel->setFrameShape(QFrame::Shape::Box);
        kategoriaBox = new QComboBox(AddTransactionDialog);
        kategoriaBox->addItem(QString());
        kategoriaBox->addItem(QString());
        kategoriaBox->addItem(QString());
        kategoriaBox->addItem(QString());
        kategoriaBox->addItem(QString());
        kategoriaBox->addItem(QString());
        kategoriaBox->setObjectName("kategoriaBox");
        kategoriaBox->setGeometry(QRect(130, 20, 231, 31));
        kwotaLabel = new QLabel(AddTransactionDialog);
        kwotaLabel->setObjectName("kwotaLabel");
        kwotaLabel->setGeometry(QRect(20, 60, 101, 31));
        kwotaLabel->setFrameShape(QFrame::Shape::Box);
        opisLabel = new QLabel(AddTransactionDialog);
        opisLabel->setObjectName("opisLabel");
        opisLabel->setGeometry(QRect(20, 100, 101, 31));
        opisLabel->setFrameShape(QFrame::Shape::Box);
        descriptionEdit = new QLineEdit(AddTransactionDialog);
        descriptionEdit->setObjectName("descriptionEdit");
        descriptionEdit->setGeometry(QRect(130, 100, 231, 71));
        dataBox = new QDateEdit(AddTransactionDialog);
        dataBox->setObjectName("dataBox");
        dataBox->setGeometry(QRect(130, 180, 71, 31));
        dataLabel = new QLabel(AddTransactionDialog);
        dataLabel->setObjectName("dataLabel");
        dataLabel->setGeometry(QRect(20, 180, 101, 31));
        dataLabel->setFrameShape(QFrame::Shape::Box);
        typLabel = new QLabel(AddTransactionDialog);
        typLabel->setObjectName("typLabel");
        typLabel->setGeometry(QRect(20, 220, 101, 31));
        typLabel->setFrameShape(QFrame::Shape::Box);
        wydatkiBox = new QComboBox(AddTransactionDialog);
        wydatkiBox->addItem(QString());
        wydatkiBox->addItem(QString());
        wydatkiBox->setObjectName("wydatkiBox");
        wydatkiBox->setGeometry(QRect(130, 220, 131, 31));
        dodajButton = new QPushButton(AddTransactionDialog);
        dodajButton->setObjectName("dodajButton");
        dodajButton->setGeometry(QRect(140, 270, 181, 24));
        kwotaEdit = new QDoubleSpinBox(AddTransactionDialog);
        kwotaEdit->setObjectName("kwotaEdit");
        kwotaEdit->setGeometry(QRect(130, 60, 231, 31));

        retranslateUi(AddTransactionDialog);

        QMetaObject::connectSlotsByName(AddTransactionDialog);
    } // setupUi

    void retranslateUi(QWidget *AddTransactionDialog)
    {
        AddTransactionDialog->setWindowTitle(QCoreApplication::translate("AddTransactionDialog", "Form", nullptr));
        kategoriaLabel->setText(QCoreApplication::translate("AddTransactionDialog", "Kategoria", nullptr));
        kategoriaBox->setItemText(0, QCoreApplication::translate("AddTransactionDialog", "Zakupy", nullptr));
        kategoriaBox->setItemText(1, QCoreApplication::translate("AddTransactionDialog", "Wp\305\202ywy", nullptr));
        kategoriaBox->setItemText(2, QCoreApplication::translate("AddTransactionDialog", "Paliwo", nullptr));
        kategoriaBox->setItemText(3, QCoreApplication::translate("AddTransactionDialog", "Wyj\305\233cia", nullptr));
        kategoriaBox->setItemText(4, QCoreApplication::translate("AddTransactionDialog", "Op\305\202aty", nullptr));
        kategoriaBox->setItemText(5, QCoreApplication::translate("AddTransactionDialog", "Raty", nullptr));

        kwotaLabel->setText(QCoreApplication::translate("AddTransactionDialog", "Kwota", nullptr));
        opisLabel->setText(QCoreApplication::translate("AddTransactionDialog", "Opis", nullptr));
        dataLabel->setText(QCoreApplication::translate("AddTransactionDialog", "Data", nullptr));
        typLabel->setText(QCoreApplication::translate("AddTransactionDialog", "Typ", nullptr));
        wydatkiBox->setItemText(0, QCoreApplication::translate("AddTransactionDialog", "Wp\305\202ywy", nullptr));
        wydatkiBox->setItemText(1, QCoreApplication::translate("AddTransactionDialog", "Wydatki", nullptr));

        dodajButton->setText(QCoreApplication::translate("AddTransactionDialog", "Dodaj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddTransactionDialog: public Ui_AddTransactionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTRANSACTIONDIALOG_H
