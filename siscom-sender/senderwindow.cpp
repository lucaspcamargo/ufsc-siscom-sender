#include "senderwindow.h"
#include "ui_senderwindow.h"
#include "helpdialog.h"
#include "selectfile.h"

SenderWindow::SenderWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SenderWindow)
{
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

void SenderWindow::on_pushButton_clicked()
{
    //'Select file' PushButton clicked
    selectFile->exec();
}

void SenderWindow::setFile(QString * filename)
{
    //change 'Send file' TextLabel's value
    fileName = filename;
    ui->label_3->setText(*fileName);
}
