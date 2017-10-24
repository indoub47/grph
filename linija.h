#ifndef LINIJA_H
#define LINIJA_H
#include <QString>
class Linija
{
public:
    Linija(){};
    Linija(QString id, QString name);
    QString getId() const;
    QString getName() const;

    // comparison
    friend inline bool operator< (const Linija& l, const Linija& r){return l._id < r._id;}
    friend inline bool operator==(const Linija& l, const Linija& r){return l._id == r._id;}
    friend inline bool operator> (const Linija& lhs, const Linija& rhs){ return rhs < lhs;}
    friend inline bool operator<=(const Linija& lhs, const Linija& rhs){ return !(lhs > rhs);}
    friend inline bool operator>=(const Linija& lhs, const Linija& rhs){ return !(lhs < rhs);}
    friend inline bool operator!=(const Linija& lhs, const Linija& rhs){ return !(lhs == rhs);}
private:
    QString _id;
    QString _name;
};

#endif // LINIJA_H
