#include "viewalldata.h"
#include "ui_viewalldata.h"

viewalldata::viewalldata(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewalldata)
{
    ui->setupUi(this);
}

viewalldata::~viewalldata()
{
    delete ui;
}
void viewalldata::setupModel(const QString &tableName, const QStringList &headers) {
    model = new QSqlTableModel(this);
    model->setTable(tableName);

    for (int i = 0, j =0; i < model->columnCount(); i++, j++) {
        model->setHeaderData(i, Qt::Horizontal, headers[j]);
    }
    model->setSort(0, Qt::AscendingOrder);
}

void viewalldata::createUI()
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
void viewalldata::getTableName(const QString &tableName) {
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
void viewalldata::on_pushButton_clicked()
{
    this->hide();
}
