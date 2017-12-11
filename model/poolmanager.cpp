#include "poolmanager.h"
#include <QVectorIterator>
#include <QVector>
#include "linija.h"
#include "div.h"
#include "oper.h"
#include "apar.h"
#include "swork.h"
#include "segm.h"
#include "team.h"
#include "teamtask.h"


PoolManager::PoolManager()
{
    // load all pools
}



bool PoolManager::tryDeleteLinija(Linija* linija)
{

    QVector<Segm*>::iterator i;
    bool isInUse = false;
    for (i = segmPool.begin(); i != segmPool.end(); ++i)
    {
        if ((*i)->getLinija() == linija)
        {
            isInUse = true;
            break;
        }
    }

    if (!isInUse)
    {
        linijaPool.removeAll(linija);
        delete linija;
        return true;
    }

    return false;
}

bool PoolManager::tryDeleteDiv(Div* div)
{

    QVector<Segm*>::iterator i;
    bool isInUse = false;
    for (i = segmPool.begin(); i != segmPool.end(); ++i)
    {
        if ((*i)->getDivs().contains(div))
        {
            isInUse = true;
            break;
        }
    }

    if (!isInUse)
    {
        divPool.removeAll(div);
        delete div;
        return true;
    }

    return false;
}

bool PoolManager::tryDeleteOper(Oper* oper)
{

    QVector<Team*>::iterator i;
    bool isInUse = false;
    for (i = teamPool.begin(); i != teamPool.end(); ++i)
    {
        if ((*i)->getOpers().contains(oper))
        {
            isInUse = true;
            break;
        }
    }

    if (!isInUse)
    {
        operPool.removeAll(oper);
        delete oper;
        return true;
    }

    return false;
}

bool PoolManager::tryDeleteApar(Apar* apar)
{
    QVector<Team*>::iterator i;
    bool isInUse = false;
    for (i = teamPool.begin(); i != teamPool.end(); ++i)
    {
        if ((*i)->getApars().contains(apar))
        {
            isInUse = true;
            break;
        }
    }

    if (!isInUse)
    {
        aparPool.removeAll(apar);
        delete apar;
        return true;
    }

    return false;
}

bool PoolManager::tryDeleteSegm(Segm* segm)
{
    QVector<Teamtask*>::iterator i;
    bool isInUse = false;
    for (i = teamtaskPool.begin(); i != teamtaskPool.end(); ++i)
    {
        if ((*i)->getSegms().contains(segm))
        {
            isInUse = true;
            break;
        }
    }

    if (!isInUse)
    {
        segmPool.removeAll(segm);
        delete segm;
        return true;
    }

    return false;
}

bool PoolManager::tryDeleteSwork(Swork* swork)
{
    QVector<Teamtask*>::iterator i;
    bool isInUse = false;
    for (i = teamtaskPool.begin(); i != teamtaskPool.end(); ++i)
    {
        if ((*i)->getSworks().contains(swork))
        {
            isInUse = true;
            break;
        }
    }

    if (!isInUse)
    {
        sworkPool.removeAll(swork);
        delete swork;
        return true;
    }

    return false;
}

bool PoolManager::tryDeleteTeam(Team* team)
{
    QVector<Teamtask*>::iterator i;
    bool isInUse = false;
    for (i = teamtaskPool.begin(); i != teamtaskPool.end(); ++i)
    {
        if ((*i)->getTeam() == team)
        {
            isInUse = true;
            break;
        }
    }

    if (!isInUse)
    {
        teamPool.removeAll(team);
        delete team;
        return true;
    }

    return false;
}

bool PoolManager::tryDeleteTeamtask(Teamtask* teamtask)
{
    QVector<Daywork*>::iterator i;
    bool isInUse = false;
    for (i = dayworkPool.begin(); i != dayworkPool.end(); ++i)
    {
        if ((*i)->getTeamtasks().contains(teamtask))
        {
            isInUse = true;
            break;
        }
    }

    if (!isInUse)
    {
        teamtaskPool.removeAll(teamtask);
        delete teamtask;
        return true;
    }

    return false;
}





