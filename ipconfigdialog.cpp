#include "ipconfigdialog.h"
#include "ui_ipconfigdialog.h"
#include "qidlethread.h"
#include "mainwindow.h"
#include "common.h"
#include <QRegExpValidator>
#include <Qt>
ipconfigdialog::ipconfigdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ipconfigdialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowCloseButtonHint|Qt::Dialog);
    fw = parent;
}

ipconfigdialog::~ipconfigdialog()
{
    delete ui;
}
void ipconfigdialog::init(void)
{
    MainWindow *mw = (MainWindow *)fw;
    mw->paraGetSem.tryLock();
    mw->paraSetSem.tryLock();
    //QIdleThread *idleThread = (QIdleThread *)(mw->idleThread);
    ipSetLineEdit_ = ui->ipSetLineEdit;
    portSetLineEdit_ = ui->portSetLineEdit;
    macLineEdit_ = ui->macLineEdit;
    ipSetLineEdit_->setText(C_STR("192.168.1.80"));
    portSetLineEdit_->setText(C_STR("888"));
    uint8_t macAddr[6] = { 0xAD, 0x3E, 0x49, 0x12, 0x34, 0x56};
    macLineEdit_->setMac(macAddr);
}

void ipconfigdialog::on_paraSetButton_clicked()
{
    MainWindow *mw = (MainWindow *)fw;
    mw->paraSetSem.unlock();
}

void ipconfigdialog::on_paraGetButton_clicked()
{
    MainWindow *mw = (MainWindow *)fw;
    mw->paraGetSem.unlock();
}
