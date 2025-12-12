#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "addtransactiondialog.h"
#include "removedialog.h"
#include "editdialog.h"
#include "alltransactions.h"
#include <QMenuBar>
#include <QToolBar>
#include <QFile>
#include <QFileDialog>
#include <QAction>
#include <QLCDNumber>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->LcdShow->setDigitCount(12);
    ui->LcdShow->setSegmentStyle(QLCDNumber::Flat);

    fileName = "Menadżer Wydatków";
    setWindowTitle(fileName);
    this->setStyleSheet(
        "QLineEdit[error=\"true\"], QComboBox[error=\"true\"], QDateEdit[error=\"true\"] {"
        "    border: 1px solid red;"
        "    background-color: #FFCCCC;"
        "}"
        );


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_allButton_clicked()
{
    alltransactions *dialog = new alltransactions(this);
    this->hide();
    dialog->exec();
    this->show();
}



void MainWindow::on_editButton_clicked()
{
    editdialog *dialog = new editdialog(this);
    this->hide();
    dialog->exec();
    this->show();
}


void MainWindow::on_addButton_clicked()
{
    AddTransactionDialog *dialog = new AddTransactionDialog(this);
    this->hide();
    dialog->exec();
    this->show();
}


void MainWindow::on_removeButton_clicked()
{
    removeDialog *dialog = new removeDialog(this);
    this->hide();
    dialog->exec();
    this->show();
}

double MainWindow::liczWplywy()
{
    double sumaWplywy = 0.0;
    QSqlQuery query;
    if (query.exec("SELECT SUM(kwota) FROM Wydatki WHERE typ = 'Wplyw' OR  typ =  'Wpływ' ")) {
        if (query.next()) {
            sumaWplywy = query.value(0).toDouble();
        }
    } else {
        qDebug() << "Błąd zapytania wpływów:" << query.lastError().text();
    }
    return sumaWplywy;
}

double MainWindow::liczWydatki()
{
    double sumaWydatkow = 0.0;
    QSqlQuery query;
    if(query.exec("SELECT SUM(kwota) FROM Wydatki WHERE typ = 'Wydatek' "))
    {
        if(query.next())
        {
            sumaWydatkow = query.value(0).toDouble();
        }
    }
    else
    {
        qDebug() << "Błąd zapytania wpływów:" << query.lastError().text();
    }
    return sumaWydatkow;

}

double MainWindow::stanKonta()
{
    double sumaKonto = 0.0;
    QSqlQuery query;
    if(query.exec("SELECT (SELECT SUM(kwota) FROM Wydatki WHERE typ = 'Wpływ') - (SELECT SUM(kwota) FROM Wydatki WHERE typ = 'Wydatek') "))
        if(query.next())
        {
            sumaKonto = query.value(0).toDouble();
        }
    else
        {
            qDebug() << "Błąd zapytania stanu konta" << query.lastError().text();
        }
    return sumaKonto;
}

void MainWindow::on_wplywyButton_clicked()
{
    ui->LcdShow->display(liczWplywy());
}


void MainWindow::on_wyadatkiButton_clicked()
{
    ui->LcdShow->display(liczWydatki());
}


void MainWindow::on_stanKontaButton_clicked()
{
    ui->LcdShow->display(stanKonta());
}

