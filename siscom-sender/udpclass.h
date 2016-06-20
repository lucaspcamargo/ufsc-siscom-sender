#ifndef UDPCLASS_H
#define UDPCLASS_H

#include <QObject>
#include <QUdpSocket>
#include <QFile>
#include <QMessageBox>
#include <QProgressDialog>
#include <QThread>
#include <QString>
#include <QHostInfo>

class UdpClass : public QObject
{
    Q_OBJECT
public:
    explicit UdpClass(QObject *parent = 0);
    void sendMessage(QString message);
    void sendMessage(QByteArray message);
    void sendFile(QString filename);
    void SetAddress(QString str);
    void SetPort(quint16 p);


signals:
public slots:
    void readMessage();

private:
    QUdpSocket * socket;
    quint16 udp_port;
    QString address;
};


#endif // UDPCLASS_H
