#ifndef VERSIONDIALOG_H
#define VERSIONDIALOG_H

#include <QDialog>

namespace Ui {
class versionDialog;
}

class versionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit versionDialog(QWidget *parent = 0);
    ~versionDialog();
    QWidget *fw;

    void init(void);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::versionDialog *ui;
};

#endif // VERSIONDIALOG_H
