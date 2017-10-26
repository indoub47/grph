#include "segmentas.h"
#include <QString>
#include <QList>
#include <QTime>
#include "meistrija.h"
#include "linija.h"

Segmentas::Segmentas(QString name, int ind, QList<Meistrija> meistrijos, float kmPagr, float kmKt, int iesmai, QTime nuoKada, Linija linija)
{
        _name = name;
        _ind = ind;
        _meistrijos = meistrijos;
        _kmPagr = kmPagr;
        _kmKt = kmKt;
        _iesmai = iesmai;
        _nuoKada = nuoKada;
        _linija = linija;
}

Segmentas::Segmentas(QString name, int ind, Meistrija meistrija, float kmPagr, float kmKt, int iesmai, QTime nuoKada, Linija linija)
{
        _name = name;
        _ind = ind;
        _meistrijos.append(meistrija);
        _kmPagr = kmPagr;
        _kmKt = kmKt;
        _iesmai = iesmai;
        _nuoKada = nuoKada;
        _linija = linija;
}


Segmentas::Segmentas(QString name, int ind, Meistrija meistrija1, Meistrija meistrija2, float kmPagr, float kmKt, int iesmai, QTime nuoKada, Linija linija)
{
        _name = name;
        _ind = ind;
        _meistrijos.append(meistrija1);
        _meistrijos.append(meistrija2);
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

int Segmentas::getInd() const
{
    return _ind;
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
