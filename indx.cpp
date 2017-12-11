#include "indx.h"
#include <QString>
#include <QDate>

Indx::Indx()
{}

Indx::Indx(const Indx &other)
{
    m_teamId = other.m_teamId;
    m_linId = other.m_linId;
    m_date = other.m_date;
}

Indx::~Indx()
{}

QString Indx::teamId() const
{
    return m_teamId;
}

QString Indx::linId() const
{
    return m_linId;
}

QDate Indx::date() const
{
    return m_date;
}


