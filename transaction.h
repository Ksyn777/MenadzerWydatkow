#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "globals.h"
#include <QDate>
#include <QString>

class Transaction
{
private:
    int id;
    int categoryId;
    double amount;
    QDate date;
    QString description;
    globals::TransactionType type;
    QString categoryName;
public:
    Transaction() = default;
    Transaction(int _id, int _categoryId, double _amount, QDate _date, QString _description, globals::TransactionType _type, QString _categoryName) ;
    //gettery
    int getId() const;
    double getAmount() const;
    QDate getDate() const;
    QString getDescriptopn() const;
    globals::TransactionType getType() const;
    QString getCategoryName() const;
    //settery
    int setId(int _id);
    double setAmount(double _amount);
    QDate setDate(QDate _date);
    QString setDescriptopn(QString _description);
    globals::TransactionType setType(globals::TransactionType _type);
    QString setCategoryName(QString _categoryName);
    bool isID(int);



};

#endif // TRANSACTION_H
