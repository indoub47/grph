#ifndef APARATAS_H
#define APARATAS_H
#include <QString>
#include <QObject>

class Aparatas : public QObject
{
  Q_OBJECT
public:
    Aparatas(){}
    Aparatas(QString name, QString model, int level);
    QString getModel() const;
    int getLevel() const;

    // comparison
    friend inline bool operator< (const Aparatas& l, const Aparatas& r)
    {return (l._level < r._level) || (l._level == r._level && l.objectName() < r.objectName());}
    friend inline bool operator==(const Aparatas& l, const Aparatas& r){return l.objectName() == r.objectName();}
    friend inline bool operator> (const Aparatas& lhs, const Aparatas& rhs){ return rhs < lhs; }
    friend inline bool operator<=(const Aparatas& lhs, const Aparatas& rhs){ return !(lhs > rhs); }
    friend inline bool operator>=(const Aparatas& lhs, const Aparatas& rhs){ return !(lhs < rhs); }
    friend inline bool operator!=(const Aparatas& lhs, const Aparatas& rhs){ return !(lhs == rhs); }
private:
  QString _model;
  int _level;
};

#endif // APARATAS_H
