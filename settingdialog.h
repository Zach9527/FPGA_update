#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>

namespace Ui {
class settingDialog;
}

class settingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit settingDialog(QWidget *parent = 0);
    ~settingDialog();

    QWidget *fw;
    void init();
private slots:
    void on_buttonBox_accepted();

private:
    Ui::settingDialog *ui;
};

#endif // SETTINGDIALOG_H
