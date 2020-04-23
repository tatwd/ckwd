#include "StandAloneDlg.h"
#include "ui_StandAloneDlg.h"

StandAloneDlg::StandAloneDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StandAloneDlg)
{
    ui->setupUi(this);
}

StandAloneDlg::~StandAloneDlg()
{
    delete ui;
}
