#include "tcpsocket.h"
#include "senderwindow.h"

TCPSocket::TCPSocket(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
}

void TCPSocket::SendFile(QString filename){
    if(OpenConnection()){
        socket->flush();
        qDebug() << "Iniciando envio do arquivo " << filename;
        QFile file(filename);

        if(!file.open(QIODevice::ReadOnly)){
            qDebug() << "Nao foi possivel abrir o arquivo, verifique o caminho e nome preenchido";
            return;
        }
        QByteArray block;
        qint64 x = 0;
        qint64 n_packs = 0;
        quint64 fsize = file.size();

        while(x < fsize){
            block.append(file.read(128));
            SendPackage(block);
            block.clear();
            x += 128;
            n_packs++;
            if(x < fsize)
                qDebug()<<100-100*(fsize-x)/fsize << "% do envio concluido";
        }

        file.close();
        qDebug() << "Enviado arquivo de tamanho "<<fsize;
        qDebug() << "Enviado "<<n_packs<<" pacotes";

        CloseConnection();
    }else
        SenderWindow::error("Nao foi possivel iniciar a conexao");
}

void TCPSocket::SendPackage(QByteArray package){
    socket->write(package);
}

void TCPSocket::SendMessage(QString msg){
    if(OpenConnection()){
        qDebug() << "\n-----------------------\n";
        qDebug() << "Connectado com " << address << " atraves da porta "<< port;

        qDebug() << "Escrevendo mensagem: "<<msg;

        QByteArray message;
        message.append(msg);

        socket->write(message);

        socket->waitForBytesWritten(1000);

        ReadServerAnswer();
        CloseConnection();
    }else{
        SenderWindow::error("Houve um erro ao iniciar a conexao. Verifique se o endereco e a porta foram configurados corretamente.");
    }
}

void TCPSocket::ReadServerAnswer(){
    socket->waitForReadyRead(3000);
    qDebug() << "Fazendo leitura de " << socket->bytesAvailable() << " bytes.";
    qDebug() << socket->readAll();
}

void TCPSocket::CloseConnection(){
    if(socket->waitForDisconnected(100)){
        qDebug() << "Conexao encerrada com sucesso! ";
        socket->close();
    }else{
        socket->close();
    }
}

bool TCPSocket::OpenConnection(){
    socket->connectToHost(address,port);

    if(socket->waitForConnected(3000))
        return true;
    else
        return false;
}

void TCPSocket::SetAddress(QString str){
    address.append(str);
    qDebug() << "Address set: " << address;
}

void TCPSocket::SetPort(quint16 p){
    port = p;
    qDebug() << "Port set: " << port;
}
