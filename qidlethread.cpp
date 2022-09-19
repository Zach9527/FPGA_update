#include "qidlethread.h"
#include "mainwindow.h"
#include "common.h"
#include "icd.h"
#include "qtcp.h"
#include "ipconfigdialog.h"
#include <QDebug>
#include <QMessageBox>
#include <QStatusBar>

QIdleThread::QIdleThread(QObject *parent) : QThread(parent)
{
    fwd = parent;
    semTimeOut = 1000;//默认1000ms超时
    connect(this,&QIdleThread::signalbut,(MainWindow*)fwd,&MainWindow::enableButton);
//    connect(this,&QIdleThread::)
}
QIdleThread::~QIdleThread()
{
    exitSem.tryLock();//防止释放了两次互斥信号量
    exitSem.unlock();

    wait(200);
    fwd = NULL;
}

void QIdleThread::run()
{
    MainWindow *mainWd;
    QTcp *tcpHandle;

    if(NULL == fwd)
    {
        qDebug() << "QIdleThread:NULL == fwd";
        return;
    }
    mainWd = (MainWindow *)fwd;
    tcpHandle = (QTcp *)(mainWd->tcpH);
    if(NULL == tcpHandle)
    {
        qDebug() << "QIdleThread:NULL == tcpHandle";
        return;
    }

    qDebug() << "QIdleThread start OK";

    while(true)
    {
        //判断需要执行那个功能任务
        if(true == mainWd->prgmUpgradeSem.tryLock()) //程序烧写程序更新
        {
            prgmUpgrade();
            emit signalbut();
        }
        if(true == mainWd->prgmReadSem.tryLock()) //程序读取
        {
            prgmRead();
            emit signalbut();
        }
        if(true == mainWd->prgmEarseSem.tryLock()) //程序擦除
        {
            prgmEarse();
            emit signalbut();
        }
        if(true == mainWd->paraGetSem.tryLock()) //参数获取
        {
            paraGet();
        }
        if(true == mainWd->paraSetSem.tryLock()) //参数设置
        {
            paraSet();
        }
        if(true == mainWd->stateGetSem.tryLock())//fpga状态获取
        {
            stateGet();
        }

        //判断是否需要退出线程
        if(true == exitSem.tryLock(1))
        {
             qDebug() << "QIdleThread return OK";
            return;
        }
    }
}

bool QIdleThread::creatReadFile(void)
{
    MainWindow *mainWd;
    mainWd = (MainWindow *)fwd;

    QString name = mainWd->readFileEdit->text();
    readFile.setFileName(name);
    return readFile.open(QIODevice::WriteOnly | QIODevice::Truncate);

    //return true;
}

uint32_t QIdleThread::checkSum(uint8_t *dat, int size)
{
    int i;
    uint32_t sum;

    for(i = 0, sum = 0; i < size; i++)
    {
        sum += dat[i];
    }

    return sum;
}

bool QIdleThread::checkDatIsOK(uint8_t *dat, int size)
{
    ICD_COMMON_HEAD_T *head;
    int sizeTmp;
    uint32_t sum;
    uint32_t *checkSump;

    if(sizeof(ICD_COMMON_HEAD_T)-sizeof(head->dat[0]) > size)
    {
        return false;
    }

    head = (ICD_COMMON_HEAD_T *)dat;
    if(head->size > ICD_DAT_MAX_SIZE)
    {
        return false;
    }

    sizeTmp = sizeof(head->head) + sizeof(head->cmd) \
            + sizeof(head->size) + head->size\
            + sizeof(head->tail) + sizeof(head->checkSum);
    if(sizeTmp != size)
    {
        return false;
    }

    sizeTmp = size - sizeof(head->checkSum);
    sum = checkSum(dat, sizeTmp);

    checkSump =(uint32_t *)(dat + sizeTmp);
    if(sum != *checkSump)
    {
        return false;
    }

    return true;
}

bool QIdleThread::getIcdCmdDat(uint8_t *recvBuf, int recvSize, \
                  uint32_t *cmd, uint8_t *dat, uint32_t *datSize)
{
    ICD_COMMON_HEAD_T *head;

    head = (ICD_COMMON_HEAD_T *)recvBuf;

    memcpy_s(head->dat, head->size, dat, ICD_DAT_MAX_SIZE);
    *cmd = head->cmd;
    *datSize = head->size;

    return true;
}

void QIdleThread::prgmUpgrade(void)
{
    MainWindow *mainWd;
    int32_t fileSize, readSize, packSize;
    int32_t i;
    uint32_t ackCnt;
    uint32_t *p32;
    int32_t fpgaCs;
    mainWd = (MainWindow *)fwd;
    QTcp *tcpHandle = (QTcp *)(mainWd->tcpH);
    QString name = mainWd->writeFileEdit->text();
    QString rateMsg;
    uint8_t sendBuf[ICD_MAX_SIZE];
    uint8_t recvBuf[ICD_MAX_SIZE];
    ICD_WRITE_CMD_T *writeCmd = (ICD_WRITE_CMD_T *)sendBuf;
    ICD_COMMON_RSP_T *writeRsp = (ICD_COMMON_RSP_T *)recvBuf;
    fpgaFile.setFileName(name);
    if(false == fpgaFile.open(QIODevice::ReadOnly) )
    {
        mainWd->sig_showMsgStatusBr(C_STR("文件打开错误，请检查文件是否存在"), 5000);
        return;
    }

    fileSize = fpgaFile.size();
    if(fileSize > FPGA_FILE_MAX_SIZE)
    {
        mainWd->sig_showMsgStatusBr(C_STR("文件太大，Flash存不下"), 5000);
        fpgaFile.close();
        return;
    }

    fpgaCs = mainWd->getFpgaCs();
    if(-1 == fpgaCs)
    {
        mainWd->sig_showMsgStatusBr(C_STR("请选择需要操作哪一片FPGA配置片"), 5000);
        fpgaFile.close();
        return;
    }

    writeCmd->head = ICD_CMD_HEAD;
    writeCmd->cmd = ICD_CMD_WRITE;
    writeCmd->fpgaCs = fpgaCs;
    for(i = 0, readSize = 0, ackCnt = 0; true; i += readSize, ackCnt++)
    {
        writeCmd->ackCnt = ackCnt;
        readSize = fpgaFile.read((char *)writeCmd->dat, ICD_FILEDAT_MAX_SIZE);
        if( (readSize > ICD_FILEDAT_MAX_SIZE) || (-1 == readSize) )
        {
            mainWd->sig_showMsgStatusBr(C_STR("文件读取错误，程序意外错误"), 5000);
            fpgaFile.close();
            return;
        }
        writeCmd->size = readSize + 8;

        p32 = (uint32_t *)(writeCmd->dat +readSize);
        *p32 = ICD_CMD_TAIL;
        p32 += 1;
        packSize = readSize + 28;
        *p32 = checkSum(sendBuf, packSize - 4);

        //发送指令数据
        if(packSize != tcpHandle->sendDat(sendBuf, packSize) )
        {
            mainWd->sig_showMsgStatusBr(C_STR("TCP数据发送失败"), 5000);
            fpgaFile.close();
            return;
        }

        //等待数据接收
        if(false == tcpRecvSem.tryLock(semTimeOut) ) //超时时间默认1000ms
        {
            mainWd->sig_showMsgStatusBr(C_STR("服务器没有数据响应，超时退出"), 5000);
            fpgaFile.close();
            return;
        }
        QString percent = QString::number((float)i/fileSize*100,'f',2);
        rateMsg = QString("加载进度:%1%").arg(percent);
        mainWd->sig_showMsgStatusBr(rateMsg, 5000);
        //读取TCP数据
        packSize = tcpHandle->readDat(recvBuf, ICD_MAX_SIZE);
        if(sizeof(ICD_COMMON_RSP_T) != packSize)
        {
            mainWd->sig_showMsgStatusBr(C_STR("接收的TCP数据长度不对"), 5000);
            fpgaFile.close();
            return;
        }
        //包格式校验
        if(false == checkDatIsOK(recvBuf, packSize))
        {
            mainWd->sig_showMsgStatusBr(C_STR("接收的TCP数据包格式不对"), 5000);
            fpgaFile.close();
            return;
        }
        //包格式校验
        if(ICD_OPRET_OK != writeRsp->opRet)
        {
            if(ICD_OPRET_UNEARSE == writeRsp->opRet)
            {
                mainWd->sig_showMsgStatusBr(C_STR("Flash扇区未擦除"), 5000);
                fpgaFile.close();
                return;
            }
            mainWd->sig_showMsgStatusBr(C_STR("未知错误，任务退出"), 5000);
            fpgaFile.close();
            return;
        }

        if(0 == readSize)
        {
            break;
        }
    }

    mainWd->sig_showMsgStatusBr(C_STR("程序更新完成"), 5000);
    fpgaFile.close();
    return;
}

void QIdleThread::prgmRead(void)
{
    MainWindow *mainWd;
    int32_t packSize;
    uint32_t ackCnt,readCnt = 0;
    int32_t fpgaCs;
    mainWd = (MainWindow *)fwd;
    QTcp *tcpHandle = (QTcp *)(mainWd->tcpH);
    QString readMsg;
    uint8_t sendBuf[ICD_MAX_SIZE];
    uint8_t recvBuf[ICD_MAX_SIZE];
    ICD_DAT_READ_CMD_T *readCmd = (ICD_DAT_READ_CMD_T *)sendBuf;
    ICD_COMMON_HEAD_T *readRsp = (ICD_COMMON_HEAD_T *)recvBuf;

    if(false == creatReadFile() )
    {
        mainWd->sig_showMsgStatusBr(C_STR("文件创建失败"), 5000);
        return;
    }

    fpgaCs = mainWd->getFpgaCs();
    if(-1 == fpgaCs)
    {
        mainWd->sig_showMsgStatusBr(C_STR("请选择需要操作哪一片FPGA配置片"), 5000);
        readFile.close();
        return;
    }

    readCmd->head = ICD_CMD_HEAD;
    readCmd->cmd = ICD_CMD_READ;
    readCmd->size = ICD_DAT_READ_SIZE;
    readCmd->fpgaCs = fpgaCs;
    readCmd->tail = ICD_CMD_TAIL;
    for(ackCnt = 0; true;  ackCnt++)
    {
        readCmd->ackCnt = ackCnt;
        packSize = sizeof(ICD_DAT_READ_CMD_T);
        readCmd->checkSum = checkSum(sendBuf, packSize - 4);

        //发送指令数据
        if(packSize != tcpHandle->sendDat(sendBuf, packSize) )
        {
            mainWd->sig_showMsgStatusBr(C_STR("TCP数据发送失败"), 5000);
            readFile.close();
            return;
        }

        //等待数据接收
        if(false == tcpRecvSem.tryLock(semTimeOut) ) //超时时间默认1000ms
        {
            mainWd->sig_showMsgStatusBr(C_STR("服务器没有数据响应，超时退出"), 5000);
            readFile.close();
            return;
        }

        //读取TCP数据
        packSize = tcpHandle->readDat(recvBuf, ICD_MAX_SIZE);
        if(packSize < 20)
        {
            mainWd->sig_showMsgStatusBr(C_STR("接收的TCP数据长度不对"), 5000);
            readFile.close();
            return;
        }
        //包格式校验
        if(false == checkDatIsOK(recvBuf, packSize))
        {
            mainWd->sig_showMsgStatusBr(C_STR("接收的TCP数据包格式不对"), 5000);
            readFile.close();
            return;
        }
        //检查数据是否读取完成
        if(0 == readRsp->size)
        {
            break;
        }
        //写文件
        if(readRsp->size != readFile.write((char *)(readRsp->dat), readRsp->size) )
        {
            mainWd->sig_showMsgStatusBr(C_STR("写文件错误，任务退出"), 5000);
            readFile.close();
            return;
        }
        readCnt += readRsp->size;
        readMsg = QString("读取字节数：%1").arg(readCnt);
        mainWd->sig_showMsgStatusBr(readMsg, 5000);
    }

    mainWd->sig_showMsgStatusBr(C_STR("程序读取完成"), 5000);
    readFile.close();
    return;
}

void QIdleThread::prgmEarse(void)
{
    MainWindow *mainWd;
    int32_t fpgaCs;
    int32_t packSize;
    mainWd = (MainWindow *)fwd;
    QTcp *tcpHandle = (QTcp *)(mainWd->tcpH);
    uint8_t sendBuf[ICD_MAX_SIZE];
    uint8_t recvBuf[ICD_MAX_SIZE];
    ICD_EARSE_CMD_T *earseCmd = (ICD_EARSE_CMD_T *)sendBuf;
    ICD_COMMON_RSP_T *earseRsp = (ICD_COMMON_RSP_T *)recvBuf;

    earseCmd->head = ICD_CMD_HEAD;
    earseCmd->cmd = ICD_CMD_EARSE;
    earseCmd->size = ICD_EARSE_SIZE;

    fpgaCs = mainWd->getFpgaCs();
    earseCmd->fpgaCs = fpgaCs;
    earseCmd->addr = 0;
    earseCmd->spaceSize = 0xFFFFFFFF;
    earseCmd->tail = ICD_CMD_TAIL;
    packSize = sizeof(ICD_EARSE_CMD_T);
    earseCmd->checkSum = checkSum(sendBuf, packSize - 4);
    if(-1 == fpgaCs)
    {
        mainWd->sig_showMsgStatusBr(C_STR("请选择需要操作哪一片FPGA配置片"), 5000);
        return;
    }
    //发送指令数据
    if(packSize != tcpHandle->sendDat(sendBuf, packSize) )
    {
        mainWd->sig_showMsgStatusBr(C_STR("TCP数据发送失败"), 5000);
        return;
    }

    //等待数据接收
    if(false == tcpRecvSem.tryLock(semTimeOut) ) //超时时间默认1000ms
    {
        mainWd->sig_showMsgStatusBr(C_STR("服务器没有数据响应，超时退出"), 5000);
        return;
    }

    //读取TCP数据
    packSize = tcpHandle->readDat(recvBuf, ICD_MAX_SIZE);
    if(sizeof(ICD_COMMON_RSP_T) != packSize)
    {
        mainWd->sig_showMsgStatusBr(C_STR("接收的TCP数据长度不对"), 5000);
        return;
    }
    //包格式校验
    if(false == checkDatIsOK(recvBuf, packSize))
    {
        mainWd->sig_showMsgStatusBr(C_STR("接收的TCP数据包格式不对"), 5000);
        fpgaFile.close();
        return;
    }
    //检查操作状态
    if(ICD_OPRET_OK != earseRsp->opRet)
    {
        mainWd->sig_showMsgStatusBr(C_STR("擦除错误，任务退出"), 5000);
        return;
    }

    mainWd->sig_showMsgStatusBr(C_STR("擦除成功"), 5000);
}

void QIdleThread::paraGet(void)
{
    MainWindow *mainWd;
    int32_t packSize;
    mainWd = (MainWindow *)fwd;
    QTcp *tcpHandle = (QTcp *)(mainWd->tcpH);
    uint8_t sendBuf[ICD_MAX_SIZE];
    uint8_t recvBuf[ICD_MAX_SIZE];
    ICD_PARA_GET_CMD_T *paraGetCmd = (ICD_PARA_GET_CMD_T *)sendBuf;
    ICD_PARA_T *paraGeteRsp = (ICD_PARA_T *)recvBuf;

    paraGetCmd->head = ICD_CMD_HEAD;
    paraGetCmd->cmd = ICD_CMD_PARA_GET;
    paraGetCmd->size = ICD_PARA_GET_SIZE;
    paraGetCmd->rev = 0;
    paraGetCmd->tail = ICD_CMD_TAIL;
    packSize = sizeof(ICD_PARA_GET_CMD_T);
    paraGetCmd->checkSum = checkSum(sendBuf, packSize - 4);

    //发送指令数据
    if(packSize != tcpHandle->sendDat(sendBuf, packSize) )
    {
        mainWd->sig_showMsgStatusBr(C_STR("TCP数据发送失败"), 5000);
        readFile.close();
        return;
    }

    //等待数据接收
    if(false == tcpRecvSem.tryLock(semTimeOut) ) //超时时间默认1000ms
    {
        mainWd->sig_showMsgStatusBr(C_STR("服务器没有数据响应，超时退出"), 5000);
        readFile.close();
        return;
    }

    //读取TCP数据
    packSize = tcpHandle->readDat(recvBuf, ICD_MAX_SIZE);
    if(sizeof(ICD_PARA_T) != packSize)
    {
        mainWd->sig_showMsgStatusBr(C_STR("接收的TCP数据长度不对"), 5000);
        return;
    }
    //包格式校验
    if(false == checkDatIsOK(recvBuf, packSize))
    {
        mainWd->sig_showMsgStatusBr(C_STR("接收的TCP数据包格式不对"), 5000);
        fpgaFile.close();
        return;
    }

    mainWd->ipconfig->ipSetLineEdit_->setIp(paraGeteRsp->ip);
    mainWd->ipconfig->portSetLineEdit_->setText(QString::number(paraGeteRsp->port));
    mainWd->ipconfig->macLineEdit_->setMac(paraGeteRsp->mac);


    mainWd->sig_showMsgStatusBr(C_STR("参数获取成功"), 5000);
}

void QIdleThread::paraSet(void)
{
    MainWindow *mainWd;
    int32_t packSize;
    mainWd = (MainWindow *)fwd;
    QTcp *tcpHandle = (QTcp *)(mainWd->tcpH);
    uint8_t sendBuf[ICD_MAX_SIZE];
    uint8_t recvBuf[ICD_MAX_SIZE];
    ICD_PARA_T *paraSetCmd = (ICD_PARA_T *)sendBuf;
    ICD_COMMON_RSP_T *paraSeteRsp = (ICD_COMMON_RSP_T *)recvBuf;

    paraSetCmd->head = ICD_CMD_HEAD;
    paraSetCmd->cmd = ICD_CMD_PARA_SET;
    paraSetCmd->size = ICD_PARA_SIZE;

    mainWd->ipconfig->ipSetLineEdit_->getIp(paraSetCmd->ip);
    paraSetCmd->port = mainWd->ipconfig->portSetLineEdit_->text().toInt();
    mainWd->ipconfig->macLineEdit_->getMac(paraSetCmd->mac);

    paraSetCmd->tail = ICD_CMD_TAIL;
    packSize = sizeof(ICD_PARA_T);
    paraSetCmd->checkSum = checkSum(sendBuf, packSize - 4);

    //发送指令数据
    if(packSize != tcpHandle->sendDat(sendBuf, packSize) )
    {
        mainWd->sig_showMsgStatusBr(C_STR("TCP数据发送失败"), 5000);
        readFile.close();
        return;
    }

    //等待数据接收
    if(false == tcpRecvSem.tryLock(semTimeOut) ) //超时时间默认1000ms
    {
        mainWd->sig_showMsgStatusBr(C_STR("服务器没有数据响应，超时退出"), 5000);
        readFile.close();
        return;
    }

    //读取TCP数据
    packSize = tcpHandle->readDat(recvBuf, ICD_MAX_SIZE);
    if(sizeof(ICD_COMMON_RSP_T) != packSize)
    {
        mainWd->sig_showMsgStatusBr(C_STR("接收的TCP数据长度不对"), 5000);
        return;
    }
    //包格式校验
    if(false == checkDatIsOK(recvBuf, packSize))
    {
        mainWd->sig_showMsgStatusBr(C_STR("接收的TCP数据包格式不对"), 5000);
        fpgaFile.close();
        return;
    }

    //检查操作状态
    if(ICD_OPRET_OK != paraSeteRsp->opRet)
    {
        mainWd->sig_showMsgStatusBr(C_STR("参数设置失败，状态返回不对"), 5000);
        return;
    }

    mainWd->sig_showMsgStatusBr(C_STR("参数设置成功"), 5000);
}



void QIdleThread::stateGet(void)
{
    MainWindow *mainWd;
    int32_t packSize;
    mainWd = (MainWindow *)fwd;
    QTcp *tcpHandle = (QTcp *)(mainWd->tcpH);
    uint8_t sendBuf[ICD_MAX_SIZE];
    uint8_t recvBuf[ICD_MAX_SIZE];
    ICD_PARA_GET_CMD_T *paraGetCmd = (ICD_PARA_GET_CMD_T *)sendBuf;
    ICD_STATE_PARA_RSP *paraGeteRsp = (ICD_STATE_PARA_RSP *)recvBuf;
    QString msg;
    paraGetCmd->head = ICD_CMD_HEAD;
    paraGetCmd->cmd = ICD_CMD_STATE_GET;
    paraGetCmd->size = ICD_PARA_GET_SIZE;
    paraGetCmd->rev = 0;
    paraGetCmd->tail = ICD_CMD_TAIL;
    packSize = sizeof(ICD_PARA_GET_CMD_T);
    paraGetCmd->checkSum = checkSum(sendBuf, packSize - 4);
    //发送指令数据
    if(packSize != tcpHandle->sendDat(sendBuf, packSize) )
    {
        mainWd->sig_showMsgStatusBr(C_STR("TCP数据发送失败"), 5000);
        readFile.close();
        return;
    }
    //等待数据接收
    if(false == tcpRecvSem.tryLock(semTimeOut) ) //超时时间默认1000ms
    {
        mainWd->sig_showMsgStatusBr(C_STR("服务器没有数据响应，超时退出"), 5000);
        readFile.close();
        return;
    }
    //读取TCP数据
    packSize = tcpHandle->readDat(recvBuf, ICD_MAX_SIZE);
    if(sizeof(ICD_STATE_PARA_RSP) != packSize)
    {
        mainWd->sig_showMsgStatusBr(C_STR("接收的TCP数据长度不对"), 5000);
        return;
    }
    if(false == checkDatIsOK(recvBuf, packSize))
    {
        mainWd->sig_showMsgStatusBr(C_STR("接收的TCP数据包格式不对"), 5000);
        fpgaFile.close();
        return;
    }
    mainWd->sig_showFpgaMsgBr(paraGeteRsp);
}








