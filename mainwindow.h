#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QDate>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int linCount, teamCount, dayCount;
    QDate startDate;
    int btnWidth, btnHeight;
    QWidget* cWidget;
};

#endif // MAINWINDOW_H
