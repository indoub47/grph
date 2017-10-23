#ifndef TEAM_H
#define TEAM_H
#include <QList>
#include "operatorius.h"
#include "aparatas.h"

class Team
{
public:
    Team(){}
    Team(QString name);
    QString getName() const;
    QList<Operatorius> getOperatoriai() const;
    QList<Aparatas> getAparatai() const;
    void addOperatorius(Operatorius operatorius);
    void addAparatas(Aparatas aparatas);
    void removeOperatorius(int index);
    void removeAparatas(int index);
    void removeOperatorius(QString id);
    void removeAparatas(QString id);
private:
    QString _name;
    QList<Operatorius> _operatoriai;
    QList<Aparatas> _aparatai;
};

#endif // TEAM_H
