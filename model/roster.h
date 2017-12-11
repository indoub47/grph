#ifndef ROSTER_H
#define ROSTER_H
#include <QString>
#include <QVector>
#include <QDate>
#include "model/daywork.h"
#include <QObject>
#include "model/linija.h"

class Roster : public QObject
{
    Q_OBJECT
public:
    Roster(){}
    Roster(QString name, QDate startDay, QDate endDay);
    Roster(QString name, QVector<Daywork*> dayworks);
    QVector<Daywork*> getDayworks() const;
    QDate getStartDate() const;
    QDate getEndDate() const;
private:
    QVector<Daywork*> _dayworks;
};

#endif // ROSTER_H
