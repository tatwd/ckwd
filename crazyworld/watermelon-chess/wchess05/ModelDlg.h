#ifndef MODELDLG_H
#define MODELDLG_H

#include <QDialog>

namespace Ui {
class ModelDlg;
}

class ModelDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ModelDlg(QWidget *parent = 0);
    ~ModelDlg();

private slots:
    void on_standAloneButton_clicked();

private:
    Ui::ModelDlg *ui;
};

#endif // MODELDLG_H
