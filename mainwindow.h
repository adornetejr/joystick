#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "playersdialog.h"
#include "manualwindow.h"
namespace Ui {
class MainWindow;
}
/*!
 * \brief The MainWindow class possibilita o usuário selecionar qual tipo de controle deseja utilizar e
 * faz alocação de todos os objetos e variáveis necessárias para iniciar a chamada da proxima interface
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    /*!
     * \brief on_ok_button_clicked verifica qual dos tipos de controle foi selecionado
     * e aloca as ui's, além dos objetos necessários
     */
    void on_ok_button_clicked();

private:
    Ui::MainWindow *ui;

    PlayersDialog *players_ui; //!<Ponteiro para o Dialog que seta o numero de players e os parametro do rádio
    ManualWindow **manual_uis; //!<Vetor de ponteiros para as ManualWindows
    SerialCommunicator<Ai2RobotMessage> *serial; //!<Ponteiro para a thread de comunicação serial
};

#endif // MAINWINDOW_H
