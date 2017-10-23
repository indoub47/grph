#ifndef OPERATORIUS_H
#define OPERATORIUS_H
#include <QString>
class Operatorius
{
public:
    Operatorius(){};
    Operatorius(QString id, QString name, int level);
    QString  getId() const;
    QString  getName() const;
    int getLevel() const;
    QString  getShortName() const;
private:
    QString _id;
    QString _name;
    int _level;
};
#endif // OPERATORIUS_H
