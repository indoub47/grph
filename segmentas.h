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
    Segmentas(QString name, int ind, QList<Meistrija> meistrijos, float kmPagr, float kmKt, int iesmai, QTime nuoKada, Linija linija);
    QString getName() const;
    int getInd() const;
    QList<Meistrija> getMeistrijos() const;
    float getKmPagr() const;
    float getKmKt() const;
    int getIesmai() const;
    QTime getNuoKada() const;
    Linija getLinija() const;

    // comparison
    friend inline bool operator< (const Segmentas& l, const Segmentas& r){return l._linija == r._linija && l._ind < r._ind;}
    friend inline bool operator==(const Segmentas& l, const Segmentas& r){return l._linija == r._linija && l._name == r._name;}
    friend inline bool operator> (const Segmentas& lhs, const Segmentas& rhs){ return rhs < lhs;}
    friend inline bool operator<=(const Segmentas& lhs, const Segmentas& rhs){ return !(lhs > rhs);}
    friend inline bool operator>=(const Segmentas& lhs, const Segmentas& rhs){ return !(lhs < rhs);}
    friend inline bool operator!=(const Segmentas& lhs, const Segmentas& rhs){ return !(lhs == rhs);}

private:
    QString _name;
    int _ind;
    QList<Meistrija> _meistrijos;
    float _kmPagr;
    float _kmKt;
    int _iesmai;
    QTime _nuoKada;
    Linija _linija;
};

#endif // SEGMENTAS_H
