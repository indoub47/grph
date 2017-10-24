#ifndef DAYWORK_H
#define DAYWORK_H
#include <QDate>
#include <QList>
#include "teamtask.h"

class Daywork
{
public:
    Daywork(){}
    Daywork(QDate date);
    void addTeamTask(TeamTask teamTask);
    QDate getDate() const;
    QList<TeamTask> getTeamTasks() const;
    QList<TeamTask> getTTByAparatas(Aparatas aparatas) const;
private:
    QDate _date;
    QList<TeamTask> _teamTasks;
};

#endif // DAYWORK_H
