#include "team.h"
#include <QString>
#include <QList>
#include "oper.h"
#include "apar.h"
#include <QListIterator>

Team::Team(QString id)
{
    _id = id;
}

Team::Team(QString id, QList<Oper*> opers, QList<Apar*> apars)
{
    _id = id;
    _opers = opers;
    _apars = apars;
}

const QList<Oper*> Team::getOpers() const
{
    return _opers;
}

const QList<Apar*> Team::getApars() const
{
    return _apars;
}


const Oper* Team::getOper(int indx) const
{
    return _opers.at(indx);
}

const Apar* Team::getApar(int indx) const
{
    return _apars.at(indx);
}

QString Team::getId() const
{
    return _id;
}

void Team::setOpers(QList<Oper*> opers)
{
    _opers = opers;
}

void Team::setApars(QList<Apar*> apars)
{
    _apars = apars;
}

void Team::clearOpers()
{
    _opers.clear();
}

void Team::clearApars()
{
    _apars.clear();
}

void Team::addOper(Oper* oper)
{
    if (!_opers.contains(oper))
        _opers.append(oper);
}

void Team::addApar(Apar* apar)
{
    if (!_apars.contains(apar))
        _apars.append(apar);
}

int Team::removeOper(Oper* oper)
{
    return _opers.removeAll(oper);
}

int Team::removeApar(Apar* apar)
{
    return _apars.removeAll(apar);
}

bool operator== (const Team& l, const Team& r)
{
    if (l._id != r._id)
        return false;

    if (l._apars.count() != r._apars.count())
        return false;

    QList<Apar*>::const_iterator ia;
    for (ia = l._apars.begin(); ia != l._apars.end(); ++ia)
    {
        if (!r._apars.contains(*ia))
            return false;
    }

    if (l._opers.count() != r._opers.count())
        return false;

    QList<Oper*>::const_iterator io;
    for (io = l._opers.begin(); io != l._opers.end(); ++io)
    {
        if (!r._opers.contains(*io))
            return false;
    }

    return true;
}



