#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "transactionrepository.h"
#include <QDate>
#include  <QMenu>
#include <QAction>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    TransactionRepository* transactioRepo;
    int filtredCategoryId;
    QDate filtredDateFrom;
    QDate filtredDateTo;
    void setupUI();
    QString fileName;
    void oznaczBlad(QWidget *widget, bool error);




public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void refreshTransactionList();
    double liczWplywy();
    double liczWydatki();
    double stanKonta();
private slots:
    void on_allButton_clicked();
    void on_editButton_clicked();
    void on_addButton_clicked();
    void on_removeButton_clicked();
    void on_wplywyButton_clicked();
    void on_wyadatkiButton_clicked();
    void on_stanKontaButton_clicked();
};
#endif // MAINWINDOW_H
