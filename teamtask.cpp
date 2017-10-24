#include "teamtask.h"
#include "segmentas.h"
#include "sidework.h"
#include "team.h"
#include <QList>

TeamTask::TeamTask(Team team, QList<Segmentas> segmentai, QList<Sidework> sideworks)
{
    _team = team;
    _segmentai = segmentai;
    _sideworks = sideworks;
}

Team TeamTask::getTeam() const
{
    return _team;
}

void TeamTask::addSegmentas(Segmentas segmentas)
{
  if (!_segmentai.contains(segmentas))
    _segmentai.append(segmentas);
}

void TeamTask::addSidework(Sidework sidework)
{
  if (!_sideworks.contains(sidework))
    _sideworks.append(sidework);
}

QList<Segmentas> TeamTask::getSegmentai() const
{
    return _segmentai;
}

QList<Sidework> TeamTask::getSideworks() const
{
    return _sideworks;
}
