#ifndef TEAM_H
#define TEAM_H
#include <QList>
#include "operatorius.h"
#include "aparatas.h"
#include <QListIterator>

class Team
{
public:
  Team(){}
  Team(QString name);
  Team(QString name, QList<Operatorius> operatoriai, QList<Aparatas> aparatai);
  QString getName() const;
  const QList<Operatorius>& getOperatoriai() const;
  const QList<Aparatas>& getAparatai() const;
  const Operatorius& getOperatorius(int indx) const;
  const Aparatas& getAparatas(int indx) const;
  void setOperatoriai(QList<Operatorius> operatoriai);
  void setAparatai(QList<Aparatas> aparatai);
  void clearOperatoriai();
  void clearAparatai();
  void addOperatorius(Operatorius operatorius);
  void addAparatas(Aparatas aparatas);
  void removeOperatorius(int index);
  void removeAparatas(int index);
  void removeOperatorius(QString id);
  void removeAparatas(QString id);

  friend bool operator== (const Team& l, const Team& r);
  friend bool operator!= (const Team& l, const Team& r);
  friend inline bool operator< (const Team& lhs, const Team& rhs) {return (lhs._name < rhs._name);}
  friend inline bool operator> (const Team& lhs, const Team& rhs){ return rhs < lhs; }
  friend inline bool operator<=(const Team& lhs, const Team& rhs){ return !(lhs > rhs); }
  friend inline bool operator>=(const Team& lhs, const Team& rhs){ return !(lhs < rhs); }
private:
    QString _name;
    QList<Operatorius> _operatoriai;
    QList<Aparatas> _aparatai;
};

#endif // TEAM_H
