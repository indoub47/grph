#ifndef SIDEWORK_H
#define SIDEWORK_H
#include <QString>


class Sidework
{
public:
    Sidework(){}
    Sidework(QString name, QString fullName);
    QString getName() const;
    QString getFullName() const;    // comparison
    friend inline bool operator< (const Sidework& l, const Sidework& r){return l._name < r._name;}
    friend inline bool operator==(const Sidework& l, const Sidework& r){return l._name == r._name;}
    friend inline bool operator> (const Sidework& lhs, const Sidework& rhs){ return rhs < lhs;}
    friend inline bool operator<=(const Sidework& lhs, const Sidework& rhs){ return !(lhs > rhs);}
    friend inline bool operator>=(const Sidework& lhs, const Sidework& rhs){ return !(lhs < rhs);}
    friend inline bool operator!=(const Sidework& lhs, const Sidework& rhs){ return !(lhs == rhs);}
private:
    QString _name;
    QString _fullName;
};

#endif // SIDEWORK_H
