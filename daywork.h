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
    void addTeamtask(Teamtask teamtask);
    QDate getDate() const;
    const QList<Teamtask>& getTeamtasks() const;
    QList<Teamtask> getTTByAparatas(Aparatas aparatas) const;
    void clearTeamtasks();
private:
    QDate _date;
    QList<Teamtask> _teamtasks;
};

#endif // DAYWORK_H
