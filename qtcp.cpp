#include "qtcp.h"
#include "mainwindow.h"
#include "common.h"
#include "qidlethread.h"
#include <QString>
#include <QObject>
#include <QHostAddress>
#include <QNetworkConfigurationManager>
#include <QNetworkSession>

QTcp::QTcp(QObject *parent) : QObject(parent)
{
    pwd = parent;

}

bool QTcp::init()
{
    if(nullptr == pwd)
    {
        return false;
    }

    m_tcpSocket = new QTcpSocket(pwd);
    if(nullptr == m_tcpSocket)
    {
        return false;
    }

    setTimeOut(1000);//1000ms超时

    //connect(m_tcpSocket, &QTcpSocket::connected, this, &QTcp::onConnected, Qt::QueuedConnection);
    connect(m_tcpSocket, &QTcpSocket::disconnected, this, &QTcp::onDisConnected, Qt::QueuedConnection);
    connect(m_tcpSocket, &QTcpSocket::stateChanged, this, &QTcp::onStateChanged, Qt::QueuedConnection);
    connect(m_tcpSocket, &QTcpSocket::readyRead, this, &QTcp::onReadyRead, Qt::QueuedConnection);

    return true;
}
void QTcp::setTimeOut(int ms)
{
    QNetworkConfigurationManager manager;
    QNetworkConfiguration config = manager.defaultConfiguration();
    config.setConnectTimeout(ms);
    QSharedPointer<QNetworkSession> spNetworkSession(new QNetworkSession(config));
    m_tcpSocket->setProperty("_q_networksession", QVariant::fromValue(spNetworkSession));
}

void QTcp::onConnected()
{
    MainWindow *mw = (MainWindow *)pwd;

    mw->cnctButton->setText(C_STR("断开"));
    mw->sig_showMsgStatusBr(C_STR("和服务器连接成功"), 5000);
    //ui->plainTextEdit->appendPlainText("**已连接到服务器");
    //ui->plainTextEdit->appendPlainTe`xt("**peer address: "+
    //                         m_tcpSocket->peerAddress().toString());
    //ui->plainTextEdit->appendPlainText("**peer port: "+
    //                         QString::number(m_tcpSocket->peerPort()));
}

void QTcp::onDisConnected()
{
    MainWindow *mw = (MainWindow *)pwd;

    mw->cnctButton->setText(C_STR("连接"));
    mw->sig_showMsgStatusBr(C_STR("和服务器已断开连接"), 5000);
    //ui->plainTextEdit->appendPlainText("**已断开服务器");
}

void QTcp::onStateChanged(QAbstractSocket::SocketState sta)
{
    MainWindow *mw = (MainWindow *)pwd;

    switch(sta)
    {
    case QAbstractSocket::SocketState::UnconnectedState:
        mw->sig_showMsgStatusBr(C_STR("连接断开或超时"), 5000);
        onDisConnected();
        break;
    case QAbstractSocket::SocketState::HostLookupState:
        mw->sig_showMsgStatusBr(C_STR("寻找目标IP..."), 5000);
        break;
    case QAbstractSocket::SocketState::ConnectingState:
        mw->sig_showMsgStatusBr(C_STR("正在连接..."), 5000);
        break;
    case QAbstractSocket::SocketState::ConnectedState:
        onConnected();
        mw->sig_showMsgStatusBr(C_STR("连接成功"), 5000);
        break;
    case QAbstractSocket::SocketState::BoundState:
        mw->sig_showMsgStatusBr(C_STR("绑定状态"), 5000);
        break;
    case QAbstractSocket::SocketState::ListeningState:
        mw->sig_showMsgStatusBr(C_STR("监听状态"), 5000);
        break;
    case QAbstractSocket::SocketState::ClosingState:
        mw->sig_showMsgStatusBr(C_STR("关闭状态"), 5000);
        break;
    default:
        mw->sig_showMsgStatusBr(C_STR("意外未定义状态"), 5000);
    }
}

void QTcp::onReadyRead()
{
    MainWindow *mw = (MainWindow *)pwd;

    //ui->plainTextEdit->appendPlainText("[in] "+m_tcpSocket->readLine());
    //mw->sig_showMsgStatusBr(m_tcpSocket->readLine(), 5000);
    if(nullptr == mw)
    {
        return;
    }
    if(nullptr == mw->idleThread)
    {
        return;
    }
    ((QIdleThread *)(mw->idleThread))->tcpRecvSem.tryLock();
    ((QIdleThread *)(mw->idleThread))->tcpRecvSem.unlock();
}


bool QTcp::cnct(QString ip, qint16 port)
{
    MainWindow *mw = (MainWindow *)pwd;
    if( mw->cnctButton->text() == "连接")
    {
        mw->cnctButton->setText(C_STR("正在连接..."));
        mw->sig_showMsgStatusBr(C_STR("正在连接服务器..."), 5000);
        m_tcpSocket->connectToHost(ip,port);
    }
    else
    {
        mw->cnctButton->setText(C_STR("正在断开..."));
        mw->sig_showMsgStatusBr(C_STR("正在断开服务器..."), 5000);
        m_tcpSocket->disconnectFromHost();
    }
    return true;
}

void QTcp::disCnct(void)
{
    m_tcpSocket->disconnectFromHost();
}

int QTcp::sendDat(uint8_t *buf, int size)
{
    QByteArray byteArry;
    int i;
    qint64 sendSize;

    for(i = 0; i < size; i++)
    {
        byteArry[i] = buf[i];
    }

    sendSize = m_tcpSocket->write(byteArry, size);
    m_tcpSocket->waitForBytesWritten(3*1000);

    return sendSize;
}

int QTcp::readDat(uint8_t *buf, int size)
{
    return m_tcpSocket->read((char *)buf, size);
}
