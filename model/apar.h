#ifndef APAR_H
#define APAR_H
#include <QString>

class Apar
{
public:
    Apar(QString id, QString model, int level);
    QString getId() const;
    QString getModel() const;
    int getLevel() const;

    // comparison
    friend inline bool operator< (const Apar& l, const Apar& r)
    {return (l._level < r._level) || (l._level == r._level && l._id < r._id);}
    friend inline bool operator==(const Apar& l, const Apar& r){return l._id == r._id;}
    friend inline bool operator> (const Apar& lhs, const Apar& rhs){ return rhs < lhs; }
    friend inline bool operator<=(const Apar& lhs, const Apar& rhs){ return !(lhs > rhs); }
    friend inline bool operator>=(const Apar& lhs, const Apar& rhs){ return !(lhs < rhs); }
    friend inline bool operator!=(const Apar& lhs, const Apar& rhs){ return !(lhs == rhs); }
private:
  QString _id;
  QString _model;
  int _level;
};

#endif // APAR_H
