#ifndef OPERATORIUS_H
#define OPERATORIUS_H
#include <QString>
class Operatorius
{
public:
    Operatorius(){};
    Operatorius(QString id, QString name, int level);
    QString  getId() const;
    QString  getName() const;
    int getLevel() const;
    QString  getShortName() const;    

    // comparison
    friend inline bool operator< (const Operatorius& l, const Operatorius& r)
    {return (l._level < r._level) || (l._level == r._level && l._id < r._id);}
    friend inline bool operator==(const Operatorius& l, const Operatorius& r){return l._id == r._id;}
    friend inline bool operator> (const Operatorius& lhs, const Operatorius& rhs){ return rhs < lhs; }
    friend inline bool operator<=(const Operatorius& lhs, const Operatorius& rhs){ return !(lhs > rhs); }
    friend inline bool operator>=(const Operatorius& lhs, const Operatorius& rhs){ return !(lhs < rhs); }
    friend inline bool operator!=(const Operatorius& lhs, const Operatorius& rhs){ return !(lhs == rhs); }
private:
    QString _id;
    QString _name;
    int _level;
};
#endif // OPERATORIUS_H
