#include "manualwindow.h"
#include "ui_manualwindow.h"

ManualWindow::ManualWindow(int _player, QWidget *parent) :
    player_num(_player),
    QMainWindow(parent),
    ui(new Ui::ManualWindow)
{
    ui->setupUi(this);

    QPixmap pix("../joystick/images/control.svg");
    ui->xbox_image->setPixmap(pix);
    setEnabledInterface('i');

    control = new ManualControl(player_num);
}

ManualWindow::~ManualWindow()
{
    delete ui;
}

//Interface
void ManualWindow::setEnabledInterface(char c)
{
    switch(c){
    case 'i':
        ui->abrir_button->setEnabled(true);
        ui->baud_box->setEnabled(true);
        ui->port_box->setEnabled(true);
        ui->xbox_image->setEnabled(false);
        ui->on_button->setEnabled(false);
        ui->vel_box->setEnabled(false);
        ui->on_button->setChecked(false);
        break;
    case 'o':
        ui->abrir_button->setEnabled(false);
        ui->baud_box->setEnabled(false);
        ui->port_box->setEnabled(false);
        ui->xbox_image->setEnabled(false);
        ui->on_button->setEnabled(true);
        ui->vel_box->setEnabled(true);
    break;
    case 'c':
        ui->xbox_image->setEnabled(true);
    break;
    }
}
void ManualWindow::on_abrir_button_clicked()
{
    setEnabledInterface('o');
}
void ManualWindow::on_close_button_clicked()
{
    setEnabledInterface('i');
}

void ManualWindow::on_on_button_clicked(bool checked)
{
    if(checked){
        control->setId(ui->id_box->value());
        control->setMaxVelocity(ui->vel_box->value());
        control->start();
        setEnabledInterface('c');
    }
    else{
        control->exit();
        setEnabledInterface('o');
    }
}
