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

QString Team::getName() const
{
    return _name;
}

QList<Operatorius> Team::getOperatoriai() const
{
    return _operatoriai;
}

QList<Aparatas> Team::getAparatai() const
{
    return _aparatai;
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
