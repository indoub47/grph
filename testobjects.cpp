#include <QtTest/QtTest>
#include "operatorius.h"
#include "aparatas.h"
#include "team.h"
#include "segmentas.h"
#include "meistrija.h"
#include "linija.h"
#include "teamtask.h"
#include <QList>
#include <QTime>


class TestObjects: public QObject
{
    Q_OBJECT
private slots:
    void testTeamtask();
    void testOperatorius();
    void testAparatas();
    void testTeam();
    void testSegmentas();
};

void TestObjects::testTeamtask()
{
  Operatorius op421("421", "Arūnas Mikužis", 1);
  Operatorius op435("435", "Eduardas Antanas Rutskis", 3);
  Operatorius op402("402", "Juozas Vaitkus", 2);
  Operatorius op427("427", "Audrius Lubys", 1);
  Operatorius op425("425", "Andrius Adakauskas", 1);
  Operatorius op4251("425", "Andrius Adakauskas", 1);
  Operatorius op428("428", "Bronius Mikužis", 2);

  Aparatas ap828("828", "RDM-23", 1);
  Aparatas ap826("826", "RDM-23", 2);
  Aparatas ap8261("826", "RDM-23", 2);
  Aparatas ap825("825", "RDM-23", 1);
  Aparatas ap829("829", "RDM-23", 1);

  QList<Operatorius> operList1;
  operList1 << op421 << op435;
  QList<Aparatas> aparList1;
  aparList1 << ap828 << ap826;
  Team tm828("828", operList1, aparList1);

  QList<Operatorius> operList2;
  operList2 << op427 << op425;
  QList<Aparatas> aparList2;
  aparList2 << ap825;
  Team tm825("825", operList2, aparList2);


  Meistrija km8 = Meistrija("Klaipėdos", "KM-8", 8, "Danė Kairienė");
  Meistrija km1 = Meistrija("Pavenčių", "KM-1", 1, "Alvydas Gelžinis");
  Meistrija km2 = Meistrija("Tryškių", "KM-2", 2, "Gintas Samuilevičius");
  Meistrija km15 = Meistrija("Viduklės", "KM-15", 15, "Remigijus Saunoris");
  Meistrija km14 = Meistrija("Batakių", "KM-14", 14, "Aurelijus Janušaits");
  Meistrija km13 = Meistrija("Tauragės", "KM-13", 13, "Gintaras Šlekys");

  Linija lin23 = Linija("23", "Klaipėda - Pagėgiai");
  Linija lin01 = Linija("01", "Vilnius - Klaipėda");
  Linija lin17 = Linija("17", "Radviliškis - Pagėgiai - valstybės siena");


  QList<Meistrija> m8;
  m8.append(km8);
  Segmentas segm1 = Segmentas("km 1-8", 0, m8, 8, 0, 5, QTime(8, 0), lin23);
  QList<Meistrija> m1_2;
  m1_2.append(km1);
  m1_2.append(km2);

  Segmentas segm254 = Segmentas("km 254-264", 20, m1_2, 11, 0, 0, QTime(11, 30), lin01);
  Segmentas segm372 = Segmentas("km 372-376", 150, km8, 5, 0, 4, QTime(8, 0), lin01);
  Segmentas segm53 = Segmentas("km 53-59", 1, km15, 9, 0, 0, QTime(11, 30), lin17);
  Segmentas segm75 = Segmentas("km 75-84", 50, km15, km14, 10, 0, 0, QTime(11, 30), lin17);
  Segmentas segm103 = Segmentas("km 103-112", 120, km14, km13, 10, 0, 4, QTime(11, 30), lin17);
  Segmentas segm113 = Segmentas("km 113-119", 200, km13, 5, 0, 4, QTime(11, 30), lin17);

  QList<Segmentas> sgs1;
  sgs1 << segm1;
  sgs1 << segm75;

  QList<Segmentas> sgs2;
  sgs2 << segm103 << segm113;

  QList<Segmentas> sgs3;
  sgs3 << segm372 << segm254;

  Sidework swT("T", "techninė priežiūra");
  Sidework swEr("ER", "einamasis remontas");
  Sidework swA("A", "ataskaita");
  Sidework swTm("TM", "techniniai mokymai");

  QList<Sidework> sdws1;
  sdws1 << swA << swT;

  Teamtask tt1(tm828);
  QCOMPARE(tt1.getTeam().getName(), QString("828"));
  QCOMPARE(tt1.getSegmentai().count(), 0);
  QCOMPARE(tt1.getSideworks().count(), 0);
  tt1.addSegmentas(segm53);
  QCOMPARE(tt1.getSegmentai().count(), 1);
  QCOMPARE(tt1.getSegmentai().first().getLinija().getId(), QString("17"));
  tt1.addSidework(swTm);
  QCOMPARE(tt1.getSideworks().count(), 1);
  QCOMPARE(tt1.getSideworks().last().getName(), QString("TM"));
  tt1.clearSideworks();
  QCOMPARE(tt1.getSideworks().count(), 0);
  tt1.setSideworks(sdws1);
  QCOMPARE(tt1.getSideworks().count(), 2);
  QCOMPARE(tt1.getSideworks().last().getName(), QString("T"));
  QCOMPARE(tt1.getSideworks().first().getName(), QString("A"));
  tt1.addSidework(swEr);
  QCOMPARE(tt1.getSideworks().count(), 3);
  QCOMPARE(tt1.getSideworks().last().getName(), QString("ER"));
  QCOMPARE(tt1.getSideworks().first().getName(), QString("A"));

  Teamtask tt2(tm825, sgs1, sdws1);
  QCOMPARE(tt2.getTeam().getName(), QString("825"));
  QCOMPARE(tt2.getSegmentai().count(), 2);
  QCOMPARE(tt2.getSegmentai().last().getMeistrijos().last().getNr(), 14);
  QCOMPARE(tt2.getSideworks().count(), 2);
  QCOMPARE(tt2.getSideworks().last().getName(), QString("T"));
  tt2.clearSegmentai();
  QCOMPARE(tt2.getSegmentai().count(), 0);
  tt2.setSegmentai(sgs2);
  QCOMPARE(tt2.getSegmentai().count(), 2);
  QCOMPARE(tt2.getSegmentai().last().getMeistrijos().last().getNr(), 13);
  tt2.setSegmentai(sgs3);
  QCOMPARE(tt2.getSegmentai().count(), 2);
  QCOMPARE(tt2.getSegmentai().last().getMeistrijos().last().getShortName(), QString("KM-2"));


  QCOMPARE(tt2.getTeam().getAparatai().count(), 1);
  Team tm = tt2.getTeam();
  tm.addAparatas(ap828);
  QCOMPARE(tm.getAparatai().count(), 2);
  QCOMPARE(tt2.getTeam().getAparatai().count(), 1);
  tt2.getTeam().addAparatas(ap828);
  QCOMPARE(tt2.getTeam().getAparatai().count(), 1);

  // jeigu getTeam grąžinti neconst pointerį arba neconst reference?

  QCOMPARE(tt2.getTeam().getAparatai().count(), 1);
  Team* tmp = tt2.getTeamP();
  tmp->addAparatas(ap828);
  QCOMPARE(tt2.getTeam().getAparatai().count(), 2);
  Team& tmr = tt2.getTeamR();
  tmr.addAparatas(ap8261);
  QCOMPARE(tt2.getTeam().getAparatai().count(), 3);

  // testing mergeSideworks and mergeSegmentai
  /*
  Segmentas segm254 = Segmentas("km 254-264", 20, m1_2, 11, 0, 0, QTime(11, 30), lin01);
  Segmentas segm372 = Segmentas("km 372-376", 150, km8, 5, 0, 4, QTime(8, 0), lin01);
  Segmentas segm53 = Segmentas("km 53-59", 1, km15, 9, 0, 0, QTime(11, 30), lin17);
  Segmentas segm75 = Segmentas("km 75-84", 50, km15, km14, 10, 0, 0, QTime(11, 30), lin17);
  Segmentas segm103 = Segmentas("km 103-112", 120, km14, km13, 10, 0, 4, QTime(11, 30), lin17);
  Segmentas segm113 = Segmentas("km 113-119", 200, km13, 5, 0, 4, QTime(11, 30), lin17);

  Sidework swT("T", "techninė priežiūra");
  Sidework swEr("ER", "einamasis remontas");
  Sidework swA("A", "ataskaita");
  Sidework swTm("TM", "techniniai mokymai");
  */
  Teamtask ttm(tm828);
  ttm.addSegmentas(segm254);
  ttm.addSegmentas(segm372);
  ttm.addSidework(swT);
  ttm.addSidework(swEr);

  QCOMPARE(ttm.getSegmentai().count(), 2);
  QCOMPARE(ttm.getSegmentai().first().getInd(), 20);
  QCOMPARE(ttm.getSegmentai().last().getInd(), 150);

  QList<Segmentas> sgm;
  sgm << segm372 << segm53;
  ttm.mergeSegmentai(sgm);
  QCOMPARE(ttm.getSegmentai().count(), 3);
  QCOMPARE(ttm.getSegmentai().first().getInd(), 20);
  QCOMPARE(ttm.getSegmentai().last().getInd(), 1);
  // 254-372-53
  QList<Segmentas> empt;
  ttm.mergeSegmentai(empt);
  QCOMPARE(ttm.getSegmentai().count(), 3);
  QCOMPARE(ttm.getSegmentai().first().getInd(), 20);
  QCOMPARE(ttm.getSegmentai()[1].getInd(), 150);
  QCOMPARE(ttm.getSegmentai().last().getInd(), 1);

  QCOMPARE(ttm.getSideworks().count(), 2);
  QCOMPARE(ttm.getSideworks().first().getName(), QString("T"));
  QCOMPARE(ttm.getSideworks().last().getName(), QString("ER"));

  QList<Sidework> emptsw;
  ttm.mergeSideworks(emptsw);
  QCOMPARE(ttm.getSideworks().count(), 2);
  QCOMPARE(ttm.getSideworks().first().getName(), QString("T"));
  QCOMPARE(ttm.getSideworks().last().getName(), QString("ER"));

  QList<Sidework> sws;
  sws << swA << swTm;
  ttm.mergeSideworks(sws);
  QCOMPARE(ttm.getSideworks().count(), 4);
  QCOMPARE(ttm.getSideworks()[0].getName(), QString("T"));
  QCOMPARE(ttm.getSideworks()[1].getName(), QString("ER"));
  QCOMPARE(ttm.getSideworks()[2].getName(), QString("A"));
  QCOMPARE(ttm.getSideworks()[3].getName(), QString("TM"));

  Sidework sextra("XX", "XXXX");
  QList<Sidework> swsx;
  swsx << swA << sextra << swTm;
  ttm.mergeSideworks(swsx);
  QCOMPARE(ttm.getSideworks().count(), 5);
  QCOMPARE(ttm.getSideworks()[0].getName(), QString("T"));
  QCOMPARE(ttm.getSideworks()[1].getName(), QString("ER"));
  QCOMPARE(ttm.getSideworks()[2].getName(), QString("A"));
  QCOMPARE(ttm.getSideworks()[3].getName(), QString("TM"));
  QCOMPARE(ttm.getSideworks()[4].getName(), QString("XX"));
}

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

  const Aparatas ap = team.getAparatas(2);
  QCOMPARE(ap.getId(), QString("829"));

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

  //const Operatorius* opminus = team.getOperatorius(-2);
  const Operatorius opok = team.getOperatorius(2);
  QCOMPARE(opok.getId(), QString("428"));
  //const Operatorius* opover = team.getOperatorius(12);

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

  // team: My first team
  // op427, op402
  // ap828, ap825
  /*
  Operatorius op421("421", "Arūnas Mikužis", 1);
  Operatorius op435("435", "Eduardas Antanas Rutskis", 3);
  Operatorius op402("402", "Juozas Vaitkus", 2);
  Operatorius op427("427", "Audrius Lubys", 1);
  Operatorius op425("425", "Andrius Adakauskas", 1);
  Operatorius op4251("425", "Andrius Adakauskas", 1);
  Operatorius op428("428", "Bronius Mikužis", 2);
  */
  /*
  Aparatas ap828("828", "RDM-23", 1);
  Aparatas ap826("826", "RDM-23", 2);
  Aparatas ap8261("826", "RDM-23", 2);
  Aparatas ap825("825", "RDM-23", 1);
  Aparatas ap829("829", "RDM-23", 1);
  */

  Team teamEq("My first team");
  Team team3("My second team");

  // create equal team
  QList<Aparatas> apEq;
  apEq << ap825 << ap828;
  QList<Operatorius> opEq;
  opEq << op427 << op402;
  teamEq.setAparatai(apEq);
  teamEq.setOperatoriai(opEq);
  // and compare
  QCOMPARE(team == teamEq, true);

  // remove operatorius and compare
  teamEq.removeOperatorius(0);
  QCOMPARE(team == teamEq, false);

  // restore to equal and compare for control
  teamEq.setOperatoriai(opEq);
  QCOMPARE(team == teamEq, true);

  // remove aparatas and compare
  teamEq.removeAparatas("828");
  QCOMPARE(team == teamEq, false);

  // restore to equal and compare for control
  teamEq.setAparatai(apEq);
  QCOMPARE(team == teamEq, true);

  // create yet another unequal case (different aparatas)
  QList<Aparatas> apUneq;
  apUneq << ap825 << ap829;
  teamEq.setAparatai(apUneq);
  QCOMPARE(team == teamEq, false);

  // restore to equal and compare for control
  teamEq.setAparatai(apEq);
  QCOMPARE(team == teamEq, true);

  // create yet another unequal case (different aparatas count)
  QList<Aparatas> apUneq1;
  apUneq1 << ap825 << ap828 << ap826;
  teamEq.setAparatai(apUneq1);
  QCOMPARE(team == teamEq, false);

  QCOMPARE(team == team3, false);
}


QTEST_MAIN(TestObjects)
#include "testobjects.moc"
