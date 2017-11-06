#ifndef FROMJSON_H
#define FROMJSON_H
#include "linija.h"
#include "div.h"
#include "oper.h"
#include "apar.h"
#include "swork.h"
#include <QString>
#include <QVector>
#include <QJsonObject>
#include <QJsonArray>


class FromJson
{
public:
    FromJson(QString);
    void charge();
    template<class S>
    void fill(QVector<S*>& pool) const;

private:
    template<class T> T* create(const QJsonObject&) const {}
    template<class T> void doFill(QVector<T*>& pool, QString itemArrName) const;

    QString _fileName;
    QJsonObject _job;

    const QString LINIJOS = QString("linijos");
    const QString DIVS = QString("divs");
    const QString OPERS = QString("opers");
    const QString APARS = QString("apars");
    const QString SWORKS = QString("sworks");
};

#endif // FROMJSON_H

template<class S>
inline void FromJson::fill(QVector<S*>& pool) const
{
    QString itemArrName;
    if (std::is_same<S, Linija>::value) itemArrName = LINIJOS;
    else if (std::is_same<S, Div>::value) itemArrName = DIVS;
    else if (std::is_same<S, Apar>::value) itemArrName = APARS;
    else if (std::is_same<S, Oper>::value) itemArrName = OPERS;
    else if (std::is_same<S, Swork>::value) itemArrName = SWORKS;
    doFill(pool, itemArrName);
}

template<class T>
inline void FromJson::doFill(QVector<T*>& pool, QString itemArrName) const
{
    QJsonArray jarr = _job.value(itemArrName).toArray();
    QJsonArray::ConstIterator ci;
    for (ci = jarr.constBegin(); ci != jarr.constEnd(); ++ci)
    {
        QJsonObject qjo = ci->toObject();
        pool << create<T>(qjo);
    }
}

template<>
inline Linija* FromJson::create<Linija>(const QJsonObject& qjo) const
{
    QString name = qjo["name"].toString();
    QString id = qjo["id"].toString();
    return new Linija(id, name);
}

template<>
inline Div* FromJson::create<Div>(const QJsonObject& qjo) const
{
    QString id = qjo["id"].toString();
    QString meistras = qjo["meistras"].toString();
    int nr = qjo["nr"].toInt();
    QString name = qjo["name"].toString();
    return new Div(id, name, nr, meistras);
}

template<>
inline Oper* FromJson::create<Oper>(const QJsonObject& qjo) const
{
    QString id = qjo["id"].toString();
    QString name = qjo["name"].toString();
    int level = qjo["level"].toInt();
    return new Oper(id, name, level);
}

template<>
inline Apar* FromJson::create<Apar>(const QJsonObject& qjo) const
{
    QString id = qjo["id"].toString();
    QString model = qjo["model"].toString();
    int level = qjo["level"].toInt();
    return new Apar(id, model, level);
}

template<>
inline Swork* FromJson::create<Swork>(const QJsonObject& qjo) const
{
    QString id = qjo["id"].toString();
    QString name = qjo["name"].toString();
    return new Swork(id, name);
}


