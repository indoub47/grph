#include "teamtask.h"
#include "segm.h"
#include "swork.h"
#include "team.h"
#include <QList>
#include <QListIterator>

Teamtask::Teamtask(Team* team)
{
	_team = team;
}

Teamtask::Teamtask(Team* team, QList<Segm*> segms, QList<Swork*> sworks)
{
    _team = team;
    _segms = segms;
    _sworks = sworks;
}

const Team* Teamtask::getTeam() const
{
    return _team;
}

void Teamtask::setTeam(Team* team)
{
	_team = team;
}

void Teamtask::setSegms(QList<Segm*> segms)
{
	_segms = segms;
}

void Teamtask::setSworks(QList<Swork*> sworks)
{
	_sworks = sworks;
}

void Teamtask::clearSegms()
{
	_segms.clear();
}

void Teamtask::clearSworks()
{
	_sworks.clear();
}

void Teamtask::addSegm(Segm* segm)
{
	if (!_segms.contains(segm))
		_segms.append(segm);
}

void Teamtask::addSwork(Swork* swork)
{
	if (!_sworks.contains(swork))
		_sworks.append(swork);
}

const QList<Segm*> Teamtask::getSegms() const
{
    return _segms;
}

const QList<Swork*> Teamtask::getSworks() const
{
    return _sworks;
}

void Teamtask::mergeSegms(QList<Segm*> segms)
{
	QList<Segm*>::iterator i;
	for (i = segms.begin(); i != segms.end(); ++i)
	{
		if (!_segms.contains(*i))
			_segms << *i;
	}
}

void Teamtask::mergeSworks(QList<Swork*> sworks)
{
	QList<Swork*>::iterator i;
	for (i = sworks.begin(); i != sworks.end(); ++i)
	{
		if (!_sworks.contains(*i))
			_sworks << *i;
	}
}

int Teamtask::removeSwork(Swork* swork)
{
	return _sworks.removeAll(swork);
}

int Teamtask::removeSegm(Segm* segm)
{
	return _segms.removeAll(segm);
}

void Teamtask::removeTeam()
{
	_team = nullptr;
}
