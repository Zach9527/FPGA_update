#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QPushButton>
#include <QTextBrowser>
#include <QObject>
#include <QMutex>
#include "qiplineedit.h"
#include "qmaclineedit.h"
#include "settingdialog.h"
#include "ipconfigdialog.h"
#include "versiondialog.h"
#include "qidlethread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    //软件版本
    QString ver;
    //状态栏
    QStatusBar *statusBr;

    QIpLineEdit *ipEdit;
    QLineEdit *portEdit;
    QLineEdit *writePathEdit;
    QLineEdit *readPathEdit;
    QPushButton *cnctButton;
    QPushButton *writePathButton;
    QPushButton *readPathButton;
    QPushButton *writButton;
    QPushButton *readButton;
    QPushButton *earseButton;
    QPushButton *stateButton;
    QLineEdit *writeFileEdit;
    QLineEdit *readFileEdit;
    QTextBrowser *textBrowser;
    //菜单栏
    ipconfigdialog *ipconfig;
    //ipconfigdialog *ipConfig_;
    //应用功能按钮信号量
    QMutex prgmUpgradeSem;//程序烧写程序更新 信号量
    QMutex prgmReadSem;//程序读取 信号量
    QMutex prgmEarseSem;//程序擦除 信号量
    QMutex paraGetSem;//参数获取 信号量
    QMutex paraSetSem;//参数设置 信号量
    QMutex stateGetSem;//FPGA状态获取 信号量

    void init(void);
    int32_t getFpgaCs(void);
    QString getFpgaState(uint8_t state);
    QString getpowerState(uint8_t* state);
    QString getTemp(uint8_t* tmp);
    QString getVol(uint8_t* vol);
    QString getclkState(uint8_t* clk);
    void *tcpH;
    void *idleThread;
signals:
    void sig_showMsgStatusBr(QString text, int timeout);
    void sig_showFpgaMsgBr(ICD_STATE_PARA_RSP*);
public slots:
    void on_showMsgStatusBr(QString text, int timeout);
    void on_showFpgaMsgBr(ICD_STATE_PARA_RSP*);
    void menuSetting(void);
    void menuIpCongfig(void);
    void menuVersion(void);
    void enableButton(void);
private slots:
    void on_connectButton_clicked();

    void on_writePathButton_clicked();

    void on_readPathButton_clicked();

    void on_writeButton_clicked();

    void on_readButton_clicked();

    void on_earseButton_clicked();

    void on_writeLineEdit_textChanged(const QString &arg1);

    void on_readLineEdit_textChanged(const QString &arg1);

    void on_stateButton_clicked();

private:
    Ui::MainWindow *ui;
    QString writeFile;
    QString readFile;

    settingDialog  *setting;
    versionDialog  *version;
};

#endif // MAINWINDOW_H
