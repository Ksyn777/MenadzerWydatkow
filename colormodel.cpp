#include "colormodel.h"
#include <QSqlRecord>
#include <QSqlTableModel>

ColorModel::ColorModel(QObject *parent, QSqlDatabase db)
    : QSqlTableModel(parent, db)
{

}

QVariant ColorModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::BackgroundRole)
    {
        QSqlRecord rek = record(index.row());
        QString typ = rek.value("typ").toString();
        if(typ.trimmed() == "Wpływ" || typ.trimmed() == "Wpływy" || typ.trimmed() == "Wlpywy")
        {
            return QColor(200, 255, 200);
        }
        else if (typ.trimmed() == "Wydatek") {
            return QColor(255, 200, 200);
        }
    }
    return QSqlTableModel::data(index, role);
}
