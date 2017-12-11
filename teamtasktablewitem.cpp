#include "teamtasktablewitem.h"
#include <QTableWidgetItem>
#include "model/teamtask.h"

TeamtaskTableWItem::TeamtaskTableWItem(Indx indx):QTableWidgetItem(1001)
{
    m_indx = indx;
    m_teamtask = nullptr;
    setFlags(Qt::NoItemFlags | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    //setSelected(false);
}

const Indx TeamtaskTableWItem::indx() const
{
    return m_indx;
}

const Teamtask* TeamtaskTableWItem::teamtask() const
{
    return m_teamtask;
}

void TeamtaskTableWItem::setTeamtask(Teamtask* teamtask)
{
    m_teamtask = teamtask;
}

bool TeamtaskTableWItem::isEmpty() const
{
    return m_teamtask == nullptr;
}

QVariant TeamtaskTableWItem::data(int role) const
{
    if (role==Qt::BackgroundRole)
        return backgroundBrush();
    else if (role==Qt::DisplayRole)
        return formatText();
    else if (role==Qt::TextAlignmentRole)
        return Qt::AlignCenter;
    else
        return QTableWidgetItem::data(role);
}

QBrush TeamtaskTableWItem::backgroundBrush() const
{
    // parinkti brush pagal team
    return QBrush(QColor(Qt::yellow), Qt::SolidPattern);
}

const QString TeamtaskTableWItem::formatText() const
{
    if (m_teamtask == nullptr)
    {
        return QString("team: %1,\nlinija: %2\n%3").arg(
                    m_indx.teamId(),
                    m_indx.linId(),
                    m_indx.date().toString(Qt::SystemLocaleShortDate));
    }
    else
    {
       QList<Segm*> segms = m_teamtask->getSegms();
       QList<Swork*> sworks = m_teamtask->getSworks();
       QString res = "";

       for(int s = 0; s < segms.length(); s++)
       {
           res = res + segms[s]->getName();
           if (s < segms.length()-1)
           {
               res = res + "\n";
           }
       }

       if (sworks.length() > 0)
       {
           res = res + "\n";
       }

       for(int s = 0; s < sworks.length(); s++)
       {
           res = res + sworks[s]->getName();
           if (s < sworks.length()-1)
           {
               res = res + ", ";
           }
       }

       return res;
    }
}
