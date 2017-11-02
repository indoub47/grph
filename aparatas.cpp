#include "aparatas.h"
#include <QString>
Aparatas::Aparatas(QString name, QString model, int level)
{
    setObjectName(name);
    _model = model;
    _level = level;
}

QString Aparatas::getModel() const
{
    return _model;
}

int Aparatas::getLevel() const
{
    return _level;
}


