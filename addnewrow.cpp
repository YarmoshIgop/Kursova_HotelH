#include "addnewrow.h"
#include "ui_addnewrow.h"

addnewrow::addnewrow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addnewrow)
{

    ui->setupUi(this);
    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->pushButton_2->hide();
}

void addnewrow::getTableName(const QString &tableName) {
    table = tableName;
    if (tableName == "Rooms") {
        ui->label->setText("beds: ");
        ui->label_2->setText("rating: ");
        ui->label_3->setText("state: ");
        ui->label_4->setText("date: ");

        ui->lineEdit->show();
        ui->lineEdit_2->show();
        ui->lineEdit_3->show();
        ui->lineEdit_4->show();
    } else if (tableName == "users") {

        ui->label->setText("name: ");
        ui->label_2->setText("age: ");

        ui->lineEdit->show();
        ui->lineEdit_2->show();
    }
}

addnewrow::~addnewrow()
{
    delete ui;
}


void addnewrow::on_pushButton_clicked()
{
     ui->label_6->clear();
    QString path = "/home/igop/Navchannya/Kursova/build-HotelH-Desktop_Qt_5_12_5_GCC_64bit-Debug/users.db";
    dataBase=QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setDatabaseName(path);

    if(!dataBase.open()){
        qDebug () << "can`t open db";
        return;
    }
    QSqlQuery query;

    if (table == "users") {
        QString age = ui->lineEdit_2->text();
        QString name = ui->lineEdit->text();

        query.prepare("INSERT INTO  users (name, age)"
                            "VALUES (:name, :age)");
              query.bindValue(":name", name);
              query.bindValue(":age", age);
              if(!query.exec()){
                  qDebug() << "error insert into ";
                  qDebug() << query.lastError().text();
              }

    } else if (table == "Rooms") {
        QString beds = ui->lineEdit->text();
        QString rating = ui->lineEdit_2->text();
        QString state = ui->lineEdit_3->text();
        QString date = ui->lineEdit_4->text();
        query.prepare("INSERT INTO  Rooms (beds, rating, state, date)"
                            "VALUES (:beds, :rating, :state, :date)");
              query.bindValue(":beds", beds.toInt());
              query.bindValue(":rating", rating.toInt());
              query.bindValue(":state", state);
              query.bindValue(":date", date);

              if(!query.exec()){
                  qDebug() << "error insert into ";
                  qDebug() << query.lastError().text();
              }

    }
    dataBase.close();
    ui->label_6->setText("запис добавлено");

    ui->pushButton_2->show();
}



void addnewrow::on_pushButton_2_clicked()
{
    this->hide();
}
