#ifndef SWORK_H
#define SWORK_H
#include <QString>

class Swork
{
public:
    Swork(QString id, QString name);
    QString getId() const;
    QString getName() const;

    friend inline bool operator< (const Swork& l, const Swork& r){return l._id < r._id;}
    friend inline bool operator==(const Swork& l, const Swork& r){return l._id == r._id;}
    friend inline bool operator> (const Swork& lhs, const Swork& rhs){ return rhs < lhs;}
    friend inline bool operator<=(const Swork& lhs, const Swork& rhs){ return !(lhs > rhs);}
    friend inline bool operator>=(const Swork& lhs, const Swork& rhs){ return !(lhs < rhs);}
    friend inline bool operator!=(const Swork& lhs, const Swork& rhs){ return !(lhs == rhs);}
private:
    QString _id;
    QString _name;
};

#endif // SWORK_H
