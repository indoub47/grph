#include <QtTest/QtTest>
#include "oper.h"
#include "apar.h"
#include "team.h"
#include "segm.h"
#include "div.h"
#include "linija.h"
#include "teamtask.h"
#include <QList>
#include <QTime>


class TestObjects: public QObject
{
    Q_OBJECT
private slots:
    //void testTeamtask();
    void testOper();
    void testApar();
    //void testTeam();
    void testSegm();
};
/*
void TestObjects::testTeamtask()
{
  Oper op421("421", "Arūnas Mikužis", 1);
  Oper op435("435", "Eduardas Antanas Rutskis", 3);
  Oper op402("402", "Juozas Vaitkus", 2);
  Oper op427("427", "Audrius Lubys", 1);
  Oper op425("425", "Andrius Adakauskas", 1);
  Oper op4251("425", "Andrius Adakauskas", 1);
  Oper op428("428", "Bronius Mikužis", 2);

  Apar ap828("828", "RDM-23", 1);
  Apar ap826("826", "RDM-23", 2);
  Apar ap8261("826", "RDM-23", 2);
  Apar ap825("825", "RDM-23", 1);
  Apar ap829("829", "RDM-23", 1);

  QList<Oper> operList1;
  operList1 << op421 << op435;
  QList<Apar> aparList1;
  aparList1 << ap828 << ap826;
  Team tm828("828", operList1, aparList1);

  QList<Oper> operList2;
  operList2 << op427 << op425;
  QList<Apar> aparList2;
  aparList2 << ap825;
  Team tm825("825", operList2, aparList2);


  Div km8 = Div("Klaipėdos", "KM-8", 8, "Danė Kairienė");
  Div km1 = Div("Pavenčių", "KM-1", 1, "Alvydas Gelžinis");
  Div km2 = Div("Tryškių", "KM-2", 2, "Gintas Samuilevičius");
  Div km15 = Div("Viduklės", "KM-15", 15, "Remigijus Saunoris");
  Div km14 = Div("Batakių", "KM-14", 14, "Aurelijus Janušaits");
  Div km13 = Div("Tauragės", "KM-13", 13, "Gintaras Šlekys");

  Linija lin23 = Linija("23", "Klaipėda - Pagėgiai");
  Linija lin01 = Linija("01", "Vilnius - Klaipėda");
  Linija lin17 = Linija("17", "Radviliškis - Pagėgiai - valstybės siena");


  QList<Div> m8;
  m8.append(km8);
  Segm segm1 = Segm("km 1-8", 0, m8, 8, 0, 5, QTime(8, 0), lin23);
  QList<Div> m1_2;
  m1_2.append(km1);
  m1_2.append(km2);

  Segm segm254 = Segm("km 254-264", 20, m1_2, 11, 0, 0, QTime(11, 30), lin01);
  Segm segm372 = Segm("km 372-376", 150, km8, 5, 0, 4, QTime(8, 0), lin01);
  Segm segm53 = Segm("km 53-59", 1, km15, 9, 0, 0, QTime(11, 30), lin17);
  Segm segm75 = Segm("km 75-84", 50, km15, km14, 10, 0, 0, QTime(11, 30), lin17);
  Segm segm103 = Segm("km 103-112", 120, km14, km13, 10, 0, 4, QTime(11, 30), lin17);
  Segm segm113 = Segm("km 113-119", 200, km13, 5, 0, 4, QTime(11, 30), lin17);

  QList<Segm> sgs1;
  sgs1 << segm1;
  sgs1 << segm75;

  QList<Segm> sgs2;
  sgs2 << segm103 << segm113;

  QList<Segm> sgs3;
  sgs3 << segm372 << segm254;

  Swork swT("T", "techninė priežiūra");
  Swork swEr("ER", "einamasis remontas");
  Swork swA("A", "ataskaita");
  Swork swTm("TM", "techniniai mokymai");

  QList<Swork> sdws1;
  sdws1 << swA << swT;

  Teamtask tt1(tm828);
  QCOMPARE(tt1.getTeam().getName(), QString("828"));
  QCOMPARE(tt1.getSegms().count(), 0);
  QCOMPARE(tt1.getSworks().count(), 0);
  tt1.addSegm(segm53);
  QCOMPARE(tt1.getSegms().count(), 1);
  QCOMPARE(tt1.getSegms().first().getLinija().getId(), QString("17"));
  tt1.addSwork(swTm);
  QCOMPARE(tt1.getSworks().count(), 1);
  QCOMPARE(tt1.getSworks().last().getName(), QString("TM"));
  tt1.clearSworks();
  QCOMPARE(tt1.getSworks().count(), 0);
  tt1.setSworks(sdws1);
  QCOMPARE(tt1.getSworks().count(), 2);
  QCOMPARE(tt1.getSworks().last().getName(), QString("T"));
  QCOMPARE(tt1.getSworks().first().getName(), QString("A"));
  tt1.addSwork(swEr);
  QCOMPARE(tt1.getSworks().count(), 3);
  QCOMPARE(tt1.getSworks().last().getName(), QString("ER"));
  QCOMPARE(tt1.getSworks().first().getName(), QString("A"));

  Teamtask tt2(tm825, sgs1, sdws1);
  QCOMPARE(tt2.getTeam().getName(), QString("825"));
  QCOMPARE(tt2.getSegms().count(), 2);
  QCOMPARE(tt2.getSegms().last().getDivs().last().getNr(), 14);
  QCOMPARE(tt2.getSworks().count(), 2);
  QCOMPARE(tt2.getSworks().last().getName(), QString("T"));
  tt2.clearSegms();
  QCOMPARE(tt2.getSegms().count(), 0);
  tt2.setSegms(sgs2);
  QCOMPARE(tt2.getSegms().count(), 2);
  QCOMPARE(tt2.getSegms().last().getDivs().last().getNr(), 13);
  tt2.setSegms(sgs3);
  QCOMPARE(tt2.getSegms().count(), 2);
  QCOMPARE(tt2.getSegms().last().getDivs().last().getShortName(), QString("KM-2"));


  QCOMPARE(tt2.getTeam().getApars().count(), 1);
  Team tm = tt2.getTeam();
  tm.addApar(ap828);
  QCOMPARE(tm.getApars().count(), 2);
  QCOMPARE(tt2.getTeam().getApars().count(), 1);
  tt2.getTeam().addApar(ap828);
  QCOMPARE(tt2.getTeam().getApars().count(), 1);

  // jeigu getTeam grąžinti neconst pointerį arba neconst reference?

  QCOMPARE(tt2.getTeam().getApars().count(), 1);
  Team* tmp = tt2.getTeamP();
  tmp->addApar(ap828);
  QCOMPARE(tt2.getTeam().getApars().count(), 2);
  Team& tmr = tt2.getTeamR();
  tmr.addApar(ap8261);
  QCOMPARE(tt2.getTeam().getApars().count(), 3);

  // testing mergeSworks and mergeSegms
  Teamtask ttm(tm828);
  ttm.addSegm(segm254);
  ttm.addSegm(segm372);
  ttm.addSwork(swT);
  ttm.addSwork(swEr);

  QCOMPARE(ttm.getSegms().count(), 2);
  QCOMPARE(ttm.getSegms().first().getInd(), 20);
  QCOMPARE(ttm.getSegms().last().getInd(), 150);

  QList<Segm> sgm;
  sgm << segm372 << segm53;
  ttm.mergeSegms(sgm);
  QCOMPARE(ttm.getSegms().count(), 3);
  QCOMPARE(ttm.getSegms().first().getInd(), 20);
  QCOMPARE(ttm.getSegms().last().getInd(), 1);
  // 254-372-53
  QList<Segm> empt;
  ttm.mergeSegms(empt);
  QCOMPARE(ttm.getSegms().count(), 3);
  QCOMPARE(ttm.getSegms().first().getInd(), 20);
  QCOMPARE(ttm.getSegms()[1].getInd(), 150);
  QCOMPARE(ttm.getSegms().last().getInd(), 1);

  QCOMPARE(ttm.getSworks().count(), 2);
  QCOMPARE(ttm.getSworks().first().getName(), QString("T"));
  QCOMPARE(ttm.getSworks().last().getName(), QString("ER"));

  QList<Swork> emptsw;
  ttm.mergeSworks(emptsw);
  QCOMPARE(ttm.getSworks().count(), 2);
  QCOMPARE(ttm.getSworks().first().getName(), QString("T"));
  QCOMPARE(ttm.getSworks().last().getName(), QString("ER"));

  QList<Swork> sws;
  sws << swA << swTm;
  ttm.mergeSworks(sws);
  QCOMPARE(ttm.getSworks().count(), 4);
  QCOMPARE(ttm.getSworks()[0].getName(), QString("T"));
  QCOMPARE(ttm.getSworks()[1].getName(), QString("ER"));
  QCOMPARE(ttm.getSworks()[2].getName(), QString("A"));
  QCOMPARE(ttm.getSworks()[3].getName(), QString("TM"));

  Swork sextra("XX", "XXXX");
  QList<Swork> swsx;
  swsx << swA << sextra << swTm;
  ttm.mergeSworks(swsx);
  QCOMPARE(ttm.getSworks().count(), 5);
  QCOMPARE(ttm.getSworks()[0].getName(), QString("T"));
  QCOMPARE(ttm.getSworks()[1].getName(), QString("ER"));
  QCOMPARE(ttm.getSworks()[2].getName(), QString("A"));
  QCOMPARE(ttm.getSworks()[3].getName(), QString("TM"));
  QCOMPARE(ttm.getSworks()[4].getName(), QString("XX"));
}
*/
void TestObjects::testSegm()
{
    Div km8("KM-8", "Klaipėdos", 8, "Danė Kairienė");
    Div* km1 = new Div("KM-1", "Pavenčių", 1, "Alvydas Gelžinis");
    Div* km2 = new Div("KM-2", "Tryškių", 2, "Gintas Samuilevičius");
    Div km15("KM-15", "Viduklės", 15, "Remigijus Saunoris");
    Div* km14 = new Div("KM-14", "Batakių", 14, "Aurelijus Janušaits");
    Div km13("KM-13", "Tauragės", 13, "Gintaras Šlekys");

    Linija lin23("23", "Klaipėda - Pagėgiai");
    Linija* lin01 = new Linija("01", "Vilnius - Klaipėda");
    Linija lin17("17", "Radviliškis - Pagėgiai - valstybės siena");

    // one div as a list
    QList<Div*> m8;
    m8.append(&km8);
    Segm segm1("km 1-8", 0, m8, 8, 0, 5, QTime(8, 0), &lin23);
    QCOMPARE(segm1.getDivs().count(), 1);
    QCOMPARE(segm1.getDivs().last()->getName(), QString("Klaipėdos"));

    // two divs as a list
    QList<Div*> m1_2;
    m1_2.append(km1);
    m1_2.append(km2);
    Segm segm254("km 254-264", 20, m1_2, 11, 0, 0, QTime(11, 30), lin01);
    QCOMPARE(segm254.getDivs().count(), 2);
    QCOMPARE(segm254.getDivs().last()->getName(), QString("Tryškių"));

    // one div as a Div
    Segm segm372("km 372-376", 150, &km8, 5, 0, 4, QTime(8, 0), lin01);
    QCOMPARE(segm372.getDivs().count(), 1);
    QCOMPARE(segm372.getDivs().last()->getName(), QString("Klaipėdos"));

    // one div as a Div
    Segm segm53("km 53-59", 1, &km15, 9, 0, 0, QTime(11, 30), &lin17);
    QCOMPARE(segm53.getDivs().count(), 1);
    QCOMPARE(segm53.getDivs().last()->getName(), QString("Viduklės"));

    // two divs separately
    Segm segm75("km 75-84", 50, &km15, km14, 10, 0, 0, QTime(11, 30), &lin17);
    QCOMPARE(segm75.getDivs().count(), 2);
    QCOMPARE(segm75.getDivs().first()->getName(), QString("Viduklės"));
    QCOMPARE(segm75.getDivs().last()->getName(), QString("Batakių"));

    // two divs separately
    Segm segm103("km 103-112", 120, km14, &km13, 10, 0, 4, QTime(11, 30), &lin17);
    QCOMPARE(segm103.getDivs().count(), 2);
    QCOMPARE(segm103.getDivs().first()->getName(), QString("Batakių"));
    QCOMPARE(segm103.getDivs().last()->getName(), QString("Tauragės"));

    // one div as a Div
    Segm segm113("km 113-119", 200, &km13, 5, 0, 4, QTime(11, 30), &lin17);
    QCOMPARE(segm113.getDivs().count(), 1);
    QCOMPARE(segm113.getDivs().first()->getNr(), 13);

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

void TestObjects::testOper()
{
    Oper oper("400", "Evaldas Ilginis", 1);
    QCOMPARE(oper.getName(), QString("Evaldas Ilginis"));
    QCOMPARE(oper.getId(), QString("400"));
    QCOMPARE(oper.getLevel(), 1);
    QCOMPARE(oper.getShortName(), QString("E.Ilginis"));

    Oper operA("401", "Antanas Eduardas Mykolas Rutskis", 3);
    QCOMPARE(operA.getShortName(), QString("A.E.M.Rutskis"));

    Oper operB("402", "Bronius", 3);
    QCOMPARE(operB.getShortName(), QString("Bronius"));

    Oper oper1_1("405", "Evaldas Ilginis", 1);
    Oper oper1_2("407", "Juozas Janonis", 1);
    Oper* oper2_1 = new Oper("401", "Andrius Jonauskas", 2);
    Oper oper2_2("402", "Saulius Adakauskas", 2);
    Oper oper2_2x("402", "Saulius Adakauskas", 3);
    Oper oper1_2x("407", "Mykolas Mykolaitis", 1);

    QCOMPARE(operB.getId(), QString("402"));
    QCOMPARE(operB.getName(), QString("Bronius"));
    QCOMPARE(operB.getShortName(), QString("Bronius"));

    QCOMPARE(oper1_2 == oper1_2x, true);
    QCOMPARE(oper1_1 == oper1_2, false);
    QCOMPARE(oper1_1 <= oper1_2, true);
    QCOMPARE(oper1_1 < oper1_2, true);
    QCOMPARE(oper1_2 < *oper2_1, true);
    QCOMPARE(oper2_2 > *oper2_1, true);
    QCOMPARE(oper2_2 >= oper1_1, true);
    QCOMPARE(oper1_2 != oper1_2x, false);
    QCOMPARE(oper2_2 < oper2_2x, true);
}

void TestObjects::testApar()
{
    Apar apar("800", "RDM-23", 1);
    QCOMPARE(apar.getModel(), QString("RDM-23"));
    QCOMPARE(apar.getId(), QString("800"));
    QCOMPARE(apar.getLevel(), 1);

    Apar apar11("805", "RDM", 1);
    Apar apar12("807", "RDM", 1);
    Apar* apar21 = new Apar("801", "RDM", 2);
    Apar apar22("802", "RDM", 2);
    Apar apar22x("802", "RDM", 3);
    Apar apar12x("807", "RDM", 1);

    QCOMPARE(apar22.getId(), QString("802"));
    QCOMPARE(apar21->getId(), QString("801"));
    QCOMPARE(apar22x.getId(), QString("802"));

    QCOMPARE(apar12 == apar12x, true);
    QCOMPARE(apar11 == apar12, false);
    QCOMPARE(apar11 <= apar12, true);
    QCOMPARE(apar11 < apar12, true);
    QCOMPARE(apar12 < *apar21, true);
    QCOMPARE(apar22 > *apar21, true);
    QCOMPARE(apar22 >= apar11, true);
    QCOMPARE(apar12 != apar12x, false);
    QCOMPARE(apar22 < apar22x, true);
}

/*
void TestObjects::testTeam()
{
  Apar ap828("828", "RDM-23", 1);
  Apar ap826("826", "RDM-23", 2);
  Apar ap8261("826", "RDM-23", 2);
  Apar ap825("825", "RDM-23", 1);
  Apar ap829("829", "RDM-23", 1);

  Team team("My first team");

  // adding apar - 828
  team.addApar(ap828);
  QCOMPARE(team.getApars().count(), 1);
  QCOMPARE(team.getApars().last().getId(), QString("828"));

  // adding apar - 828, 826
  team.addApar(ap826);
  QCOMPARE(team.getApars().count(), 2);
  QCOMPARE(team.getApars().last().getId(), QString("826"));

  // adding apar - 828, 826, 829
  team.addApar(ap829);
  QCOMPARE(team.getApars().count(), 3);
  QCOMPARE(team.getApars().last().getId(), QString("829"));

  // adding apar - 828, 826, 829, 825
  team.addApar(ap825);
  QCOMPARE(team.getApars().count(), 4);
  QCOMPARE(team.getApars().last().getId(), QString("825"));

  const Apar ap = team.getApar(2);
  QCOMPARE(ap.getId(), QString("829"));

  // adding existing apar - 828, 826, 829, 825
  team.addApar(ap8261);
  QCOMPARE(team.getApars().count(), 4);
  QCOMPARE(team.getApars().last().getId(), QString("825"));

  // removing apar by index - 828, 829, 825
  team.removeApar(1);
  QCOMPARE(team.getApars().count(), 3);
  QCOMPARE(team.getApars().last().getId(), QString("825"));

  // removing apar by id - 828, 825
  team.removeApar("829");
  QCOMPARE(team.getApars().count(), 2);
  QCOMPARE(team.getApars().last().getId(), QString("825"));

  // removing apar by non-existing id - 828, 825
  team.removeApar("829");
  QCOMPARE(team.getApars().count(), 2);
  QCOMPARE(team.getApars().last().getId(), QString("825"));

  // removing apar by too big index - 828, 825
  team.removeApar(3);
  QCOMPARE(team.getApars().count(), 2);
  QCOMPARE(team.getApars().last().getId(), QString("825"));

  // removing apar by negative index - 828, 825
  team.removeApar(-1);
  QCOMPARE(team.getApars().count(), 2);
  QCOMPARE(team.getApars().last().getId(), QString("825"));


  Oper op421("421", "Arūnas Mikužis", 1);
  Oper op435("435", "Eduardas Antanas Rutskis", 3);
  Oper op402("402", "Juozas Vaitkus", 2);
  Oper op427("427", "Audrius Lubys", 1);
  Oper op425("425", "Andrius Adakauskas", 1);
  Oper op4251("425", "Andrius Adakauskas", 1);
  Oper op428("428", "Bronius Mikužis", 2);

  // adding oper - 427
  team.addOper(op427);
  QCOMPARE(team.getOpers().count(), 1);
  QCOMPARE(team.getOpers().last().getId(), QString("427"));

  // adding oper - 427, 425
  team.addOper(op425);
  QCOMPARE(team.getOpers().count(), 2);
  QCOMPARE(team.getOpers().last().getId(), QString("425"));

  // adding oper - 427, 425, 428
  team.addOper(op428);
  QCOMPARE(team.getOpers().count(), 3);
  QCOMPARE(team.getOpers().last().getId(), QString("428"));

  // adding oper - 427, 425, 428, 402
  team.addOper(op402);
  QCOMPARE(team.getOpers().count(), 4);
  QCOMPARE(team.getOpers().last().getId(), QString("402"));

  //const Oper* opminus = team.getOper(-2);
  const Oper opok = team.getOper(2);
  QCOMPARE(opok.getId(), QString("428"));
  //const Oper* opover = team.getOper(12);

  // adding oper already in list - 427, 425, 428, 402
  team.addOper(op4251);
  QCOMPARE(team.getOpers().count(), 4);
  QCOMPARE(team.getOpers().last().getId(), QString("402"));

  // removing oper by index - 427, 428, 402
  team.removeOper(1);
  QCOMPARE(team.getOpers().count(), 3);
  QCOMPARE(team.getOpers()[1].getId(), QString("428"));
  QCOMPARE(team.getOpers().last().getId(), QString("402"));

  // removing oper by id - 427, 402
  team.removeOper("428");
  QCOMPARE(team.getOpers().count(), 2);
  QCOMPARE(team.getOpers()[1].getId(), QString("402"));
  QCOMPARE(team.getOpers().last().getId(), QString("402"));

  // removing oper by non-existing id - 427, 402
  team.removeOper("428");
  QCOMPARE(team.getOpers().count(), 2);
  QCOMPARE(team.getOpers()[1].getId(), QString("402"));
  QCOMPARE(team.getOpers().last().getId(), QString("402"));

  // removing oper by inexisting index - 427, 402
  team.removeOper(3);
  QCOMPARE(team.getOpers().count(), 2);
  QCOMPARE(team.getOpers()[1].getId(), QString("402"));
  QCOMPARE(team.getOpers().last().getId(), QString("402"));

  // removing oper by negative index - 427, 402
  team.removeOper(-1);
  QCOMPARE(team.getOpers().count(), 2);
  QCOMPARE(team.getOpers()[1].getId(), QString("402"));
  QCOMPARE(team.getOpers().last().getId(), QString("402"));

  // team: My first team
  // op427, op402
  // ap828, ap825

  Team teamEq("My first team");
  Team team3("My second team");

  // create equal team
  QList<Apar> apEq;
  apEq << ap825 << ap828;
  QList<Oper> opEq;
  opEq << op427 << op402;
  teamEq.setApars(apEq);
  teamEq.setOpers(opEq);
  // and compare
  QCOMPARE(team == teamEq, true);

  // remove oper and compare
  teamEq.removeOper(0);
  QCOMPARE(team == teamEq, false);

  // restore to equal and compare for control
  teamEq.setOpers(opEq);
  QCOMPARE(team == teamEq, true);

  // remove apar and compare
  teamEq.removeApar("828");
  QCOMPARE(team == teamEq, false);

  // restore to equal and compare for control
  teamEq.setApars(apEq);
  QCOMPARE(team == teamEq, true);

  // create yet another unequal case (different apar)
  QList<Apar> apUneq;
  apUneq << ap825 << ap829;
  teamEq.setApars(apUneq);
  QCOMPARE(team == teamEq, false);

  // restore to equal and compare for control
  teamEq.setApars(apEq);
  QCOMPARE(team == teamEq, true);

  // create yet another unequal case (different apar count)
  QList<Apar> apUneq1;
  apUneq1 << ap825 << ap828 << ap826;
  teamEq.setApars(apUneq1);
  QCOMPARE(team == teamEq, false);

  QCOMPARE(team == team3, false);
}
*/


QTEST_MAIN(TestObjects)
#include "testobjects.moc"
