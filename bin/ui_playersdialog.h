/********************************************************************************
** Form generated from reading UI file 'playersdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERSDIALOG_H
#define UI_PLAYERSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayersDialog
{
public:
    QDialogButtonBox *ok_cancel_button;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *player_box;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QSpinBox *port_box;
    QLabel *label_4;
    QComboBox *baud_box;

    void setupUi(QDialog *PlayersDialog)
    {
        if (PlayersDialog->objectName().isEmpty())
            PlayersDialog->setObjectName(QStringLiteral("PlayersDialog"));
        PlayersDialog->resize(400, 110);
        ok_cancel_button = new QDialogButtonBox(PlayersDialog);
        ok_cancel_button->setObjectName(QStringLiteral("ok_cancel_button"));
        ok_cancel_button->setGeometry(QRect(50, 70, 341, 32));
        ok_cancel_button->setOrientation(Qt::Horizontal);
        ok_cancel_button->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget = new QWidget(PlayersDialog);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(200, 20, 171, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        player_box = new QSpinBox(horizontalLayoutWidget);
        player_box->setObjectName(QStringLiteral("player_box"));
        player_box->setMinimum(1);
        player_box->setMaximum(4);

        horizontalLayout->addWidget(player_box);

        formLayoutWidget_3 = new QWidget(PlayersDialog);
        formLayoutWidget_3->setObjectName(QStringLiteral("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(20, 10, 168, 61));
        formLayout_2 = new QFormLayout(formLayoutWidget_3);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(formLayoutWidget_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        port_box = new QSpinBox(formLayoutWidget_3);
        port_box->setObjectName(QStringLiteral("port_box"));
        port_box->setMaximum(16);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, port_box);

        label_4 = new QLabel(formLayoutWidget_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_4);

        baud_box = new QComboBox(formLayoutWidget_3);
        baud_box->setObjectName(QStringLiteral("baud_box"));
        baud_box->setEnabled(true);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, baud_box);


        retranslateUi(PlayersDialog);
        QObject::connect(ok_cancel_button, SIGNAL(accepted()), PlayersDialog, SLOT(accept()));
        QObject::connect(ok_cancel_button, SIGNAL(rejected()), PlayersDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PlayersDialog);
    } // setupUi

    void retranslateUi(QDialog *PlayersDialog)
    {
        PlayersDialog->setWindowTitle(QApplication::translate("PlayersDialog", "Players", Q_NULLPTR));
        label->setText(QApplication::translate("PlayersDialog", "Players:", Q_NULLPTR));
        label_3->setText(QApplication::translate("PlayersDialog", "Dispositivo:", Q_NULLPTR));
        port_box->setPrefix(QApplication::translate("PlayersDialog", "USB", Q_NULLPTR));
        label_4->setText(QApplication::translate("PlayersDialog", "Baudrate:", Q_NULLPTR));
        baud_box->clear();
        baud_box->insertItems(0, QStringList()
         << QApplication::translate("PlayersDialog", "115200", Q_NULLPTR)
         << QApplication::translate("PlayersDialog", "9600", Q_NULLPTR)
         << QApplication::translate("PlayersDialog", "19200", Q_NULLPTR)
         << QApplication::translate("PlayersDialog", "38400", Q_NULLPTR)
         << QApplication::translate("PlayersDialog", "57600", Q_NULLPTR)
         << QApplication::translate("PlayersDialog", "230400", Q_NULLPTR)
         << QApplication::translate("PlayersDialog", "460800", Q_NULLPTR)
         << QApplication::translate("PlayersDialog", "921600", Q_NULLPTR)
        );
        baud_box->setCurrentText(QApplication::translate("PlayersDialog", "115200", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PlayersDialog: public Ui_PlayersDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERSDIALOG_H
