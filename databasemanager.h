#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include "globals.h"
#include <QList>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QDate>

class DatabaseManager : public QObject
{
    Q_OBJECT

private:
    QSqlDatabase db;
    explicit DatabaseManager(QObject *parent = nullptr);

    void initTables();
public:
    ~DatabaseManager();
    static DatabaseManager& getInstance(); // zwraca singleton
    bool connectToDatabase();
    QSqlDatabase database();        // dostęp do QSqlDatabase
    bool dodajWydatek(const QString& kategoria, double kwota, const QDate& data,const QString& typ,  const QString& opis);
    bool edytujWydatek(int id, const QString& kategoria, double kwota, const QDate& data, const QString& typ, const QString& opis);
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;


signals:
};

#endif // DATABASEMANAGER_H
