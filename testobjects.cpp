#include <QtTest/QtTest>
#include "operatorius.h"
#include "aparatas.h"
#include "team.h"
#include "segmentas.h"
#include "meistrija.h"
#include "linija.h"
#include <QList>
#include <QTime>


class TestObjects: public QObject
{
    Q_OBJECT
private slots:
    void testOperatorius();
    void testAparatas();
    void testTeam();
    void testSegmentas();
};

void TestObjects::testSegmentas()
{
  Meistrija km8 = Meistrija("Klaipėdos", "KM-8", 8, "Danė Kairienė");
  Meistrija km1 = Meistrija("Pavenčių", "KM-1", 1, "Alvydas Gelžinis");
  Meistrija km2 = Meistrija("Tryškių", "KM-2", 2, "Gintas Samuilevičius");
  Meistrija km15 = Meistrija("Viduklės", "KM-15", 15, "Remigijus Saunoris");
  Meistrija km14 = Meistrija("Batakių", "KM-14", 14, "Aurelijus Janušaits");
  Meistrija km13 = Meistrija("Tauragės", "KM-13", 13, "Gintaras Šlekys");

  Linija lin23 = Linija("23", "Klaipėda - Pagėgiai");
  Linija lin01 = Linija("01", "Vilnius - Klaipėda");
  Linija lin17 = Linija("17", "Radviliškis - Pagėgiai - valstybės siena");

  // one meistrija as a list
  QList<Meistrija> m8;
  m8.append(km8);
  Segmentas segm1("km 1-8", 0, m8, 8, 0, 5, QTime(8, 0), lin23);
  QCOMPARE(segm1.getMeistrijos().count(), 1);
  QCOMPARE(segm1.getMeistrijos().last().getName(), QString("Klaipėdos"));

  // two meistrijos as a list
  QList<Meistrija> m1_2;
  m1_2.append(km1);
  m1_2.append(km2);
  Segmentas segm254("km 254-264", 20, m1_2, 11, 0, 0, QTime(11, 30), lin01);
  QCOMPARE(segm254.getMeistrijos().count(), 2);
  QCOMPARE(segm254.getMeistrijos().last().getName(), QString("Tryškių"));

  // one meistrija as a Meistrija
  Segmentas segm372("km 372-376", 150, km8, 5, 0, 4, QTime(8, 0), lin01);
  QCOMPARE(segm372.getMeistrijos().count(), 1);
  QCOMPARE(segm372.getMeistrijos().last().getName(), QString("Klaipėdos"));

  // one meistrija as a Meistrija
  Segmentas segm53("km 53-59", 1, km15, 9, 0, 0, QTime(11, 30), lin17);
  QCOMPARE(segm53.getMeistrijos().count(), 1);
  QCOMPARE(segm53.getMeistrijos().last().getName(), QString("Viduklės"));

  // two meistrijos separately
  Segmentas segm75("km 75-84", 50, km15, km14, 10, 0, 0, QTime(11, 30), lin17);
  QCOMPARE(segm75.getMeistrijos().count(), 2);
  QCOMPARE(segm75.getMeistrijos().first().getName(), QString("Viduklės"));
  QCOMPARE(segm75.getMeistrijos().last().getName(), QString("Batakių"));

  // two meistrijos separately
  Segmentas segm103("km 103-112", 120, km14, km13, 10, 0, 4, QTime(11, 30), lin17);
  QCOMPARE(segm103.getMeistrijos().count(), 2);
  QCOMPARE(segm103.getMeistrijos().first().getName(), QString("Batakių"));
  QCOMPARE(segm103.getMeistrijos().last().getName(), QString("Tauragės"));

  // one meistrija as a Meistrija
  Segmentas segm113("km 113-119", 200, km13, 5, 0, 4, QTime(11, 30), lin17);
  QCOMPARE(segm113.getMeistrijos().count(), 1);
  QCOMPARE(segm113.getMeistrijos().first().getNr(), 13);

  QCOMPARE(segm53 < segm75, true);
  QCOMPARE(segm75 <= segm103, true);
  QCOMPARE(segm113 > segm53, true);
  QCOMPARE(segm103 >= segm103, true);
  QCOMPARE(segm103 <= segm103, true);
  QCOMPARE(segm113 != segm103, true);
  QCOMPARE(segm1 == segm1, true);
  QCOMPARE(segm254 != segm113, true);
  // bool comp1 = segm113 > segm1;
  try
  {
    bool comp = segm113 > segm1;
    QCOMPARE(comp, false);
  }
  catch(std::invalid_argument& e)
  {
    QCOMPARE(QString(e.what()), QString("comparing segments from different linijas"));
  }
}

void TestObjects::testOperatorius()
{
    Operatorius oper("400", "Evaldas Ilginis", 1);
    QCOMPARE(oper.getName(), QString("Evaldas Ilginis"));
    QCOMPARE(oper.getId(), QString("400"));
    QCOMPARE(oper.getLevel(), 1);
    QCOMPARE(oper.getShortName(), QString("E.Ilginis"));

    Operatorius operA("401", "Antanas Eduardas Mykolas Rutskis", 3);
    QCOMPARE(operA.getShortName(), QString("A.E.M.Rutskis"));

    Operatorius operB("402", "Bronius", 3);
    QCOMPARE(operB.getShortName(), QString("Bronius"));

    Operatorius oper1_1("405", "Evaldas Ilginis", 1);
    Operatorius oper1_2("407", "Juozas Janonis", 1);
    Operatorius oper2_1("401", "Andrius Jonauskas", 2);
    Operatorius oper2_2("402", "Saulius Adakauskas", 2);
    Operatorius oper2_2x("402", "Saulius Adakauskas", 3);
    Operatorius oper1_2x("407", "Mykolas Mykolaitis", 1);

    QCOMPARE(oper1_2 == oper1_2x, true);
    QCOMPARE(oper1_1 == oper1_2, false);
    QCOMPARE(oper1_1 <= oper1_2, true);
    QCOMPARE(oper1_1 < oper1_2, true);
    QCOMPARE(oper1_2 < oper2_1, true);
    QCOMPARE(oper2_2 > oper2_1, true);
    QCOMPARE(oper2_2 >= oper1_1, true);
    QCOMPARE(oper1_2 != oper1_2x, false);
    QCOMPARE(oper2_2 < oper2_2x, true);
}

void TestObjects::testAparatas()
{
    Aparatas apar("800", "RDM-23", 1);
    QCOMPARE(apar.getModel(), QString("RDM-23"));
    QCOMPARE(apar.getId(), QString("800"));
    QCOMPARE(apar.getLevel(), 1);

    Aparatas apar11("805", "RDM", 1);
    Aparatas apar12("807", "RDM", 1);
    Aparatas apar21("801", "RDM", 2);
    Aparatas apar22("802", "RDM", 2);
    Aparatas apar22x("802", "RDM", 3);
    Aparatas apar12x("807", "RDM", 1);

    QCOMPARE(apar12 == apar12x, true);
    QCOMPARE(apar11 == apar12, false);
    QCOMPARE(apar11 <= apar12, true);
    QCOMPARE(apar11 < apar12, true);
    QCOMPARE(apar12 < apar21, true);
    QCOMPARE(apar22 > apar21, true);
    QCOMPARE(apar22 >= apar11, true);
    QCOMPARE(apar12 != apar12x, false);
    QCOMPARE(apar22 < apar22x, true);
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
