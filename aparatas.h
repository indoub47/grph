#ifndef APARATAS_H
#define APARATAS_H
#include <QString>

class Aparatas
{
public:
    Aparatas(){};
    Aparatas(QString id, QString model, int level);
    QString getId() const;
    QString getModel() const;
    int getLevel() const;
private:
  QString _id;
  QString _model;
  int _level;
};

#endif // APARATAS_H
