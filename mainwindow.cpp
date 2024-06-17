#include "mainwindow.h"
#include "nowaksiazka.h"
#include "nowekonto.h"
#include "qsqlerror.h"
#include "ui_mainwindow.h"
#include "loginbox.h"

#include <QStandardItemModel>
#include <QSql>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->listView->

    loginBox = new LoginBox(this);
    db=loginBox->dbl;

    connect(loginBox,&LoginBox::OKClicked,this,&MainWindow::login);
    loginBox->show();

    connect(ui->przeglad_users,&QPushButton::clicked,this,&MainWindow::przeglad_u);
    connect(ui->dodaj_konto,&QPushButton::clicked,this,&MainWindow::konto);
    connect(ui->przeglad_ksiazki,&QPushButton::clicked,this,&MainWindow::przeglad_k);
    connect(ui->wypozyczone_ksiazki,&QPushButton::clicked,this,&MainWindow::przeglad_w);
    connect(ui->dodaj_ksiazke,&QPushButton::clicked,this,&MainWindow::ksiazka);
    connect(ui->wypozycz_ksiazke,&QPushButton::clicked,this,&MainWindow::wypozycz);
    connect(ui->zwroc_ksiazke,&QPushButton::clicked,this,&MainWindow::zwrot);
    connect(ui->reset,&QPushButton::clicked,this,&MainWindow::reset);
    connect(ui->szukaj,&QLineEdit::textChanged,this,&MainWindow::szukaj);


    ui->przeglad_users->setEnabled(false);
    ui->dodaj_konto->setEnabled(false);
    ui->dodaj_ksiazke->setEnabled(false);

    ui->bledy->setStyleSheet("color: red;");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::przeglad_u(){
    // Tworzenie modelu danych
    QStandardItemModel *model = new QStandardItemModel(this);

    QSqlQuery query(db);
    QSqlDatabase::database().transaction();
    query.prepare("SELECT imie, nazwisko FROM users");
    QSqlDatabase::database().commit();
    if (!query.exec()) {
        qDebug() << "Błąd zapytania SQL:";
    } else {
        while (query.next()) {
            QString imie = query.value(0).toString();
            QString nazwisko = query.value(1).toString();
            qDebug() << "Imię:" << imie;

            QStandardItem *item = new QStandardItem(imie + " " + nazwisko);
            model->appendRow(item);
        }
    }
    // Ustawienie modelu danych w QListView
    ui->listView->setModel(model);
}

void MainWindow::przeglad_k(){
    QStandardItemModel *model = new QStandardItemModel(this);

    QSqlQuery query(db);
    QSqlDatabase::database().transaction();
    query.prepare("SELECT imie, nazwisko,tytul,wypozyczona FROM ksiazki");
    QSqlDatabase::database().commit();
    if (!query.exec()) {
        qDebug() << "Błąd zapytania SQL:";
    } else {
        while (query.next()) {
            QString imie = query.value(0).toString();
            QString nazwisko = query.value(1).toString();
            QString tytul=query.value(2).toString();
            QStandardItem *item = new QStandardItem(imie + " " + nazwisko+", "+tytul);
            if(query.value(3).toInt()){
                item->setForeground(QBrush(QColor(Qt::red)));
            }
            item->setFlags(item->flags()&~Qt::ItemIsEditable);
            model->appendRow(item);
        }
    }
    // Ustawienie modelu danych w QListView
    ui->listView->setModel(model);
}

void MainWindow::konto(){
    NoweKonto *nk=new NoweKonto(db,this);
    nk->show();
}

void MainWindow::login(){
    user_name=loginBox->user_login;
    user_pass=loginBox->user_haslo;
    admin=loginBox->admin;
    kod_o=loginBox->kod_o;
    if(admin){
        ui->przeglad_users->setEnabled(true);
        ui->dodaj_konto->setEnabled(true);
        ui->dodaj_ksiazke->setEnabled(true);
    }
    return;
}

void MainWindow::przeglad_w(){
    QStandardItemModel *model = new QStandardItemModel(this);

    QSqlQuery query(db);
    db.transaction();
    query.prepare("SELECT kod_k,data_wyp,data_zwr FROM karta_wypozyczen where kod_o = :kod_o");
    query.bindValue(":kod_o",kod_o);
    if(!query.exec()){
        qDebug()<<"blad select";
    }
    db.commit();


    if (!query.exec()) {
        qDebug() << "Błąd zapytania SQL:";
    } else {
        while (query.next()) {
            int kod_k = query.value(0).toInt();
            QString data_wyp=query.value(1).toString();
            QString data_zwr=query.value(2).toString();

            QSqlQuery query_2;
            db.transaction();
            query_2.prepare("SELECT imie,nazwisko,tytul FROM ksiazki where kod_k = :kod_k");
            query_2.bindValue(":kod_k",kod_k);
            if(!query_2.exec()){
                qDebug() << query_2.lastError();
            }

            db.commit();
            if(query_2.first()){
                QString imie = query_2.value(0).toString();
                QString nazwisko = query_2.value(1).toString();
                QString tytul=query_2.value(2).toString();

                QStandardItem *item = new QStandardItem(imie + " " + nazwisko+", "+tytul+", data wypozyczenia:"+data_wyp+", data zwrotu:"+data_zwr);
                model->appendRow(item);
            }




        }
    }


    // Ustawienie modelu danych w QListView
    ui->listView->setModel(model);
}

void MainWindow::ksiazka(){
    NowaKsiazka *nk=new NowaKsiazka(db,this);
    nk->show();
}

void MainWindow::enableWypButton(){
    ui->wypozycz_ksiazke->setEnabled(true);
}

void MainWindow::wypozycz(){
    QModelIndex selectedIndex=ui->listView->currentIndex();



    if(!selectedIndex.isValid()){
        ui->bledy->setText("nic nie zaznaczono");
        return;
    }

    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->listView->model());
    QStandardItem *item = model->itemFromIndex(selectedIndex);
    QColor textColor = item->foreground().color();
    if(textColor == Qt::red){
        ui->bledy->setText("Ta ksiazka jest niedostepna");
        return;
    }

    QString index = ui->listView->model()->data(selectedIndex, Qt::DisplayRole).toString();
    index=index.section(", ",1);

    int kod_k;

    QSqlQuery bookcode;
    db.transaction();
    bookcode.prepare("SELECT kod_k from ksiazki where tytul = :tytul");
    bookcode.bindValue(":tytul",index);
    if(bookcode.exec() && bookcode.first()){
        kod_k=bookcode.value(0).toInt();
    }
    if(!bookcode.exec()){
        qDebug()<<"Blad select"<<bookcode.lastError();
        db.rollback();
        return;
    }
    db.commit();

    QSqlQuery query;
    db.transaction();
    query.prepare("INSERT into karta_wypozyczen(kod_k,kod_o,data_wyp) VALUES (:kod_k, :kod_o, date('now'))");
    query.bindValue(":kod_k",kod_k);
    query.bindValue(":kod_o",kod_o);
    if (!query.exec()) {
        qDebug() << "Błąd zapytania INSERT:"<<query.lastError();
        db.rollback();
        return;
    }
    db.commit();

    db.transaction();
    query.prepare("UPDATE ksiazki SET wypozyczona = 1 where kod_k = :kod_k");
    query.bindValue(":kod_k",kod_k);
    if (!query.exec()) {
        qDebug() << "Błąd zapytania UPDATE:"<<query.lastError();
        db.rollback();
        return;
    }
    db.commit();
    this->przeglad_k();


}

void MainWindow::zwrot(){
    QModelIndex selectedIndex=ui->listView->currentIndex();



    if(!selectedIndex.isValid()){
        ui->bledy->setText("nic nie zaznaczono");
        return;
    }

    QString index = ui->listView->model()->data(selectedIndex, Qt::DisplayRole).toString();
    QString tytul=index.section(", ",1,1);





    int kod_k=0;

    QSqlQuery bookcode;
    db.transaction();
    bookcode.prepare("SELECT kod_k from ksiazki where tytul = :tytul");
    bookcode.bindValue(":tytul",tytul);
    if(bookcode.exec() && bookcode.first()){
        kod_k=bookcode.value(0).toInt();
    }
    if(!bookcode.exec()){
        qDebug()<<"Blad select"<<bookcode.lastError();
        db.rollback();
        return;
    }
    db.commit();

    QSqlQuery query_k;
    db.transaction();
    query_k.prepare("SELECT data_zwr from karta_wypozyczen where kod_k = :kod_k");
    query_k.bindValue(":kod_k",kod_k);
    if (!query_k.exec()) {
        qDebug() << "Błąd zapytania SELECT:"<<query_k.lastError();
        db.rollback();
        return;
    }
    QString data_zwr= query_k.value(0).toString();
    if(!data_zwr.isEmpty()){
        ui->bledy->setText("Ta książka już została zwrócona");
        db.rollback();
        return;
    }
    db.commit();


    QSqlQuery query;
    db.transaction();
    query.prepare("UPDATE karta_wypozyczen SET data_zwr = date('now') where kod_k = :kod_k");
    query.bindValue(":kod_k",kod_k);
    if (!query.exec()) {
        qDebug() << "Błąd zapytania UPDATE:"<<query.lastError();
        db.rollback();
        return;
    }
    db.commit();

    db.transaction();
    query.prepare("UPDATE ksiazki SET wypozyczona = 0 where kod_k = :kod_k");
    query.bindValue(":kod_k",kod_k);
    if (!query.exec()) {
        qDebug() << "Błąd zapytania UPDATE:"<<query.lastError();
        db.rollback();
        return;
    }
    db.commit();
    this->przeglad_w();
}

void MainWindow::reset(){
    QSqlQuery query;
    db.transaction();
    query.prepare("DELETE FROM karta_wypozyczen");
    if (!query.exec()) {
        qDebug() << "Błąd zapytania delete:"<<query.lastError();
        db.rollback();
        return;
    }
    db.commit();
    db.transaction();
    query.prepare("UPDATE ksiazki set wypozyczona = 0");
    if (!query.exec()) {
        qDebug() << "Błąd zapytania update:"<<query.lastError();
        db.rollback();
        return;
    }
    db.commit();
}

void MainWindow::szukaj(){
    QString szukane = ui->szukaj->text();
    szukane=szukane+"%";

    QStandardItemModel *model = new QStandardItemModel(this);

    QSqlQuery query(db);
    QSqlDatabase::database().transaction();
    query.prepare("SELECT imie, nazwisko,tytul,wypozyczona FROM ksiazki where imie like :imie or nazwisko like :nazwisko or tytul like :tytul");
    query.bindValue(":imie", szukane);
    query.bindValue(":nazwisko", szukane);
    query.bindValue(":tytul", szukane);
    QSqlDatabase::database().commit();
    if (!query.exec()) {
        qDebug() << "Błąd zapytania SQL:";
    } else {
        while (query.next()) {
            QString imie = query.value(0).toString();
            QString nazwisko = query.value(1).toString();
            QString tytul=query.value(2).toString();
            QStandardItem *item = new QStandardItem(imie + " " + nazwisko+", "+tytul);
            if(query.value(3).toInt()){
                item->setForeground(QBrush(QColor(Qt::red)));
            }
            item->setFlags(item->flags()&~Qt::ItemIsEditable);
            model->appendRow(item);
        }


    }


    // Ustawienie modelu danych w QListView
    ui->listView->setModel(model);

}


