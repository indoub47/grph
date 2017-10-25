#include <QtTest/QtTest>
#include "operatorius.h"
#include "aparatas.h"
#include "team.h"

class TestObjects: public QObject
{
    Q_OBJECT
private slots:
    void operatoriusGetters();
    void aparatasGetters();
    void testTeam();
};

void TestObjects::operatoriusGetters()
{
    Operatorius oper("400", "Evaldas Ilginis", 1);
    QCOMPARE(oper.getName(), QString("Evaldas Ilginis"));
    QCOMPARE(oper.getId(), QString("400"));
    QCOMPARE(oper.getLevel(), 1);
    QCOMPARE(oper.getShortName(), QString("E.Ilginis"));

    Operatorius oper1("401", "Antanas Eduardas Mykolas Rutskis", 3);
    QCOMPARE(oper1.getShortName(), QString("A.E.M.Rutskis"));

    Operatorius oper2("402", "Bronius", 3);
    QCOMPARE(oper2.getShortName(), QString("Bronius"));
}

void TestObjects::aparatasGetters()
{
    Aparatas apar("800", "RDM-23", 1);
    QCOMPARE(apar.getModel(), QString("RDM-23"));
    QCOMPARE(apar.getId(), QString("800"));
    QCOMPARE(apar.getLevel(), 1);
}

void TestObjects::testTeam()
{
  Aparatas ap828("828", "RDM-23", 1);
  Aparatas ap826("826", "RDM-23", 2);
  Aparatas ap8261("826", "RDM-23", 2);
  Aparatas ap825("825", "RDM-23", 1);
  Aparatas ap829("829", "RDM-23", 1);

  Team team("My first team");

  // adding aparatas - 828
  team.addAparatas(ap828);
  QCOMPARE(team.getAparatai().count(), 1);
  QCOMPARE(team.getAparatai().last().getId(), QString("828"));

  // adding aparatas - 828, 826
  team.addAparatas(ap826);
  QCOMPARE(team.getAparatai().count(), 2);
  QCOMPARE(team.getAparatai().last().getId(), QString("826"));

  // adding aparatas - 828, 826, 829
  team.addAparatas(ap829);
  QCOMPARE(team.getAparatai().count(), 3);
  QCOMPARE(team.getAparatai().last().getId(), QString("829"));

  // adding aparatas - 828, 826, 829, 825
  team.addAparatas(ap825);
  QCOMPARE(team.getAparatai().count(), 4);
  QCOMPARE(team.getAparatai().last().getId(), QString("825"));

  // adding existing aparatas - 828, 826, 829, 825
  team.addAparatas(ap8261);
  QCOMPARE(team.getAparatai().count(), 4);
  QCOMPARE(team.getAparatai().last().getId(), QString("825"));

  // removing aparatas by index - 828, 829, 825
  team.removeAparatas(1);
  QCOMPARE(team.getAparatai().count(), 3);
  QCOMPARE(team.getAparatai().last().getId(), QString("825"));

  // removing aparatas by id - 828, 825
  team.removeAparatas("829");
  QCOMPARE(team.getAparatai().count(), 2);
  QCOMPARE(team.getAparatai().last().getId(), QString("825"));

  // removing aparatas by non-existing id - 828, 825
  team.removeAparatas("829");
  QCOMPARE(team.getAparatai().count(), 2);
  QCOMPARE(team.getAparatai().last().getId(), QString("825"));

  // removing aparatas by too big index - 828, 825
  team.removeAparatas(3);
  QCOMPARE(team.getAparatai().count(), 2);
  QCOMPARE(team.getAparatai().last().getId(), QString("825"));

  // removing aparatas by negative index - 828, 825
  team.removeAparatas(-1);
  QCOMPARE(team.getAparatai().count(), 2);
  QCOMPARE(team.getAparatai().last().getId(), QString("825"));


  Operatorius op421("421", "Arūnas Mikužis", 1);
  Operatorius op435("435", "Eduardas Antanas Rutskis", 3);
  Operatorius op402("402", "Juozas Vaitkus", 2);
  Operatorius op427("427", "Audrius Lubys", 1);
  Operatorius op425("425", "Andrius Adakauskas", 1);
  Operatorius op4251("425", "Andrius Adakauskas", 1);
  Operatorius op428("428", "Bronius Mikužis", 2);

  // adding operatorius - 427
  team.addOperatorius(op427);
  QCOMPARE(team.getOperatoriai().count(), 1);
  QCOMPARE(team.getOperatoriai().last().getId(), QString("427"));

  // adding operatorius - 427, 425
  team.addOperatorius(op425);
  QCOMPARE(team.getOperatoriai().count(), 2);
  QCOMPARE(team.getOperatoriai().last().getId(), QString("425"));

  // adding operatorius - 427, 425, 428
  team.addOperatorius(op428);
  QCOMPARE(team.getOperatoriai().count(), 3);
  QCOMPARE(team.getOperatoriai().last().getId(), QString("428"));

  // adding operatorius - 427, 425, 428, 402
  team.addOperatorius(op402);
  QCOMPARE(team.getOperatoriai().count(), 4);
  QCOMPARE(team.getOperatoriai().last().getId(), QString("402"));

  // adding operatorius already in list - 427, 425, 428, 402
  team.addOperatorius(op4251);
  QCOMPARE(team.getOperatoriai().count(), 4);
  QCOMPARE(team.getOperatoriai().last().getId(), QString("402"));

  // removing operatorius by index - 427, 428, 402
  team.removeOperatorius(1);
  QCOMPARE(team.getOperatoriai().count(), 3);
  QCOMPARE(team.getOperatoriai()[1].getId(), QString("428"));
  QCOMPARE(team.getOperatoriai().last().getId(), QString("402"));

  // removing operatorius by id - 427, 402
  team.removeOperatorius("428");
  QCOMPARE(team.getOperatoriai().count(), 2);
  QCOMPARE(team.getOperatoriai()[1].getId(), QString("402"));
  QCOMPARE(team.getOperatoriai().last().getId(), QString("402"));

  // removing operatorius by non-existing id - 427, 402
  team.removeOperatorius("428");
  QCOMPARE(team.getOperatoriai().count(), 2);
  QCOMPARE(team.getOperatoriai()[1].getId(), QString("402"));
  QCOMPARE(team.getOperatoriai().last().getId(), QString("402"));

  // removing operatorius by inexisting index - 427, 402
  team.removeOperatorius(3);
  QCOMPARE(team.getOperatoriai().count(), 2);
  QCOMPARE(team.getOperatoriai()[1].getId(), QString("402"));
  QCOMPARE(team.getOperatoriai().last().getId(), QString("402"));

  // removing operatorius by negative index - 427, 402
  team.removeOperatorius(-1);
  QCOMPARE(team.getOperatoriai().count(), 2);
  QCOMPARE(team.getOperatoriai()[1].getId(), QString("402"));
  QCOMPARE(team.getOperatoriai().last().getId(), QString("402"));
}


QTEST_MAIN(TestObjects)
#include "testobjects.moc"
