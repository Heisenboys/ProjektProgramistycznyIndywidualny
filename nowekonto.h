#ifndef NOWEKONTO_H
#define NOWEKONTO_H

#include "qsqldatabase.h"
#include <QDialog>

namespace Ui {
class NoweKonto;
}

class NoweKonto : public QDialog
{
    Q_OBJECT

public:
    explicit NoweKonto(QSqlDatabase &db,QWidget *parent = nullptr);
    ~NoweKonto();

    QSqlDatabase dbn;

    void insert();
    void enablePushButton();
    void Anuluj();

private:
    Ui::NoweKonto *ui;
};

#endif // NOWEKONTO_H
