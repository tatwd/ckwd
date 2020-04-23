#ifndef STANDALONEDLG_H
#define STANDALONEDLG_H

#include <QDialog>

namespace Ui {
class StandAloneDlg;
}

class StandAloneDlg : public QDialog
{
    Q_OBJECT

public:
    explicit StandAloneDlg(QWidget *parent = 0);
    ~StandAloneDlg();

private:
    Ui::StandAloneDlg *ui;
};

#endif // STANDALONEDLG_H
