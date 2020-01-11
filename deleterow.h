#ifndef DELETEROW_H
#define DELETEROW_H

#include <QDialog>
#include<QtSql>
#include<QSqlQuery>
#include<QFileDialog>
#include<QRegExp>
#include <QDebug>
namespace Ui {
class deleterow;
}

class deleterow : public QDialog
{
    Q_OBJECT

public:
    explicit deleterow(QWidget *parent = nullptr);
     void getTableName(const QString& tableName);
    ~deleterow();

private slots:
     void on_pushButton_clicked();

     void on_pushButton_2_clicked();

private:
    Ui::deleterow *ui;
    QString table;
    QSqlDatabase dataBase;
    QSqlTableModel  *model;

      void setupModel(const QString &tableName, const QStringList &headers);
      void createUI();
};

#endif // DELETEROW_H
