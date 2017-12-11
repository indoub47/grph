#include "linija.h"
#include <QString>

Linija::Linija(QString id, QString name)
{
    _id = id;
    _name = name;
}

QString Linija::getId() const
{
	return _id;
}

QString Linija::getName() const
{
    return _name;
}
