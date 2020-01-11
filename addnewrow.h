#ifndef ADDNEWROW_H
#define ADDNEWROW_H

#include <QDialog>
#include<QtSql>
#include<QSqlQuery>
#include<QFileDialog>
#include<QRegExp>
#include <QDebug>
namespace Ui {
class addnewrow;
}

class addnewrow : public QDialog
{
    Q_OBJECT

public:
    explicit addnewrow(QWidget *parent = nullptr);
    void getTableName(const QString& tableName);
    ~addnewrow();

private slots:
    void on_pushButton_clicked();



    void on_pushButton_2_clicked();

private:
    Ui::addnewrow *ui;
    QString table;
    QSqlDatabase dataBase;
};

#endif // ADDNEWROW_H
