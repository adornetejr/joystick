/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *fbot_image;
    QTextBrowser *project_name;
    QComboBox *mode_box;
    QPushButton *ok_button;
    QLabel *description;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1280, 720);
        MainWindow->setMaximumSize(QSize(1280, 720));
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        fbot_image = new QLabel(centralWidget);
        fbot_image->setObjectName(QStringLiteral("fbot_image"));
        fbot_image->setGeometry(QRect(530, 20, 220, 240));
        project_name = new QTextBrowser(centralWidget);
        project_name->setObjectName(QStringLiteral("project_name"));
        project_name->setGeometry(QRect(475, 280, 330, 50));
        mode_box = new QComboBox(centralWidget);
        mode_box->setObjectName(QStringLiteral("mode_box"));
        mode_box->setGeometry(QRect(490, 400, 300, 30));
        ok_button = new QPushButton(centralWidget);
        ok_button->setObjectName(QStringLiteral("ok_button"));
        ok_button->setGeometry(QRect(590, 435, 100, 30));
        description = new QLabel(centralWidget);
        description->setObjectName(QStringLiteral("description"));
        description->setGeometry(QRect(430, 500, 420, 140));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Joystick Furgbol", Q_NULLPTR));
        fbot_image->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        project_name->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:26pt;\">JOYSTICK FURGBOL</span></p></body></html>", Q_NULLPTR));
        mode_box->clear();
        mode_box->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Escolha o modo...", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Manual", Q_NULLPTR)
        );
        mode_box->setCurrentText(QApplication::translate("MainWindow", "Escolha o modo...", Q_NULLPTR));
        ok_button->setText(QApplication::translate("MainWindow", "OK", Q_NULLPTR));
        description->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Universidade Federal do Rio Grande - FURG</span></p><p align=\"center\"><span style=\" font-size:12pt;\">Centro de Ci\303\252ncias Computacionais - C3</span></p><p align=\"center\"><span style=\" font-size:12pt;\">Equipe de Rob\303\263tica FURGBOT</span></p><p align=\"center\"><span style=\" font-size:12pt;\">FURGBOL 2016</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
