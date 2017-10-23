#include "segmentas.h"
#include <QString>
#include <QList>
#include <QTime>
#include "meistrija.h"
#include "linija.h"

Segmentas::Segmentas(QString name, int id, QList<Meistrija> meistrijos, float kmPagr, float kmKt, int iesmai, QTime nuoKada, Linija linija)
{
        _name = name;
        _id = id;
        _meistrijos = meistrijos;
        _kmPagr = kmPagr;
        _kmKt = kmKt;
        _iesmai = iesmai;
        _nuoKada = nuoKada;
        _linija = linija;
}

QString Segmentas::getName() const
{
    return _name;
}

int Segmentas::getId() const
{
    return _id;
}

QList<Meistrija> Segmentas::getMeistrijos() const
{
    return _meistrijos;
}

float Segmentas::getKmPagr() const
{
    return _kmPagr;
}

float Segmentas::getKmKt() const
{
    return _kmKt;
}

int Segmentas::getIesmai() const
{
    return _iesmai;
}

QTime Segmentas::getNuoKada() const
{
    return _nuoKada;
}

Linija Segmentas::getLinija() const
{
    return _linija;
}
