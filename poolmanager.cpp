#include "poolmanager.h"
#include <QVectorIterator>
#include <QVector>
#include "linija.h"
#include "meistrija.h"
#include "operatorius.h"
#include "aparatas.h"
#include "sidework.h"
#include "segmentas.h"
#include "team.h"
#include "teamtask.h"


PoolManager::PoolManager()
{

}

void PoolManager::addLinija(Linija* linija)
{
  if (! linijaPool.contains(linija))
  {
    linijaPool << linija;
  }
}

bool PoolManager::tryRemoveLinija(Linija* linija)
{
  QVector<Segmentas>::iterator i;
  bool isInUse = false;
  for (i = segmentasPool.begin(); i != segmentasPool.end(); ++i)
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
    delete *linija;
    return true;
  }

  return false;
}

void PoolManager::editLinija(Linija* which, Linija* toWhat)
{

}




