#include "senderwindow.h"

SenderWindow * SenderWindow::_instance = 0;

SenderWindow::SenderWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SenderWindow)
{
    _instance = this;

    ui->setupUi(this);

    helpDialog = new HelpDialog(this);
    selectFile = new SelectFile(this);

}

SenderWindow::~SenderWindow()
{
    delete ui;
}

void SenderWindow::on_actionHelp_triggered()
{
    helpDialog->exec();
}

void SenderWindow::on_actionSend_triggered()
{



    //QThread * thread = new QThread;
    //client.moveToThread(thread);

    UdpClass client1;
    TCPSocket client2;
    //QString fileName("/home/rlove/QT_PROJECTS/SISCOM/tropical-beach-background-8.jpg");

    QString text = ui->plainTextEdit->toPlainText();

    if (ui->udpRadio->isChecked())
    {
        client1.SetAddress(ui->comboBox->currentText());
        client1.SetPort(ui->portSpinBox->value());
        client1.sendMessage(text);
        if(ui->checkBox->isChecked())
        {
            if(fileName.isEmpty())
                error("No file was selected");
            else
                client1.sendFile(fileName);
        }
    }
    else
    {
        //QString address = ui->comboBox->currentText();
        //quint16 port = ui->portSpinBox->value();
        client2.SetAddress(ui->comboBox->currentText());
        client2.SetPort(ui->portSpinBox->value());
        client2.SendMessage(text);
        if(ui->checkBox->isChecked())
        {
            if(fileName.isEmpty())
                error("No file was selected");
            else
                client2.SendFile(fileName);
        }

    }

    ui->comboBox->addItem(ui->comboBox->currentText());
}


void SenderWindow::on_pushButton_clicked()
{
    //'Select file' PushButton clicked
    selectFile->exec();
}

void SenderWindow::setFile(QString filename)
{
    //change 'Send file' TextLabel's value
    fileName = filename;
    ui->label_3->setText(fileName);
}

void SenderWindow::error(QString err)
{
    QMessageBox::warning(_instance, "Error", err);
}

void SenderWindow::on_checkBox_toggled(bool checked)
{
    ui->plainTextEdit->setEnabled(!checked);
}
