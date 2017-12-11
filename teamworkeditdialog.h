#ifndef TEAMWORKEDITDIALOG_H
#define TEAMWORKEDITDIALOG_H

#include <QDialog>

namespace Ui {
class TeamWorkEditDialog;
}

class TeamWorkEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TeamWorkEditDialog(QWidget *parent = 0);
    ~TeamWorkEditDialog();

private:
    Ui::TeamWorkEditDialog *ui;
};

#endif // TEAMWORKEDITDIALOG_H
