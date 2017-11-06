#ifndef TEAMTASK_H
#define TEAMTASK_H
#include <QList>
#include "segm.h"
#include "team.h"
#include "swork.h"
#include <QObject>

class Teamtask : public QObject
{
	Q_OBJECT
public:
    Teamtask(){}
    Teamtask(Team* team);
    Teamtask(Team* team, QList<Segm*> segms, QList<Swork*> sworks);
    const Team* getTeam() const;
    void setTeam(Team* team);
    void setSegms(QList<Segm*> segms);
    void setSworks(QList<Swork*> sworks);
    void clearSegms();
    void clearSworks();
    const QList<Segm*> getSegms() const;
    const QList<Swork*> getSworks() const;
    void addSegm(Segm* segm);
    void addSwork(Swork* swork);
    void mergeSegms(QList<Segm*>);
    void mergeSworks(QList<Swork*>);
    int removeSwork(Swork*);
    int removeSegm(Segm*);
    void removeTeam();
private:
    Team* _team;
    QList<Segm*> _segms;
    QList<Swork*> _sworks;
};

#endif // TEAMTASK_H
