#include "loginbox.h"
#include "qsqldatabase.h"
#include "qsqlerror.h"
#include "qsqlquery.h"
#include "ui_loginbox.h"

LoginBox::LoginBox(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginBox)
{
    ui->setupUi(this);
    this->setModal(true);


    dbl=QSqlDatabase::addDatabase("QSQLITE");
    dbl.setDatabaseName("C:/Users/karow/Documents/bibt/biblioteka.db");





    if (!dbl.open()) {
        qDebug() << "Nie można połączyć się z bazą danych. Błąd:";
    } else {
        qDebug() << "Połączenie z bazą danych ustanowione.";
    }

    connect(ui->lineEdit,&QLineEdit::textChanged,this,&LoginBox::Login);
    connect(ui->lineEdit_2,&QLineEdit::textChanged,this,&LoginBox::Haslo);

    connect(ui->lineEdit, &QLineEdit::textChanged, this, &LoginBox::enablePushButton);
    connect(ui->lineEdit_2, &QLineEdit::textChanged, this, &LoginBox::enablePushButton);

    connect(ui->pushButton,&QPushButton::clicked,this,&LoginBox::onClick);
    ui->pushButton->setEnabled(false);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);

    ui->label_3->setStyleSheet("color: red;");


    connect(ui->pushButton,&QPushButton::clicked,this,&LoginBox::OKClicked);
}

LoginBox::~LoginBox()
{
    delete ui;
}

QString LoginBox::Login(){
    user_login=ui->lineEdit->text();
    return ui->lineEdit->text();
}

QString LoginBox::Haslo(){
    user_haslo=ui->lineEdit_2->text();
    return ui->lineEdit_2->text();
}

void LoginBox::onClick(){
    dbl.transaction();
    QSqlQuery query;
    query.prepare("SELECT * from users where login = :user_login and haslo = :user_haslo");
    query.bindValue(":user_login",user_login);
    query.bindValue(":user_haslo",user_haslo);
    query.exec();
    if(!query.first()){
        ui->label_3->setText("login lub haslo nieprawidlowe");
        return;
    }
    kod_o=query.value(0).toInt();
    admin=query.value(10).toInt();

    dbl.commit();
    accept();
}

void LoginBox::enablePushButton(){
    bool enable = !user_login.isEmpty()&&!user_haslo.isEmpty();
    ui->pushButton->setEnabled(enable);
}

void LoginBox::OK(){
    emit OKClicked();
}




