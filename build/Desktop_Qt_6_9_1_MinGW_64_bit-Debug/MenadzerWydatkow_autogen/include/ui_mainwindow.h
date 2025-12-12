/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *editButton;
    QPushButton *removeButton;
    QPushButton *allButton;
    QPushButton *addButton;
    QLCDNumber *LcdShow;
    QPushButton *wplywyButton;
    QPushButton *wyadatkiButton;
    QPushButton *stanKontaButton;
    QMenuBar *fileMenu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(423, 453);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        editButton = new QPushButton(centralwidget);
        editButton->setObjectName("editButton");
        editButton->setGeometry(QRect(210, 70, 211, 181));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/edit.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        editButton->setIcon(icon);
        editButton->setIconSize(QSize(160, 160));
        removeButton = new QPushButton(centralwidget);
        removeButton->setObjectName("removeButton");
        removeButton->setGeometry(QRect(210, 250, 211, 181));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/remove.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        removeButton->setIcon(icon1);
        removeButton->setIconSize(QSize(160, 160));
        allButton = new QPushButton(centralwidget);
        allButton->setObjectName("allButton");
        allButton->setGeometry(QRect(0, 70, 211, 181));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/all.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        allButton->setIcon(icon2);
        allButton->setIconSize(QSize(160, 160));
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(0, 250, 211, 181));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/add.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        addButton->setIcon(icon3);
        addButton->setIconSize(QSize(160, 160));
        LcdShow = new QLCDNumber(centralwidget);
        LcdShow->setObjectName("LcdShow");
        LcdShow->setGeometry(QRect(0, 30, 421, 41));
        wplywyButton = new QPushButton(centralwidget);
        wplywyButton->setObjectName("wplywyButton");
        wplywyButton->setGeometry(QRect(0, 0, 141, 24));
        wyadatkiButton = new QPushButton(centralwidget);
        wyadatkiButton->setObjectName("wyadatkiButton");
        wyadatkiButton->setGeometry(QRect(140, 0, 141, 24));
        stanKontaButton = new QPushButton(centralwidget);
        stanKontaButton->setObjectName("stanKontaButton");
        stanKontaButton->setGeometry(QRect(280, 0, 141, 24));
        MainWindow->setCentralWidget(centralwidget);
        fileMenu = new QMenuBar(MainWindow);
        fileMenu->setObjectName("fileMenu");
        fileMenu->setGeometry(QRect(0, 0, 423, 21));
        MainWindow->setMenuBar(fileMenu);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        editButton->setToolTip(QCoreApplication::translate("MainWindow", "Edytuj transakcj\304\231", nullptr));
#endif // QT_CONFIG(tooltip)
        editButton->setText(QString());
#if QT_CONFIG(tooltip)
        removeButton->setToolTip(QCoreApplication::translate("MainWindow", "Usu\305\204 Transakcj\304\231", nullptr));
#endif // QT_CONFIG(tooltip)
        removeButton->setText(QString());
#if QT_CONFIG(tooltip)
        allButton->setToolTip(QCoreApplication::translate("MainWindow", "Wszystkie Transakcj\304\231", nullptr));
#endif // QT_CONFIG(tooltip)
        allButton->setText(QString());
#if QT_CONFIG(tooltip)
        addButton->setToolTip(QCoreApplication::translate("MainWindow", "Dodaj Transakcj\304\231", nullptr));
#endif // QT_CONFIG(tooltip)
        addButton->setText(QString());
        wplywyButton->setText(QCoreApplication::translate("MainWindow", "Wp\305\202ywy", nullptr));
        wyadatkiButton->setText(QCoreApplication::translate("MainWindow", "Wydatki", nullptr));
        stanKontaButton->setText(QCoreApplication::translate("MainWindow", "Stan Konta", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
