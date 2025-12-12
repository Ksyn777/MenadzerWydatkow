#include "removedialog.h"
#include "ui_removedialog.h"
#include "databasemanager.h"
#include <QMessageBox>
#include <QSqlError>

removeDialog::removeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removeDialog)
{
    ui->setupUi(this);
    modelRemove = new ColorModel(this, DatabaseManager::getInstance().database());
    modelRemove->setTable("wydatki");
    modelRemove->select();

    modelRemove->setHeaderData(0, Qt::Horizontal, tr("ID"));
    modelRemove->setHeaderData(1, Qt::Horizontal, tr("Kategoria"));
    modelRemove->setHeaderData(2, Qt::Horizontal, tr("Kwota"));
    modelRemove->setHeaderData(3, Qt::Horizontal, tr("Data"));
    modelRemove->setHeaderData(4, Qt::Horizontal, tr("Typ"));
    modelRemove->setHeaderData(5, Qt::Horizontal, tr("Opis"));

    ui->removeTableView->setModel(modelRemove);


    ui->removeTableView->hideColumn(0);


    ui->removeTableView->resizeColumnsToContents();


    ui->removeTableView->horizontalHeader()->setStretchLastSection(true);
}



void removeDialog::removeRow( QModelIndex indeks)
{

        QMessageBox::StandardButton odp;
        odp = QMessageBox::question(this, "Usuwanie", "Czy na pewno chcesz usunąć ten wpis?",
                                    QMessageBox::Yes | QMessageBox::No);

        if (odp == QMessageBox::No)
        {
            return;
        }

        // 3. Usuń wiersz z modelu
        // Pobieramy numer wiersza (row) z indeksu
        modelRemove->removeRow(indeks.row());

        // 4. Zatwierdź zmiany w bazie danych
        // Bez tego wiersz zniknie tylko z ekranu, a po restarcie wróci!
        if (modelRemove->submitAll())
        {
            // Udało się usunąć z bazy
            modelRemove->select(); // Odśwież widok (dla pewności)
        }
        else
        {
            QMessageBox::critical(this, "Błąd", "Nie udało się usunąć z bazy: " + modelRemove->lastError().text());
        }

}


removeDialog::~removeDialog()
{
    delete ui;

}


void removeDialog::on_pushButton_clicked()
{
    QModelIndex indeks = ui->removeTableView->currentIndex();

    if (!indeks.isValid()) {
        QMessageBox::warning(this, "Błąd", "Najpierw zaznacz wiersz do usunięcia!");

    }
    else
    {
        removeRow(indeks);
    }

}

