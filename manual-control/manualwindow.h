#ifndef MANUALWINDOW_H
#define MANUALWINDOW_H

#include <QMainWindow>
#include <QPixmap>

#include "manualcontrol.h"
#include "serialcommunicator.h"

namespace Ui {
class ManualWindow;
}

class ManualWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManualWindow(int _player, SerialCommunicator<Ai2RobotMessage> *_serial, QWidget *parent = 0);
    ~ManualWindow();

private slots:
    void on_on_button_clicked(bool checked);

    void on_id_box_editingFinished();

    void on_ang_box_editingFinished();

    void on_vel_box_editingFinished();

    void on_dri_box_editingFinished();

    void on_kick_box_editingFinished();

    void on_pass_box_editingFinished();

private:
    Ui::ManualWindow *ui;
    int player_num;

    ManualControl *control;
    SerialCommunicator<Ai2RobotMessage> *serial;
};

#endif // MANUALWINDOW_H
