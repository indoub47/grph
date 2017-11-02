#ifndef POOLMANAGER_H
#define POOLMANAGER_H

#include <QVector>
#include "linija.h"
#include "meistrija.h"
#include "operatorius.h"
#include "aparatas.h"
#include "sidework.h"
#include "segmentas.h"
#include "team.h"
#include "teamtask.h"

class PoolManager
{
public:
  PoolManager();
  void addLinija(Linija*);
  bool tryRemoveLinija(Linija*);
  void editLinija(Linija*);


private:
  QVector<Linija*> linijaPool;
  QVector<Meistrija*> meistrijaPool;
  QVector<Operatorius*> operatoriusPool;
  QVector<Aparatas*> aparatasPool;
  QVector<Sidework*> sideworkPool;
  QVector<Segmentas*> segmentasPool;
  QVector<Team*> teamPool;
  QVector<Teamtask*> teamtaskPool;
};

#endif // POOLMANAGER_H
