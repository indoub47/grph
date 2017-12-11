#ifndef TEAMTASKTABLEWITEM_H
#define TEAMTASKTABLEWITEM_H
#include <QTableWidgetItem>
#include "model/teamtask.h"
#include "indx.h"

#include <QObject>

class TeamtaskTableWItem : public QObject, public QTableWidgetItem
{
    Q_OBJECT
public:
    TeamtaskTableWItem(Indx indx);
    const Indx indx() const;
    const Teamtask* teamtask() const;
    void setTeamtask(Teamtask* teamtask);
    bool isEmpty() const;
    QVariant data(int role) const;
private:
    QBrush backgroundBrush() const;
    const QString formatText() const;
    Teamtask* m_teamtask;
    Indx m_indx;
};

#endif // TEAMTASKTABLEWITEM_H
