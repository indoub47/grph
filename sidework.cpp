#include "sidework.h"
#include <QString>
QString Sidework::getName() const
{
    return _name;
}

Sidework::Sidework(QString objectName, QString name)
{
   _name = name;
   setObjectName(objectName);
}
