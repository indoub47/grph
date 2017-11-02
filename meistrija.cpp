#include "meistrija.h"
#include <QString>
#include <QObject>

Meistrija::Meistrija(QString objectName, QString name, int nr, QString meistras)
{
  setObjectName(objectName);
  _name = name;
  _nr = nr;
  _meistras = meistras;
}

QString Meistrija::getName() const
{
  return _name;
}

int Meistrija::getNr() const
{
  return _nr;
}

QString Meistrija::getMeistras() const
{
  return _meistras;
}

