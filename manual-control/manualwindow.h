#ifndef MANUALWINDOW_H
#define MANUALWINDOW_H

#include <QMainWindow>
#include <QPixmap>

#include "manualcontrol.h"
#include "serialcommunicator.h"

namespace Ui {
class ManualWindow;
}
/*!
 * \brief The ManualWindow class possibilita o contole direto do robô (através de um objeto ManualControl),
 * bem como a alteração dos parâmetros físicos do controle
 */
class ManualWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManualWindow(int _player, SerialCommunicator<Ai2RobotMessage> *_serial, QWidget *parent = 0);
    ~ManualWindow();

private slots:
    /*!
     * \brief on_on_button_clicked inicia ou para a thread de leitura do controle
     * \param checked define se o método vai parar ou iniciar a thread
     */
    void on_on_button_clicked(bool checked);
    void on_id_box_editingFinished();
    void on_ang_box_editingFinished();
    void on_vel_box_editingFinished();
    void on_dri_box_editingFinished();
    void on_kick_box_editingFinished();
    void on_pass_box_editingFinished();

private:
    Ui::ManualWindow *ui;
    int player_num; //!<Numero do player da interface em questão

    ManualControl *control; //!<Ponteiro para a thread ManualControl
    SerialCommunicator<Ai2RobotMessage> *serial; //!<Ponteiro para a comunicação serial vinda da MainWindow
};

#endif // MANUALWINDOW_H
