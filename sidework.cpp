#include "sidework.h"
#include <QString>
QString Sidework::getName() const
{
    return _name;
}

QString Sidework::getFullName() const
{
     return _fullName;
}

Sidework::Sidework(QString name, QString fullName)
 {
     _name = name;
     _fullName = fullName;
 }
