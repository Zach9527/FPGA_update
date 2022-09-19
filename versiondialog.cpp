#include "versiondialog.h"
#include "ui_versiondialog.h"
#include "MainWindow.h"

versionDialog::versionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::versionDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowCloseButtonHint|Qt::Dialog);
    fw = parent;
}

versionDialog::~versionDialog()
{
    delete ui;
}

void versionDialog::init(void)
{
    MainWindow *mw = (MainWindow *)fw;

    ui->versionLable->setText(mw->ver);
}

void versionDialog::on_buttonBox_accepted()
{

}
