#ifndef GLOBALS_H
#define GLOBALS_H

#include <QObject>

class globals : public QObject
{
    Q_OBJECT
public:
    explicit globals(QObject *parent = nullptr);
    enum TransactionType { wydatki,  wplywy };
    static TransactionType currentTransactionType;

signals:
};

#endif // GLOBALS_H
