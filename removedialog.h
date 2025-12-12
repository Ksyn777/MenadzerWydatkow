#ifndef REMOVEDIALOG_H
#define REMOVEDIALOG_H

#include <QDialog>
#include <QSqlTableModel>
#include "ColorModel.h"

namespace Ui {
class removeDialog;
}

class removeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit removeDialog(QWidget *parent = nullptr);
    ~removeDialog();
    ColorModel *modelRemove;
    bool sprawdzZaznaczenie();
    void removeRow(QModelIndex indeks);


private slots:


    void on_pushButton_clicked();

private:
    Ui::removeDialog *ui;

};

#endif // REMOVEDIALOG_H
