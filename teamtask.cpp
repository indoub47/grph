#include "teamtask.h"
#include "segmentas.h"
#include "sidework.h"
#include "team.h"
#include <QList>
#include <QListIterator>

Teamtask::Teamtask(Team* team)
{
  _team = team;
}

Teamtask::Teamtask(Team* team, QList<Segmentas*> segmentai, QList<Sidework*> sideworks)
{
    _team = team;
    _segmentai = segmentai;
    _sideworks = sideworks;
}

const Team* Teamtask::getTeam() const
{
    return _team;
}

void Teamtask::setTeam(Team* team)
{
  _team = team;
}

void Teamtask::setSegmentai(QList<Segmentas*> segmentai)
{
  _segmentai = segmentai;
}

void Teamtask::setSideworks(QList<Sidework*> sideworks)
{
  _sideworks = sideworks;
}

void Teamtask::clearSegmentai()
{
  _segmentai.clear();
}

void Teamtask::clearSideworks()
{
  _sideworks.clear();
}

void Teamtask::addSegmentas(Segmentas* segmentas)
{
  if (!_segmentai.contains(segmentas))
    _segmentai.append(segmentas);
}

void Teamtask::addSidework(Sidework* sidework)
{
  if (!_sideworks.contains(sidework))
    _sideworks.append(sidework);
}

const QList<Segmentas*> Teamtask::getSegmentai() const
{
    return _segmentai;
}

const QList<Sidework*> Teamtask::getSideworks() const
{
    return _sideworks;
}

void Teamtask::mergeSegmentai(QList<Segmentas*> segmentai)
{
  QList<Segmentas*>::iterator i;
  for (i = segmentai.begin(); i != segmentai.end(); ++i)
  {
    if (!_segmentai.contains(*i))
      _segmentai << *i;
  }
}

void Teamtask::mergeSideworks(QList<Sidework*> sideworks)
{
  QList<Sidework*>::iterator i;
  for (i = sideworks.begin(); i != sideworks.end(); ++i)
  {
    if (!_sideworks.contains(*i))
      _sideworks << *i;
  }
}

int Teamtask::removeSidework(Sidework* sidework)
{
  return _sideworks.removeAll(sidework);
}

int Teamtask::removeSegmentas(Segmentas* segmentas)
{
  return _segmentai.removeAll(segmentas);
}

void Teamtask::removeTeam()
{
  _team = nullptr;
}
