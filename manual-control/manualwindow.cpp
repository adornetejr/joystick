#include "manualwindow.h"
#include "ui_manualwindow.h"

ManualWindow::ManualWindow(int _player, SerialCommunicator<Ai2RobotMessage> *_serial, QWidget *parent) :
    player_num(_player),
    serial(_serial),
    QMainWindow(parent),
    ui(new Ui::ManualWindow)
{
    ui->setupUi(this);

    QPixmap pix("../joystick/images/control.svg");
    QPixmap pix2("../joystick/images/logo-mini");
    ui->xbox_image->setPixmap(pix);
    //ui->logo->setPixmap(pix2);
    ui->xbox_image->setEnabled(false);

    control = new ManualControl(player_num);
}

ManualWindow::~ManualWindow()
{
    delete control;
    delete ui;
}

//Interface
void ManualWindow::on_on_button_clicked(bool checked)
{
    if(checked){
        control->setId(ui->id_box->value());
        control->setMaxVelocity(ui->vel_box->value());
        control->setDribblerVelocity(ui->dri_box->value());
        control->setKickPower(ui->kick_box->value());
        control->setPassPower(ui->pass_box->value());
        control->start();
        ui->xbox_image->setEnabled(true);
    }
    else{
        control->stop();
        ui->xbox_image->setEnabled(true);
    }
}
