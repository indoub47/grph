#include "daywork.h"
#include <QDate>
#include <QList>
#include "teamtask.h"
#include "aparatas.h"
#include <QlistIterator>
Daywork::Daywork(QDate date)
{
    _date = date;
    //_teamtasks = new QList<Teamtask>();
}

void Daywork::addTeamtask(Teamtask* teamtask)
{
  QList<Teamtask*>::iterator i;
  for (i = _teamtasks.begin(); i != _teamtasks.end(); ++i)
  {
      if ((*i)->getTeam() == teamtask->getTeam()) {
        (*i)->mergeSegmentai(teamtask->getSegmentai());
        (*i)->mergeSideworks(teamtask->getSideworks());
        return;
      }
  }
  _teamtasks << teamtask;
}

const QDate Daywork::getDate() const
{
    return _date;
}

const QList<Teamtask*> Daywork::getTeamtasks() const
{
    return _teamtasks;
}

const QList<Teamtask*> Daywork::getTTByAparatas(Aparatas* aparatas) const
{
  QList<Teamtask*> result;
  QListIterator<Teamtask*> i(_teamtasks);
  while (i.hasNext())
  {
    Teamtask* tt = i.next();
    if (tt->getTeam()->getAparatai().contains(aparatas))
    {
      result << tt;
    }
  }
  return result;
}

const QList<Teamtask *> Daywork::getTeamtasks(QString teamName) const
{
  QList<Teamtask*> result;
  QListIterator<Teamtask*> i(_teamtasks);
  while (i.hasNext())
  {
    Teamtask* tt = i.next();
    if (tt->getTeam()->objectName() == teamName)
    {
      result << tt;
    }
  }
  return result;
}

void Daywork::clearTeamtasks()
{
  _teamtasks.clear();
}

int Daywork::removeTeamtask(Teamtask* teamtask)
{
  return _teamtasks.removeAll(teamtask);
}
