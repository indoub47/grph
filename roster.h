#ifndef ROSTER_H
#define ROSTER_H
#include <QString>
#include <QVector>
#include <QDate>
#include "daywork.h"

class Roster
{
public:
    Roster(){}
    Roster(QString name, QDate startDate, QDate endDate);
    Roster(QString name, QVector<Daywork> dayworks);
    QString getName() const;
    QVector<Daywork> getDayworks() const;
    QDate getStartDate() const;
    QDate getEndDate() const;
private:
    QString _name;
    QVector<Daywork> _dayworks;
};

#endif // ROSTER_H
