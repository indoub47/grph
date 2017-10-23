#include "operatorius.h"
#include <QString>
Operatorius::Operatorius(QString id, QString name, int level)
{
    _id = id;
    _name = name;
    _level = level;
}

QString Operatorius::getId() const
{
    return _id;
}

QString Operatorius::getName() const
{
    return _name;
}

int Operatorius::getLevel() const
{
    return _level;
}

QString Operatorius::Operatorius::getShortName() const
{
    // _name must be split by space and the first item
    // used as the first letter with period
    return _name;
}
