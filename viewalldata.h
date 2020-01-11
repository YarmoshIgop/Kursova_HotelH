#ifndef VIEWALLDATA_H
#define VIEWALLDATA_H

#include <QDialog>
#include<QtSql>
#include<QSqlQuery>
#include<QFileDialog>
#include<QRegExp>
#include <QDebug>
namespace Ui {
class viewalldata;
}

class viewalldata : public QDialog
{
    Q_OBJECT

public:
    explicit viewalldata(QWidget *parent = nullptr);
      void getTableName(const QString& tableName);
    ~viewalldata();

private slots:
    void on_pushButton_clicked();

private:
    Ui::viewalldata *ui;
    QString table;
    QSqlDatabase dataBase;
       QSqlTableModel  *model;
    void setupModel(const QString &tableName, const QStringList &headers);
    void createUI();
};

#endif // VIEWALLDATA_H
