#include "teamworkeditdialog.h"
#include "ui_teamworkeditdialog.h"

TeamWorkEditDialog::TeamWorkEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeamWorkEditDialog)
{
    ui->setupUi(this);
}

TeamWorkEditDialog::~TeamWorkEditDialog()
{
    delete ui;
}
