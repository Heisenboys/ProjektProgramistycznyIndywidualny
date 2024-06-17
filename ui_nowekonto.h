/********************************************************************************
** Form generated from reading UI file 'nowekonto.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOWEKONTO_H
#define UI_NOWEKONTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NoweKonto
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *login;
    QLineEdit *haslo;
    QLineEdit *imie;
    QLineEdit *imie_2;
    QLineEdit *nazwisko;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QComboBox *miasto;
    QLineEdit *nr;
    QLineEdit *ulica;
    QLineEdit *data;
    QLineEdit *email;
    QCheckBox *checkBox;
    QPushButton *OK;
    QPushButton *Anuluj;

    void setupUi(QDialog *NoweKonto)
    {
        if (NoweKonto->objectName().isEmpty())
            NoweKonto->setObjectName("NoweKonto");
        NoweKonto->resize(400, 478);
        formLayoutWidget = new QWidget(NoweKonto);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(39, 39, 331, 324));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        login = new QLineEdit(formLayoutWidget);
        login->setObjectName("login");

        formLayout->setWidget(0, QFormLayout::FieldRole, login);

        haslo = new QLineEdit(formLayoutWidget);
        haslo->setObjectName("haslo");

        formLayout->setWidget(1, QFormLayout::FieldRole, haslo);

        imie = new QLineEdit(formLayoutWidget);
        imie->setObjectName("imie");

        formLayout->setWidget(2, QFormLayout::FieldRole, imie);

        imie_2 = new QLineEdit(formLayoutWidget);
        imie_2->setObjectName("imie_2");

        formLayout->setWidget(3, QFormLayout::FieldRole, imie_2);

        nazwisko = new QLineEdit(formLayoutWidget);
        nazwisko->setObjectName("nazwisko");

        formLayout->setWidget(4, QFormLayout::FieldRole, nazwisko);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName("label_7");

        formLayout->setWidget(9, QFormLayout::LabelRole, label_7);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName("label_8");

        formLayout->setWidget(8, QFormLayout::LabelRole, label_8);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName("label_9");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_9);

        label_10 = new QLabel(formLayoutWidget);
        label_10->setObjectName("label_10");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_10);

        miasto = new QComboBox(formLayoutWidget);
        miasto->setObjectName("miasto");

        formLayout->setWidget(9, QFormLayout::FieldRole, miasto);

        nr = new QLineEdit(formLayoutWidget);
        nr->setObjectName("nr");

        formLayout->setWidget(8, QFormLayout::FieldRole, nr);

        ulica = new QLineEdit(formLayoutWidget);
        ulica->setObjectName("ulica");

        formLayout->setWidget(7, QFormLayout::FieldRole, ulica);

        data = new QLineEdit(formLayoutWidget);
        data->setObjectName("data");

        formLayout->setWidget(6, QFormLayout::FieldRole, data);

        email = new QLineEdit(formLayoutWidget);
        email->setObjectName("email");

        formLayout->setWidget(5, QFormLayout::FieldRole, email);

        checkBox = new QCheckBox(formLayoutWidget);
        checkBox->setObjectName("checkBox");

        formLayout->setWidget(10, QFormLayout::FieldRole, checkBox);

        OK = new QPushButton(NoweKonto);
        OK->setObjectName("OK");
        OK->setGeometry(QRect(170, 440, 80, 24));
        Anuluj = new QPushButton(NoweKonto);
        Anuluj->setObjectName("Anuluj");
        Anuluj->setGeometry(QRect(260, 440, 80, 24));

        retranslateUi(NoweKonto);

        QMetaObject::connectSlotsByName(NoweKonto);
    } // setupUi

    void retranslateUi(QDialog *NoweKonto)
    {
        NoweKonto->setWindowTitle(QCoreApplication::translate("NoweKonto", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("NoweKonto", "Login:", nullptr));
        label_2->setText(QCoreApplication::translate("NoweKonto", "Haslo:", nullptr));
        label_3->setText(QCoreApplication::translate("NoweKonto", "Imie 2:", nullptr));
        label_4->setText(QCoreApplication::translate("NoweKonto", "Imie:", nullptr));
        label_5->setText(QCoreApplication::translate("NoweKonto", "Nazwisko:", nullptr));
        label_6->setText(QCoreApplication::translate("NoweKonto", "Email:", nullptr));
        label_7->setText(QCoreApplication::translate("NoweKonto", "Miasto:", nullptr));
        label_8->setText(QCoreApplication::translate("NoweKonto", "Nr:", nullptr));
        label_9->setText(QCoreApplication::translate("NoweKonto", "Ulia:", nullptr));
        label_10->setText(QCoreApplication::translate("NoweKonto", "Data_urodzenia:", nullptr));
        checkBox->setText(QCoreApplication::translate("NoweKonto", "Admin", nullptr));
        OK->setText(QCoreApplication::translate("NoweKonto", "OK", nullptr));
        Anuluj->setText(QCoreApplication::translate("NoweKonto", "Anuluj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NoweKonto: public Ui_NoweKonto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOWEKONTO_H
