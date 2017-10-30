#ifndef TEAMTASK_H
#define TEAMTASK_H
#include <QList>
#include "segmentas.h"
#include "team.h"
#include "sidework.h"
class Teamtask
{
public:
    Teamtask(){}
    Teamtask(Team team);
    Teamtask(Team team, QList<Segmentas> segmentai, QList<Sidework> sideworks);
    Team getTeam() const;
    Team* getTeamP();
    Team& getTeamR();
    void setTeam(Team team);
    void setSegmentai(QList<Segmentas> segmentai);
    void setSideworks(QList<Sidework> sideworks);
    void clearSegmentai();
    void clearSideworks();
    const QList<Segmentas>& getSegmentai() const;
    const QList<Sidework>& getSideworks() const;
    void addSegmentas(Segmentas segmentas);
    void addSidework(Sidework sidework);
    void mergeSegmentai(QList<Segmentas>);
    void mergeSideworks(QList<Sidework>);
private:
    Team _team;
    QList<Segmentas> _segmentai;
    QList<Sidework> _sideworks;
};

#endif // TEAMTASK_H
