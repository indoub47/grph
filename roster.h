#ifndef ROSTER_H
#define ROSTER_H
#include <QString>
#include <QVector>
#include <QDate>
#include "daywork.h"
#include <QObject>
#include <linija.h>

class Roster : public QObject
{
  Q_OBJECT
public:
    Roster(){}
    Roster(QString objectName, QDate startDay, QDate endDay);
    Roster(QString objectName, QVector<Daywork*> dayworks);
    const QVector<Daywork*> getDayworks() const;
    QDate getStartDate() const;
    QDate getEndDate() const;

    void deleteLinija(Linija*);
private:
    QVector<Daywork*> _dayworks;
};

#endif // ROSTER_H
