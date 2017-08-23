#ifndef MANUALWINDOW_H
#define MANUALWINDOW_H

#include <QMainWindow>

namespace Ui {
class ManualWindow;
}

class ManualWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManualWindow(int _player, QWidget *parent = 0);
    ~ManualWindow();

private:
    Ui::ManualWindow *ui;

    int player_num;
};

#endif // MANUALWINDOW_H
