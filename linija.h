#ifndef LINIJA_H
#define LINIJA_H
#include <QString>
class Linija
{
public:
    Linija(){};
    Linija(QString id, QString name);
    QString getId() const;
    QString getName() const;
private:
    QString _id;
    QString _name;
};

#endif // LINIJA_H
