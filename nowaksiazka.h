#ifndef NOWAKSIAZKA_H
#define NOWAKSIAZKA_H

#include "qsqldatabase.h"
#include <QDialog>

namespace Ui {
class NowaKsiazka;
}

class NowaKsiazka : public QDialog
{
    Q_OBJECT

public:
    explicit NowaKsiazka(QSqlDatabase dbk,QWidget *parent = nullptr);
    ~NowaKsiazka();
    QSqlDatabase dbk;

private slots:
    void OK();
    void Anuluj();
    void enablePushButton();

private:
    Ui::NowaKsiazka *ui;
};

#endif // NOWAKSIAZKA_H
