#ifndef OPERATORIUS_H
#define OPERATORIUS_H
#include <QString>
#include <QObject>
class Operatorius : public QObject
{
  Q_OBJECT
public:
    Operatorius(){};
    Operatorius(QString objectName, QString name, int level);
    QString  getName() const;
    int getLevel() const;
    QString  getShortName() const;    

    // comparison
    friend inline bool operator< (const Operatorius& l, const Operatorius& r)
    {return (l._level < r._level) || (l._level == r._level && l.objectName() < r.objectName());}
    friend inline bool operator==(const Operatorius& l, const Operatorius& r){return l.objectName() == r.objectName();}
    friend inline bool operator> (const Operatorius& lhs, const Operatorius& rhs){ return rhs < lhs; }
    friend inline bool operator<=(const Operatorius& lhs, const Operatorius& rhs){ return !(lhs > rhs); }
    friend inline bool operator>=(const Operatorius& lhs, const Operatorius& rhs){ return !(lhs < rhs); }
    friend inline bool operator!=(const Operatorius& lhs, const Operatorius& rhs){ return !(lhs == rhs); }
private:
    QString _name;
    int _level;
};
#endif // OPERATORIUS_H
