#include "daywork.h"
#include <QDate>
#include <QList>
#include "teamtask.h"
#include "apar.h"
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
            (*i)->mergeSegms(teamtask->getSegms());
            (*i)->mergeSworks(teamtask->getSworks());
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

const QList<Teamtask*> Daywork::getTTByApar(Apar* apar) const
{
    QList<Teamtask*> result;
    QListIterator<Teamtask*> i(_teamtasks);
    while (i.hasNext())
    {
        Teamtask* tt = i.next();
        if (tt->getTeam()->getApars().contains(apar))
        {
            result << tt;
        }
    }
    return result;
}

const QList<Teamtask *> Daywork::getTeamtasks(QString teamId) const
{
    QList<Teamtask*> result;
    QListIterator<Teamtask*> i(_teamtasks);
    while (i.hasNext())
    {
        Teamtask* tt = i.next();
        if (tt->getTeam()->getId() == teamId)
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
