#include "segm.h"
#include <QString>
#include <QList>
#include <QTime>
#include "div.h"
#include "linija.h"

Segm::Segm(QString name, int ind, QList<Div*> divs, float kmPagr, float kmKt, int iesmai, QTime nuoKada, Linija* linija)
{
	_name = name;
	_ind = ind;
	_divs = divs;
	_kmPagr = kmPagr;
	_kmKt = kmKt;
	_iesmai = iesmai;
	_nuoKada = nuoKada;
	_linija = linija;
}

Segm::Segm(QString name, int ind, Div* div, float kmPagr, float kmKt, int iesmai, QTime nuoKada, Linija* linija)
{
	_name = name;
	_ind = ind;
	_divs.append(div);
	_kmPagr = kmPagr;
	_kmKt = kmKt;
	_iesmai = iesmai;
	_nuoKada = nuoKada;
	_linija = linija;
}


Segm::Segm(QString name, int ind, Div* div1, Div* div2, float kmPagr, float kmKt, int iesmai, QTime nuoKada, Linija* linija)
{
	_name = name;
	_ind = ind;
	_divs.append(div1);
	_divs.append(div2);
	_kmPagr = kmPagr;
	_kmKt = kmKt;
	_iesmai = iesmai;
	_nuoKada = nuoKada;
	_linija = linija;
}

QString Segm::getName() const
{
    return _name;
}

int Segm::getInd() const
{
    return _ind;
}

const QList<Div*> Segm::getDivs() const
{
    return _divs;
}

float Segm::getKmPagr() const
{
    return _kmPagr;
}

float Segm::getKmKt() const
{
    return _kmKt;
}

int Segm::getIesmai() const
{
    return _iesmai;
}

QTime Segm::getNuoKada() const
{
    return _nuoKada;
}

const Linija* Segm::getLinija() const
{
	return _linija;
}

int Segm::removeDiv(Div* div)
{
	return _divs.removeAll(div);
}

void Segm::removeLinija()
{
	_linija = nullptr;
}
