#include "settingdialog.h"
#include "ui_settingdialog.h"
#include "common.h"
#include "mainwindow.h"
#include "qidlethread.h"
#include <QMessageBox>
#include <QRegExpValidator>
settingDialog::settingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settingDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowCloseButtonHint|Qt::Dialog);
    fw = parent;
}

settingDialog::~settingDialog()
{
    delete ui;
}


void settingDialog::init(void)
{
    MainWindow *mw = (MainWindow *)fw;
    QIdleThread *idleThread = (QIdleThread *)(mw->idleThread);

    QRegExp regx("[0-9]+$");
    QValidator *validator = new QRegExpValidator(regx, ui->timeOutLineEdit);

    ui->timeOutLineEdit->setValidator(validator);
    ui->timeOutLineEdit->setText(QString::number(idleThread->semTimeOut));
}

void settingDialog::on_buttonBox_accepted()
{
    QString str;
    MainWindow *mw = (MainWindow *)fw;
    QIdleThread *idleThread = (QIdleThread *)(mw->idleThread);

    idleThread->semTimeOut = ui->timeOutLineEdit->text().toInt();

    str = C_STR("超时时间设置为：") + QString::number(idleThread->semTimeOut);

    if(idleThread->semTimeOut > 1000)
    {
        QMessageBox::warning(NULL, \
                     C_STR("该功能仅用于联试测试"), \
                     C_STR("超时时间设置过长，在关闭软件时，可能触发后台任务资源不能释放的软件错误"));
    }

    mw->sig_showMsgStatusBr(str, 5000);
}
