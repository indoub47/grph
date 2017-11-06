#ifndef SEGM_H
#define SEGM_H
#include <QString>
#include <QList>
#include <QTime>
#include "div.h"
#include "linija.h"
#include <stdexcept>

class Segm
{
public:
    Segm(){}
    Segm(QString name, int ind, QList<Div*> divs, float kmPagr, float kmKt, int iesmai, QTime nuoKada, Linija* linija);
    Segm(QString name, int ind, Div* div, float kmPagr, float kmKt, int iesmai, QTime nuoKada, Linija* linija);
    Segm(QString name, int ind, Div* div1, Div* div2, float kmPagr, float kmKt, int iesmai, QTime nuoKada, Linija* linija);
    QString getName() const;
    int getInd() const;
    const QList<Div*> getDivs() const;
    float getKmPagr() const;
    float getKmKt() const;
    int getIesmai() const;
    QTime getNuoKada() const;
    const Linija* getLinija() const;
    int removeDiv(Div* div);
    void removeLinija();

    friend inline bool operator< (const Segm& l, const Segm& r)
    {
		if (l._linija != r._linija)
		{
			throw std::invalid_argument("comparing segments from different linijas");
		}
		return l._ind < r._ind;
    }
    friend inline bool operator==(const Segm& l, const Segm& r){return l._linija == r._linija && l._ind == r._ind;}
    friend inline bool operator> (const Segm& lhs, const Segm& rhs){ return rhs < lhs;}
    friend inline bool operator<=(const Segm& lhs, const Segm& rhs){ return !(lhs > rhs);}
    friend inline bool operator>=(const Segm& lhs, const Segm& rhs){ return !(lhs < rhs);}
    friend inline bool operator!=(const Segm& lhs, const Segm& rhs){ return !(lhs == rhs);}

private:
    QString _name;
    int _ind;
    QList<Div*> _divs;
    float _kmPagr;
    float _kmKt;
    int _iesmai;
    QTime _nuoKada;
    Linija* _linija;
};

#endif // SEGM_H
