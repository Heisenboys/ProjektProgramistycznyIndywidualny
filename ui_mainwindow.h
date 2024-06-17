/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QListView *listView;
    QLineEdit *szukaj;
    QLabel *label;
    QPushButton *przeglad_ksiazki;
    QPushButton *przeglad_users;
    QPushButton *dodaj_konto;
    QPushButton *dodaj_ksiazke;
    QPushButton *wypozycz_ksiazke;
    QPushButton *zwroc_ksiazke;
    QPushButton *wypozyczone_ksiazki;
    QLabel *bledy;
    QPushButton *reset;
    QMenuBar *menubar;
    QMenu *menuBiblioteka;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(661, 382);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        listView = new QListView(centralwidget);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(50, 50, 421, 251));
        szukaj = new QLineEdit(centralwidget);
        szukaj->setObjectName("szukaj");
        szukaj->setGeometry(QRect(530, 50, 113, 22));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(480, 50, 49, 16));
        przeglad_ksiazki = new QPushButton(centralwidget);
        przeglad_ksiazki->setObjectName("przeglad_ksiazki");
        przeglad_ksiazki->setGeometry(QRect(50, 10, 101, 24));
        przeglad_users = new QPushButton(centralwidget);
        przeglad_users->setObjectName("przeglad_users");
        przeglad_users->setGeometry(QRect(160, 10, 141, 24));
        dodaj_konto = new QPushButton(centralwidget);
        dodaj_konto->setObjectName("dodaj_konto");
        dodaj_konto->setGeometry(QRect(530, 90, 111, 24));
        dodaj_ksiazke = new QPushButton(centralwidget);
        dodaj_ksiazke->setObjectName("dodaj_ksiazke");
        dodaj_ksiazke->setGeometry(QRect(530, 130, 111, 24));
        wypozycz_ksiazke = new QPushButton(centralwidget);
        wypozycz_ksiazke->setObjectName("wypozycz_ksiazke");
        wypozycz_ksiazke->setGeometry(QRect(530, 170, 111, 24));
        zwroc_ksiazke = new QPushButton(centralwidget);
        zwroc_ksiazke->setObjectName("zwroc_ksiazke");
        zwroc_ksiazke->setGeometry(QRect(530, 210, 111, 24));
        wypozyczone_ksiazki = new QPushButton(centralwidget);
        wypozyczone_ksiazki->setObjectName("wypozyczone_ksiazki");
        wypozyczone_ksiazki->setGeometry(QRect(310, 10, 161, 24));
        bledy = new QLabel(centralwidget);
        bledy->setObjectName("bledy");
        bledy->setGeometry(QRect(488, 20, 151, 20));
        reset = new QPushButton(centralwidget);
        reset->setObjectName("reset");
        reset->setGeometry(QRect(50, 310, 80, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 661, 21));
        menuBiblioteka = new QMenu(menubar);
        menuBiblioteka->setObjectName("menuBiblioteka");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuBiblioteka->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Szukaj:", nullptr));
        przeglad_ksiazki->setText(QCoreApplication::translate("MainWindow", "Przegl\304\205daj ksi\304\205\305\274ki", nullptr));
        przeglad_users->setText(QCoreApplication::translate("MainWindow", "Przegl\304\205daj u\305\274ytkownik\303\263w", nullptr));
        dodaj_konto->setText(QCoreApplication::translate("MainWindow", "Dodaj konto", nullptr));
        dodaj_ksiazke->setText(QCoreApplication::translate("MainWindow", "Dodaj ksi\304\205\305\274k\304\231", nullptr));
        wypozycz_ksiazke->setText(QCoreApplication::translate("MainWindow", "Wypo\305\274ycz ksi\304\205\305\274k\304\231", nullptr));
        zwroc_ksiazke->setText(QCoreApplication::translate("MainWindow", "Zwr\303\263\304\207 ksi\304\205\305\274k\304\231", nullptr));
        wypozyczone_ksiazki->setText(QCoreApplication::translate("MainWindow", "Wypo\305\274yczone ksi\304\205\305\274ki", nullptr));
        bledy->setText(QString());
        reset->setText(QCoreApplication::translate("MainWindow", "Reset Systemu", nullptr));
        menuBiblioteka->setTitle(QCoreApplication::translate("MainWindow", "Biblioteka", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
