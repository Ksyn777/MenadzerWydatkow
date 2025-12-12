#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlDatabase>
#include <QDate>



DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent)
{
    // sterownik bazy
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Menadzer_Wydatkow_baza.db");
}


DatabaseManager::~DatabaseManager()
{
    if (db.isOpen()) {
        db.close();
        qDebug() << "Połączenie z bazą zamknięte.";
    }
}

DatabaseManager& DatabaseManager::getInstance()
{
    static DatabaseManager instance;
    return instance;
}

QSqlDatabase DatabaseManager::database()
{
    return db;
}

bool DatabaseManager::connectToDatabase()
{


    if (!db.open()) {
        qDebug() << "Błąd: Nie udało się otworzyć bazy danych!";
        return false;
    }
    qDebug() << "Połączono z bazą danych!";
    initTables();
    return true;

}



void DatabaseManager::initTables()
{
    QSqlQuery query;
    QString sql = "CREATE TABLE IF NOT EXISTS Wydatki ("
                            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                            "kategoria TEXT NOT NULL, "
                            "kwota REAL, "
                            "data DATE, "
                            "typ TEXT,"
                            "opis VARCHAR(20)) ";

    if (!query.exec(sql)) {
        qDebug() << "Błąd tworzenia tabeli:" << query.lastError().text();
    } else {
        qDebug() << "Tabela sprawdzona/utworzona.";
    }

}

bool DatabaseManager::dodajWydatek(const QString& kategoria, double kwota, const QDate& data, const QString& typ, const QString& opis)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Wydatki (kategoria, kwota, data, typ, opis)"
                  "Values (:kategoria, :kwota, :data, :typ, :opis)" );

    query.bindValue(":kategoria", kategoria);
    query.bindValue(":kwota", kwota);
    query.bindValue(":data", data);
    query.bindValue(":typ", typ);
    query.bindValue(":opis", opis);

    if(query.exec())
    {
        qDebug()<<"Sukces";
        return true;
    }
    else
    {
        qDebug()<<"Błąd!"<<query.lastError().text();
        return false;
    }


}

bool DatabaseManager::edytujWydatek(int id, const QString& kategoria, double kwota, const QDate& data, const QString& typ, const QString& opis)
{
    QSqlQuery query;
    // Używamy UPDATE ... WHERE id = :id
    query.prepare("UPDATE Wydatki SET kategoria=:kategoria, kwota=:kwota, data=:data, typ=:typ, opis=:opis WHERE id=:id");

    query.bindValue(":kategoria", kategoria);
    query.bindValue(":kwota", kwota);
    query.bindValue(":data", data);
    query.bindValue(":typ", typ);
    query.bindValue(":opis", opis);
    query.bindValue(":id", id); // To najważniejsze - wiemy który wiersz zmienić!

    if(query.exec()) {
        qDebug() << "Zaktualizowano wiersz ID:" << id;
        return true;
    } else {
        qDebug() << "Błąd edycji:" << query.lastError().text();
        return false;
    }
}


