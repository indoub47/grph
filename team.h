#ifndef TEAM_H
#define TEAM_H
#include <QList>
#include "operatorius.h"
#include "aparatas.h"
#include <QListIterator>
#include <QObject>

class Team : public QObject
{
  Q_OBJECT
public:
  Team(){}
  Team(QString objectName);
  Team(QString objectName, QList<Operatorius*> operatoriai, QList<Aparatas*> aparatai);
  const QList<Operatorius*> getOperatoriai() const;
  const QList<Aparatas*> getAparatai() const;
  const Operatorius* getOperatorius(int indx) const;
  const Aparatas* getAparatas(int indx) const;
  void setOperatoriai(QList<Operatorius*> operatoriai);
  void setAparatai(QList<Aparatas*> aparatai);
  void clearOperatoriai();
  void clearAparatai();
  void addOperatorius(Operatorius* operatorius);
  void addAparatas(Aparatas* aparatas);
  int removeOperatorius(Operatorius* operatorius);
  int removeAparatas(Aparatas* aparatas);

  friend bool operator== (const Team& l, const Team& r);
  friend bool operator!= (const Team& l, const Team& r){return !(l == r);}
  friend inline bool operator< (const Team& lhs, const Team& rhs){return (lhs.objectName() < rhs.objectName());}
  friend inline bool operator> (const Team& lhs, const Team& rhs){ return rhs < lhs; }
  friend inline bool operator<=(const Team& lhs, const Team& rhs){ return !(lhs > rhs); }
  friend inline bool operator>=(const Team& lhs, const Team& rhs){ return !(lhs < rhs); }
private:
    QList<Operatorius*> _operatoriai;
    QList<Aparatas*> _aparatai;
};

#endif // TEAM_H
