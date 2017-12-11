#include "mainwindow.h"
#include <QWidget>
#include <QTableWidget>
#include "teamtasktablewitem.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QDate>
#include <QLabel>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    cWidget(new QWidget)
{
    ui->setupUi(this);
    linCount = 3;
    teamCount = 4;
    dayCount = 10;
    startDate = QDate(2017, 11, 1);
    btnWidth = 30;
    btnHeight = 20;
    setCentralWidget(cWidget);
    QVBoxLayout* graphLayout = new QVBoxLayout();
    cWidget->setLayout(graphLayout);
    for (int lin = 0; lin < linCount; lin++)
    {
        QLabel* label = new QLabel(QString("Linija: %1").arg(lin));
        QTableWidget* tableWidget = new QTableWidget(teamCount, dayCount);
        QVBoxLayout* lineLayout = new QVBoxLayout();
        for (int t = 0; t < teamCount; t++)
        {
            for (QDate d = startDate; d < startDate.addDays(dayCount); d=d.addDays(1))
            {
                TeamtaskTableWItem* tableItem = new TeamtaskTableWItem(Indx(QString::number(t), QString::number(lin), d));
                tableWidget->setItem(t, startDate.daysTo(d), tableItem);

                qDebug() << tableItem->indx();
            }
        }
        lineLayout->addWidget(label);
        lineLayout->addWidget(tableWidget);
        graphLayout->addLayout(lineLayout);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
