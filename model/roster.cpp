#include "roster.h"
#include <QString>
#include <QVector>
#include <QDate>
#include "daywork.h"
#include <QObject>

Roster::Roster(QString name, QDate startDay, QDate endDay)
{
    setObjectName(name);
    for (QDate d = startDay; d <= endDay; d.addDays(1))
    {
        _dayworks << new Daywork(d);
    }
}

Roster::Roster(QString name, QVector<Daywork*> dayworks)
{
    setObjectName(name);
    _dayworks = dayworks;
}

QVector<Daywork*> Roster::getDayworks() const
{
    return _dayworks;
}

QDate Roster::getStartDate() const
{
    return _dayworks.first()->getDate();
}

QDate Roster::getEndDate() const
{
    return _dayworks.last()->getDate();
}
