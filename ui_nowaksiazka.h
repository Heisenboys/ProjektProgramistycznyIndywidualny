/********************************************************************************
** Form generated from reading UI file 'nowaksiazka.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOWAKSIAZKA_H
#define UI_NOWAKSIAZKA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NowaKsiazka
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *imie_autora;
    QLineEdit *nazwisko_autora;
    QLineEdit *tytul;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QPushButton *OK;
    QPushButton *Anuluj;

    void setupUi(QDialog *NowaKsiazka)
    {
        if (NowaKsiazka->objectName().isEmpty())
            NowaKsiazka->setObjectName("NowaKsiazka");
        NowaKsiazka->resize(400, 300);
        formLayoutWidget = new QWidget(NowaKsiazka);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(50, 19, 321, 191));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        imie_autora = new QLineEdit(formLayoutWidget);
        imie_autora->setObjectName("imie_autora");

        formLayout->setWidget(0, QFormLayout::FieldRole, imie_autora);

        nazwisko_autora = new QLineEdit(formLayoutWidget);
        nazwisko_autora->setObjectName("nazwisko_autora");

        formLayout->setWidget(2, QFormLayout::FieldRole, nazwisko_autora);

        tytul = new QLineEdit(formLayoutWidget);
        tytul->setObjectName("tytul");

        formLayout->setWidget(4, QFormLayout::FieldRole, tytul);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout->setItem(3, QFormLayout::LabelRole, verticalSpacer);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout->setItem(1, QFormLayout::LabelRole, verticalSpacer_2);

        OK = new QPushButton(NowaKsiazka);
        OK->setObjectName("OK");
        OK->setGeometry(QRect(200, 250, 80, 24));
        Anuluj = new QPushButton(NowaKsiazka);
        Anuluj->setObjectName("Anuluj");
        Anuluj->setGeometry(QRect(290, 250, 80, 24));

        retranslateUi(NowaKsiazka);

        QMetaObject::connectSlotsByName(NowaKsiazka);
    } // setupUi

    void retranslateUi(QDialog *NowaKsiazka)
    {
        NowaKsiazka->setWindowTitle(QCoreApplication::translate("NowaKsiazka", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("NowaKsiazka", "Ime Autora:", nullptr));
        label_2->setText(QCoreApplication::translate("NowaKsiazka", "Tytul:", nullptr));
        label_3->setText(QCoreApplication::translate("NowaKsiazka", "Nazwisko Autora:", nullptr));
        OK->setText(QCoreApplication::translate("NowaKsiazka", "OK", nullptr));
        Anuluj->setText(QCoreApplication::translate("NowaKsiazka", "Anuluj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NowaKsiazka: public Ui_NowaKsiazka {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOWAKSIAZKA_H
