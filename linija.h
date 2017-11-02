#ifndef LINIJA_H
#define LINIJA_H
#include <QString>
#include <QObject>
class Linija : public QObject
{
  Q_OBJECT
public:
    Linija(){};
    Linija(QString objectName, QString name);
    QString getName() const;

    // comparison
    friend inline bool operator==(const Linija& l, const Linija& r){return l.objectName() == r.objectName();}
    friend inline bool operator!=(const Linija& lhs, const Linija& rhs){ return !(lhs == rhs);}
    friend inline bool operator< (const Linija& l, const Linija& r){return l.objectName() < r.objectName();}
    friend inline bool operator> (const Linija& lhs, const Linija& rhs){ return rhs < lhs;}
    friend inline bool operator<=(const Linija& lhs, const Linija& rhs){ return !(lhs > rhs);}
    friend inline bool operator>=(const Linija& lhs, const Linija& rhs){ return !(lhs < rhs);}
private:
    QString _name;
};

#endif // LINIJA_H
