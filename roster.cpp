#include "roster.h"
#include <QString>
#include <QVector>
#include <QDate>
#include "daywork.h"

Roster::Roster(QString objectName, QDate startDay, QDate endDay)
{
  setObjectName(objectName);
  for (d = startDay; d <= endDay; d.addDays(1))
  {
    _dayworks << &Daywork(d);
  }
}

Roster::Roster(QString name, QVector<Daywork*> dayworks)
{
    _name = name;
    _dayworks = dayworks;
}
const QVector<Daywork*> Roster::getDayworks() const
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

void Roster::deleteLinija(Linija* linija)
{
  QList<Daywork*>::iterator idw;
  for (idw = _dayworks.begin(); idw != _dayworks.end(); ++idw)
  {
    QList<Teamtask*> tts = (*idw)->getTeamtasks();
    QList<Teamtask*>::iterator itt;
    for (itt = tts.begin(); itt != tts.end(); +itt)
    {
      QList<Segmentas*> ss = (*itt)->getSegmentai();
      QList<Segmentas*>::iterator is;
      for (is = ss.begin(); is != ss.end(); ++is)
      {
        if ((*is)->getLinija() == linija)
          (*is)->removeLinija();
      }
    }
  }
}
