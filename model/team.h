#ifndef TEAM_H
#define TEAM_H
#include <QList>
#include "oper.h"
#include "apar.h"
#include <QListIterator>

class Team
{
public:
    Team(){}
    Team(QString id);
    Team(QString id, QList<Oper*> opers, QList<Apar*> apars);
    const QList<Oper*> getOpers() const;
    const QList<Apar*> getApars() const;
    const Oper* getOper(int indx) const;
    const Apar* getApar(int indx) const;
    QString getId() const;
    void setOpers(QList<Oper*> opers);
    void setApars(QList<Apar*> apars);
    void clearOpers();
    void clearApars();
    void addOper(Oper* oper);
    void addApar(Apar* apar);
    int removeOper(Oper* oper);
    int removeApar(Apar* apar);

    friend bool operator== (const Team& l, const Team& r);
    friend bool operator!= (const Team& l, const Team& r){return !(l == r);}
    friend inline bool operator< (const Team& lhs, const Team& rhs){return (lhs._id < rhs._id);}
    friend inline bool operator> (const Team& lhs, const Team& rhs){ return rhs < lhs; }
    friend inline bool operator<=(const Team& lhs, const Team& rhs){ return !(lhs > rhs); }
    friend inline bool operator>=(const Team& lhs, const Team& rhs){ return !(lhs < rhs); }
private:
    QString _id;
    QList<Oper*> _opers;
    QList<Apar*> _apars;
};

#endif // TEAM_H
