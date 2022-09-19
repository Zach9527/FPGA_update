#include "mainwindow.h"
#include "qiplineedit.h"
#include "qmaclineedit.h"
#include "qidlethread.h"
#include "ui_mainwindow.h"
#include "qtcp.h"
#include "common.h"
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QDockWidget>
#include <QString>
#include <QMessageBox>
#include <QFileDialog>
#include <QMenuBar>
#include <QMenu>
#include <QRegExpValidator>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ver = C_STR("V1.00");

    this->setWindowFlags(Qt::WindowCloseButtonHint|Qt::Dialog);
    setting = new settingDialog(this);
    version = new versionDialog(this);
    ipconfig = new ipconfigdialog(this);
    //菜单栏
    QMenuBar *menuBr = menuBar();
    setMenuBar(menuBr);
    //菜单栏 选项
    QMenu *pOption = menuBr->addMenu(C_STR("选项") );//QString::fromLocal8Bit("选项")
    QAction *pSetting = pOption->addAction(C_STR("软件设置") );
    QAction *pIpConfig = pOption->addAction(C_STR("服务器设置") );
    // 绑定动作
    connect(pSetting, &QAction::triggered, this, &MainWindow::menuSetting );
    connect(pIpConfig, &QAction::triggered, this, &MainWindow::menuIpCongfig );
    //菜单栏 关于
    QMenu *pAbout = menuBr->addMenu(C_STR("关于") );//QString::fromLocal8Bit("关于")
    QAction *pVersion = pAbout->addAction(C_STR("软件版本") );
    // 绑定动作
    connect(pVersion, &QAction::triggered, this, &MainWindow::menuVersion );

    idleThread = nullptr;
    tcpH = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_showMsgStatusBr(QString text, int timeout)
{
    statusBr->showMessage(text, timeout);
}
void MainWindow::on_showFpgaMsgBr(ICD_STATE_PARA_RSP* text)
{
    QString msg;
    textBrowser->clear();
    msg = QString("CPLD编译时间:%1%2.%3.%4.%5.%6").arg(text->yy_h).arg(text->yy_l).arg(text->mm).arg(text->dd).arg(text->hh).arg(text->ss);
    textBrowser->insertPlainText(msg);
    textBrowser->moveCursor(QTextCursor::End);
    textBrowser->append(QString(""));
    msg = "FPGA1状态寄存器，";
    msg.append(getFpgaState(text->fpga1));
    textBrowser->insertPlainText(msg);
    textBrowser->moveCursor(QTextCursor::End);
    textBrowser->append(QString(""));
    msg = "FPGA2状态寄存器，";
    msg.append(getFpgaState(text->fpga2));
    textBrowser->insertPlainText(msg);
    textBrowser->moveCursor(QTextCursor::End);
    textBrowser->append(QString(""));
    msg = "FPGA3状态寄存器，";
    msg.append(getFpgaState(text->fpga3));
    textBrowser->insertPlainText(msg);
    textBrowser->moveCursor(QTextCursor::End);
    textBrowser->append(QString(""));
    msg = getpowerState(&text->ctrl_h);
    textBrowser->insertPlainText(msg);
    textBrowser->moveCursor(QTextCursor::End);
    textBrowser->append(QString(""));
    msg = getTemp(&text->LTM4630_0_h);
    textBrowser->insertPlainText(msg);
    textBrowser->moveCursor(QTextCursor::End);
    textBrowser->append(QString(""));
    msg = getVol(&text->FPGA1_1V0_h);
    textBrowser->insertPlainText(msg);
    textBrowser->moveCursor(QTextCursor::End);
    textBrowser->append(QString(""));
    msg = getclkState(&text->clkChoose);
    textBrowser->insertPlainText(msg);
    textBrowser->moveCursor(QTextCursor::End);
    textBrowser->append(QString(""));
}
void MainWindow::init(void)
{
    QSizePolicy retain;

    ipEdit = ui->ipLineEdit;
    portEdit = ui->portLineEdit;
    writePathEdit = ui->writeLineEdit;
    readPathEdit = ui->readLineEdit;
    cnctButton = ui->connectButton;
    writePathButton = ui->writePathButton;
    readPathButton = ui->readPathButton;
    writButton = ui->writeButton;
    readButton = ui->readButton;
    earseButton = ui->earseButton;
    stateButton = ui->stateButton;
    writeFileEdit = ui->writeLineEdit;
    readFileEdit = ui->readLineEdit;
    textBrowser = ui->textBrowser;

    retain = ui->pushButton_7->sizePolicy();
    retain.setRetainSizeWhenHidden(true);
    ui->pushButton_7->setSizePolicy(retain);
    ui->pushButton_7->setHidden(true);

    statusBr = statusBar();
    QObject::connect(this, SIGNAL(sig_showMsgStatusBr(QString,int)), this, SLOT(on_showMsgStatusBr(QString,int)));
    QObject::connect(this, SIGNAL(sig_showFpgaMsgBr(ICD_STATE_PARA_RSP*)), this, SLOT(on_showFpgaMsgBr(ICD_STATE_PARA_RSP*)));
    //初始化按键信号量默认为没有按下状态
    prgmUpgradeSem.tryLock();
    prgmReadSem.tryLock();
    prgmEarseSem.tryLock();
    paraGetSem.tryLock();
    paraSetSem.tryLock();
    stateGetSem.tryLock();


    tcpH = new QTcp(this);
    if(nullptr == tcpH)
    {
        QMessageBox::critical(NULL, \
           C_STR("软件错误"), \
           C_STR("TCP客户端初始化失败"));
        return;
    }
    ((QTcp*)tcpH)->init();

    idleThread = new QIdleThread(this);
    if(nullptr == idleThread)
    {
        QMessageBox::critical(NULL, \
           C_STR("软件错误"), \
           C_STR("后台进程创建失败"));
        return;
    }
    ((QIdleThread*)idleThread)->exitSem.tryLock();
    ((QIdleThread*)idleThread)->tcpRecvSem.tryLock();
    ((QIdleThread*)idleThread)->start();

    QRegExp regx("[0-9]+$");
    QValidator *validator = new QRegExpValidator(regx, portEdit);
    portEdit->setValidator(validator);

    ipEdit->setText(C_STR("192.168.1.78"));
    portEdit->setText(C_STR("888"));
    ui->radioButtonFpga1->setChecked(true);
    statusBr->showMessage(C_STR("软件初始化完成 "), 5000);
}

int32_t MainWindow::getFpgaCs(void)
{
    if(true == ui->radioButtonFpga1->isChecked() )
    {
        return 1;
    }
    if(true == ui->radioButtonFpga2->isChecked() )
    {
        return 2;
    }
    if(true == ui->radioButtonFpga3->isChecked() )
    {
        return 3;
    }

    return -1;
}
QString MainWindow::getFpgaState(uint8_t state)
{
    QString msg1,msg2;
    msg1 = (state&0x01)?"加载完成,":"未加载完成,";
    msg2 = (state&0x10)?"复位完成":"复位中";
    msg1.append(msg2);
    return msg1;
}
QString MainWindow::getpowerState(uint8_t* state)
{
    QString msg1,msg2;
    msg1 = (*state & 0x01)?"3.3V启动输出\n":"3.3V关闭输出\n";
    msg2 = (*state & 0x02)?"ADC_3.3V启动输出\n":"ADC_3.3V关闭输出\n";
    msg1.append(msg2);
    msg2 = (*state & 0x04)?"ADC_1.8V启动输出\n":"ADC_1.8V关闭输出\n";
    msg1.append(msg2);
    msg2 = (*state & 0x08)?"1.5V启动输出\n":"1.5V关闭输出\n";
    msg1.append(msg2);
    msg2 = (*state & 0x10)?"3.7V启动输出\n":"3.7V关闭输出\n";
    msg1.append(msg2);
    state++;
    msg2 = (*state & 0x01)?"FPGA1_1.0V启动输出\n":"FPGA1_1.0V关闭输出\n";
    msg1.append(msg2);
    msg2 = (*state & 0x02)?"FPGA1_MGTAVCC_1.0V启动输出\n":"FPGA1_MGTAVCC_1.0V关闭输出\n";
    msg1.append(msg2);
    msg2 = (*state & 0x04)?"FPGA2&3_1.0V启动输出\n":"FPGA2&3_1.0V关闭输出\n";
    msg1.append(msg2);
    msg2 = (*state & 0x08)?"FPGA2&3_MGTAVCC_1.0V启动输出\n":"FPGA2&3_MGTAVCC_1.0V关闭输出\n";
    msg1.append(msg2);
    msg2 = (*state & 0x10)?"FPGA1_MGTAVTT_1.2V启动输出\n":"FPGA1_MGTAVTT_1.2V关闭输出\n";
    msg1.append(msg2);
    msg2 = (*state & 0x20)?"FPGA1_1.8V启动输出\n":"FPGA1_1.8V关闭输出\n";
    msg1.append(msg2);
    msg2 = (*state & 0x40)?"FPGA2&3_MGTAVTT_1.2V启动输出\n":"FPGA2&3_MGTAVTT_1.2V关闭输出\n";
    msg1.append(msg2);
    msg2 = (*state & 0x80)?"1.8V启动输出\n":"1.8V关闭输出\n";
    msg1.append(msg2);

    state++;
    msg2 = (*state & 0x01)?"3.3V输出正常\n":"3.3V输出错误\n";
    msg1.append(msg2);
    msg2 = (*state & 0x02)?"ADC_3.3V输出正常\n":"ADC_3.3V输出错误\n";
    msg1.append(msg2);
    msg2 = (*state & 0x04)?"ADC_1.8V输出正常\n":"ADC_1.8V输出错误\n";
    msg1.append(msg2);
    msg2 = (*state & 0x08)?"1.5V输出正常\n":"1.5V输出错误\n";
    msg1.append(msg2);
    msg2 = (*state & 0x10)?"3.7V输出正常\n":"3.7V输出错误\n";
    msg1.append(msg2);
    msg2 = (*state & 0x80)?"所有电源输出正常\n":"所有电源输出错误\n";
    msg1.append(msg2);
    state++;
    msg2 = (*state & 0x01)?"FPGA1_1.0V输出正常\n":"FPGA1_1.0V输出错误\n";
    msg1.append(msg2);
    msg2 = (*state & 0x02)?"FPGA1_MGTAVCC_1.0V输出正常\n":"FPGA1_MGTAVCC_1.0V输出错误\n";
    msg1.append(msg2);
    msg2 = (*state & 0x04)?"FPGA2&3_1.0V输出正常\n":"FPGA2&3_1.0V输出错误\n";
    msg1.append(msg2);
    msg2 = (*state & 0x08)?"FPGA2&3_MGTAVCC_1.0V输出正常\n":"FPGA2&3_MGTAVCC_1.0V输出错误\n";
    msg1.append(msg2);
    msg2 = (*state & 0x10)?"FPGA1_MGTAVTT_1.2V输出正常\n":"FPGA1_MGTAVTT_1.2V输出错误\n";
    msg1.append(msg2);
    msg2 = (*state & 0x20)?"FPGA1_1.8V输出正常\n":"FPGA1_1.8V输出错误\n";
    msg1.append(msg2);
    msg2 = (*state & 0x40)?"FPGA2&3_MGTAVTT_1.2V输出正常\n":"FPGA2&3_MGTAVTT_1.2V输出错误\n";
    msg1.append(msg2);
    msg2 = (*state & 0x80)?"1.8V输出正常":"1.8V关闭输出";
    msg1.append(msg2);
    return msg1;
}


QString MainWindow::getTemp(uint8_t* tmp)
{
#define LTM4630_0 0
#define LTM4630_1 2
#define LTM4630_2 4
#define TOP       6
#define BOTTOM    8
#define FPGA1     10
#define FPGA2     12
#define FPGA3     14
    int16_t tmep;
    float real_tep;
    int i = 0;
    QString msg1,msg2;
    for(i; i < 16; i += 2)
    {
        tmep = (tmp[i]<<8)|(tmp[i+1]&0xff);
        if(i < 6)
        {
            real_tep = 325 - ((tmep*305.18)/1000000)*500;
        }
        else
        {
            if(tmep&0x1000)
            {
                tmep = (tmep^0x1fff)+1;//取补码
                real_tep = 0-tmep*0.0625;
            }
            else
            {
                real_tep = tmep*0.0625;
            }
        }
        switch (i)
        {
        case LTM4630_0:
                msg1 = QString("FPGA1内核电压电源温度:%1\n").arg(real_tep);
            break;
        case LTM4630_1:
                msg2 = QString("FPGA2内核电压电源温度:%1\n").arg(real_tep);
                msg1.append(msg2);
            break;
        case LTM4630_2:
                msg2 = QString("FPGA3内核电压电源温度:%1\n").arg(real_tep);
                msg1.append(msg2);
            break;
        case TOP:
                msg2 = QString("正面温度:%1\n").arg(real_tep);
                msg1.append(msg2);
            break;
        case BOTTOM:
                msg2 = QString("背面温度:%1\n").arg(real_tep);
                msg1.append(msg2);
            break;
        case FPGA1:
                msg2 = QString("FPGA1附近温度:%1\n").arg(real_tep);
                msg1.append(msg2);
            break;
        case FPGA2:
                msg2 = QString("FPGA2附近温度:%1\n").arg(real_tep);
                msg1.append(msg2);
            break;
        case FPGA3:
                msg2 = QString("FPGA3附近温度:%1").arg(real_tep);
                msg1.append(msg2);
            break;
        default:
            break;
        }

    }
    return msg1;
}
QString MainWindow::getVol(uint8_t* vol)
{
#define FPGA1_1V0              0
#define FPGA2_3_1V0            2
#define FPGA1_1V0_MGTA         4
#define FPGA2_3_1V0_MGTA       6
#define FPGA1_1V2_MGTA         8
#define FPGA2_3_1V2_MGTA       10
#define FPGA1_1V8              12
#define _1V8                   14
    int16_t voltage;
    float real_vol;
    int i = 0;
    QString msg1,msg2;
    for(i; i < 16; i += 2)
    {
        voltage = (vol[i]<<8)|(vol[i+1]&0xff);
        real_vol = (voltage*305.18)/1000000;
        switch (i)
        {
        case FPGA1_1V0:
                msg1 = QString("+1V0_FPGA1电压:%1\n").arg(real_vol);
            break;
        case FPGA2_3_1V0:
                msg2 = QString("+1V0_FPGA2_3电压:%1\n").arg(real_vol);
                msg1.append(msg2);
            break;
        case FPGA1_1V0_MGTA:
                msg2 = QString("+1V0_FPGA1_MGTAVCC电压:%1\n").arg(real_vol);
                msg1.append(msg2);
            break;
        case FPGA2_3_1V0_MGTA:
                msg2 = QString("+1V0_FPGA2_3_MGTAVCC电压:%1\n").arg(real_vol);
                msg1.append(msg2);
            break;
        case FPGA1_1V2_MGTA:
                msg2 = QString("+1V2_FPGA1_MGTAVTT电压:%1\n").arg(real_vol);
                msg1.append(msg2);
            break;
        case FPGA2_3_1V2_MGTA:
                msg2 = QString("+1V2_FPGA2_3_MGTAVTT电压:%1\n").arg(real_vol);
                msg1.append(msg2);
            break;
        case FPGA1_1V8:
                msg2 = QString("+1V8_FPGA1电压:%1\n").arg(real_vol);
                msg1.append(msg2);
            break;
        case _1V8:
                msg2 = QString("+1V8电压:%1").arg(real_vol);
                msg1.append(msg2);
            break;
        default:
            break;
        }

    }
    return msg1;
}
QString MainWindow::getclkState(uint8_t* clk)
{
    QString msg1,msg2;
    msg1 = (*clk&0x01)?"采样参考时钟为内时钟\n":"采样参考时钟为外时钟\n";
    clk++;
    msg2 = (*clk&0x01)?"时钟配置完成\n":"时钟配置过程中\n";
    msg1.append(msg2);
    msg2 = (*clk&0x10)?"PLL1时钟锁定\n":"PLL1时钟失锁\n";
    msg1.append(msg2);
    msg2 = (*clk&0x20)?"PLL2时钟锁定\n":"PLL2时钟失锁\n";
    msg1.append(msg2);
    clk++;
    msg2 = (*clk&0x01)?"外部进行上电控制\n":"外部控制掉电\n";
    msg1.append(msg2);
    msg2 = (*clk&0x10)?"电源上电正常":"电源上电异常";
    msg1.append(msg2);
    return msg1;
}

void MainWindow::menuSetting(void)
{
    setting->init();
    setting->exec();
}

void MainWindow::menuIpCongfig(void)
{
    ipconfig->init();
    ipconfig->exec();
}
void MainWindow::menuVersion(void)
{
    version->init();
    version->exec();
}
void MainWindow::enableButton(void)
{
    ui->writeButton->setEnabled(true);
    ui->readButton->setEnabled(true);
    ui->earseButton->setEnabled(true);
    ui->stateButton->setEnabled(true);
}
void MainWindow::on_connectButton_clicked()
{
    QString ip;
    QString portQstr;
    int tmp;
    qint16 port;
    QTcp *tcpHandle = (QTcp *)tcpH;

    if(false == ui->ipLineEdit->getText(ip) )
    {
        QMessageBox::critical(NULL, \
           C_STR("输入信息错误"), \
           C_STR("IP设置错误"));
        return;
    }

    portQstr = ui->portLineEdit->text();
    tmp = portQstr.toInt();
    if((0 == tmp) || (tmp >= 65535) )
    {
        QMessageBox::critical(NULL, \
           C_STR("输入信息错误"), \
           C_STR("端口设置错误"));
        return;
    }
    port = tmp;

    tcpHandle->cnct(ip, port);
}

void MainWindow::on_writePathButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, \
                        tr("选择bin/bit文件"), "./", \
                        tr("bin(*.bin)"));

    if(fileName.length() > 0)
    {
        ui->writeLineEdit->setText(fileName);
    }
}

void MainWindow::on_readPathButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, \
                        tr("选择bin/bit文件"), "./", \
                        tr("bin(*.bin)"));

    if(fileName.length() > 0)
    {
        ui->readLineEdit->setText(fileName);
    }
}

void MainWindow::on_writeButton_clicked()
{
    //QTcp *tcpHandle = (QTcp *)tcpH;

    //tcpHandle->sendDat((uint8_t *)"hello world", 11);
    ui->readButton->setDisabled(true);
    ui->writeButton->setDisabled(true);
    ui->earseButton->setDisabled(true);
    ui->stateButton->setDisabled(true);
    prgmUpgradeSem.unlock();
}

void MainWindow::on_readButton_clicked()
{
    ui->readButton->setDisabled(true);
    ui->writeButton->setDisabled(true);
    ui->earseButton->setDisabled(true);
    ui->stateButton->setDisabled(true);
    prgmReadSem.unlock();
}

void MainWindow::on_earseButton_clicked()
{
    ui->readButton->setDisabled(true);
    ui->writeButton->setDisabled(true);
    ui->earseButton->setDisabled(true);
    ui->stateButton->setDisabled(true);
    prgmEarseSem.unlock();
}

void MainWindow::on_writeLineEdit_textChanged(const QString &arg1)
{
    writeFile = arg1;
    qDebug() << writeFile;
}

void MainWindow::on_readLineEdit_textChanged(const QString &arg1)
{
    readFile = arg1;
    qDebug() << readFile;
}


void MainWindow::on_stateButton_clicked()
{
    stateGetSem.unlock();
}
