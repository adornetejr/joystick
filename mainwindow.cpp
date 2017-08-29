#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix("../joystick/images/logo.png");
    ui->fbot_image->setPixmap(pix);
    players_ui = new PlayersDialog();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//QT slots
void MainWindow::on_ok_button_clicked()
{
    int index = ui->mode_box->currentIndex();
    switch(index){
    case 0:
        return;
        break;
    case 1:
        string device;
        int baud_rate, n_players;
        if(players_ui->exec()){
            n_players = players_ui->getPlayers();
            device = players_ui->getDevice();
            baud_rate = players_ui->getBaudRate();

            serial = new SerialCommunicator<Ai2RobotMessage>(device, baud_rate, n_players);
            if(!serial->start()) return;

            manual_uis = new ManualWindow*[n_players];
            for(int i = 0 ; i<n_players ; i++){
                manual_uis[i] = new ManualWindow(i, serial);
                manual_uis[i]->setWindowTitle("Player " + QString::number((i+1)));
                manual_uis[i]->show();
            }
        }
        break;
    }
}
