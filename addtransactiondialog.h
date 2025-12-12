#ifndef ADDTRANSACTIONDIALOG_H
#define ADDTRANSACTIONDIALOG_H
#include "ui_addtransactiondialog.h"
#include "databasemanager.h"
#include <QComboBox>
#include <QWidget>
#include <QDialog>
#include "Category.h"
#include <QDate>
#include "globals.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AddTransactionDialog; }
QT_END_NAMESPACE
class AddTransactionDialog : public QDialog
{
    Q_OBJECT
private:
    Ui::AddTransactionDialog* ui;
    bool isEditMode();
public:
    explicit AddTransactionDialog(QWidget *parent = nullptr);
    ~AddTransactionDialog();
    void loadData();
    bool validate();
    void accept() override;
    QDateEdit* dataBox;
    QLineEdit* descriptionEdit;
    QComboBox* kategoriaBox;
    QDoubleSpinBox* kwotaEdit;
    QComboBox* wydatkiBox;
    void oznaczBlad(QWidget *widget, bool error);
   bool sprawdzBlad();





signals:
private slots:
    void on_dodajButton_clicked();
};

#endif // ADDTRANSACTIONDIALOG_H
