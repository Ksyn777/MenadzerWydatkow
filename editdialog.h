#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QWidget>
#include <QDialog>
#include <QSqlTableModel>
#include "ColorModel.h"

namespace Ui {
class editdialog;
}

class editdialog : public QDialog
{
    Q_OBJECT

public:
    explicit editdialog(QWidget *parent = nullptr);
    ~editdialog();
    ColorModel *modelEdit;

private slots:
    void on_editButtomDialog_clicked();

private:
    Ui::editdialog *ui;
};

#endif // EDITDIALOG_H
