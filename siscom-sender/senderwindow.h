#ifndef SENDERWINDOW_H
#define SENDERWINDOW_H

#include <QMainWindow>

namespace Ui {
class SenderWindow;
}

class HelpDialog;

class SenderWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SenderWindow(QWidget *parent = 0);
    ~SenderWindow();

private slots:
    void on_actionHelp_triggered();

private:
    Ui::SenderWindow *ui;
    HelpDialog * helpDialog;
};

#endif // SENDERWINDOW_H
