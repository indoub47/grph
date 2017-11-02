#include "team.h"
#include <QString>
#include <QList>
#include "operatorius.h"
#include "aparatas.h"
#include <QListIterator>

Team::Team(QString objectName)
{
    setObjectName(objectName);
}

Team::Team(QString objectName, QList<Operatorius*> operatoriai, QList<Aparatas*> aparatai)
{
  setObjectName(objectName);
  _operatoriai = operatoriai;
  _aparatai = aparatai;
}

const QList<Operatorius*> Team::getOperatoriai() const
{
    return _operatoriai;
}

const QList<Aparatas*> Team::getAparatai() const
{
    return _aparatai;
}


const Operatorius* Team::getOperatorius(int indx) const
{
    return _operatoriai.at(indx);
}

const Aparatas* Team::getAparatas(int indx) const
{
    return _aparatai.at(indx);
}

void Team::setOperatoriai(QList<Operatorius*> operatoriai)
{
  _operatoriai = operatoriai;
}

void Team::setAparatai(QList<Aparatas*> aparatai)
{
  _aparatai = aparatai;
}

void Team::clearOperatoriai()
{
  _operatoriai.clear();
}

void Team::clearAparatai()
{
  _aparatai.clear();
}

void Team::addOperatorius(Operatorius* operatorius)
{
  if (!_operatoriai.contains(operatorius))
    _operatoriai.append(operatorius);
}

void Team::addAparatas(Aparatas* aparatas)
{
  if (!_aparatai.contains(aparatas))
    _aparatai.append(aparatas);
}

int Team::removeOperatorius(Operatorius* operatorius)
{
    return _operatoriai.removeAll(operatorius);
}

int Team::removeAparatas(Aparatas* aparatas)
{
    return _aparatai.removeAll(aparatas);
}

bool operator== (const Team& l, const Team& r)
{
  if (l.objectName() != r.objectName())
    return false;

  if (l._aparatai.count() != r._aparatai.count())
    return false;

  QList<Aparatas*>::const_iterator ia;
  for (ia = l._aparatai.begin(); ia != l._aparatai.end(); ++ia)
  {
    if (!r._aparatai.contains(*ia))
    {
      return false;
    }
  }

  if (l._operatoriai.count() != r._operatoriai.count())
    return false;

  QList<Operatorius*>::const_iterator io;
  for (io = l._operatoriai.begin(); io != l._operatoriai.end(); ++io)
  {
    if (!r._operatoriai.contains(*io))
    {
      return false;
    }
  }

  return true;
}



