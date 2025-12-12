#ifndef ALLTRANSACTIONS_H
#define ALLTRANSACTIONS_H

#include <QWidget>
#include <QDialog>
#include <QSqlTableModel>
#include "ColorModel.h"
#include <QComboBox>
#include <QSortFilterProxyModel>
#include <QStandardItemModel>
#include <QLCDNumber>
#include <QString>


namespace Ui {
class alltransactions;
}

class alltransactions : public QDialog
{
    Q_OBJECT

public:
    explicit alltransactions(QWidget *parent = nullptr);
    ~alltransactions();
    QComboBox* comboBoxFiltruj;
    void filtruj();
    QStandardItemModel *sourceModel;
    QSortFilterProxyModel *proxyModel;
    QLCDNumber* lcdNumberFiltruj;
    double liczKonkret(QString nazwaKolumny, QString wartosc);




private slots:
    void on_filtrujButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::alltransactions *ui;
    ColorModel* model;
};

#endif // ALLTRANSACTIONS_H
