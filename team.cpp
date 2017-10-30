#include "team.h"
#include <QString>
#include <QList>
#include "operatorius.h"
#include "aparatas.h"
#include <QListIterator>

Team::Team(QString name)
{
    _name = name;
}

Team::Team(QString name, QList<Operatorius> operatoriai, QList<Aparatas> aparatai)
{
  _name = name;
  _operatoriai = operatoriai;
  _aparatai = aparatai;
}

QString Team::getName() const
{
    return _name;
}

const QList<Operatorius>& Team::getOperatoriai() const
{
    return _operatoriai;
}

const QList<Aparatas>& Team::getAparatai() const
{
    return _aparatai;
}


const Operatorius& Team::getOperatorius(int indx) const
{
    return _operatoriai.at(indx);
}

const Aparatas& Team::getAparatas(int indx) const
{
    return _aparatai.at(indx);
}

void Team::setOperatoriai(QList<Operatorius> operatoriai)
{
  _operatoriai = operatoriai;
}

void Team::setAparatai(QList<Aparatas> aparatai)
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

void Team::addOperatorius(Operatorius operatorius)
{
  if (!_operatoriai.contains(operatorius))
    _operatoriai.append(operatorius);
}

void Team::addAparatas(Aparatas aparatas)
{
  if (!_aparatai.contains(aparatas))
    _aparatai.append(aparatas);
}

void Team::removeOperatorius(int index)
{
    _operatoriai.removeAt(index);
}

void Team::removeAparatas(int index)
{
    _aparatai.removeAt(index);
}

void Team::removeOperatorius(QString id)
{
  QList<Operatorius>::iterator i;
  for (i = _operatoriai.begin(); i != _operatoriai.end(); ++i)
  {
    if ((*i).getId() == id)
    {
      _operatoriai.removeOne(*i);
      break;
    }
  }
}

void Team::removeAparatas(QString id)
{
  QList<Aparatas>::iterator i;
  for (i = _aparatai.begin(); i != _aparatai.end(); ++i)
  {
    if ((*i).getId() == id)
    {
      _aparatai.removeOne(*i);
      break;
    }
  }
}

bool operator== (const Team& l, const Team& r)
{
  if (l._name != r._name)
    return false;

  if (l._aparatai.count() != r._aparatai.count())
    return false;

  QList<Aparatas>::const_iterator ia;
  for (ia = l._aparatai.begin(); ia != l._aparatai.end(); ++ia)
  {
    if (!r._aparatai.contains(*ia))
    {
      return false;
    }
  }

  if (l._operatoriai.count() != r._operatoriai.count())
    return false;

  QList<Operatorius>::const_iterator io;
  for (io = l._operatoriai.begin(); io != l._operatoriai.end(); ++io)
  {
    if (!r._operatoriai.contains(*io))
    {
      return false;
    }
  }

  return true;
}

bool operator!= (const Team& l, const Team& r)
{
  return !(l == r);
}


