#ifndef INDX_H
#define INDX_H
#include <QString>
#include <QDate>
#include <QDebug>


struct Indx
{
public:
    Indx();
    Indx(const Indx &other);
    ~Indx();
    Indx(const QString &teamId, const QString &linId, const QDate &date):m_teamId(teamId), m_linId(linId), m_date(date){}
    QString teamId() const;
    QString linId() const;
    QDate date() const;
    friend QDebug operator<<(QDebug dbg, const Indx& index)
    {
        dbg.nospace() << "Index(" <<
                         "team_id:" << index.m_teamId <<
                         ", linija_id:" << index.m_linId <<
                         ", date:" << index.m_date.toString(Qt::SystemLocaleShortDate) <<
                         ")";
        return dbg.maybeSpace();
    }
private:
    QString m_teamId;
    QString m_linId;
    QDate m_date;
};
#endif //INDX_H
Q_DECLARE_METATYPE(Indx)


