#ifndef DAYWORK_H
#define DAYWORK_H
#include <QDate>
#include <QVector>
#include "teamtask.h"

class Daywork
{
public:
    Daywork(){}
    Daywork(QDate date);
    Daywork(QDate date, QVector<Teamtask> teamtasks);
    QDate getDate() const;
    QVector<Teamtask> getTeamTasks() const;
private:
    QDate _date;
    QVector<Teamtask> _teamtasks;
};

#endif // DAYWORK_H
