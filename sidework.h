#ifndef SIDEWORK_H
#define SIDEWORK_H
#include <QString>
#include <QObject>

class Sidework : public QObject
{
  Q_OBJECT
public:
    Sidework(){}
    Sidework(QString objectName, QString name);
    QString getName() const;    // comparison
    friend inline bool operator< (const Sidework& l, const Sidework& r){return l.objectName() < r.objectName();}
    friend inline bool operator==(const Sidework& l, const Sidework& r){return l.objectName() == r.objectName();}
    friend inline bool operator> (const Sidework& lhs, const Sidework& rhs){ return rhs < lhs;}
    friend inline bool operator<=(const Sidework& lhs, const Sidework& rhs){ return !(lhs > rhs);}
    friend inline bool operator>=(const Sidework& lhs, const Sidework& rhs){ return !(lhs < rhs);}
    friend inline bool operator!=(const Sidework& lhs, const Sidework& rhs){ return !(lhs == rhs);}
private:
    QString _name;
};

#endif // SIDEWORK_H
