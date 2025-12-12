#include "transaction.h"

Transaction::Transaction(int _id, int _categoryId, double _amount, QDate _date, QString _description, globals::TransactionType _type, QString _categoryName)
    : id(_id), categoryId(_categoryId), amount(_amount), date(_date), description(_description), categoryName(_categoryName) {}
