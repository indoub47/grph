#ifndef TEAMTASK_H
#define TEAMTASK_H
#include <QVector>
#include "segmentas.h"
#include "team.h"
#include "sidework.h"
class Teamtask
{
public:
    Teamtask(){}
    Teamtask(Team team, QVector<Segmentas> segmentai, QVector<Sidework> sideworks);
    Team getTeam() const;
    QVector<Segmentas> getSegmentai() const;
    QVector<Sidework> getSideworks() const;
private:
    Team _team;
    QVector<Segmentas> _segmentai;
    QVector<Sidework> _sideworks;
};

#endif // TEAMTASK_H
