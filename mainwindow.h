#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "playersdialog.h"
#include "manualwindow.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_ok_button_clicked();

private:
    Ui::MainWindow *ui;

    PlayersDialog *players_ui;
    ManualWindow **manual_uis;
    SerialCommunicator<Ai2RobotMessage> *serial;
};

#endif // MAINWINDOW_H
