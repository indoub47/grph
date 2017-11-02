#include "linija.h"
#include <QString>

Linija::Linija(QString objectName, QString name)
{
    setObjectName(objectName);
     _name = name;
}

QString Linija::getName() const
{
    return _name;
}
