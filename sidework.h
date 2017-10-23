#ifndef SIDEWORK_H
#define SIDEWORK_H
#include <QString>


class Sidework
{
public:
    Sidework(){}
    Sidework(QString name, QString fullName);
    QString getName() const;
    QString getFullName() const;
private:
    QString _name;
    QString _fullName;
};

#endif // SIDEWORK_H
