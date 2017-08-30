#ifndef PLAYERSDIALOG_H
#define PLAYERSDIALOG_H

#include <QDialog>

#include <string>

using namespace std;

namespace Ui {
class PlayersDialog;
}
/*!
 * \brief The PlayersDialog class possibilita a obtenção do número de players e parâmetros da comunicação serial
 * para um controle manual
 */
class PlayersDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlayersDialog(QWidget *parent = 0);
    ~PlayersDialog();

    int getPlayers();
    string getDevice();
    int getBaudRate();

private slots:
    /*!
     * \brief on_ok_cancel_button_accepted faz com que quando o dialog for aceito
     * todos atributos da classe sejam setados de forma correta
     */
    void on_ok_cancel_button_accepted();

private:
    Ui::PlayersDialog *ui;
    int n_players; //!<Numero de players que vão controlar os robôs

    string device; //!<Dispositivo serial
    int baud_rate; //!<BaudRate do dispositivo
};

#endif // PLAYERSDIALOG_H
