#include "daywork.h"
#include <QDate>
#include <QVector>
#include "teamtask.h"
Daywork::Daywork(QDate date)
{
    _date = date;
    //_teamtasks = new QVector<Teamtask>();
}
Daywork::Daywork(QDate date, QVector<Teamtask> teamtasks)
{
    _date = date;
    _teamtasks = teamtasks;
}

QDate Daywork::getDate() const
{
    return _date;
}

QVector<Teamtask> Daywork::getTeamTasks() const
{
    return _teamtasks;
}
