#ifndef APARATAS_H
#define APARATAS_H
#include <QString>

class Aparatas
{
public:
    Aparatas(){};
    Aparatas(QString id, QString model, int level);
    QString getId() const;
    QString getModel() const;
    int getLevel() const;

    // comparison
    friend inline bool operator< (const Aparatas& l, const Aparatas& r)
    {return (l._level < r._level) || (l._level == r._level && l._id < r._id);}
    friend inline bool operator==(const Aparatas& l, const Aparatas& r){return l._id == r._id;}
    friend inline bool operator> (const Aparatas& lhs, const Aparatas& rhs){ return rhs < lhs; }
    friend inline bool operator<=(const Aparatas& lhs, const Aparatas& rhs){ return !(lhs > rhs); }
    friend inline bool operator>=(const Aparatas& lhs, const Aparatas& rhs){ return !(lhs < rhs); }
    friend inline bool operator!=(const Aparatas& lhs, const Aparatas& rhs){ return !(lhs == rhs); }
private:
  QString _id;
  QString _model;
  int _level;
};

#endif // APARATAS_H
