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
}

ManualWindow::~ManualWindow()
{
    delete ui;
}

void ManualWindow::setEnabledInterface(char c)
{
    switch(c){
    case 'i':
        ui->xbox_image->setEnabled(false);
        ui->on_button->setEnabled(false);
        ui->vel_box->setEnabled(false);
        ui->on_button->setChecked(false);
    break;
    case 'o':
        ui->xbox_image->setEnabled(false);
        ui->on_button->setEnabled(true);
        ui->vel_box->setEnabled(true);
    break;
    case 'c':
        ui->xbox_image->setEnabled(true);
    break;
    }
}