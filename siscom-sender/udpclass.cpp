#include "udpclass.h"
#include <QProgressBar>

#include "senderwindow.h"

UdpClass::UdpClass(QObject *parent) : QObject(parent)
{
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost, udp_port);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readMessage()));
   // pBar = new ProgressBar(0);
   // dialog.setLabelText(QString("Progressing using %1 thread(s)..."));

}

void UdpClass::sendMessage(QString  message) //client
{
    //creates datagram and append message
    QByteArray Datagram;
    Datagram.append(message);

    qDebug() << "Enviando mensagem: " << message;

    //specifies port and send datagram
    //quint16 udp_port = 22000;
    socket->writeDatagram(Datagram, QHostAddress(address), udp_port);

}

void UdpClass::sendMessage(QByteArray message) //client
{
    //specifies port and send ByteArray
    //quint16 udp_port = 22000;
    socket->writeDatagram(message, QHostAddress(address), udp_port);
}

void UdpClass::sendFile(QString fileName)
{
    //sends a txt files given its address
    qDebug() << fileName;
    QFile file(fileName);

    //opening file
    if (!file.open(QIODevice::ReadOnly))
    {
        SenderWindow::error("Could not open the file!");
        return;
    }

    QByteArray block;
    QDataStream out(&block, QIODevice::ReadWrite);
    //out.setVersion(QDataStream::Qt_5_4);
    qint64 x = 0;
    qint64 n_packs = 0;
    qint64 fsize = file.size();

    QString line = "123FILE321";
    sendMessage(line);
    sendMessage(fileName);

    while (x < fsize) {
        block.append(file.read(512));
        //out.device()->seek(0);
        sendMessage(block);
        block.clear();
        x += 512;
        n_packs++;
        if(x<fsize)
            qDebug()<<100-100*(fsize-x)/fsize<<"%";
     }
    file.close();
    qDebug() << "Tamanho do arquivo: "<< fsize;
    qDebug()<<"Pacotes enviados: "<<n_packs;
    qDebug()<<"fechando arquivo..";

    line = "123CLOSE321";
    sendMessage(line);

    //delete progressBar;
}

void UdpClass::readMessage() //server
{
    //configures buffer acording to the message size
    QByteArray Buffer;
    Buffer.resize(socket->pendingDatagramSize());

    //reads datagram, getting message, sender and senderPort
    QHostAddress sender;
    quint16 senderPort;
    socket->readDatagram(Buffer.data(), Buffer.size(),&sender, &senderPort);

    qDebug() << "Message from: " << sender.toString();
    qDebug() << "Message port: " << senderPort;
    qDebug() << "Message: " << Buffer;
}


void UdpClass::SetAddress(QString str){

    QHostInfo hostadd = QHostInfo::fromName(str);
    qDebug() << "Address set: " << str;
    address.append(hostadd.addresses().first().toString());
    qDebug() << "Address name: " << hostadd.addresses().first().toString();
}

void UdpClass::SetPort(quint16 p){
    udp_port = p;
    qDebug() << "Port set: " << udp_port;
}
