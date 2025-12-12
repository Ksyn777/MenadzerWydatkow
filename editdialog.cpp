#include "editdialog.h"
#include "ui_editdialog.h"
#include "databasemanager.h"
#include <QMessageBox>
#include <QSqlError>

editdialog::editdialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::editdialog)
{
    ui->setupUi(this);
    modelEdit = new ColorModel(this, DatabaseManager::getInstance().database());
    modelEdit->setTable("wydatki");
    modelEdit->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelEdit->select();

    modelEdit->setHeaderData(0, Qt::Horizontal, tr("ID"));
    modelEdit->setHeaderData(1, Qt::Horizontal, tr("Kategoria"));
    modelEdit->setHeaderData(2, Qt::Horizontal, tr("Kwota"));
    modelEdit->setHeaderData(3, Qt::Horizontal, tr("Data"));
    modelEdit->setHeaderData(4, Qt::Horizontal, tr("Typ"));
    modelEdit->setHeaderData(5, Qt::Horizontal, tr("Opis"));

    ui->tableViewEdit->setModel(modelEdit);


    ui->tableViewEdit->hideColumn(0);


    ui->tableViewEdit->resizeColumnsToContents();


    ui->tableViewEdit->horizontalHeader()->setStretchLastSection(true);
}

editdialog::~editdialog()
{
    delete ui;
}

void editdialog::on_editButtomDialog_clicked()
{


        for(int i = 0; i < modelEdit->rowCount(); ++i) {


            if(!modelEdit->isDirty(modelEdit->index(i, 0))) continue;


            double kwota = modelEdit->data(modelEdit->index(i, 2)).toDouble();
            QString opis = modelEdit->data(modelEdit->index(i, 5)).toString();
            QVariant var = modelEdit->data(modelEdit->index(i, 3));
            QString text = var.toString();
            QDate nowa_data = QDate::fromString(text, Qt::ISODate);
            if (!nowa_data.isValid())
                nowa_data = QDate::fromString(text, "dd-MM-yyyy");



            if (kwota < 0) {
                QMessageBox::warning(this, "Błąd", "Wiersz " + QString::number(i+1) + ": Kwota nie może być ujemna!");
                return;
            }

            if (opis.isEmpty()) {
                QMessageBox::warning(this, "Błąd", "Wiersz " + QString::number(i+1) + ": Opis nie może być pusty!");
                return;
            }
        }


        if (modelEdit->submitAll()) {
            QMessageBox::information(this, "Sukces", "Zmiany zostały zapisane w bazie.");
        } else {
            QMessageBox::critical(this, "Błąd SQL", "Nie udało się zapisać: " + modelEdit->lastError().text());
        }

}

