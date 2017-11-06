#ifndef OPER_H
#define OPER_H
#include <QString>

class Oper
{
public:
    Oper(QString id, QString name, int level);
    QString getId() const;
    QString  getName() const;
    int getLevel() const;
    QString  getShortName() const;

    friend inline bool operator< (const Oper& l, const Oper& r)
    {return (l._level < r._level) || (l._level == r._level && l._id < r._id);}
    friend inline bool operator==(const Oper& l, const Oper& r){return l._id == r._id;}
    friend inline bool operator> (const Oper& lhs, const Oper& rhs){ return rhs < lhs; }
    friend inline bool operator<=(const Oper& lhs, const Oper& rhs){ return !(lhs > rhs); }
    friend inline bool operator>=(const Oper& lhs, const Oper& rhs){ return !(lhs < rhs); }
    friend inline bool operator!=(const Oper& lhs, const Oper& rhs){ return !(lhs == rhs); }
private:
    QString _id;
    QString _name;
    int _level;
};
#endif // OPER_H
