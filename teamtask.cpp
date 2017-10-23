#include "teamtask.h"
#include "segmentas.h"
#include "sidework.h"
#include "team.h"
#include <QVector>

Teamtask::Teamtask(Team team, QVector<Segmentas> segmentai, QVector<Sidework> sideworks)
{
    _team = team;
    _segmentai = segmentai;
    _sideworks = sideworks;
}

Team Teamtask::getTeam() const
{
    return _team;
}

QVector<Segmentas> Teamtask::getSegmentai() const
{
    return _segmentai;
}

QVector<Sidework> Teamtask::getSideworks() const
{
    return _sideworks;
}
