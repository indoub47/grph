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
private:
  QString _name;
  QString _shortName;
  int _nr;
  QString _meistras;
};

#endif // MEISTRIJA_H
