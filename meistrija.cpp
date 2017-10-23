#include "meistrija.h"
#include <QString>

Meistrija::Meistrija(QString name, QString shortName, int nr, QString meistras)
{
    _name = name;
    _shortName = shortName;
    _nr = nr;
    _meistras = meistras;
}

QString Meistrija::getName() const
{
    return _name;
}

QString Meistrija::getShortName() const
{
    return _shortName;
}

int Meistrija::getNr() const
{
    return _nr;
}

QString Meistrija::getMeistras() const
{
    return _meistras;
}
