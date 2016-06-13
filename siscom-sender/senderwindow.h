#ifndef SENDERWINDOW_H
#define SENDERWINDOW_H

#include <QMainWindow>

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

    void setFile(QString * filename);

private slots:
    void on_actionHelp_triggered();
    void on_pushButton_clicked();


private:
    Ui::SenderWindow *ui;
    HelpDialog * helpDialog;
    SelectFile * selectFile;

    QString * fileName;
};

#endif // SENDERWINDOW_H
