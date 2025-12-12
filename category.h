#ifndef CATEGORY_H
#define CATEGORY_H

#include <QString>

class Category
{
private:
    int id;
    QString name;
public:
    Category(int _id, QString& _name);
    int getId() const;
    QString getName() const;
    int setId(int _id);
    QString setName(QString& _name);



};

#endif // CATEGORY_H
