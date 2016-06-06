#include "senderwindow.h"
#include "ui_senderwindow.h"
#include "helpdialog.h"

SenderWindow::SenderWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SenderWindow)
{
    ui->setupUi(this);

    helpDialog = new HelpDialog(this);
}

SenderWindow::~SenderWindow()
{
    delete ui;
}

void SenderWindow::on_actionHelp_triggered()
{
    helpDialog->exec();
}
