#include "indexbutton.h"
#include <QPushButton>
#include "index.h"
#include <QString>
#include <QDate>

IndexButton::IndexButton(Index index):_index(index)
{
    //base();
}

IndexButton::IndexButton(QString teamId, QString linId, QDate date):_index(Index(teamId, linId, date))
{
    //base();
}

const Index IndexButton::index() const
{
    return _index;
}
