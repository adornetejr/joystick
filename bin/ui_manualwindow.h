/********************************************************************************
** Form generated from reading UI file 'manualwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANUALWINDOW_H
#define UI_MANUALWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManualWindow
{
public:
    QWidget *centralwidget;
    QTextBrowser *robor;
    QLabel *xbox_image;
    QRadioButton *on_button;
    QWidget *formLayoutWidget;
    QFormLayout *param_lay;
    QLabel *id_label;
    QSpinBox *id_box;
    QLabel *vel_label;
    QLabel *dri_label;
    QSpinBox *dri_box;
    QLabel *kick_label;
    QSpinBox *kick_box;
    QLabel *pass_label;
    QSpinBox *pass_box;
    QDoubleSpinBox *vel_box;
    QLabel *ang_label;
    QDoubleSpinBox *ang_box;
    QFrame *line;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ManualWindow)
    {
        if (ManualWindow->objectName().isEmpty())
            ManualWindow->setObjectName(QStringLiteral("ManualWindow"));
        ManualWindow->resize(800, 420);
        ManualWindow->setMaximumSize(QSize(800, 420));
        centralwidget = new QWidget(ManualWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        robor = new QTextBrowser(centralwidget);
        robor->setObjectName(QStringLiteral("robor"));
        robor->setGeometry(QRect(10, 10, 120, 30));
        xbox_image = new QLabel(centralwidget);
        xbox_image->setObjectName(QStringLiteral("xbox_image"));
        xbox_image->setGeometry(QRect(250, 40, 531, 325));
        on_button = new QRadioButton(centralwidget);
        on_button->setObjectName(QStringLiteral("on_button"));
        on_button->setGeometry(QRect(250, 20, 122, 23));
        on_button->setChecked(false);
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 40, 224, 188));
        param_lay = new QFormLayout(formLayoutWidget);
        param_lay->setObjectName(QStringLiteral("param_lay"));
        param_lay->setContentsMargins(0, 0, 0, 0);
        id_label = new QLabel(formLayoutWidget);
        id_label->setObjectName(QStringLiteral("id_label"));

        param_lay->setWidget(0, QFormLayout::LabelRole, id_label);

        id_box = new QSpinBox(formLayoutWidget);
        id_box->setObjectName(QStringLiteral("id_box"));
        id_box->setMaximum(6);

        param_lay->setWidget(0, QFormLayout::FieldRole, id_box);

        vel_label = new QLabel(formLayoutWidget);
        vel_label->setObjectName(QStringLiteral("vel_label"));

        param_lay->setWidget(2, QFormLayout::LabelRole, vel_label);

        dri_label = new QLabel(formLayoutWidget);
        dri_label->setObjectName(QStringLiteral("dri_label"));

        param_lay->setWidget(3, QFormLayout::LabelRole, dri_label);

        dri_box = new QSpinBox(formLayoutWidget);
        dri_box->setObjectName(QStringLiteral("dri_box"));
        dri_box->setMaximum(127);
        dri_box->setValue(70);

        param_lay->setWidget(3, QFormLayout::FieldRole, dri_box);

        kick_label = new QLabel(formLayoutWidget);
        kick_label->setObjectName(QStringLiteral("kick_label"));

        param_lay->setWidget(4, QFormLayout::LabelRole, kick_label);

        kick_box = new QSpinBox(formLayoutWidget);
        kick_box->setObjectName(QStringLiteral("kick_box"));
        kick_box->setMaximum(32);
        kick_box->setValue(32);

        param_lay->setWidget(4, QFormLayout::FieldRole, kick_box);

        pass_label = new QLabel(formLayoutWidget);
        pass_label->setObjectName(QStringLiteral("pass_label"));

        param_lay->setWidget(5, QFormLayout::LabelRole, pass_label);

        pass_box = new QSpinBox(formLayoutWidget);
        pass_box->setObjectName(QStringLiteral("pass_box"));
        pass_box->setMaximum(32);
        pass_box->setValue(10);

        param_lay->setWidget(5, QFormLayout::FieldRole, pass_box);

        vel_box = new QDoubleSpinBox(formLayoutWidget);
        vel_box->setObjectName(QStringLiteral("vel_box"));
        vel_box->setMinimum(0);
        vel_box->setMaximum(1.5);
        vel_box->setSingleStep(0.25);
        vel_box->setValue(0.75);

        param_lay->setWidget(2, QFormLayout::FieldRole, vel_box);

        ang_label = new QLabel(formLayoutWidget);
        ang_label->setObjectName(QStringLiteral("ang_label"));

        param_lay->setWidget(1, QFormLayout::LabelRole, ang_label);

        ang_box = new QDoubleSpinBox(formLayoutWidget);
        ang_box->setObjectName(QStringLiteral("ang_box"));
        ang_box->setMinimum(0);
        ang_box->setMaximum(10);
        ang_box->setSingleStep(0.25);
        ang_box->setValue(2.5);

        param_lay->setWidget(1, QFormLayout::FieldRole, ang_box);

        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(230, -20, 20, 411));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        ManualWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ManualWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        ManualWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ManualWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ManualWindow->setStatusBar(statusbar);

        retranslateUi(ManualWindow);

        QMetaObject::connectSlotsByName(ManualWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ManualWindow)
    {
        ManualWindow->setWindowTitle(QApplication::translate("ManualWindow", "MainWindow", Q_NULLPTR));
        robor->setHtml(QApplication::translate("ManualWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600;\">Rob\303\264</span></p></body></html>", Q_NULLPTR));
        xbox_image->setText(QApplication::translate("ManualWindow", "TextLabel", Q_NULLPTR));
        on_button->setText(QApplication::translate("ManualWindow", "Ligar Controle", Q_NULLPTR));
        id_label->setText(QApplication::translate("ManualWindow", "ID:", Q_NULLPTR));
        vel_label->setText(QApplication::translate("ManualWindow", "Velocidade m\303\241xima:", Q_NULLPTR));
        dri_label->setText(QApplication::translate("ManualWindow", "Velocidade dribbler: ", Q_NULLPTR));
        kick_label->setText(QApplication::translate("ManualWindow", "For\303\247a do chute: ", Q_NULLPTR));
        pass_label->setText(QApplication::translate("ManualWindow", "For\303\247a do passe: ", Q_NULLPTR));
        ang_label->setText(QApplication::translate("ManualWindow", "Vel. angular m\303\241xima:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ManualWindow: public Ui_ManualWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANUALWINDOW_H
