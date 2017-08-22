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

private:
    Ui::PlayersDialog *ui;
};

#endif // PLAYERSDIALOG_H
