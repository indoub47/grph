#ifndef DAYWORK_H
#define DAYWORK_H
#include <QDate>
#include <QList>
#include "teamtask.h"
#include <QObject>

class Daywork : public QObject
{
  Q_OBJECT
public:
    Daywork(){}
    Daywork(QDate date);
    void addTeamtask(Teamtask* teamtask);
    const QDate getDate() const;
    const QList<Teamtask*> getTeamtasks() const;
    const QList<Teamtask*> getTTByAparatas(Aparatas* aparatas) const;
    const QList<Teamtask*> getTeamtasks(QString teamName) const;
    void clearTeamtasks();
    int removeTeamtask(Teamtask*);
private:
    QDate _date;
    QList<Teamtask*> _teamtasks;
};

#endif // DAYWORK_H
