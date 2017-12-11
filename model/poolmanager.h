#ifndef POOLMANAGER_H
#define POOLMANAGER_H

#include <QVector>
#include "linija.h"
#include "div.h"
#include "oper.h"
#include "apar.h"
#include "swork.h"
#include "segm.h"
#include "team.h"
#include "teamtask.h"
#include "daywork.h"

class PoolManager
{
public:
    PoolManager();

    void addLinija(Linija*);
    bool tryDeleteLinija(Linija*);
    void addDiv(Div*);
    bool tryDeleteDiv(Div*);
    void addSegm(Segm*);
    bool tryDeleteSegm(Segm*);
    void addOper(Oper*);
    bool tryDeleteOper(Oper*);
    void addApar(Apar*);
    bool tryDeleteApar(Apar*);
    void addSwork(Swork*);
    bool tryDeleteSwork(Swork*);
    void addTeam(Team*);
    bool tryDeleteTeam(Team*);
    void addTeamtask(Teamtask*);
    bool tryDeleteTeamtask(Teamtask*);

    //if (std::is_same<T, int>::value)
    //if (typeid(T) == typeid(int))

    template<typename T>
    void addNew(T*);

    template<typename T>
    bool tryDelete(T*);

private:
    QVector<Linija*> linijaPool;
    QVector<Div*> divPool;
    QVector<Oper*> operPool;
    QVector<Apar*> aparPool;
    QVector<Swork*> sworkPool;
    QVector<Segm*> segmPool;
    QVector<Team*> teamPool;
    QVector<Teamtask*> teamtaskPool;
    QVector<Daywork*> dayworkPool;
};

template<class T>
void PoolManager::addNew(T* thing)
{
    QVector<T>* pool;
    switch(typeid(T))
    {
        case(typeid(Linija)):
        pool = &linijaPool;
        break;
        case(typeid(Div)):
        pool = &divPool;
        break;
        case(typeid(Oper)):
        pool = &operPool;
        break;
        case(typeid(Apar)):
        pool = &aparPool;
        break;
        case(typeid(Segm)):
        pool = &segmPool;
        break;
        case(typeid(Swork)):
        pool = &sworkPool;
        break;
        case(typeid(Team)):
        pool = &teamPool;
        break;
        case(typeid(Teamtask)):
        pool = &teamtaskPool;
        break;
    }

    if (!pool->contains(thing))
        *pool << thing;
}

#endif // POOLMANAGER_H
