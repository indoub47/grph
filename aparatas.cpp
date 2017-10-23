#include "aparatas.h"
#include <QString>
Aparatas::Aparatas(QString id, QString model, int level)
{
    _id = id;
    _model = model;
    _level = level;
}

QString Aparatas::getId() const
{
    return _id;
}

QString Aparatas::getModel() const
{
    return _model;
}

int Aparatas::getLevel() const
{
    return _level;
}
