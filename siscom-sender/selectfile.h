#ifndef SELECTFILE_H
#define SELECTFILE_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QFileSystemModel>
#include <QDebug>
#include <QWidget>
#include <QMessageBox>

//reference: https://www.youtube.com/watch?v=92biLZST6Vg&index=49&list=PL2D1942A4688E9D63

namespace Ui {
class SelectFile;
}

class SenderWindow;

class SelectFile : public QDialog
{
    Q_OBJECT

public:
    explicit SelectFile(QWidget *parent = 0);
    ~SelectFile();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_treeView_clicked(const QModelIndex &index);

    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::SelectFile *ui;

    QFileSystemModel * dirmodel; //display folders
    QFileSystemModel * filemodel; //display files

    static QString * filePath;
};

#endif // SELECTFILE_H
