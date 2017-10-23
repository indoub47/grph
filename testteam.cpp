#include<QtTest/QtTest>
#include <QObject>
#include "operatorius.h"
#include "aparatas.h"
#include <QString>
#include <QList>
#include "team.h"
class TestTeam : public QObject
{
    Q_OBJECT
private slots:
    void construct();
};
void TestTeam::construct()
{
    Operatorius op1("421", "Arūnas Mikužis", 1);
    Operatorius op2("435", "Eduardas Rutskis", 3);
    Operatorius op3("402", "Juozas Vaitkus", 2);
    Aparatas ap1("828", "RDM-23", 1);
    Aparatas ap2("826", "RDM-23", 2);

    QList<Operatorius> operatoriai;
    QList<Aparatas> aparatai;

    operatoriai.append(op1);
    operatoriai.append(op2);
    operatoriai.append(op3);

    aparatai.append(ap1);
    aparatai.append(ap2);

    Team team("My first team", operatoriai, aparatai);

    QVERIFY(team.getOperatoriai()[1].getLevel == 3);
    QVERIFY(team.getAparatai()[0].getId == "828");
    QVERIFY(team.getOperatoriai()[0].getId == "422");
    QVERIFY(team.getOperatoriai()[2].getName == "Juozas Vaitkus");


    QTEST_MAIN(TestTeam)
   #include "testteam.moc"
}
