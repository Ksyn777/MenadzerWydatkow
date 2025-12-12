#include "alltransactions.h"
#include "ui_alltransactions.h"
#include "globals.h"
#include "databasemanager.h"
#include "ColorModel.h"
#include <QSortFilterProxyModel>
#include <QComboBox>
#include <QSortFilterProxyModel>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QSqlError>

alltransactions::alltransactions(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::alltransactions)
{
    ui->setupUi(this);
    model = new ColorModel(this, DatabaseManager::getInstance().database());
    QHeaderView* header = ui->allTableView->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::ResizeToContents);

    model->setTable("Wydatki");
    model->setHeaderData(1, Qt::Horizontal, "Kategoria");
    model->setHeaderData(2, Qt::Horizontal, "Kwota");
    model->setHeaderData(3, Qt::Horizontal, "Data");
    model->setHeaderData(4, Qt::Horizontal, "Typ");
    model->setHeaderData(5, Qt::Horizontal, "Opis");


    model->select();

    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);
    ui->allTableView->setModel(proxyModel);

    ui->allTableView->setSortingEnabled(true);

    ui->allTableView->hideColumn(0);
    header->setStretchLastSection(true);

    ui->lcdNumberFiltruj->setDigitCount(12);
    ui->lcdNumberFiltruj->setSegmentStyle(QLCDNumber::Flat);


}

alltransactions::~alltransactions()
{
    delete ui;
}

double alltransactions::liczKonkret(QString nazwaKolumny, QString wartosc)
{
    double suma = 0.0;
    QSqlQuery query;
    QString sql = "SELECT SUM(kwota) FROM Wydatki WHERE " + nazwaKolumny + " = :val";

    query.prepare(sql);
    query.bindValue(":val", wartosc);

    if (query.exec()) {           //Wyślij zapytanie
        if (query.next()) {       // Przejdź do wyniku
            suma = query.value(0).toDouble(); //  Pobierz liczbę
        }
    } else {
        qDebug() << "Błąd SQL:" << query.lastError().text();
    }
    // -----------------------

    return suma;
}

void alltransactions::filtruj()
{

    QString tekst = ui->comboBoxFiltruj->currentText();
    proxyModel->setFilterFixedString("");
    double suma = 0;

    if(tekst == "Wszystko")
    {
        proxyModel->setFilterFixedString("");
        QSqlQuery query("SELECT SUM(kwota) FROM Wydatki");
        if(query.next())
        {
            suma = query.value(0).toDouble();
        }

    }
    else
    {
        int numerKolumny = 1;
        QString nazwaKolumny = "Kategoria";

        if(tekst == "Wydatek" || tekst == "Wpływ")
        {
            numerKolumny = 4;
            nazwaKolumny = "Typ";
        }
        proxyModel->setFilterKeyColumn(numerKolumny);
        proxyModel->setFilterFixedString(tekst);
        suma = liczKonkret(nazwaKolumny, tekst);
    }
    ui->lcdNumberFiltruj->display(suma);


}

void alltransactions::on_filtrujButton_clicked()
{
    filtruj();
}


void alltransactions::on_pushButton_clicked()
{

}

