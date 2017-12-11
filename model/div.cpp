#include "div.h"
#include <QString>

Div::Div(QString id, QString name, int nr, QString meistras)
{
  _id = id;
  _name = name;
  _nr = nr;
  _meistras = meistras;
}

QString Div::getName() const
{
  return _name;
}

int Div::getNr() const
{
  return _nr;
}

QString Div::getMeistras() const
{
  return _meistras;
}

QString Div::getId() const
{
  return _id;
}

