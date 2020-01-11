#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include<QtSql>
#include<QSqlQuery>
#include<QFileDialog>
#include<QRegExp>
#include <QDebug>

namespace Ui {
class secondwindow;
}

class secondwindow : public QDialog
{
    Q_OBJECT

    QSqlDatabase dataBase;
    QSqlQuery sqlQuery;
    QString pathDB;
    QStringList * list;
public:
    explicit secondwindow(QWidget *parent = nullptr);
    ~secondwindow();

private slots:
    void on_pushButton_clicked();

    void on_comboBoxTables_activated(int index);

    void on_comboBoxColums_activated(int index);

    void on_lineEdit_textChanged(const QString &arg1);


    void on_pushButton_2_clicked();

    void on_delet_btn_clicked();

    void on_view_btn_clicked();

private:
    Ui::secondwindow *ui;

    void fillingData();
    void addTables();
    void makeRequest();
    void addColumns();
    void addValues(int index);

    void refleshLits();

};

#endif // SECONDWINDOW_H
