#ifndef SENDERWINDOW_H
#define SENDERWINDOW_H

#include <QMainWindow>
#include "ui_senderwindow.h"
#include "helpdialog.h"
#include "selectfile.h"
#include "udpclass.h"
#include "tcpsocket.h"

namespace Ui {
class SenderWindow;
}

class HelpDialog;
class SelectFile;


class SenderWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SenderWindow(QWidget *parent = 0);
    ~SenderWindow();

    void setFile(QString filename);
    QString getFilename()
    {
        return fileName;
    };

    static void error(QString err);

private slots:
    void on_actionHelp_triggered();
    void on_pushButton_clicked();
    void on_actionSend_triggered();


    void on_checkBox_toggled(bool checked);

private:
    Ui::SenderWindow *ui;
    HelpDialog * helpDialog;
    SelectFile * selectFile;


    QString fileName;

    static SenderWindow * _instance;
};

#endif // SENDERWINDOW_H
