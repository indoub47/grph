#ifndef TESTTEAM_H
#define TESTTEAM_H
 #include<QtTest/QtTest>
#include <QObject>
#include "team.h"

class TestTeam : public QObject
{
    Q_OBJECT
private slots:
    void construct();
};

#endif //TESTTEAM_H
