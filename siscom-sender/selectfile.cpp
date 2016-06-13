#include "selectfile.h"
#include "ui_selectfile.h"
#include "senderwindow.h"

QString * SelectFile::filePath;

SelectFile::SelectFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectFile)
{

    ui->setupUi(this);

    //QString sPath = "/home/rlove/QT_PROJECTS/";
    //qDebug()<<sPath;
    dirmodel = new QFileSystemModel(this);
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs); //nao mostrar arquivos
    ui->treeView->setModel(dirmodel);
    ui->treeView->setRootIndex(dirmodel->setRootPath("/home"));

    filemodel = new QFileSystemModel(this);
    filemodel->setFilter(QDir::NoDotAndDotDot | QDir::Files); //nao mostrar arquivos
    //filemodel->setRootPath("/");
    ui->listView->setModel(filemodel);
}

SelectFile::~SelectFile()
{
    delete ui;
}

void SelectFile::on_buttonBox_accepted()
{
    //ok button
    if(filePath==0)
        //shows message informing to select file
        QMessageBox::information(this, "Warning", "You have to select one file!");
    else
    {
        //static cast to call parent's method
        static_cast<SenderWindow*>(parent())->setFile(filePath);
        this->close(); //close when file is selected
    }
}

void SelectFile::on_buttonBox_rejected()
{
    //cancel button
    delete filePath;
    filePath = 0;
    this->close();
}

void SelectFile::on_treeView_clicked(const QModelIndex &index)
{
    //when clicking in a node on the folders tree
    QString sPath = dirmodel->fileInfo(index).absoluteFilePath();
    ui->listView->setRootIndex(filemodel->setRootPath(sPath));
}

void SelectFile::on_listView_clicked(const QModelIndex &index)
{
    //when clicking in a node on the files tree
    delete filePath;
    filePath = new QString(filemodel->fileInfo(index).absoluteFilePath());
}
