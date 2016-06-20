#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QString>
#include <QDebug>
#include <string.h>
#include <QFile>

/*
 *  A classe seguinte foi desenvolvida para abrir um socket de conexao TCP
 *  Eh possivel enviar mensagens ao endereco e porta escolhidos.
 *
 *      Funcionamento:
 *          * Primeiramente a conexao e aberta
 *          * Caso seja aberta com sucesso a mensagem eh enviada
 *          * A resposta do outro lado da comunicacao eh lida
 *          * A conexao eh encerrada.
 *
 *  @author: Felipe Willian Fraporti
 *  @email: ffraporti@gmail.com
 *  @date: 16/06/2016
 */
class TCPSocket : public QObject
{
    Q_OBJECT
public:
    /*
     *  Construtor da classe
     */
    explicit TCPSocket(QObject *parent = 0);

    /*
     *  metodo: SendMessage
     *  Envia a mensagem ao endereco fornecido
     *
     *  parametros: recebe uma string contendo a mensagem que sera enviada
     *  retorno: nao ha retorno neste metodo
     */
    void SendMessage(QString msg);

    /*
     *  metodo: SendFile
     *  Envia um arquivo atraves do protocolo TCP
     *
     *  parametros: recebe uma string contendo o nome e caminho do arquivo
     *          Por exemplo: /home/felipe/Documents/teste.txt
     *  retorno: nao ha retorno neste metodo
     */
    void SendFile(QString filename);

    /*
     *  metodo: SetAddress
     *  Altera o endereco utilizado na conexao
     *
     *  parametros: recebe uma string contendo o endereco que sera utilizado para comunicacao
     *  retorno: nao ha retorno neste metodo
     */
    void SetAddress(QString str);

    /*
     *  metodo: SetPort
     *  Altera a porta utilizada na conexao
     *
     *  parametros: recebe um inteiro de 16 bits contendo a porta utilizada na comunicacao
     *  retorno: nao ha retorno neste metodo
     */
    void SetPort(quint16 p);

private:
    //socket utilizado na conexao
    QTcpSocket *socket;

    //endereco utilizado na conexao
    QString address;

    //porta utilizada na conexao
    quint16 port;

    /*
     *  metodo: CloseConnection
     *  Encerra a conexao
     *
     *  retorno: nao ha retorno para este metodo
     */
    void CloseConnection();

    /*
     *  metodo: OpenConnection
     *  Inicia a conexao atraves do endereco e porta fornecidos
     *
     *  retorno: verdadeiro caso a conexao foi aberta com sucesso, falso para o contrario
     */
    bool OpenConnection();

    /*
     *  metodo: ReadServerAnswer
     *  Realiza a leitura do outro lado da comunicacao
     *
     *  retorno: nao ha retorno para este metodo
     */
    void ReadServerAnswer();

    /*
     *  metodo: SendPackage
     *  Envia pacote de dados na conexao
     *  parametros: package, o vetor de bytes relacionado com o pacote
     *  retorno: nao ha retorno para este metodo
     */
    void SendPackage(QByteArray package);
};

#endif // TCPSOCKET_H
