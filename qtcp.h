#ifndef QTCP_H
#define QTCP_H

#include <QObject>
#include <QTcpSocket>

class QTcp : public QObject
{
    Q_OBJECT
public:
    explicit QTcp(QObject *parent = nullptr);

    QObject *pwd;
    QTcpSocket *m_tcpSocket = nullptr;

    bool init(void);
    void setTimeOut(int ms);
    bool cnct(QString ip, qint16 port);
    void disCnct(void);
    int sendDat(uint8_t *buf, int size);
    int readDat(uint8_t *buf, int size);

signals:

public slots:

    void onConnected();

    void onDisConnected();

    void onStateChanged(QAbstractSocket::SocketState);

    void onReadyRead();
};

#endif // QTCP_H
