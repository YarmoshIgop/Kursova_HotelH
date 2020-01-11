#include "deleterow.h"
#include "ui_deleterow.h"

deleterow::deleterow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleterow)
{
    ui->setupUi(this);
    ui->label_2->hide();
    ui->pushButton_2->hide();

}
void deleterow::setupModel(const QString &tableName, const QStringList &headers) {
    model = new QSqlTableModel(this);
    model->setTable(tableName);

    for (int i = 0, j =0; i < model->columnCount(); i++, j++) {
        model->setHeaderData(i, Qt::Horizontal, headers[j]);
    }
    model->setSort(0, Qt::AscendingOrder);
}

void deleterow::createUI()
{
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    model->select();
}
void deleterow::getTableName(const QString &tableName) {
    table = tableName;

    if (tableName == "users") {
        dataBase =  QSqlDatabase::addDatabase("QSQLITE");
        dataBase.setDatabaseName("/home/igop/Navchannya/Kursova/build-HotelH-Desktop_Qt_5_12_5_GCC_64bit-Debug/users.db");
        if (!dataBase.open()) {
            qDebug()<<dataBase.lastError().text();
        }

        this->setupModel("users",
                         QStringList() << trUtf8("id")
                         << trUtf8("name")
                         << trUtf8("age")
                         );

        this->createUI();
        dataBase.close();
    } else if (tableName == "Rooms") {
        dataBase =  QSqlDatabase::addDatabase("QSQLITE");
        dataBase.setDatabaseName("/home/igop/Navchannya/Kursova/build-HotelH-Desktop_Qt_5_12_5_GCC_64bit-Debug/users.db");
        if (!dataBase.open()) {
            qDebug()<<dataBase.lastError().text();
        }

        this->setupModel("Rooms",
                         QStringList() << trUtf8("id")
                         << trUtf8("beds")
                         << trUtf8("rating")
                         << trUtf8("state")
                         << trUtf8("date")
                         );

        this->createUI();
        dataBase.close();
    }

}

deleterow::~deleterow()
{
    delete ui;
}

void deleterow::on_pushButton_clicked()
{
    QString strId = ui->lineEdit->text();
    int id = strId.toInt();
    dataBase =  QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setDatabaseName("/home/igop/Navchannya/Kursova/build-HotelH-Desktop_Qt_5_12_5_GCC_64bit-Debug/users.db");
    if (!dataBase.open()) {
        qDebug()<<dataBase.lastError().text();
    }
    QSqlQuery query;
    if (table == "users") {
         if (!query.exec("DELETE FROM users WHERE id = '"+strId+"' ;")) {
             qDebug() <<"error deleting";
         }
        ui->label_2->setText("deleting status(200)");

    } else if (table == "Rooms") {
        if (!query.exec("DELETE FROM Rooms WHERE Number = '"+strId+"' ;")) {
            qDebug() <<"error deleting";
        }
       ui->label_2->setText("deleting status(200)");
    }
    dataBase.close();
    ui->pushButton_2->show();

}

void deleterow::on_pushButton_2_clicked()
{
    this->hide();
}
