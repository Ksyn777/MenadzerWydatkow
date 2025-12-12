#include "addtransactiondialog.h"
#include "ui_AddTransactionDialog.h"
#include <QDate>
#include <QString>
#include <QTime>
#include "globals.h"
#include "databasemanager.h"
#include <QMessageBox>
#include <QDate>

AddTransactionDialog::AddTransactionDialog(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::AddTransactionDialog)
{
    ui->setupUi(this);
    ui->dataBox->setDate(QDate::currentDate());
    ui->dataBox->setCalendarPopup(true);
    ui->kwotaEdit->setRange(0, 9999999);
    ui->kwotaEdit->setDecimals(2);

}
AddTransactionDialog::~AddTransactionDialog() {}

void AddTransactionDialog::accept()
{

    QDialog::accept();   // zamknięcie okna
}

void AddTransactionDialog::loadData()
{
    QDate pobrana_data = ui->dataBox->date();
    QString opis = ui->descriptionEdit->text();
    QString kategoria = ui->kategoriaBox->currentText();
    double kwota = ui->kwotaEdit->value();

    QString tekst_typ = ui->wydatkiBox->currentText();
    QString typDlaBazy;

    if(tekst_typ.startsWith("Wpływ") || tekst_typ.startsWith("Wplyw"))
    {
        typDlaBazy = "Wpływ";
    }
    else
    {
        typDlaBazy = "Wydatek";
    }

  bool sukces = DatabaseManager::getInstance().dodajWydatek(kategoria, kwota, pobrana_data, typDlaBazy, opis);
    if (sukces) {
        QMessageBox::information(this, "Sukces", "Dodano nowy wpis!");
        this->accept(); // Zamykamy okno dodawania
    }
    else {
        QMessageBox::critical(this, "Błąd", "Nie udało się zapisać do bazy danych.\nSprawdź logi aplikacji.");
    }

}

void AddTransactionDialog::oznaczBlad(QWidget *widget, bool error)
{
    widget->setProperty("error", error);
    widget->style()->unpolish(widget);
    widget->style()->polish(widget);
};

bool AddTransactionDialog::sprawdzBlad()
{
    bool czy_blad = false;
    if(ui->kategoriaBox->currentIndex() == -1)
    {
        oznaczBlad(ui->kategoriaBox, true);
        czy_blad = true;
    }
    else
    {
        oznaczBlad(ui->kategoriaBox, false);
    }
    if(ui->descriptionEdit->text().trimmed().isEmpty())
    {
        oznaczBlad(ui->descriptionEdit, true);
        czy_blad = true;
    }
    else
    {
        oznaczBlad(ui->descriptionEdit, false);
    }
    if(ui->wydatkiBox->currentIndex() == -1)
    {
        oznaczBlad(ui->wydatkiBox, true);
        czy_blad = true;
    }
    else
    {
        oznaczBlad(ui->wydatkiBox, false);
    }
    QDate dataDomyslna(2025, 1, 1);
    if(ui->dataBox->date() == dataDomyslna)
    {
        oznaczBlad(ui->dataBox, true);
        czy_blad = true;
    }
    else
    {
        oznaczBlad(ui->dataBox, false);
    }
    if(czy_blad)
    {
        qDebug() << "Formularz zawiera błedy";
        return false;
    }
    qDebug() << "Wszytsko się zgadza";
    return true;
}

void AddTransactionDialog::on_dodajButton_clicked()
{
    if(sprawdzBlad() == true)
    {
        loadData();
    }
    else
    {
        QMessageBox::warning(this, "Błąd", "Popraw zaznaczone pola przed zapisaniem.");
    }

}

