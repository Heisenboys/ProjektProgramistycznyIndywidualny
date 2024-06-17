#include "nowaksiazka.h"
#include "qsqlerror.h"
#include "qsqlquery.h"
#include "ui_nowaksiazka.h"

NowaKsiazka::NowaKsiazka(QSqlDatabase db, QWidget *parent)
    : QDialog(parent)
    , dbk(db)
    ,ui(new Ui::NowaKsiazka)
{
    ui->setupUi(this);

    connect(ui->OK,&QPushButton::clicked,this,&NowaKsiazka::OK);
    connect(ui->Anuluj,&QPushButton::clicked,this,&NowaKsiazka::Anuluj);

    connect(ui->imie_autora, &QLineEdit::textChanged, this, &NowaKsiazka::enablePushButton);
    connect(ui->tytul, &QLineEdit::textChanged, this, &NowaKsiazka::enablePushButton);

    ui->OK->setEnabled(false);
}

NowaKsiazka::~NowaKsiazka()
{
    delete ui;
}

void NowaKsiazka::Anuluj(){
    reject();
}

void NowaKsiazka::enablePushButton(){
    bool enable = !ui->imie_autora->text().isEmpty() &&
                  !ui->tytul->text().isEmpty();

    ui->OK->setEnabled(enable);
}

void NowaKsiazka::OK(){
    QString imie = ui->imie_autora->text();
    QString nazwisko = ui->nazwisko_autora->text();
    QString tytul = ui->tytul->text();


    // Rozpoczęcie transakcji
    dbk.transaction();

    // Przygotowanie zapytania SQL z użyciem parametrów wiązanych
    QSqlQuery query;
    query.prepare("INSERT INTO ksiazki (imie, nazwisko, tytul, wypozyczona) "
                  "VALUES (:imie, :nazwisko, :tytul, 0)");

    query.bindValue(":imie", imie);
    if(nazwisko.isEmpty()){
        query.bindValue(":nazwisko", "NULL");
    }
    else{
        query.bindValue(":nazwisko", nazwisko);
    }
    query.bindValue(":tytul",tytul);
    if (!query.exec()) {
        qDebug() << "Błąd zapytania INSERT:"<<query.lastError();
        dbk.rollback();
        return;
    }
    dbk.commit();
    accept(); // Zaakceptowanie i zamknięcie okna dialogowego
}
