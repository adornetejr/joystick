#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




//QT slots
void MainWindow::on_ok_button_clicked()
{
    index = ui->mode_box->currentIndex();
    switch(index){
    case 0:
        return;
        break;
    case 1:
        int n_players;
        if(players_ui->exec()){
            n_players = players_ui->getPlayers();

            manual_uis = new ManualWindow*[n_players];
            for(int i = 0 ; i<n_players ; i++){
                manual_uis[i] = new ManualWindow(i+1);
                manual_uis[i]->setWindowTitle("Player " + QString::number((i+1)));
                manual_uis[i]->show();
            }
        }
        break;
    }
}
