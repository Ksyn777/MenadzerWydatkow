#ifndef COLORMODEL_H
#define COLORMODEL_H

#include <QObject>
#include <QSqlTableModel>
#include <QColor>

class ColorModel : public QSqlTableModel
{
    Q_OBJECT
public:
    explicit ColorModel(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

signals:
};

#endif // COLORMODEL_H
