#include "nowekonto.h"
#include "qsqldatabase.h"
#include "qsqlquery.h"
#include "ui_nowekonto.h"
#include <QSql>
#include <QSqlError>

NoweKonto::NoweKonto(QSqlDatabase &db,QWidget *parent)
    : QDialog(parent)
    , dbn(db)
    , ui(new Ui::NoweKonto)
{
    ui->setupUi(this);
    ui->haslo->setEchoMode(QLineEdit::Password);
    ui->OK->setEnabled(false);


    QSqlDatabase::database().transaction();
    QSqlQuery query("SELECT nazwa FROM miasta", db);
    QSqlDatabase::database().commit();
    QStringList nazwyMiast;
    while (query.next()) {
        QString nazwaMiasta = query.value(0).toString();
        nazwyMiast << nazwaMiasta;
    }

    ui->miasto->addItems(nazwyMiast);


    connect(ui->OK,&QPushButton::clicked,this,&NoweKonto::insert);
    connect(ui->Anuluj,&QPushButton::clicked,this,&NoweKonto::Anuluj);

    connect(ui->imie, &QLineEdit::textChanged, this, &NoweKonto::enablePushButton);
    connect(ui->nazwisko, &QLineEdit::textChanged, this, &NoweKonto::enablePushButton);
    connect(ui->data, &QLineEdit::textChanged, this, &NoweKonto::enablePushButton);
    connect(ui->ulica, &QLineEdit::textChanged, this, &NoweKonto::enablePushButton);
    connect(ui->nr, &QLineEdit::textChanged, this, &NoweKonto::enablePushButton);
    connect(ui->login, &QLineEdit::textChanged, this, &NoweKonto::enablePushButton);
    connect(ui->haslo, &QLineEdit::textChanged, this, &NoweKonto::enablePushButton);
}

NoweKonto::~NoweKonto(){
    delete ui;
}

void NoweKonto::insert() {
    QString imie = ui->imie->text();
    QString imie_2 = ui->imie_2->text();
    QString nazwisko = ui->nazwisko->text();
    QString email = ui->email->text();
    QString data_ur = ui->data->text();
    QString ulica = ui->ulica->text();
    QString nr = ui->nr->text();
    QString login = ui->login->text();
    QString haslo = ui->haslo->text();
    QString admin = ui->checkBox->isChecked() ? "1" : "0"; // Przyjmij, że admin to checkbox

    QString miasto = ui->miasto->currentText(); // Pobierz wybrane miasto z combobox



    dbn.transaction();
    QSqlQuery miastokod;
    miastokod.prepare("SELECT kod_m FROM miasta WHERE nazwa = :miasto");
    miastokod.bindValue(":miasto",miasto);
    if (!miastokod.exec()) {
        qDebug() << "Błąd zapytania SELECT kod_m:";
        dbn.rollback();
        return;
    }
    if (miastokod.next()) {
        miasto = miastokod.value(0).toString();
    } else {
        qDebug() << "Nie znaleziono miasta.";
        dbn.rollback();
        return;
    }
    dbn.commit();
    miasto=miastokod.value(0).toString();
    qDebug()<<miasto;
    // Rozpoczęcie transakcji
    dbn.transaction();

    // Przygotowanie zapytania SQL z użyciem parametrów wiązanych
    QSqlQuery query;
    query.prepare("INSERT INTO users (imie, imie2, nazwisko, email, data_urodzenia, ulica, nr, login, haslo, admin, kod_m, data_utworzenia_konta) "
                  "VALUES (:imie, :imie2, :nazwisko, :email, :data_ur, :ulica, :nr, :login, :haslo, :admin, :miasto, date('now'))");

    query.bindValue(":imie", imie);
    if(imie_2.isEmpty()){
        query.bindValue(":imie2", "NULL");
    }
    else{
        query.bindValue(":imie2", imie_2);
    }
    query.bindValue(":nazwisko", nazwisko);
    if(email.isEmpty()){
        query.bindValue(":email", "NULL");
    }
    else{
        query.bindValue(":email", email);
    }
    query.bindValue(":data_ur", data_ur);
    query.bindValue(":ulica", ulica);
    query.bindValue(":nr", nr);
    query.bindValue(":login", login);
    query.bindValue(":haslo", haslo);
    query.bindValue(":admin", admin);



    query.bindValue(":miasto", miasto);
    if (!query.exec()) {
        qDebug() << "Błąd zapytania INSERT:"<<query.lastError();
        dbn.rollback();
        return;
    }


    dbn.commit();
    accept(); // Zaakceptowanie i zamknięcie okna dialogowego

}

void NoweKonto::enablePushButton(){
    bool enable = !ui->imie->text().isEmpty() &&
                  !ui->nazwisko->text().isEmpty() &&
                  !ui->data->text().isEmpty() &&
                  !ui->ulica->text().isEmpty() &&
                  !ui->nr->text().isEmpty() &&
                  !ui->login->text().isEmpty() &&
                  !ui->haslo->text().isEmpty();
    ui->OK->setEnabled(enable);
}

void NoweKonto::Anuluj(){
    reject();
}



