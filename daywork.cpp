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

void Daywork::addTeamTask(TeamTask teamTask)
{
  _teamTasks.append(teamTask);
}

QDate Daywork::getDate() const
{
    return _date;
}

QList<TeamTask> Daywork::getTeamTasks() const
{
    return _teamTasks;
}

QList<TeamTask> Daywork::getTTByAparatas(Aparatas aparatas) const
{
  QList<TeamTask> result;
  QListIterator<TeamTask> i(_teamTasks);
  while (i.hasNext())
  {
    TeamTask tt = i.next();
    if (tt.getTeam().getAparatai().contains(aparatas))
    {
      result << tt;
    }
  }
  return result;
}
