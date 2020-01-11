#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "addnewrow.h"
#include "deleterow.h"
#include "viewalldata.h"

secondwindow::secondwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);

    list=new QStringList;

    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->add_label->hide();
    ui->delete_label->hide();
    ui->view_label->hide();

    /*
    dataBase = QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setDatabaseName("users.db");

    if (dataBase.open()){

        sqlQuery=QSqlQuery(dataBase);
        sqlQuery.exec("SELECT *FROM users");

        //for (const QString &tableName:dataBase.tables())
          //  qDebug() << tableName;

        /*int count = sqlQuery.record().count();

        for (int i =0;i<count;i++)
        qDebug()<<sqlQuery.record().field(i).name();*/

        //while (sqlQuery.next())
          //  qDebug() << sqlQuery.value(1).toString();}*/

}

secondwindow::~secondwindow()
{
    delete ui;
}

void secondwindow::on_pushButton_clicked()
{
    pathDB=QFileDialog::getOpenFileName(this,"Open file","","Database (*db)");
    dataBase=QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setDatabaseName(pathDB);

    if(dataBase.open()){

        sqlQuery=QSqlQuery(dataBase);
        fillingData();
        refleshLits();
    }
}

void secondwindow::fillingData()
{
    addTables();
    makeRequest();
    addColumns();
    addValues(0);
}

void secondwindow::addTables()
{
ui->comboBoxTables->clear();

for (const QString &tableName:dataBase.tables())
    ui->comboBoxTables->addItem(tableName);

}

void secondwindow::makeRequest()
{

    QString tableName=ui->comboBoxTables->currentText();

    if (!sqlQuery.exec("SELECT * FROM '" + tableName + "';")) {
        qDebug() << sqlQuery.lastError()<<" error selecting";
    }
}

void secondwindow::addColumns(){

    ui->comboBoxColums->clear();
    int columnCount = sqlQuery.record().count();
    for (int i=0;i<columnCount;i++)
          ui->comboBoxColums->addItem(sqlQuery.record().field(i).name());
}
void secondwindow::addValues(int index){
    ui->listWidget->clear();

    while(sqlQuery.next())
        ui->listWidget->addItem(sqlQuery.value(index).toString());
}

void secondwindow::refleshLits(){
    list->clear();
    for (int i=0;i<ui->listWidget->count();i++)
    list->append(ui->listWidget->item(i)->text());


}
void secondwindow::on_comboBoxTables_activated(int index)
{
    makeRequest();
    addColumns();
    addValues(0);

    refleshLits();
}

void secondwindow::on_comboBoxColums_activated(int index)
{
    makeRequest();
    addColumns();
    addValues(index);

    refleshLits();
}

void secondwindow::on_lineEdit_textChanged(const QString &arg1)
{
    QRegExp regExp(arg1,Qt::CaseInsensitive,QRegExp::Wildcard);
    ui->listWidget->clear();
    ui->listWidget->addItems(list->filter(regExp));
}



void secondwindow::on_pushButton_2_clicked()
{
    ui->view_label->show();
    ui->lineEdit_3->show();

    QString tableName = ui->lineEdit_3->text();
    if (tableName != "") {
        qDebug() << tableName;

        addnewrow add;
        add.setModal(true);
        add.getTableName(tableName);
        add.exec();
        ui->view_label->hide();
        ui->lineEdit_3->hide();

    } else  if (tableName != "users" || tableName != "Rooms" || tableName != "" ) {
              ui->view_label->setText("такої таблиці не існує");
        }


}

void secondwindow::on_delet_btn_clicked()
{
    ui->delete_label->show();
    ui->lineEdit_2->show();

    QString tableName = ui->lineEdit_2->text();
    if (tableName != "") {
        qDebug() << tableName;

        deleterow add;
        add.setModal(true);
        add.getTableName(tableName);
        add.exec();
        ui->delete_label->hide();
        ui->lineEdit_2->hide();
    } else  if (tableName != "users" || tableName != "Rooms" || tableName != "" ) {
              ui->delete_label->setText("такої таблиці не існує");
        }

}

void secondwindow::on_view_btn_clicked()
{
    ui->add_label->show();
    ui->lineEdit_4->show();

    QString tableName = ui->lineEdit_4->text();
    if (tableName != "") {
        qDebug() << tableName;

        viewalldata add;
        add.setModal(true);
        add.getTableName(tableName);
        add.exec();
        ui->add_label->hide();
        ui->lineEdit_4->hide();
    } else  if (tableName != "users" || tableName != "Rooms" || tableName != "" ) {
              ui->delete_label->setText("такої таблиці не існує");
        }

}
