#ifndef INDEXBUTTON_H
#define INDEXBUTTON_H
#include <QPushButton>
#include "index.h"

#include <QObject>

class IndexButton : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(Index Index READ index)
public:
    IndexButton(Index index);
    IndexButton(QString teamId, QString linId, QDate date);
    const Index index() const;
private:
    Index _index;
};

#endif // INDEXBUTTON_H
