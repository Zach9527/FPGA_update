#ifndef IPCONFIGDIALOG_H
#define IPCONFIGDIALOG_H

#include <QDialog>
#include "qiplineedit.h"
#include "qmaclineedit.h"
namespace Ui {
class ipconfigdialog;
}

class ipconfigdialog : public QDialog
{
    Q_OBJECT

public:
    explicit ipconfigdialog(QWidget *parent = 0);
    ~ipconfigdialog();

    QWidget *fw;
    void init();
public:
    QIpLineEdit *ipSetLineEdit_;
    QLineEdit *portSetLineEdit_;
    QMacLineEdit *macLineEdit_;
private slots:
    void on_paraSetButton_clicked();

    void on_paraGetButton_clicked();

private:
    Ui::ipconfigdialog *ui;
};

#endif // IPCONFIGDIALOG_H
