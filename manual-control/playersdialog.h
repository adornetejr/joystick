#ifndef PLAYERSDIALOG_H
#define PLAYERSDIALOG_H

#include <QDialog>

namespace Ui {
class PlayersDialog;
}

class PlayersDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlayersDialog(QWidget *parent = 0);
    ~PlayersDialog();

    int getPlayers();

private slots:
    void on_ok_cancel_button_accepted();

private:
    Ui::PlayersDialog *ui;
    int n_players;
};

#endif // PLAYERSDIALOG_H
