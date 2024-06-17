#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "loginbox.h"
#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSqlDatabase db;

private slots:
   // void select();
    void konto();
    void przeglad_u();
    void przeglad_k();
    void login();
    void przeglad_w();
    void ksiazka();
    void enableWypButton();
    void wypozycz();
    void zwrot();
    void szukaj();


private:
    Ui::MainWindow *ui;

    LoginBox *loginBox;
    QString user_name;
    QString user_pass;
    int admin;
    int kod_o;

    void reset();


};
#endif // MAINWINDOW_H
