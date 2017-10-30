#include "roster.h"
#include <QString>
#include <QVector>
#include <QDate>
#include "daywork.h"

Roster::Roster(QString name, QDate startDate, QDate endDate)
{
    _name = name;
    // daycount from startDate till endDate
    // create an empty _dayworks - a Daywork per each day
}
Roster::Roster(QString name, QVector<Daywork> dayworks)
{
    _name = name;
    _dayworks = dayworks;
}
QString Roster::getName() const
{
    return _name;
}
const QVector<Daywork>& Roster::getDayworks() const
{
    return _dayworks;
}
QDate Roster::getStartDate() const
{
    return _dayworks.first().getDate();
}
QDate Roster::getEndDate() const
{
    return _dayworks.last().getDate();
}
