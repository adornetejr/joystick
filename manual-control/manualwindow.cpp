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

    control = new ManualControl(player_num, serial);
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
        control->setMaxAngularVelocity(ui->ang_box->value());
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

void ManualWindow::on_id_box_editingFinished()
{
    control->setId(ui->id_box->value());
}

void ManualWindow::on_ang_box_editingFinished()
{
    control->setMaxAngularVelocity(ui->ang_box->value());
}

void ManualWindow::on_vel_box_editingFinished()
{
    control->setMaxVelocity(ui->vel_box->value());
}

void ManualWindow::on_dri_box_editingFinished()
{
    control->setDribblerVelocity(ui->dri_box->value());
}

void ManualWindow::on_kick_box_editingFinished()
{
    control->setKickPower(ui->kick_box->value());
}

void ManualWindow::on_pass_box_editingFinished()
{
    control->setPassPower(ui->pass_box->value());
}
