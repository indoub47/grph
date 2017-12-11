#include "swork.h"
#include <QString>

Swork::Swork(QString id, QString name)
{
	_id = id;
	_name = name;
}

QString Swork::getId() const
{
    return _id;
}

QString Swork::getName() const
{
    return _name;
}
