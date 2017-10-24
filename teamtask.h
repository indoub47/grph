#ifndef TEAMTASK_H
#define TEAMTASK_H
#include <QList>
#include "segmentas.h"
#include "team.h"
#include "sidework.h"
class TeamTask
{
public:
    TeamTask(){}
    TeamTask(Team team, QList<Segmentas> segmentai, QList<Sidework> sideworks);
    Team getTeam() const;
    QList<Segmentas> getSegmentai() const;
    QList<Sidework> getSideworks() const;
    void addSegmentas(Segmentas segmentas);
    void addSidework(Sidework sidework);
private:
    Team _team;
    QList<Segmentas> _segmentai;
    QList<Sidework> _sideworks;
};

#endif // TEAMTASK_H
