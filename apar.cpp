#include "apar.h"
#include <QString>
Apar::Apar(QString id, QString model, int level)
{
    _id = id;
    _model = model;
    _level = level;
}

QString Apar::getId() const
{
  return _id;
}

QString Apar::getModel() const
{
    return _model;
}

int Apar::getLevel() const
{
    return _level;
}


