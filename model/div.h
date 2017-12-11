#ifndef DIV_H
#define DIV_H
#include <QString>
class Div
{
public:
   Div(QString id, QString name, int nr, QString meistras);
   QString getId() const;
   QString getName() const;
   int getNr() const;
   QString getMeistras() const;

   // comparison
   friend inline bool operator< (const Div& l, const Div& r){return l._nr < r._nr;}
   friend inline bool operator==(const Div& l, const Div& r){return l._id == r._id;}
   friend inline bool operator> (const Div& lhs, const Div& rhs){ return rhs < lhs;}
   friend inline bool operator<=(const Div& lhs, const Div& rhs){ return !(lhs > rhs);}
   friend inline bool operator>=(const Div& lhs, const Div& rhs){ return !(lhs < rhs);}
   friend inline bool operator!=(const Div& lhs, const Div& rhs){ return !(lhs == rhs);}
private:
  QString _id;
  QString _name;
  int _nr;
  QString _meistras;

};

#endif // DIV_H
