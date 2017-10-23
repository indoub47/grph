#ifndef SEGMENTAS_H
#define SEGMENTAS_H
#include <QString>
#include <QList>
#include <QTime>
#include "meistrija.h"
#include "linija.h"

class Segmentas
{
public:
    Segmentas(){};
    Segmentas(QString name, int id, QList<Meistrija> meistrijos, float kmPagr, float kmKt, int iesmai, QTime nuoKada, Linija linija);
    QString getName() const;
    int getId() const;
    QList<Meistrija> getMeistrijos() const;
    float getKmPagr() const;
    float getKmKt() const;
    int getIesmai() const;
    QTime getNuoKada() const;
    Linija getLinija() const;
private:
    QString _name;
    int _id;
    QList<Meistrija> _meistrijos;
    float _kmPagr;
    float _kmKt;
    int _iesmai;
    QTime _nuoKada;
    Linija _linija;
};

#endif // SEGMENTAS_H
