#include "team.h"
#include <QString>
#include <QList>
#include "operatorius.h"
#include "aparatas.h"

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
    // test if doesn't exists
    int i = 0;
    int c = _operatoriai.count();
    QString id = operatorius.getId();
    while (i < c)
    {
        if (_operatoriai[i].getId() == id)
        {
            return;
        }
        i++;
    }
    _operatoriai.append(operatorius);
}

void Team::addAparatas(Aparatas aparatas)
{
    // test if doesn't exists
    int i = 0;
    int c = _aparatai.count();
    QString id = aparatas.getId();
    while (i < c)
    {
        if (_aparatai[i].getId() == id)
        {
            return;
        }
        i++;
    }
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
    int i = 0;
    int c = _operatoriai.count();
    while (i < c)
    {
        if (_operatoriai[i].getId() == id)
        {
            _operatoriai.removeAt(i);
            break;
        }
        i++;
    }
}
void Team::removeAparatas(QString id)
{
    int i = 0;
    int c = _aparatai.count();
    while (i < c)
    {
        if (_aparatai[i].getId() == id)
        {
            _aparatai.removeAt(i);
            break;
        }
        i++;
    }
}
