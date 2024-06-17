#ifndef LOGINBOX_H
#define LOGINBOX_H

#include "qsqldatabase.h"
#include <QDialog>


namespace Ui {
class LoginBox;
}

class LoginBox : public QDialog
{
    Q_OBJECT

public:
    explicit LoginBox(QWidget *parent = nullptr);
    ~LoginBox();

    QSqlDatabase dbl;

    QString user_login;
    QString user_haslo;
    int admin;
    int kod_o;

    void enablePushButton();

signals:
    void OKClicked();

private slots:
    QString Login();
    QString Haslo();
    void onClick();
    void OK();


private:
     Ui::LoginBox *ui;
};

#endif // LOGINBOX_H
