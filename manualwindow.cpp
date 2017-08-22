#include "manualwindow.h"
#include "ui_manualwindow.h"

ManualWindow::ManualWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManualWindow)
{
    ui->setupUi(this);
}

ManualWindow::~ManualWindow()
{
    delete ui;
}
