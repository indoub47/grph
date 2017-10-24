#ifndef MEISTRIJA_H
#define MEISTRIJA_H
#include <QString>

class Meistrija
{
public:
   Meistrija(){};
   Meistrija(QString name, QString shortName, int nr, QString meistras);
   QString getName() const;
   QString getShortName() const;
   int getNr() const;
   QString getMeistras() const;

   // comparison
   friend inline bool operator< (const Meistrija& l, const Meistrija& r){return l._nr < r._nr;}
   friend inline bool operator==(const Meistrija& l, const Meistrija& r){return l._nr == r._nr;}
   friend inline bool operator> (const Meistrija& lhs, const Meistrija& rhs){ return rhs < lhs;}
   friend inline bool operator<=(const Meistrija& lhs, const Meistrija& rhs){ return !(lhs > rhs);}
   friend inline bool operator>=(const Meistrija& lhs, const Meistrija& rhs){ return !(lhs < rhs);}
   friend inline bool operator!=(const Meistrija& lhs, const Meistrija& rhs){ return !(lhs == rhs);}
private:
  QString _name;
  QString _shortName;
  int _nr;
  QString _meistras;
};

#endif // MEISTRIJA_H
