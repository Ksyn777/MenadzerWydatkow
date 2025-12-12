#ifndef TRANSACTIONREPOSITORY_H
#define TRANSACTIONREPOSITORY_H

#include "transaction.h"
#include "databasemanager.h"
#include "globals.h"
#include <QList>
#include <QDate>
#include <QString>
#include <QSqlDatabase>

class TransactionRepository
{
private:
    QSqlDatabase db;



public:
    TransactionRepository();
    QList<Transaction> getAll();
    QList<Transaction> getFiltred(int categoryId, QDate dateFrom, QDate dateTo);
    bool add(const Transaction& t); // INSERT
    bool update(const Transaction& t); // UPDATE
    bool remove(int id);    // DELETE

};

#endif // TRANSACTIONREPOSITORY_H
